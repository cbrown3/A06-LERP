#include "MyMesh.h"
//  MyMesh
void MyMesh::Init(void)
{
	m_bBinded = false;
	m_nVertexCount = 0;

	m_vao = 0;
	m_VertexBuffer = 0;
	m_ColorBuffer = 0;

	//Compile Color shader
	m_nShaderProgram = LoadShaders("shaders\\BasicColor.vs", "shaders\\BasicColor.fs");
}
void MyMesh::Swap(MyMesh& other)
{
	std::swap(m_bBinded, other.m_bBinded);
	std::swap(m_nVertexCount, other.m_nVertexCount);

	std::swap(m_vao, other.m_vao);
	std::swap(m_VertexBuffer, other.m_VertexBuffer);
	std::swap(m_ColorBuffer, other.m_ColorBuffer);

	std::swap(m_lVertexPos, other.m_lVertexPos);
	std::swap(m_lVertexCol, other.m_lVertexCol);

	std::swap(m_nShaderProgram, other.m_nShaderProgram);
}
void MyMesh::Release(void)
{
	if (m_ColorBuffer > 0)
		glDeleteBuffers(1, &m_ColorBuffer);

	if (m_VertexBuffer > 0)
		glDeleteBuffers(1, &m_VertexBuffer);

	if (m_vao > 0)
		glDeleteVertexArrays(1, &m_vao);

	m_lVertexPos.clear();
	m_lVertexCol.clear();
}
//The big 3
MyMesh::MyMesh(){ Init(); }
MyMesh::MyMesh(MyMesh const& other)
{
	m_bBinded = other.m_bBinded;
	m_nVertexCount = other.m_nVertexCount;

	m_vao = other.m_vao;
	m_VertexBuffer = other.m_VertexBuffer;
	m_ColorBuffer = other.m_ColorBuffer;

	m_lVertexPos = other.m_lVertexPos;
	m_lVertexCol = other.m_lVertexCol;

	m_nShaderProgram = other.m_nShaderProgram;
}
MyMesh& MyMesh::operator=(MyMesh const& other)
{
	if (this != &other)
	{
		Release();
		Init();
		MyMesh temp(other);
		Swap(temp);
	}
	return *this;
}
MyMesh::~MyMesh(){ Release(); };
//Accessors
int MyMesh::GetVertexTotal(void){ return m_nVertexCount; }
void MyMesh::AddVertexPosition(glm::vec3 input){ m_lVertexPos.push_back(input); m_nVertexCount++; }
void MyMesh::AddVertexColor(glm::vec3 input){ m_lVertexCol.push_back(input); }
//Methods
void MyMesh::CompleteMesh(void)
{
	int nColorTotal = static_cast<int>(m_lVertexCol.size());
	for (int nColor = nColorTotal; nColor < m_nVertexCount; nColor++)
		m_lVertexCol.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
}
void MyMesh::CompileOpenGL3X(void)
{
	if (m_bBinded)
		return;

	if (m_nVertexCount == 0)
		return;

	CompleteMesh();

	// Create a vertex array object
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	// Create and initialize a buffer object for each shape.
	glGenBuffers(1, &m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_nVertexCount * sizeof(glm::vec3), &m_lVertexPos[0], GL_STATIC_DRAW);

	//Initialize the color buffer for the object.
	glGenBuffers(1, &m_ColorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_ColorBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_nVertexCount * sizeof(glm::vec3), &m_lVertexCol[0], GL_STATIC_DRAW);

	m_bBinded = true;

	return;
}
void MyMesh::Render(glm::mat4 a_mToWorld)
{
	if (!m_bBinded)
		return;

	if (m_nVertexCount == 0)
		return;

	// Use the buffer and shader
	glUseProgram(m_nShaderProgram);

	// Get the GPU variables by their name and hook them to CPU variables
	GLuint MVP = glGetUniformLocation(m_nShaderProgram, "MVP");
	GLuint v4Position = glGetAttribLocation(m_nShaderProgram, "Position_b");
	GLuint v4Color = glGetAttribLocation(m_nShaderProgram, "Color_b");

	//Final Projection of the Camera is going to be hard coded
	glm::mat4 m4Projection = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
	glm::mat4 m4View = glm::lookAt(glm::vec3(0.0f, 0.0f, 15.0f), glm::vec3(0.0f, 0.0f, 14.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(m4Projection * m4View * a_mToWorld));

	//position
	glEnableVertexAttribArray(v4Position);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
	glVertexAttribPointer(v4Position, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	//Color
	glEnableVertexAttribArray(v4Color);
	glBindBuffer(GL_ARRAY_BUFFER, m_ColorBuffer);
	glVertexAttribPointer(v4Color, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	//Color and draw
	glDrawArrays(GL_TRIANGLES, 0, m_nVertexCount);

	glDisableVertexAttribArray(v4Position);
	glDisableVertexAttribArray(v4Color);
}