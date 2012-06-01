package br.com.menus;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MenusActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        
        
    }
    
    //Métodos chamados quando clicado em Menu
    
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	super.onCreateOptionsMenu(menu);
    	CreateMenu(menu);
    	return true;
    	
    }
    
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
    	
    	return MenuChoice(item);
    }
    
    private void CreateMenu (Menu menu){
    	
    	
    	MenuItem mnu1 = menu.add(0, 0, 0, "Abrir");
    	{
    		mnu1.setAlphabeticShortcut('a');
    		
    	}
    	MenuItem mnu2 = menu.add(0, 1, 1, "Salvar");
    	{
    		mnu2.setAlphabeticShortcut('s');
    		
    	}
    	MenuItem mnu3 = menu.add(0, 2, 2, "Salvar como");
    	{
    		mnu3.setAlphabeticShortcut('b');
    		
    	}
    	MenuItem mnu4 = menu.add(0, 3, 3, "Editar");
    	{
    		mnu4.setAlphabeticShortcut('e');
    	}
    	
    	menu.add(0, 4, 4, "Importar");
    	menu.add(0, 5, 5, "Propriedades");
    	menu.add(0, 6, 6, "Sair");
    	
    }
    
    private boolean MenuChoice (MenuItem item){
    	switch(item.getItemId()){
    	
    	case 0:
    		Toast.makeText(this, "Selecionou ABRIR", Toast.LENGTH_LONG).show();
    		return true;
    		
    	case 1:
    		Toast.makeText(this, "Selecionou SALVAR", Toast.LENGTH_LONG).show();
    		return true;
    		
    	case 2:
    		Toast.makeText(this, "Selecionou SALVAR COMO", Toast.LENGTH_LONG).show();
    		return true;
    		
    	case 3:
    		Toast.makeText(this, "Selecionou EDITAR", Toast.LENGTH_LONG).show();
    		return true;
    		
    	case 4:
    		Toast.makeText(this, "Selecionou IMPORTAR", Toast.LENGTH_LONG).show();
    		return true;
    		
    	case 5:
    		Toast.makeText(this, "Selecionou PROPRIEDADES", Toast.LENGTH_LONG).show();
    		return true;
    		
    	case 6:
    		Toast.makeText(this, "Selecionou SAIR", Toast.LENGTH_LONG).show();
    		return true;
    	}
    	return false;
    	
    	
    }
    
}