package br.com.camera;

import java.io.File;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.view.View;
import android.widget.Button;

public class And_cameraActivity extends Activity {
    /** Called when the activity is first created. */
	Button btFoto, btVis;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        btFoto = (Button) findViewById(R.id.foto);
        btVis = (Button) findViewById(R.id.visualizar);
        
        btVis.setVisibility(View.INVISIBLE); //Deixando o botão de Visualização Invisível
        
        btFoto.setOnClickListener(new View.OnClickListener() {
		
			@Override
			public void onClick(View v) {
				
			File picsDir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
			File imageFile = new File(picsDir, "fotos.jpg");
			Intent i = new Intent(MediaStore.ACTION_IMAGE_CAPTURE); //identifica a aplicação nativa de câmera	
			i.putExtra(MediaStore.EXTRA_OUTPUT, Uri.fromFile(imageFile)); 
			startActivity(i); // envia a intent para a plataforma
			
			
			//	File imageFile = new File(Environment.getExternalStorageDirectory(), "fotos.jpg"); // O caminho onde será armazenada a foto		
			//	 Intent it = new Intent("android.media.action.IMAGE_CAPTURE");  
			 //    startActivityForResult(it, 0);  
			     
				
				 
				btVis.setVisibility(View.VISIBLE); // Deixando Visível o botão de visualização
				
				//AINDA VOU IMPLEMENTAR O BOTÃO VISUALIZAR

				// permisão de Salvar arquivo, no Mainifest: <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE"/>    
				
			}
		});
        
        
    }
}
