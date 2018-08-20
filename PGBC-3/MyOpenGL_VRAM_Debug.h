#pragma once

#include "glew.h"
#include <QOpenGLWidget>
#include "ui_MyOpenGL_VRAM_Debug.h"

class MyOpenGL_VRAM_Debug : public QOpenGLWidget
{
private:
	Q_OBJECT

	Ui::MyOpenGL_VRAM_Debug ui;

	const unsigned int SCALE = 2;

	GLubyte rendBuffers[2][143 * 215 * 5];

	GLubyte *rendBufferFront = nullptr;

	GLuint programID;
	GLuint VBO_ID;
	GLuint uniformSize;
	GLuint uniformWidth;
	GLuint uniformHeight;

	void installShader(const char* filename, GLuint shaderType, GLuint programID);

	void setupGlew();
	void setupVBO();
	void setupShaders();

public:
	GLubyte * rendBufferBack = nullptr;

	MyOpenGL_VRAM_Debug(QWidget *parent = Q_NULLPTR);
	~MyOpenGL_VRAM_Debug();

	void initializeGL();
	void swapBuffers();
	void paintGL();
};
