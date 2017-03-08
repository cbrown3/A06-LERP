/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2015/06
Modified: 2016/05
----------------------------------------------*/
#ifndef __MATERIALMANAGERSINGLETON_H_
#define __MATERIALMANAGERSINGLETON_H_

#include "RE\system\SystemSingleton.h"
#include "RE\materials\MaterialClass.h"
#include <map>


namespace ReEng
{

class ReEngDLL MaterialManagerSingleton
{
	/* 
		The material vector is public for accessing speed reasons its more secure to have it as private
		and provide the right accessors for it, but its call so often that it creates overhead the other way
	*/
	std::map<String,int> m_map; //Map of the materials
	SystemSingleton* m_pSystem; //System class Pointer
	static MaterialManagerSingleton* m_pInstance; // Singleton Pointer

public:
	std::vector<MaterialClass*> m_lMaterial; //Materials Vector
	

	/*
	USAGE: Singleton Accessor
	ARGUMENTS:
	OUTPUT:
	*/
	static MaterialManagerSingleton* GetInstance();
	
	/*
	USAGE: Singleton Destructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	static void ReleaseInstance(void);

	/*
	USAGE: Identifies the material, if found return its index -1 otherwise
	ARGUMENTS:
	OUTPUT:
	*/
	int IdentifyMaterial(String a_sName);

	/*
	USAGE: returns the index number of the material if it created a new one, otherwise it returns the index
	ARGUMENTS:
	OUTPUT:
	*/
	int AddMaterial(String a_sName);
	
	/*
	USAGE:
	ARGUMENTS:
	OUTPUT:
	*/
	int AddMaterial(MaterialClass a_InputMaterial);

	/*
	USAGE: Return the number of materials in the vector
	ARGUMENTS: ---
	OUTPUT:
	*/
	int GetMaterialCount(void);

	/*
	USAGE: Tries to load all the textures for all of the materials
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void ReloadMaps(void);

	/*
	USAGE: Gets a copy of the material specified by name
	ARGUMENTS:
	OUTPUT:
	*/
	MaterialClass GetMaterialCopy(String a_sName);

	/*
	USAGE: Returns the memory location containing the material specified by the name
	ARGUMENTS:
	OUTPUT:
	*/
	MaterialClass* GetMaterial(String a_sName);

	/*
	USAGE: Returns the memory location containing the material specified by the index
	ARGUMENTS:
	OUTPUT:
	*/
	MaterialClass* GetMaterial(uint a_nIndex);

	/*
	USAGE: Sets the Diffuse map name of the specified material
	ARGUMENTS:
		String a_sFileName -> name of the texture file "File.png"
		int a_nIndex = -1 -> index of the material to modify, -1 for last added material
	OUTPUT:
	*/
	void SetDiffuseMapName(String a_sFileName, int a_nIndex = -1);

	/*
	USAGE: Sets the Normal map name of the specified material
	ARGUMENTS:
		String a_sFileName -> name of the texture file "File.png"
		int a_nIndex = -1 -> index of the material to modify, -1 for last added material
	OUTPUT:
	*/
	void SetNormalMapName(String a_sFileName, int a_nIndex = -1);

	/*
	USAGE: Sets the Specular map name of the specified material
	ARGUMENTS:
	String a_sFileName -> name of the texture file "File.png"
	int a_nIndex = -1 -> index of the material to modify, -1 for last added material
	OUTPUT:
	*/
	void SetSpecularMapName(String a_sFileName, int a_nIndex = -1);

	/*
	USAGE: Gets the Diffuse map name of the specified material
	ARGUMENTS:
		int a_nIndex = -1 -> index of the material to modify, -1 for last added material
	OUTPUT: name of the diffuse map of the specified material
	*/
	String GetDiffuseMapName(int a_nIndex = -1);

	/*
	USAGE: Gets the Diffuse map name of the specified material
	ARGUMENTS:
	int a_nIndex = -1 -> index of the material to modify, -1 for last added material
	OUTPUT: name of the diffuse map of the specified material
	*/
	String GetNormalMapName(int a_nIndex = -1);

	/*
	USAGE: Gets the Diffuse map name of the specified material
	ARGUMENTS:
	int a_nIndex = -1 -> index of the material to modify, -1 for last added material
	OUTPUT: name of the diffuse map of the specified material
	*/
	String GetSpecularMapName(int a_nIndex = -1);

private:
	
	/*
	USAGE: Constructor
	ARGUMENTS: ---
	OUTPUT:
	*/
	MaterialManagerSingleton(void);

	/*
	USAGE: Copy Constructor
	ARGUMENTS:
	OUTPUT:
	*/
	MaterialManagerSingleton(MaterialManagerSingleton const& other);
	
	/*
	USAGE: Copy Assignment Operator
	ARGUMENTS:
	OUTPUT:
	*/
	MaterialManagerSingleton& operator=(MaterialManagerSingleton const& other);
	
	/*
	USAGE: Destructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	~MaterialManagerSingleton(void);

	/*
	USAGE: Release Memory
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Release(void);
	
	/*
	USAGE: Initialize variables
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Init(void);
};

}
#endif //_MATERIALMANAGERSINGLETON_H