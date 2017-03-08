/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2016/05
----------------------------------------------*/
#ifndef __SKYBOXCLASS_H_
#define __SKYBOXCLASS_H_

#include "RE\Mesh\MeshClass.h"

namespace ReEng
{

//System Class
class ReEngDLL SkyboxClass
{

public:
	/*
	Method: SkyboxClass
	Usage: Constructor
	Arguments: ---
	Output: class object
	*/
	SkyboxClass(void);
	/*
	Method: SkyboxClass
	Usage: Copy Constructor
	Arguments: class object to copy
	Output: class object instance
	*/
	SkyboxClass(SkyboxClass const& other);
	/*
	Method: operator=
	Usage: Copy Assignment Operator
	Arguments: class object to copy
	Output: ---
	*/
	SkyboxClass& operator=(SkyboxClass const& other);
	/*
	Method: ~SkyboxClass
	Usage: Destructor
	Arguments: ---
	Output: ---
	*/
	~SkyboxClass(void);

	/*
	Method: Swap
	Usage: Changes object contents for other object's
	Arguments:
	other -> object to swap content from
	Output: ---
	*/
	void Swap(SkyboxClass& other);

private:
	/*
	Method: Release
	Usage: Deallocates member fields
	Arguments: ---
	Output: ---
	*/
	void Release(void);
	/*
	Method: Init
	Usage: Allocates member fields
	Arguments: ---
	Output: ---
	*/
	void Init(void);
};

EXPIMP_TEMPLATE template class ReEngDLL std::vector<SkyboxClass>;
EXPIMP_TEMPLATE template class ReEngDLL std::vector<SkyboxClass*>;

}

#endif //__SkyboxClass_H__