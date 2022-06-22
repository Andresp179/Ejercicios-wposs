package com.example.recargacelular;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import com.example.recargacelular.Metodos.Datos;
import com.example.recargacelular.Metodos.Personal;
import com.google.android.material.textfield.TextInputLayout;

public class LoginActivity extends AppCompatActivity {
    TextInputLayout usu , contra;
    Button ini, res;
    Toolbar toolbar;
    String usuario, contraseña;
    int sesion;
    boolean valida_email, isValida_clave;
    Personal p=null;
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.app_bar_login);
        //definimos las variables
        toolbar = (Toolbar) findViewById(R.id.toolbar);
        toolbar.setTitle(getString(R.string.app_name));//-->Colocamos el titulo del toolbar "Recargas App"
        toolbar.setSubtitle(getString(R.string.inicio)); //-->Colocamos el subtitulo del toolbar "Iniciar Sesion"
        setSupportActionBar(toolbar);//Barra de herramientas para establecer como la barra de acción de la actividad.

        usu = (TextInputLayout) findViewById(R.id.usu);
        contra = (TextInputLayout) findViewById(R.id.contra);
        ini = (Button) findViewById(R.id.ingreBt);
        res = (Button) findViewById(R.id.regisBt);
        Datos met= new Datos();
        //---------------------------------------------

        ini.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(!(usuario=usu.getEditText().getText().toString()).trim().isEmpty()){
                    if (!(contraseña=contra.getEditText().getText().toString()).trim().isEmpty()) {
                        if (valida_email=met.validarCorreo(usuario=usu.getEditText().getText().toString())){
                            if(isValida_clave=met.validarClave(contraseña=contra.getEditText().getText().toString())) {
                                sesion = met.login(usuario, contraseña);
                                p = met.envio(usuario, contraseña);
                                Llamado(sesion);
                                usu.getEditText().setText("");
                                contra.getEditText().setText("");

                            }else{
                                mensaje("Por favor, Digite una clave valida");
                                contra.requestFocus();
                            }

                    }else {
                            mensaje("Por favor digite un correo valido");
                            usu.requestFocus();
                    }

                    }else{
                        mensaje("Por favor, Ingresa la contraseña");
                        contra.requestFocus();
                    }
                }else{
                    mensaje("Por favor, Ingrese el usuario");
                    usu.requestFocus();
                }

            }
        });

        res.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                registro();
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



    public void Llamado (int x){
        switch (x){
            case 0:
                Datos met= new Datos();
                if(met.existencia(usuario)){
                    mensaje("Usuario no existe");
                }
                mensaje("Usuario o contraseña incorrecta");
                break;
            case 1:
                Intent intenta = new Intent(this, MainActivity.class);
                Bundle transporte =new Bundle();
                transporte.putString("nombre_usuario",p.getNombre().toString());
                transporte.putString("apellido_usuario",p.getApellido().toString());
                transporte.putString("correo_usuario",p.getCorreo().toString());
                transporte.putDouble("monto",p.getSaldo());
                intenta.putExtras(transporte);
                startActivity(intenta);
                break;
        }

    }

    public void registro(){
        Intent intenta = new Intent(this, RegistroActivity.class);
        startActivity(intenta );
    }

    public void mensaje(String x){
        Toast.makeText( this , x,Toast.LENGTH_SHORT).show();
    }


}
