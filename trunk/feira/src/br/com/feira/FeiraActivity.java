package br.com.feira;

import android.app.Activity;
import android.app.AlertDialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.TextView;

public class FeiraActivity extends Activity {
    /** Called when the activity is first created. */
	CheckBox cbFeijao, cbArroz, cbFarinha, cbCarne, cbCoca;
	TextView tvRes;
	Button btFin;
	RadioButton rdVista, rdPrazo;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        cbFeijao = (CheckBox) findViewById(R.produto.feijao);
        cbArroz = (CheckBox) findViewById(R.produto.arroz);
        cbFarinha = (CheckBox) findViewById(R.produto.farinha);
        cbCarne = (CheckBox) findViewById(R.produto.carne);
        cbCoca = (CheckBox) findViewById(R.produto.coca);
        rdVista = (RadioButton) findViewById(R.pagamento.vista);
        rdPrazo = (RadioButton) findViewById(R.pagamento.prazo);
        tvRes = (TextView) findViewById(R.produto.resultado);
        btFin = (Button) findViewById(R.botao.finalizar);
        
        btFin.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				double preco=0;
				if(cbFeijao.isChecked()){
					preco = preco + 1.5 ;
				}
				if(cbArroz.isChecked()){
					preco = preco + 0.80 ;	
				}
				if(cbFarinha.isChecked()){
					preco = preco + 2.5;
				}
				if(cbCoca.isChecked()){
					preco = preco + 4 ;
				}
				if(cbCarne.isChecked()){
					preco = preco + 12.5 ;
				}
				
				tvRes.setText(String.valueOf(preco));
		
				AlertDialog.Builder cx = new AlertDialog.Builder(FeiraActivity.this);
				cx.setTitle("Compra Finalizada");
				cx.setNeutralButton("OK", null);
				
				if(rdVista.isChecked()){
					cx.setMessage("Seu pagamento à Vista foi efetuado com sucesso!");
				}
				else if(rdPrazo.isChecked()){
					cx.setMessage("Seu pagamento à Prazo foi efetuado com sucesso!");
				}
				else{
					cx.setMessage("Primeiro é preciso selecionar a forma de pagamento.");
				}
				cx.show();
				
			}
		});
        
    }
}