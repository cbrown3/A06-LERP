/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2015/06
----------------------------------------------*/
#ifndef __MESHDRAWERSINGLETON_H_
#define __MESHDRAWERSINGLETON_H_

#include "RE\System\SystemSingleton.h"
#include "RE\Mesh\MeshClass.h"
#include "RE\Light\LightManagerSingleton.h"
#include "RE\Camera\CameraManagerSingleton.h"
#include <map>

namespace ReEng
{
struct ReEngDLL MeshHandler
{
	uint m_uInstanceCount = 0;			//Number of instances to draw
	std::vector<matrix4> m_lToWorld;	//List that holds the matrix per object

	/*
	 MeshHandler
	USAGE: Constructor
	ARGUMENTS: ---
	OUTPUT: class object
	*/
	MeshHandler(void);
	/* Copy Constructor */
	/*
	 USAGE:
	ARGUMENTS:
	OUTPUT:
	*/
	MeshHandler(MeshHandler& other);
	/* Copy Assignment operator */
	/*
	 USAGE:
	ARGUMENTS:
	OUTPUT:
	*/
	MeshHandler& operator=(MeshHandler& other);
	/* Destructor */
	/*
	 USAGE:
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	~MeshHandler(void);
	/*
	USAGE: Converts the list of matrix into an array of floats
	ARGUMENTS:
	OUTPUT:
	*/
	void GetMatrixArray(float* a_fArray);
	/*
	USAGE: Get the total count of instances for this model
	ARGUMENTS: ---
	OUTPUT: Total number if instances
	*/
	int GetInstanceCount(void);
};

//System Class
class ReEngDLL MeshDrawerSingleton
{
	int m_nInstanceCapacity = 250; //Number of instances to hold
	int m_nMeshes; //number of elements in the list
	static MeshDrawerSingleton* m_pInstance; // Singleton pointer
	std::vector<MeshClass*> m_lMesh; //list of meshes
	std::vector<MeshHandler*> m_lMeshHandler; //list of mesh handlers
	float* m_fMatrix;	//List of matrices to render in float form;
	ShaderManagerSingleton* m_pShaderMngr = nullptr;//Shader Manager
	LightManagerSingleton* m_pLightMngr = nullptr;		//Light Manager
	MaterialManagerSingleton* m_pMatMngr = nullptr;		//Material Manager
	CameraManagerSingleton* m_pCameraMngr = nullptr;//Pointer to the singleton of CameraSingleton
	std::map<String,int> m_map; //Identifies the objects in the list.

	MeshClass* m_pPlane = nullptr;
public:

	/*
	USAGE: Gets/Constructs the singleton pointer 
	ARGUMENTS:
	OUTPUT:
	*/
	static MeshDrawerSingleton* GetInstance();

	/*
	USAGE: Destroys the singleton
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	static void ReleaseInstance(void);

	/*
	USAGE: Adds a mesh to the mesh list
	ARGUMENTS:
	OUTPUT:
	*/
	int AddMesh(MeshClass* a_pMesh);

	/*
	USAGE: Renders the specified texture on a plane right in front of the camera
	ARGUMENTS: GLuint a_uGLIndex index of the texture in opengl (not in the texture manager)
	OUTPUT: ---
	*/
	void RenderTexture(GLuint a_uGLIndex, vector3 a_v3Tint = vector3(1.0f));

	/*
	USAGE: Gets the total number of instances currently able to hold
	ARGUMENTS: ---
	OUTPUT: number of instances currently holding
	*/
	int GetInstanceCapacity(void);

	/*
	USAGE: Sets the total number of instances able to hold
	ARGUMENTS: number of instances to hold
	OUTPUT: ---
	*/
	void SetInstanceCapacity(int a_Input);

	/*
	USAGE: Gets the mesh pointer from the vector specified by name 
	ARGUMENTS:
	OUTPUT:
	*/
	MeshClass* GetMesh(String a_sName);

	/*
	USAGE: Gets the mesh pointer from the vector specified by index
	ARGUMENTS:
	OUTPUT:
	*/
	MeshClass* GetMesh(int a_nIndex);

	/*
	USAGE: Gets the mesh index from the vector specified by name
	ARGUMENTS:
	OUTPUT:
	*/
	int GetMeshIndex(String a_sName);

	/*
	USAGE: Renders a mesh on the specified space
	ARGUMENTS:
	OUTPUT: ---
	*/
	void AddMeshToRenderList(MeshClass* a_pMesh, matrix4& a_m4ToWorld);

	/*
	USAGE: Renders a mesh on the specified space
	ARGUMENTS:
	OUTPUT: ---
	*/
	void AddMeshToRenderList(int  a_nIndex, matrix4& a_m4ToWorld);

	/*
	USAGE: Renders the list of meshes
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Render(void);

	/*
	USAGE: Renders the shape asking for its position in the world
	ARGUMENTS:
	OUTPUT: ---
	*/
	virtual void RenderMesh(MeshClass* a_pMesh, matrix4 a_mToWorld);
	
	/*
	USAGE: Renders the shape 
	ARGUMENTS:
	OUTPUT: ---
	*/
	virtual void RenderMesh(MeshClass* a_pMesh, float* a_fMatrixArray, int a_nInstances);

	/*
	USAGE: Renders the shape asking for its position in the world and a color
	ARGUMENTS:
	OUTPUT: ---
	*/
	virtual void RenderMeshWire(MeshClass* a_pMesh, matrix4 a_mToWorld, vector3 a_v3Color);

	/*
	USAGE: Renders the shape asking for its position in the world and a color
	ARGUMENTS:
	OUTPUT: ---
	*/
	virtual void RenderMeshSolid(MeshClass* a_pMesh, matrix4 a_mToWorld, vector3 a_v3Color);

	/*
	USAGE: Resets the render list
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void ClearRenderList(void);

private:
	/*
	USAGE: Constructor
	ARGUMENTS: ---
	OUTPUT:
	*/
	MeshDrawerSingleton(void);

	/*
	USAGE: Copy Constructor
	ARGUMENTS:
	OUTPUT:
	*/
	MeshDrawerSingleton(MeshDrawerSingleton const& other);

	/*
	USAGE: Copy Assignment Operator
	ARGUMENTS:
	OUTPUT:
	*/
	MeshDrawerSingleton& operator=(MeshDrawerSingleton const& other);

	/*
	USAGE: Destructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	~MeshDrawerSingleton(void);

	/*
	USAGE: Returns the index of the mesh in the list of meshes
	ARGUMENTS:
	OUTPUT:
	*/
	int IdentifyMesh(MeshClass* a_pMesh);

	/*
	USAGE: Initializates the objects fields
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Init(void);

	/*
	USAGE: Releases the objects memory
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Release(void);
};

}

#endif //__MESHRAWERSINGLETON_H_