package br.com.galeria;

import android.app.Activity;
import android.content.Context;
import android.content.res.TypedArray;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.BaseAdapter;
import android.widget.Gallery;
import android.widget.ImageView;
import android.widget.Toast;

public class GaleriaActivity extends Activity {
    /** Called when the activity is first created. */
   Integer[] imageIDs = {
	R.drawable.pic1,
	R.drawable.pic2,
	R.drawable.pic3,
	R.drawable.pic4,
	R.drawable.pic5,
	R.drawable.pic6,
	R.drawable.pic7
		   
   };
	
	@Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        Gallery galeria = (Gallery) findViewById(R.id.gallery);
        
        galeria.setAdapter(new ImageAdapter(this));
        galeria.setOnItemClickListener(new OnItemClickListener() {
		
        	public void onItemClick(AdapterView<?> parent, View v, int position, long id){
        		Toast.makeText(getBaseContext(), "Pic" + (position + 1) + " selected", Toast.LENGTH_SHORT).show();
        		
        		//Mostrar as imagens selecionadas
        		ImageView imageView = (ImageView) findViewById(R.id.image1);
        		imageView.setImageResource(imageIDs[position]);
        		
        	}
        });
        
    }
	
	public class ImageAdapter extends BaseAdapter{
		
		private Context context;
		private int itemBackground;
		
		public ImageAdapter(Context c){
			
			context = c;
			//Configurando o Estilo
			TypedArray a = obtainStyledAttributes(R.styleable.Gallery);
			itemBackground = a.getResourceId(R.styleable.Gallery_android_galleryItemBackground, 0);
			a.recycle();
		}
		
		//Retorna o número da página
		public int getCount(){
			return imageIDs.length;
			
		}
		
		//Retorna o ID de um Item
		public Object getItem(int position){
			return position;
			
		}
		//Retorna o ID de um Item
		public long getItemId(int position){
			return position;
			
		}
		
		// Retorna um ImageView
		public View getView(int position, View convertView, ViewGroup parent){
			ImageView imageView = new ImageView(context);
			imageView.setImageResource(imageIDs[position]);
			imageView.setScaleType(ImageView.ScaleType.FIT_XY);
			imageView.setLayoutParams(new Gallery.LayoutParams(150, 120));
			imageView.setBackgroundResource(itemBackground);
			return imageView;
		}
	}
}