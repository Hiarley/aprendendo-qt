package s.s;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Button;

public class Stability_systemsActivity extends Activity {
	Button btJC;
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        btJC = (Button) this.findViewById(R.buttons.jc);
    }
}