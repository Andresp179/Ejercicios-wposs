package com.example.recargacelular;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import com.example.recargacelular.Metodos.Datos;
import com.example.recargacelular.Metodos.Personal;
import com.google.android.material.textfield.TextInputLayout;

public class RegistroActivity extends AppCompatActivity {
    TextInputLayout nom, ape, cc, email, pass;
    Button regist;
    Spinner Spgenero;
    Toolbar toolbar;
    boolean val_email, val_clave;
    Datos d=new Datos();

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.app_bar_register);
        //definimos las variables
        toolbar = (Toolbar) findViewById(R.id.toolbar);
        toolbar.setTitle(getString(R.string.app_name));//-->Colocamos el titulo del toolbar "Recargas App"
        toolbar.setSubtitle(getString(R.string.regist)); //-->Colocamos el subtitulo del toolbar "Registrar"
        setSupportActionBar(toolbar);//Barra de herramientas para establecer como la barra de acción de la actividad.

        nom = (TextInputLayout) findViewById(R.id.nom_usuario);
        ape = (TextInputLayout) findViewById(R.id.ape_usuario);
        cc = (TextInputLayout) findViewById(R.id.cc_usuario);
        email =(TextInputLayout)findViewById(R.id.email_usuario);
        pass =(TextInputLayout)findViewById(R.id.clave_usuario);
        //---------------------------------------------------------
        Spgenero = (Spinner) findViewById(R.id.SppGenero);
        ArrayAdapter<CharSequence> Adapter =ArrayAdapter.createFromResource(this,R.array.genero, android.R.layout.simple_spinner_item);
        Spgenero.setAdapter(Adapter);
        //---------------------------------------------------------
        regist = (Button) findViewById(R.id.reistro_bt);
        Datos met = new Datos();
        //---------------------------------------------

        regist.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!(nom.getEditText().getText().toString()).trim().isEmpty()){
                    if(!(ape.getEditText().getText().toString()).trim().isEmpty()){
                        if(!(cc.getEditText().getText().toString()).trim().isEmpty()){
                            if(!(Spgenero.getSelectedItem().toString()).equalsIgnoreCase("Seleccionar:")){
                                if(!(email.getEditText().getText().toString()).trim().isEmpty()){
                                    if(!(pass.getEditText().getText().toString()).trim().isEmpty()){
                                        if(val_email=d.validarCorreo(email.getEditText().getText().toString())) {
                                            if(val_clave=d.validarClave(pass.getEditText().getText().toString())) {
                                                d.guardar_objetos(new Personal((nom.getEditText().getText().toString()), (ape.getEditText().getText().toString()), (cc.getEditText().getText().toString()), (email.getEditText().getText().toString()), 100000, (pass.getEditText().getText().toString())));
                                                mensaje("Se ha registrado exitosamente");
                                                finish();
                                            }else{
                                                pass.requestFocus();
                                                mensaje("Por favor, Digite la clave valida");
                                            }
                                        }else{
                                            email.requestFocus();
                                            mensaje("Por favor, Digite el correo electronico valido");
                                        }
                                    }else{
                                        pass.requestFocus();
                                        mensaje("Por favor, Digite la clave");
                                    }
                                }else{
                                    email.requestFocus();
                                    mensaje("Por favor, Digite el correo electronico");
                                }
                            }else{
                                Spgenero.requestFocus();
                                mensaje("Por favor, Seleccione el genero");
                            }
                        }else{
                            cc.requestFocus();
                            mensaje("Por favor, Digite el numero de cedula");
                        }
                    }else{
                        ape.requestFocus();
                        mensaje("Por favor, Digite el apellido");
                    }
                }else{
                    nom.requestFocus();
                    mensaje("Por favor, Digite el nombre");
                }
            }
        });
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

    public void mensaje (String X){
        Toast.makeText( this, X,Toast.LENGTH_SHORT).show();
    }
}
