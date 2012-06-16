#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>
#include <QTimer>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    
void initializeGL();
void paintGL();
void resizeGL(int w, int h);

private:
QTimer timer;


private:
GLfloat rtri;


    
};

#endif // GLWIDGET_H
