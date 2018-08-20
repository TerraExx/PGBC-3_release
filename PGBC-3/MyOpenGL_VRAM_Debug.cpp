#include <iostream>
#include <fstream>
#include <string>

#include "MyOpenGL_VRAM_Debug.h"

MyOpenGL_VRAM_Debug::MyOpenGL_VRAM_Debug(QWidget *parent)
	: QOpenGLWidget(parent)
{
	ui.setupUi(this);
}

MyOpenGL_VRAM_Debug::~MyOpenGL_VRAM_Debug()
{
}

void MyOpenGL_VRAM_Debug::initializeGL()
{
	setupGlew();
	setupVBO();
	setupShaders();
}

void MyOpenGL_VRAM_Debug::swapBuffers()
{
	GLubyte *temp = rendBufferFront;

	rendBufferFront = rendBufferBack;
	rendBufferBack = temp;
}

void MyOpenGL_VRAM_Debug::paintGL()
{
	glUseProgram(programID);

	glBufferData(GL_ARRAY_BUFFER, 143 * 215 * 5,
		rendBufferFront, GL_STATIC_DRAW);

	glDrawArrays(GL_POINTS, 0, 143 * 215);

	glUseProgram(programID);
}

void MyOpenGL_VRAM_Debug::installShader(const char* filename, GLuint shaderType, GLuint programID)
{
	GLint result;
	GLchar eLog[1024] = { 0 };
	const char* adapter[1];

	GLuint shaderID = glCreateShader(shaderType);

	std::ifstream file(filename);
	if (!file.good())
	{
		std::cout << "File failed to load: " << filename << std::endl;
	}

	std::string tempString = std::string(
		std::istreambuf_iterator<char>(file),
		std::istreambuf_iterator<char>()
	);

	adapter[0] = tempString.c_str();

	glShaderSource(shaderID, 1, adapter, 0);

	glCompileShader(shaderID);
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(shaderID, sizeof(eLog), NULL, eLog);
		printf("Compile Error: %s\n", eLog);
	}

	glAttachShader(programID, shaderID);

}

void MyOpenGL_VRAM_Debug::setupGlew()
{
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		std::cout << "Glew init failed to initialize" << std::endl;
	}
}

void MyOpenGL_VRAM_Debug::setupVBO()
{
	glGenBuffers(1, &VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(char) * 5, 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(char) * 5, (char*)(sizeof(char) * 2));

	rendBufferFront = rendBuffers[0];
	rendBufferBack = rendBuffers[1];

	memset(rendBufferFront, 0, sizeof(rendBufferFront));
	memset(rendBufferBack, 0, sizeof(rendBufferBack));
}

void MyOpenGL_VRAM_Debug::setupShaders()
{
	glEnable(GL_PROGRAM_POINT_SIZE);
	programID = glCreateProgram();

	installShader("VertexShaderVRAMdbg.glsl", GL_VERTEX_SHADER, programID);
	installShader("FragmentShaderVRAMdbg.glsl", GL_FRAGMENT_SHADER, programID);

	glLinkProgram(programID);
	glUseProgram(programID);

	uniformSize = glGetUniformLocation(programID, "size");
	glUniform1f(uniformSize, SCALE);

	uniformWidth = glGetUniformLocation(programID, "width");
	glUniform1f(uniformWidth, 143);

	uniformHeight = glGetUniformLocation(programID, "height");
	glUniform1f(uniformHeight, 215);
}
