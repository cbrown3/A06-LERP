/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2015/06
----------------------------------------------*/
#ifndef __ExampleSingleton_H_
#define __ExampleSingleton_H_

#include "RE\system\SystemSingleton.h"

namespace ReEng
{

//System Class
class ReEngDLL ExampleSingleton
{
	int m_nData = 0; //number of elements in the list
	static ExampleSingleton* m_pInstance; // Singleton pointer
	std::vector<int> m_lData; //list of elements
public:
	/*
	Method:
	Usage:
	Arguments:
	Output:
	*/
	static ExampleSingleton* GetInstance();
	/*
	Method:
	Usage:
	Arguments: ---
	Output: ---
	*/
	static void ReleaseInstance(void);

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
	/* Property GetData/SetData */
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
	Method:
	Usage:
	Arguments: ---
	Output:
	*/
	ExampleSingleton(void);
	/*
	Method:
	Usage:
	Arguments:
	Output:
	*/
	ExampleSingleton(ExampleSingleton const& other);
	/*
	Method:
	Usage:
	Arguments:
	Output:
	*/
	ExampleSingleton& operator=(ExampleSingleton const& other);
	/*
	Method:
	Usage:
	Arguments: ---
	Output: ---
	*/
	~ExampleSingleton(void);
	/*
	Method:
	Usage:
	Arguments: ---
	Output: ---
	*/
	void Release(void);
	/*
	Method:
	Usage:
	Arguments: ---
	Output: ---
	*/
	void Init(void);
};

}

#endif //__EXAMPLECLASS_H__