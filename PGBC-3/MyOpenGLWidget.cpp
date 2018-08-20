#include <iostream>
#include <fstream>
#include <string>

#include "MyOpenGLWidget.h"

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	ui.setupUi(this);
}

MyOpenGLWidget::~MyOpenGLWidget()
{
}

void MyOpenGLWidget::initializeGL()
{
	setupGlew();
	setupVBO();
	setupShaders();
}

void MyOpenGLWidget::swapBuffers()
{
	GLubyte *temp = rendBufferFront;

	rendBufferFront = rendBufferBack;
	rendBufferBack = temp;
}

void MyOpenGLWidget::paintGL()
{
	glUseProgram(programID);

	glBufferData(GL_ARRAY_BUFFER, 160 * 144 * 5,
		rendBufferFront, GL_STATIC_DRAW);

	glDrawArrays(GL_POINTS, 0, 160 * 144);

	glUseProgram(programID);
}

void MyOpenGLWidget::installShader(const char* filename, GLuint shaderType, GLuint programID)
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

void MyOpenGLWidget::setupGlew()
{
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		std::cout << "Glew init failed to initialize" << std::endl;
	}
}

void MyOpenGLWidget::setupVBO()
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

void MyOpenGLWidget::setupShaders()
{
	glEnable(GL_PROGRAM_POINT_SIZE);
	programID = glCreateProgram();

	installShader("VertexShader.glsl", GL_VERTEX_SHADER, programID);
	installShader("FragmentShader.glsl", GL_FRAGMENT_SHADER, programID);

	glLinkProgram(programID);
	glUseProgram(programID);

	uniformSize = glGetUniformLocation(programID, "size");
	glUniform1f(uniformSize, SCALE);

	uniformWidth = glGetUniformLocation(programID, "width");
	glUniform1f(uniformWidth, 160);

	uniformHeight = glGetUniformLocation(programID, "height");
	glUniform1f(uniformHeight, 144);
}
