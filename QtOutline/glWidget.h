#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "E:/thirdLib/gl/glew.h"

#include <QtOpenGL/QGLWidget>

class GLWidget : public QGLWidget {
	Q_OBJECT
public:
	GLWidget(QWidget *parent = 0);
	~GLWidget();

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

private:
};

#endif