package br.com.calculadora;

import android.app.Activity;
import android.os.Bundle;
import android.widget.*;
import android.view.*;

public class CalculadoraActivity extends Activity {
    /** Called when the activity is first created. */
	EditText etNum1, etNum2, etRes;
	Button btSomar;
	double num1, num2, res;
	
    @Override
    
  public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        etNum1 = (EditText) findViewById(R.calculo.num1);
        etNum2 = (EditText) findViewById(R.calculo.num2);
        etRes = (EditText) findViewById(R.calculo.resultado);
        btSomar = (Button) findViewById(R.botao.somar);
        
        btSomar.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				num1 = Double.parseDouble(etNum1.getText().toString());
				num2 = Double.parseDouble(etNum2.getText().toString());
				res = num1 + num2;
				etRes.setText(String.valueOf(res));
				
			}
		});
        
    }
}