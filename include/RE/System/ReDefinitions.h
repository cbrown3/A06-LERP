/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2015/06
----------------------------------------------*/
#ifndef __REDEFINITIONS_H_
#define __REDEFINITIONS_H_

// Include standard headers
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include <math.h>
#include <vector>
#include <locale>
#include <algorithm>
#include <fstream>
#include <sstream>

// Include GLM
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\ext.hpp>
#include <glm\gtc\quaternion.hpp>

#ifdef EXP_STL
#	define ReEngDLL __declspec(dllexport)
#	define EXPIMP_TEMPLATE
#else
#	define ReEngDLL __declspec(dllimport)
#	define EXPIMP_TEMPLATE extern
#endif

namespace ReEng
{
typedef std::string String;
typedef glm::vec2 vector2;
typedef glm::vec3 vector3;
typedef glm::vec4 vector4;
typedef glm::mat3 matrix3;
typedef glm::mat4 matrix4;
typedef unsigned int uint;
typedef glm::quat quaternion;

#define SafeDelete(p){ if(p) { delete p; p = nullptr; } }
////https://stackoverflow.com/questions/10240161/reason-to-pass-a-pointer-by-reference-in-c/20188970#20188970
//template<typename T>
//void SafeDelete(T*& p)
//{
//	if(p != nullptr)
//	{
//		delete p;
//		p = nullptr;
//	} 
//}
#define PI 3.14159265358979323846
#define IDENTITY_M4 matrix4(1.0f)

#define REBLACK vector3(0.0f, 0.0f, 0.0f)
#define REWHITE vector3(1.0f, 1.0f, 1.0f)
#define REGRAY vector3(0.3f, 0.3f, 0.3f)

#define RERED vector3(1.0f, 0.0f, 0.0f)
#define REMAGENTA vector3(1.0f, 0.0f, 1.0f)
#define REBROWN vector3(0.6f,0.3f,0.0f)

#define REGREEN vector3(0.0f, 1.0f, 0.0f)
#define REGREENDARK vector3(0.0f, 5.0f, 0.0f)
#define RELIME vector3(0.33f,0.90f,0.33f)

#define RECORNFLOWERBLUE vector3(0.4f, 0.6f, 0.9f)
#define REBLUE vector3(0.0f, 0.0f, 1.0f)
#define RECYAN vector3(0.0f,1.0f,1.0f)

#define REYELLOW vector3(1.0f, 1.0f, 0.0f)
#define REORANGE vector3(1.0f,0.5f,0.0f)
#define REVIOLET vector3(0.54f,0.16f,0.88f)
#define REPURPLE vector3(0.50f,0.0f,0.50f)

#define REDEFAULT vector3(-1.0f, -1.0f, -1.0f)

#define ZERO_V3 vector3(0.0f, 0.0f, 0.0f)
#define REAXISX vector3(1.0f, 0.0f, 0.0f)
#define REAXISY vector3(0.0f, 1.0f, 0.0f)
#define REAXISZ vector3(0.0f, 0.0f, 1.0f)

//-----------------------------------------------------------------------------------------------------------
// Enumerations
//-----------------------------------------------------------------------------------------------------------
enum REOptions
{
	NO = 0,
	YES = 1,
	ASK = 2,
	OPENGL2X = 3,
	OPENGL3X = 4,
	DIRECTX = 5
};
enum REERRORS
{
	RERROR_GENERAL,
	RERROR_FREE,
	RERROR_FILE_MISSING,
	RERROR_CONTEXT,
	RERROR_MEMORY,
	RERROR_NAME,
	RERROR_NOT_INITIALIZED,
	RERROR_FILE,
	RERROR_NO_EXTENSION,
	RE_DONE,
	RE_RUNNING,
};
enum REAXIS
{
	NONE = 0,
	XY = 1,
	XZ = 2,
	YZ = 4,
};
enum REBODISPLAY
{
	BD_NONE = 0,//...
	BD_BS = 1, //Bounding Sphere
	BD_OB = 2, //Oriented Bounding Box
	BD_AB = 4, //Axis (Re)Aligned Bounding Box
};
enum RERENDER
{
	SOLID = 1,
	WIRE = 2,
};
enum CAMERAMODE
{
	CAMPERSP = 0,
	CAMROTHOX = 1,
	CAMROTHOY = 2,
	CAMROTHOZ = 3,
};
enum FORMAT
{
	ATO = 0,
	BTO = 1,
};
enum RESOLUTIONS
{
	//Resolution | Aspect Ratio | Name
	WINDOWED,
	//Common resolutions
	C_720x480_4x3_NTSC,
	C_1280x720_16x9_HD,
	C_1920x1080_16x9_FULLHD,

	CV_480x720_3x4_NTSC,
	CV_720x1280_9x16_HD,
	CV_1080x1920_9x16_FULLHD,

	//Monitor Resolutions
	M_640x480_4x3_VGA,
	M_1600x900_16x9_WXGA,
	M_1920x1200_16x10_WUXGA,
	M_2560x1080_21x9_UWUXGA,

	MV_480x640_3x4_VGA,
	MV_900x1600_9x16_WXGA,
	MV_1200x1920_10x16_WUXGA,
	MV_1080x2560_9x21_UWUXGA,

	//Other Resolutions
	O_800x600_4x3_SVGA,
	O_1024x768_4x3_XGA,
	O_1280x800_16x10_WXGA,
	O_1600x1200_4x3_UXGA,
	O_2048x1080_17x9_2K,
	O_3840x2160_17x9_4K,
};

/*
MapValue
USAGE: Will map a value from an original scale to a new scale
ARGUMENTS:
T valueToMap -> input value
T originalScale_min ->  Start of the original scale
T originalScale_max -> End of the original scale
T mappedScale_min -> Start of the new scale
T mappedScale_max -> end of the new scale
OUTPUT: returns the mapped value
*/
template <class T>
static T MapValue(T valueToMap, T originalScale_min, T originalScale_max, T mappedScale_min, T mappedScale_max)
{
	return (valueToMap - originalScale_min) * (mappedScale_max - mappedScale_min) / (originalScale_max - originalScale_min) + mappedScale_min;
}


}

#endif //__REDEFINITIONS_H__