#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

void GLWidget::initializeGL(){

    glClearColor(0.8, 1, 0, 1);


}

void GLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex3f(-1, -1, 0);
        glVertex3f( 1, -1, 0);
        glVertex3f( 0.0,  1, 0);
    glEnd();


}


void GLWidget::resizeGL(int w, int h){


}


