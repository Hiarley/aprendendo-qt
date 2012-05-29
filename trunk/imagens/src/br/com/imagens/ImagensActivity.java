package br.com.imagens;

import android.app.Activity;
import android.os.Bundle;
import android.widget.*;
import android.view.*;

public class ImagensActivity extends Activity {
    /** Called when the activity is first created. */
	ImageButton imgBt1, imgBt2;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Principal();
        
               
        
        
    }
    public void Principal(){
    	setContentView(R.layout.main);
    	ImageButton imgBt1 = (ImageButton) findViewById(R.id.imageButton1);
        ImageButton imgBt2 = (ImageButton) findViewById(R.id.imageButton2);
        
        imgBt1.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				chamarMusica();
				
			}
		});
        
        imgBt2.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				chamarVideo();
				
			}
		});
    	
    }
    public void chamarMusica(){
    	setContentView(R.layout.musica);
    	Button btVoltar = (Button) findViewById(R.botao.btVoltar);
    	btVoltar.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Principal();
				
			}
		});
    	
    }
    public void chamarVideo(){
    	setContentView(R.layout.video);
    	Button btVoltar2 = (Button) findViewById(R.botao.btVoltar2);
    	btVoltar2.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Principal();
				
			}
		});
    	
    }
}