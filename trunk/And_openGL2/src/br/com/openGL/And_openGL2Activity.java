package br.com.openGL;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;
 


public class And_openGL2Activity extends Activity {
	
	/** The OpenGL view */
	private GLSurfaceView glSurfaceView;
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // Tirando o título do programa
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        // Deixando FullScreen
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
				WindowManager.LayoutParams.FLAG_FULLSCREEN);

        // Iniciando o Open GL view e criando uma estancia
        glSurfaceView = new GLSurfaceView(this);
        
        // inserindo o renderer
        glSurfaceView.setRenderer(new GlRenderer());
        setContentView(glSurfaceView);
    }

	/**
	 * Continuar o glSurface
	 */
	@Override
	protected void onResume() {
		super.onResume();
		glSurfaceView.onResume();
	}

	/**
	 * Pausar glSurface
	 */
	@Override
	protected void onPause() {
		super.onPause();
		glSurfaceView.onPause();
	}
    
    
        
       
}