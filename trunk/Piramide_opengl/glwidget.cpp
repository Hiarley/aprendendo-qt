#include "glwidget.h"


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    rtri = 0.0f;

    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(16); // Tempo em mili-segundo

}

void GLWidget::initializeGL(){

    glClearColor(0, 0, 0, 1);  // Cor de fundo

}
void GLWidget::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa a Tela e o Depth Buffer (Buffer de Profundidade)
        glLoadIdentity();             // Reseta a visualizaçao

    //    glTranslatef(0.2f, 0.2f, 0.0f);   // Move a posiçao do triangulo, o bug tá mais ou menos aqui,
        // Quando eu movo ele pro centro ele passa de uma margem que tem perto dele, ai ele some.

        glRotatef(rtri,0.0f,1.0f,0.0f);       // Rotaçao da Piramide no eixo Y

        glBegin(GL_TRIANGLES); // Cria o Triangulo

        //Atribui as Vertices e suas determinadas cores

        glColor3f(1.0f,0.0f,0.0f);          // Red
        glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Front)
        glColor3f(0.0f,1.0f,0.0f);          // Green
        glVertex3f(-1.0f,-1.0f, 1.0f);          // Left Of Triangle (Front)
        glColor3f(0.0f,0.0f,1.0f);          // Blue
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Right Of Triangle (Front)

        glColor3f(1.0f,0.0f,0.0f);          // Red
        glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Right)
        glColor3f(0.0f,0.0f,1.0f);          // Blue
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Left Of Triangle (Right)
        glColor3f(0.0f,1.0f,0.0f);          // Green
        glVertex3f( 1.0f,-1.0f, -1.0f);         // Right Of Triangle (Right)
        glColor3f(1.0f,0.0f,0.0f);          // Red

        glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Back)
        glColor3f(0.0f,1.0f,0.0f);          // Green
        glVertex3f( 1.0f,-1.0f, -1.0f);         // Left Of Triangle (Back)
        glColor3f(0.0f,0.0f,1.0f);          // Blue
        glVertex3f(-1.0f,-1.0f, -1.0f);         // Right Of Triangle (Back)
        glColor3f(1.0f,0.0f,0.0f);          // Red

           glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Left)
           glColor3f(0.0f,0.0f,1.0f);          // Blue
           glVertex3f(-1.0f,-1.0f,-1.0f);          // Left Of Triangle (Left)
           glColor3f(0.0f,1.0f,0.0f);          // Green
           glVertex3f(-1.0f,-1.0f, 1.0f);          // Right Of Triangle (Left)

       glEnd();                        // Termina o desenho

       rtri+=2.0f;                     // Incrementa a a variável de rotaçao do Triangulo




}


void GLWidget::resizeGL(int w, int h){

}


