/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@rit.edu)
Date: 2015/09
Notes: This is a simplified version of MeshClass
inside of ReEng.dll, its stripped out of a lot
of functionality in order to focuss on important
concepts of OpenGL, please use a MeshClass object
for better functionality.
----------------------------------------------*/
#ifndef __MyMesh_H_
#define __MyMesh_H_

#include <vector>
#include <iostream>

// Include standard headers
#include <stdio.h>
#include <stdlib.h>

#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include "GLM\glm.hpp"
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtx\transform.hpp>

#include "OpenGL-Tutorials\shader.hpp"

//System Class
class MyMesh
{
protected:
	bool m_bBinded = false; //Binded flag
	int m_nVertexCount = 0; //Number of Vertices in this Mesh

	GLuint m_vao = 0;			//OpenGL Vertex Array Object
	GLuint m_VertexBuffer = 0;	//OpenGL Buffer (Will hold the vertex buffer pointer)
	GLuint m_ColorBuffer = 0;	//OpenGL Buffer (Will hold the color buffer pointer)

	GLuint m_nShaderProgram = 0;

	std::vector<glm::vec3> m_lVertexPos;	//List of Vertices
	std::vector<glm::vec3> m_lVertexCol;	//List of Colors

public:
	/* Constructor */
	MyMesh(void);
	/* Copy Constructor */
	MyMesh(MyMesh const& other);
	/* Copy Assignment Operator*/
	MyMesh& operator=(MyMesh const& other);
	/* Destructor */
	~MyMesh(void);

	/* Swaps the contents of the object with another object's content */
	void Swap(MyMesh& other);

	/* Compiles the Mesh for OpenGL 3.X use*/
	void CompileOpenGL3X(void);

	/* Returns the total number of vertices in this Mesh */
	int GetVertexTotal(void);

	/* Adds a new point to the vector of vertices */
	void AddVertexPosition(glm::vec3 a_v3Input);

	/* Adds a new color to the vector of vertices */
	void AddVertexColor(glm::vec3 a_v3Input);

	/* Renders the shape asking for its position in the world and a color */
	virtual void Render(glm::mat4 a_mToWorld);

protected:
	/* Initialize the object's fields */
	virtual void Init(void);
	/* Releases the object from memory */
	virtual void Release(void);
	/* Completes the information missing to create the mesh */
	void CompleteMesh(void);

public:
	/* Completes the triangle information */
	void CompleteTriangleInfo(void);
};

#endif //__MyMesh_H_