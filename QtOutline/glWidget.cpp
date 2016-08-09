#include "glWidget.h"

GLWidget::GLWidget(QWidget *parent /* = 0 */) : QGLWidget(parent) {

}

GLWidget::~GLWidget() {}

void GLWidget::initializeGL() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	gluPerspective(45.0f, 1, 0.1f, 100.0f);
}

void GLWidget::resizeGL(int w, int h) {
	if (h == 0) h = 1;
	glViewport(0, 0, (GLint)w, (GLint)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GLWidget::paintGL() {
	//Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex3d(1.0, 0.0, 0.0);
	glVertex3d(0.0, 1.0, 0.0);
	glVertex3d(0.0, 0.0, 1.0);
	glEnd();
}