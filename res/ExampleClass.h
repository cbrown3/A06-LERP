/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2015/06
----------------------------------------------*/
#ifndef __EXAMPLECLASS_H_
#define __EXAMPLECLASS_H_

#include "RE\system\SystemSingleton.h"

namespace ReEng
{

//System Class
class ReEngDLL ExampleClass
{
	int m_nData = 0; //Number of elements in the list of elements
	std::vector<int> m_lData; //list of elements

public:
	/*
	Method: ExampleClass
	Usage: Constructor
	Arguments: ---
	Output: class object
	*/
	ExampleClass(void);
	/*
	Method: ExampleClass
	Usage: Copy Constructor
	Arguments: class object to copy
	Output: class object instance
	*/
	ExampleClass(ExampleClass const& other);
	/*
	Method: operator=
	Usage: Copy Assignment Operator
	Arguments: class object to copy
	Output: ---
	*/
	ExampleClass& operator=(ExampleClass const& other);
	/*
	Method: ~ExampleClass
	Usage: Destructor
	Arguments: ---
	Output: ---
	*/
	~ExampleClass(void);

	/*
	Method: Swap
	Usage: Changes object contents for other object's
	Arguments:
	other -> object to swap content from
	Output: ---
	*/
	void Swap(ExampleClass& other);

	/*
	Method:
	Usage:
	Arguments: ---
	Output:
	*/
	int GetData(void);
	/*
	Method:
	Usage:
	Arguments:
	Output: ---
	*/
	void SetData(int a_nData = 1);
	/* Property */
	//__declspec(property(get = GetData, put = SetData)) int Data;

	/*
	Method:
	Usage:
	Arguments:
	Output: ---
	*/
	void SetDataOnVector(int a_nData);
	/*
	Method:
	Usage:
	Arguments:
	Output:
	*/
	int& GetDataOnVector(int a_nIndex);

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

EXPIMP_TEMPLATE template class ReEngDLL std::vector<ExampleClass>;
EXPIMP_TEMPLATE template class ReEngDLL std::vector<ExampleClass*>;

}

#endif //__EXAMPLECLASS_H__