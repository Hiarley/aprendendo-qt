package br.com.calculadora2;

import android.app.Activity;
import android.os.Bundle;
import android.widget.*;
import android.view.*;

public class Calculadora2Activity extends Activity {
    /** Called when the activity is first created. */
	EditText etNum1, etNum2, etRes;
	Button btSomar, btSub, btMult, btDiv;
	Double num1, num2, res;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        etNum1 = (EditText) findViewById(R.calculo.num1);
        etNum2 = (EditText) findViewById(R.calculo.num2);
        etRes = (EditText) findViewById(R.calculo.resultado);
        btSomar = (Button) findViewById(R.botao.somar);
        btSub = (Button) findViewById(R.botao.subtrair);
        btMult = (Button) findViewById(R.botao.multiplicar);
        btDiv = (Button) findViewById(R.botao.dividir);
        
        btSomar.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				num1 = Double.parseDouble(etNum1.getText().toString());
				num2 = Double.parseDouble(etNum2.getText().toString());
				res = num1 + num2;
				etRes.setText(String.valueOf(res));
				
			}
		});
        
        btSub.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				num1 = Double.parseDouble(etNum1.getText().toString());
				num2 = Double.parseDouble(etNum2.getText().toString());
				res = num1 - num2;
				etRes.setText(String.valueOf(res));
				
			}
		});
        
        btMult.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				num1 = Double.parseDouble(etNum1.getText().toString());
				num2 = Double.parseDouble(etNum2.getText().toString());
				res = num1 * num2;
				etRes.setText(String.valueOf(res));
				
			}
		});
        
        btDiv.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				num1 = Double.parseDouble(etNum1.getText().toString());
				num2 = Double.parseDouble(etNum2.getText().toString());
				res = num1 / num2;
				etRes.setText(String.valueOf(res));
				
			}
		});
        
        
    }
}