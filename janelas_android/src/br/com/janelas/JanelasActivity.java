package br.com.janelas;

import android.app.Activity;
import android.os.Bundle;
import android.widget.*;
import android.view.*;

public class JanelasActivity extends Activity {
    /** Called when the activity is first created. */
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        MenuPrincipal();
        
        
    }
    
    
    public void MenuPrincipal(){
    	setContentView(R.layout.main);
    	Button btCadastrar = (Button) findViewById(R.botao.btCadastrar);
        Button btVisualizar = (Button) findViewById(R.botao.btVisualizar);
        
        
        btCadastrar.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				setContentView(R.layout.cadastrar); // Pode chamar a janela cadastrar diretamente
				
				// O botão Voltar tem que ser criado dentro do evento que chama o cadastro.
				
				Button btVoltar = (Button) findViewById(R.botao.btvoltar);
				
				btVoltar.setOnClickListener(new View.OnClickListener() {
					
					public void onClick(View v) {
						MenuPrincipal();
						
					}
				});
				
			}
		});
        
        btVisualizar.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				mostrarVisualizar(); // pode chamar a janela visualizar por um método
				
				
						
					}
				});
				
			}
    

    	
    
    public void mostrarVisualizar(){
    	setContentView(R.layout.visualizar);
    	Button btVoltar2 = (Button) findViewById(R.botao.btvoltar2);
    	
    	btVoltar2.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				MenuPrincipal();
				
			}
		});

    }
}