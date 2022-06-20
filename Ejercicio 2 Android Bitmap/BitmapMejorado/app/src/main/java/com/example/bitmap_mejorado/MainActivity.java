package com.example.bitmap_mejorado;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.viewpager.widget.ViewPager;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

import com.example.bitmap_mejorado.body_main.SectionsPagerAdapter;
import com.google.android.material.tabs.TabLayout;

public class MainActivity extends AppCompatActivity {

    Toolbar toolbar;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //-----------------------------------------------------------------
        //definimos las variables
        toolbar = (Toolbar) findViewById(R.id.toolbar);
        toolbar.setTitle(getString(R.string.app_name));//-->Colocamos el titulo del toolbar "Bitmap App"
        toolbar.setSubtitle(getString(R.string.portal)); //-->Colocamos el subtitulo del toolbar "Mapa de bits ISO 8583"
        setSupportActionBar(toolbar);//Barra de herramientas para establecer como la barra de acción de la actividad.

        SectionsPagerAdapter sectionsPagerAdapter = new SectionsPagerAdapter(this, getSupportFragmentManager());
        ViewPager viewPager = findViewById(R.id.view_pager);
        viewPager.setAdapter(sectionsPagerAdapter);
        TabLayout tabs = findViewById(R.id.tabs);
        tabs.setupWithViewPager(viewPager);
    }
    // metodo que carga el menu a mostrar que se encuentra en la ruta> res>menu> main.xml
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflar el menú; esto agrega elementos a la barra de acción si está presente
        getMenuInflater().inflate(R.menu.main_principal, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Manejar los clics del elemento de la barra de acción aquí.
        // La barra de acción manejará automáticamente los clics en el botón Inicio / Arriba,
        // siempre que especifique una actividad principal en AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_exit) {

            finishAffinity(); //finaliza la actividad o cierra la app
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}