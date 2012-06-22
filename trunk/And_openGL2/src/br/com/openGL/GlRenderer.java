package br.com.openGL;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import br.com.openGL.Triangle;
import android.opengl.GLU;
import android.opengl.GLSurfaceView.Renderer;
 
public class GlRenderer implements Renderer {

	private Triangle 	triangle;	// O triangulo para ser desenhado
	
	/** Constructor to set the handed over context */
	public GlRenderer() {
		this.triangle = new Triangle();
	}
	
	
	//onDrawFrame - é chamado para todo o redraw da classe GLSurfaceView;
	@Override
	public void onDrawFrame(GL10 gl) {
		// Limpa a tela e Depth Buffer profundidade
		gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);

		// Reseta Modelview Matrix
		gl.glLoadIdentity();

		// Drawing
		gl.glTranslatef(0.0f, 0.0f, -5.0f);		// move 5 unidades para dentro da tela
		
												// Move a camera 5 unidades
         //  	gl.glScalef(0.5f, 0.5f, 0.5f);			// escala do triangulo em 50%. Deixa o triangulo menor
												
		triangle.draw(gl);						// Constroi o triangulo

	}

	//onSurfaceChanged -  é chamado se acontecer alguma mudança geometrica na classe GLSurfaceView. 
	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		if(height == 0) { 						//Se a altura for zero, coloca 1, para evitar erros
			height = 1; 						
		}

		gl.glViewport(0, 0, width, height); 	//Reseta o Current Viewport
		gl.glMatrixMode(GL10.GL_PROJECTION); 	//Seleciona o Projection Matrix
		gl.glLoadIdentity(); 					//Reseta Projection Matrix

		//Calculate The Aspect Ratio Of The Window
		GLU.gluPerspective(gl, 45.0f, (float)width / (float)height, 0.1f, 100.0f);

		gl.glMatrixMode(GL10.GL_MODELVIEW); 	//Seleciona Modelview Matrix
		gl.glLoadIdentity(); 					//Reseta Modelview Matrix
	}

	//onSurfaceCreated - é chamado uma vez para configurar o ambiente da GLSurfaceView;
	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		 
	}

}