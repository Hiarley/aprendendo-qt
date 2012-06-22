package br.com.openGL;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer; 
import javax.microedition.khronos.opengles.GL10;

public class Triangle {
	
	private FloatBuffer vertexBuffer;	// buffer holding the vertices
	
	//Os pontos das vértices do triangulo, em um gráfico cartesiano
	
	private float vertices[] = {
			-0.5f, -0.5f,  0.0f,		// V1 - first vertex (x,y,z)
			 0.5f, -0.5f,  0.0f,		// V2 - second vertex
			 0.0f,  0.5f,  0.0f			// V3 - third vertex
	};
	
	public Triangle() {
		// um float tem 4 bytes, então é alocado 4 bytes para cada float
		ByteBuffer vertexByteBuffer = ByteBuffer.allocateDirect(vertices.length * 4);
		vertexByteBuffer.order(ByteOrder.nativeOrder());
		
		// Disponibiliza a memória para o Byte Buffer
		vertexBuffer = vertexByteBuffer.asFloatBuffer();
		
		vertexBuffer.put(vertices); //
		vertexBuffer.position(0);
		
	}

	
	/** The draw method for the triangle with the GL context */
	public void draw(GL10 gl) {
		
		gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
		
		// gl.glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
		gl.glClearColor(0.5f, 0.5f, 0.5f, 1.0f); //Cor de Fundo
		
		// Para mostrar a cor é necessário apagar o color buffer
		gl.glClear(GL10.GL_COLOR_BUFFER_BIT);
		
		// A cor do Triangulo
		gl.glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		
		// Ponto vertex buffer (Vértices)
		gl.glVertexPointer(3, GL10.GL_FLOAT, 0, vertexBuffer);

		// Desenha as vertices do triangulo (modo triangle strip)
		gl.glDrawArrays(GL10.GL_TRIANGLE_STRIP, 0, vertices.length / 3);
		
		//Disabilita client state
		gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
	}
}
