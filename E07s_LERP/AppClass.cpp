#include "AppClass.h"
void AppClass::InitWindow(String a_sWindowName)
{
	super::InitWindow("E07s - LERP"); // Window Name

	// Set the clear color based on Microsoft's CornflowerBlue (default in XNA)
	//if this line is in Init Application it will depend on the .cfg file, if it
	//is on the InitVariables it will always force it regardless of the .cfg
	m_v4ClearColor = vector4(0.4f, 0.6f, 0.9f, 0.0f);
}

void AppClass::InitVariables(void)
{
	m_pCameraMngr->SetPosition(vector3(0.0f, 0.0f, 35.0f));

	srand(static_cast<uint>(time(NULL)));
	m_nObjects = rand() % 23 + 5;

	vector3 v3Start = vector3(-m_nObjects, 0.0f, 0.0f);
	vector3 v3End = vector3(m_nObjects, 0.0f, 0.0f);

	m_pSphere = new PrimitiveClass[m_nObjects];
	m_pMatrix = new matrix4[m_nObjects];


	for (int nSphere = 0; nSphere < m_nObjects; nSphere++)
	{
		float fPercent = MapValue(static_cast<float>(nSphere), 0.0f, static_cast<float>(m_nObjects), 0.0f, 1.0f);
		m_pSphere[nSphere].GenerateSphere(1.0f, 5, vector3(fPercent, 0.0f, 0.0f));
		m_pMatrix[nSphere] = glm::translate(glm::lerp(v3Start, v3End, fPercent));
	}
}

void AppClass::Update(void)
{
	//Update the system's time
	m_pSystem->UpdateTime();

	//Update the mesh manager's time without updating for collision detection
	m_pMeshMngr->Update();

	//First person camera movement
	if (m_bFPC == true)
		CameraRotation();

	//Call the arcball method
	ArcBall();
	
	//Adds all loaded instance to the render list
	m_pMeshMngr->AddInstanceToRenderList("ALL");

	//Indicate the FPS
	int nFPS = m_pSystem->GetFPS();
	//print info into the console
	//printf("FPS: %d            \r", nFPS);//print the Frames per Second
	//Print info on the screen
	m_pMeshMngr->PrintLine("");
	m_pMeshMngr->PrintLine(m_pSystem->GetAppName(), REYELLOW);

	m_pMeshMngr->Print("Selection: ");
	m_pMeshMngr->PrintLine(m_pMeshMngr->GetInstanceGroupName(m_selection.first, m_selection.second), REYELLOW);
	
	m_pMeshMngr->Print("FPS:");
	m_pMeshMngr->Print(std::to_string(nFPS), RERED);
}

void AppClass::Display(void)
{
	//clear the screen
	ClearScreen();
	
	//Matrices from the camera
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();

	for (int nSphere = 0; nSphere < m_nObjects; nSphere++)
	{
		m_pSphere[nSphere].Render(m4Projection, m4View, m_pMatrix[nSphere]);
	}
	//Render the grid based on the camera's mode:
	m_pMeshMngr->AddGridToRenderListBasedOnCamera(m_pCameraMngr->GetCameraMode());
	m_pMeshMngr->Render(); //renders the render list
	m_pMeshMngr->ClearRenderList(); //Reset the Render list after render
	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	if (m_pSphere != nullptr)
	{
		delete[] m_pSphere;
		m_pSphere = nullptr;
	}
	if (m_pMatrix != nullptr)
	{
		delete[] m_pMatrix;
		m_pMatrix = nullptr;
	}

	super::Release(); //release the memory of the inherited fields
}