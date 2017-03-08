/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2015/06
----------------------------------------------*/
#ifndef __RENDERINGENGINE_H_
#define __RENDERINGENGINE_H_

#pragma warning( disable : 4251 )

#include "RE\system\REDefinitions.h" //ReEng basic Definitions
#include "RE\system\SystemSingleton.h" //System related methods

#include "RE\system\WindowClass.h" //WinAPI encapsulated methods
#include "RE\system\FileReaderClass.h" //Reads an object and returns lines as strings
#include "RE\system\FolderSingleton.h" //Sets the working directory
#include "RE\system\GLSystemSingleton.h" //OpenGL 2.0 and 3.0 initialization

#include "RE\system\ShaderManagerSingleton.h" //Shader Manager, loads and manages different shader files
#include "RE\system\ShaderCompiler.h" //Compiles the shader objects

#include "RE\light\LightManagerSingleton.h" //Manages the light sources of the world

#include "RE\materials\MaterialManagerSingleton.h" //Manages the materials
#include "RE\materials\TextureManagerSingleton.h" //Manages the Textures, loads, display and release

#include "RE\Animation\AnimationClass.h" //Manages the animations in a model
#include "RE\Animation\FrameClass.h" //Manages the transformations of a model in a frame of time
#include "RE\Animation\SequenceClass.h" //Manages the starting and ending point of an animation
#include "RE\Animation\StateClass.h" //Manages the current state of the model

#include "RE\Mesh\MeshDrawerSingleton.h" //Singleton for drawing Meshes
#include "RE\Mesh\TextSingleton.h" //Singleton for drawing Text on the screen
#include "RE\Mesh\MeshManagerSingleton.h" //Singleton for drawing Meshes
#include "RE\Mesh\PrimitiveManagerSingleton.h" //Creates and manages the Primitive objects
#include "RE\Mesh\ModelManagerSingleton.h" //Manages models and instances

#include "RE\Physics\OctantClass.h"//Manages the octants

#include "RE\Camera\CameraManagerSingleton.h" //Creates and manages the camera object for the world


/*
 MapVector
USAGE: Will return a vector mapped in the mappedScale range from a value vectorToMap in the OriginalScale range
ARGUMENTS:
	vector3 vectorToMap -> input vector
	vector3 originalScaleVectorMin -> Start of the original vector
	vector3 originalScaleVectorMax -> End of the original vector
	vector3 mappedScaleVectorMin -> Start of the new vector
	vector3 mappedScaleVectorMax -> End of the new vector
OUTPUT: returns the mapped vector
*/
static vector3 MapVector(vector3 vectorToMap, vector3 originalScaleVectorMin, vector3 originalScaleVectorMax,
	vector3 mappedScaleVectorMin, vector3 mappedScaleVectorMax)
{
	vector3 v3Output;
	v3Output.x = MapValue(vectorToMap.x, originalScaleVectorMin.x, originalScaleVectorMax.x, mappedScaleVectorMin.x, mappedScaleVectorMax.x);
	v3Output.y = MapValue(vectorToMap.y, originalScaleVectorMin.y, originalScaleVectorMax.y, mappedScaleVectorMin.y, mappedScaleVectorMax.y);
	v3Output.z = MapValue(vectorToMap.z, originalScaleVectorMin.z, originalScaleVectorMax.z, mappedScaleVectorMin.z, mappedScaleVectorMax.z);
	return v3Output;
}
/*
 ToMatrix4
USAGE: Will take a glm::quat and return a glm::mat4 wrapping glm::mat4_cast
ARGUMENTS: 
	quaternion a_qInput -> quaternion to translate from
OUTPUT: matrix4 conversion of a_qInput
*/
static matrix4 ToMatrix4(quaternion a_qInput)
{
	return glm::mat4_cast(a_qInput);
}

/*
USAGE: Will generate random numbers limited to the cap (inclusive)
ARGUMENTS:
	uint a_uMin -> lower cap (exclusive)
	uint a_uMax -> upper cap (exclusive)
OUTPUT: random number between 0 and a_uMax
*/
static double GenerateRandom(double a_uMin, double a_uMax)
{
	//Old way
	//srand((unsigned)time(0));
	//return (rand() % a_uMax);

	if (a_uMin >= a_uMax)
		a_uMax = a_uMin + 1;

	//C++11 way
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(a_uMin, a_uMax);
	return dist(gen);
}

/*
 ReleaseAllSingletons
USAGE: Releases all ReEngine Singletons
ARGUMENTS: ---
OUTPUT: ---
*/
static void ReleaseAllSingletons(void)
{
	LightManagerSingleton::ReleaseInstance();
	MaterialManagerSingleton::ReleaseInstance();
	TextureManagerSingleton::ReleaseInstance();
	ModelManagerSingleton::ReleaseInstance();
	CameraManagerSingleton::ReleaseInstance();
	FolderSingleton::ReleaseInstance();
	GLSystemSingleton::ReleaseInstance();
	ShaderManagerSingleton::ReleaseInstance();
	SystemSingleton::ReleaseInstance();
	PrimitiveManagerSingleton::ReleaseInstance();
	MeshManagerSingleton::ReleaseInstance();
	TextSingleton::ReleaseInstance();
	MeshDrawerSingleton::ReleaseInstance();
}
#endif //__RENDERINGENGINE_H__