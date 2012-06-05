package br.com.cadastro;

import android.app.Activity;
import android.app.AlertDialog;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;


public class CadastroActivity extends Activity {
    /** Called when the activity is first created. */
	
	SQLiteDatabase BancoDados;
	Cursor cursor;
	EditText etNome, etEmail, etTel;
	Button btCad, btVis;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        MenuPrincipal();
        
        
    }
    
    public void MenuPrincipal(){
    	
setContentView(R.layout.main);
        
        Connection();
        
        etNome = (EditText) findViewById(R.id.nome);
        etEmail = (EditText) findViewById(R.id.email);
        etTel = (EditText) findViewById(R.id.telefone);
        btCad = (Button) findViewById(R.botao.cadastrar);
        btVis = (Button) findViewById(R.botao.Visualizar);
        
        btCad.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				inserirDados();
				
				
			}
		});
        
        btVis.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				MostrarDados();
				
			}
		});
    }
    
    public void Connection(){
    	
    	try{
    		BancoDados = openOrCreateDatabase("Cadastro", MODE_WORLD_READABLE, null);
    		
    		BancoDados.execSQL("CREATE TABLE IF NOT EXISTS usuario (id INTEGER PRIMARY KEY, nome TEXT, email TEXT, telefone TEXT);");
    		
    	}
    	catch(Exception erro){
    		AlertDialog.Builder msg = new AlertDialog.Builder(CadastroActivity.this);
    		msg.setTitle("Erro");
    		msg.setMessage("Erro ao Abrir ou Criar o Banco de Dados");
    	}
    }
    
    public void inserirDados(){
    	String nome, email, tel;
    	nome = etNome.getText().toString();
    	email = etEmail.getText().toString();
    	tel = etTel.getText().toString();
    	try{
    		
        	BancoDados.execSQL("INSERT INTO usuario ( nome, email, telefone) values ( '" + nome +"' , '"+ email +"' , '"+ tel +"' ) ");
        
        	//Apagar os Campos depois de inserir
        	etNome.setText(null);
        	etEmail.setText(null);
        	etTel.setText(null);
        	
        Toast.makeText( this, "Cadastrado com sucesso", Toast.LENGTH_LONG).show();
        
    		
    	}
    	catch(Exception erro){
    		AlertDialog.Builder msg = new AlertDialog.Builder(CadastroActivity.this);
    		msg.setTitle("Erro");
    		msg.setMessage("Erro ao Cadastrar no Banco de dados");
    		
    	}
    	
    	
    }
    
    public boolean MostrarDados(){
    	try{
    		cursor = BancoDados.query("usuario", new String[]{"nome","email","telefone"}, null, null, null, null, null);
    		int numDados = cursor.getCount();
    		String dados="";
    		
    		if(numDados != 0){
    			cursor.moveToFirst();
    			int n=0;
    			while(n<numDados){
    			dados += "Nome: ";
    			dados += cursor.getString(cursor.getColumnIndex("nome"));
    			dados += "\n Email: ";
    			dados += cursor.getString(cursor.getColumnIndex("email"));
    			dados += "\n Telefone: ";
    			dados += cursor.getString(cursor.getColumnIndex("telefone"));
    			dados += "\n--------------------------\n\n";
    			
    			cursor.moveToNext();
    			n++;
    			
    			}
    			mostrarVisualizar(dados);
    			

    			
    			return true;
    		}
    		else{
    			return false;
    		}
    		
    	}
    	catch(Exception erro){
    		AlertDialog.Builder msg = new AlertDialog.Builder(CadastroActivity.this);
    		msg.setTitle("Erro");
    		msg.setMessage("Erro ao Abrir ou Criar o Banco de Dados");
    		return false;
    		
    	}
    	
    }
    
    public void mostrarVisualizar(String mostrar){
    	
    	setContentView(R.layout.visualizar);
    	
    	TextView tvDados = (TextView) findViewById(R.id.dados);
    	Button voltar = (Button) findViewById(R.botao.Voltar);
    	
    	tvDados.setText(mostrar);
    	
    	voltar.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				MenuPrincipal();
				
			}
		});

    	
    	
    }
    
}