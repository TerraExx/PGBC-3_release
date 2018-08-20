#pragma once

#include "glew.h"
#include <QOpenGLWidget>
#include "ui_MyOpenGLWidget.h"

class MyOpenGLWidget : public QOpenGLWidget
{
private:
	Q_OBJECT

	Ui::MyOpenGLWidget ui;
	const unsigned int SCALE = 3;

	GLubyte rendBuffers[2][160 * 144 * 5];

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
	GLubyte *rendBufferBack = nullptr;

	MyOpenGLWidget(QWidget *parent = Q_NULLPTR);
	~MyOpenGLWidget();

	void initializeGL();
	void swapBuffers();
	void paintGL();
};
