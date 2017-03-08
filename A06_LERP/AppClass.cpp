#include "AppClass.h"
void AppClass::InitWindow(String a_sWindowName)
{
	super::InitWindow("Assignment  06 - LERP"); // Window Name
}

void AppClass::InitVariables(void)
{
	m_pCameraMngr->SetPositionTargetAndView(vector3(0.0f, 0.0f, 15.0f), ZERO_V3, REAXISY);

	// Color of the screen
	m_v4ClearColor = vector4(REBLACK, 1); // Set the clear color to black

	m_pMeshMngr->LoadModel("Sorted\\WallEye.bto", "WallEye");

	fDuration = 1.0f;
}

void AppClass::Update(void)
{
#pragma region Does not change anything here
	//Update the system's time
	m_pSystem->UpdateTime();

	//Update the mesh manager's time without updating for collision detection
	m_pMeshMngr->Update();
#pragma endregion

#pragma region Does not need changes but feel free to change anything here
	//Lets us know how much time has passed since the last call
	double fTimeSpan = m_pSystem->LapClock(); //Delta time (between frame calls)

	//cumulative time
	static double fRunTime = 0.0f; //How much time has passed since the program started
	fRunTime += fTimeSpan; 
#pragma endregion

#pragma region Your Code goes here

	static DWORD timerSinceBoot = GetTickCount();//time since the computer booted up
	DWORD timerSinceStart = GetTickCount() - timerSinceBoot; //time since the program starts
	float fTimer = timerSinceStart / 1000.0f;//converting from milliseconds to seconds

	vector3 locs[] =
	{
		vector3(-4.0f, -2.0f, 5.0f),

		vector3(1.0f, -2.0f, 5.0f),

		vector3(-3.0f, -1.0f, 3.0f),
		
		vector3(2.0f, -1.0f, 3.0f),

		vector3(-2.0f, 0.0f, 0.0f),
	
		vector3(3.0f, 0.0f, 0.0f),

		vector3(-1.0f, 1.0f, -3.0f),

		vector3(4.0f, 1.0f, -3.0f),

		vector3(0.0f, 2.0f, -5.0f),

		vector3(5.0f, 2.0f, -5.0f),

		vector3(1.0f, 3.0f, -5.0f),

		vector3(-4.0f, -2.0f, 5.0f)
	};

	

	//Print info
	m_pMeshMngr->PrintLine("");
	m_pMeshMngr->PrintLine("Timer(seconds): " + std::to_string(fRunTime));//prints out timer

	vector3 v3From = vector3();
	vector3 v3To = vector3();
	float percentage = MapValue(fTimer, 0.0f, 1.0f, 0.0f, 1.0f);

	static int indexer = 0;

	v3From = locs[indexer];

	v3To = locs[indexer + 1];

	if (percentage > 1.0f)
	{
		timerSinceBoot = GetTickCount();
		indexer++;
	}
	if (indexer >= 11)
	{
		v3From = locs[indexer];
		indexer = 0;
		v3To = locs[indexer];
	}
	vector3 v3Current = glm::lerp(v3From, v3To, percentage);
	matrix4 m4WallEye = glm::translate(v3Current);


	m_pMeshMngr->SetModelMatrix(m4WallEye, "WallEye");
	for (int i = 0; i < sizeof(locs); i++)
	{
		matrix4 m4SpherePosition = glm::translate(locs[i]) * glm::scale(vector3(0.1));
		m_pMeshMngr->AddSphereToRenderList(m4SpherePosition, RERED, WIRE | SOLID);
	}

	m_pMeshMngr->PrintLine("Percentage: " + std::to_string(percentage));//prints out timer

#pragma endregion

#pragma region Does not need changes but feel free to change anything here
	//Adds all loaded instance to the render list
	m_pMeshMngr->AddInstanceToRenderList("ALL");

	//Indicate the FPS
	int nFPS = m_pSystem->GetFPS();

	//Print info on the screen
	m_pMeshMngr->PrintLine("");
	m_pMeshMngr->PrintLine(m_pSystem->GetAppName(), REYELLOW);
	m_pMeshMngr->Print("FPS:");
	m_pMeshMngr->Print(std::to_string(nFPS), RERED);


#pragma endregion
}

void AppClass::Display(void)
{
	//clear the screen
	ClearScreen();
	//Render the grid based on the camera's mode:
	m_pMeshMngr->AddGridToRenderListBasedOnCamera(m_pCameraMngr->GetCameraMode());
	m_pMeshMngr->Render(); //renders the render list
	m_pMeshMngr->ClearRenderList(); //Reset the Render list after render
	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	super::Release(); //release the memory of the inherited fields
}