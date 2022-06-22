package com.example.recargacelular.Fragments;

import android.app.Dialog;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import androidx.fragment.app.Fragment;

import com.example.recargacelular.Metodos.Datos;
import com.example.recargacelular.Metodos.Historial;
import com.example.recargacelular.Metodos.Personal;
import com.example.recargacelular.R;
import com.google.android.material.textfield.TextInputLayout;

import static com.example.recargacelular.Fragments.Inicio.mon;
import static com.example.recargacelular.MainActivity.email_usuario;
import static com.example.recargacelular.MainActivity.monto_usuario;
import static com.example.recargacelular.MainActivity.nom_usuario;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link Recarga#newInstance} factory method to
 * create an instance of this fragment.
 */
public class Recarga extends Fragment {
    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    TextInputLayout num_telefono, monto_recarga;
    EditText confi_numero, confi_monto, confi_operador;
    Spinner Spoperador;
    Button btn_recarga, confi_confirma, confi_cancela;
    Datos d=new Datos();
    Personal p;

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public Recarga() {
        // Required empty public constructor
    }
    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Info_general_Fragment.
     */
    // TODO: Rename and change types and number of parameters
    public static Recarga newInstance(String param1, String param2) {
        Recarga fragment = new Recarga();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            mParam1 = getArguments().getString(ARG_PARAM1);
            mParam2 = getArguments().getString(ARG_PARAM2);
        }
    }
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_recargar, container, false);
        num_telefono = v.findViewById(R.id.numero);
        monto_recarga = v.findViewById(R.id.monto);
        Spoperador = v.findViewById(R.id.SppOperador);
        btn_recarga = v.findViewById(R.id.recarga_bt);
        //----------------------------------------------------------------------------------
        p=null;
        p=d.Validador(email_usuario);
        //----------------------------------------------------------------------------------
        ArrayAdapter<CharSequence> Adapter =ArrayAdapter.createFromResource(getContext(),R.array.operador, android.R.layout.simple_spinner_item);
        Spoperador.setAdapter(Adapter);
        //----------------------------------------------------------------------------------
        btn_recarga.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(!(num_telefono.getEditText().getText().toString()).trim().isEmpty()){
                    if(!(monto_recarga.getEditText().getText().toString()).trim().isEmpty()){
                        if(!(Spoperador.getSelectedItem().toString()).equalsIgnoreCase("Seleccione:")) {
                            if (Double.valueOf(monto_recarga.getEditText().getText().toString())<=p.getSaldo()) {
                                if (Integer.parseInt(monto_recarga.getEditText().getText().toString())>=1000) {
                                    if ((num_telefono.getEditText().getText().toString()).length()==10){
                                        final Dialog dialog = new Dialog(getActivity());
                                    dialog.setContentView(R.layout.popup_confirmacion);
                                    confi_numero = dialog.findViewById(R.id.confirm_numero);
                                    confi_operador = dialog.findViewById(R.id.confirm_operador);
                                    confi_monto = dialog.findViewById(R.id.confirm_monto);
                                    confi_confirma = dialog.findViewById(R.id.btnconfirmacion);
                                    confi_cancela = dialog.findViewById(R.id.btncancelar);
                                    //------------------------------------------------------
                                    confi_numero.setEnabled(false);
                                    confi_operador.setEnabled(false);
                                    confi_monto.setEnabled(false);
                                    //------------------------------------------------------
                                    confi_numero.setText(num_telefono.getEditText().getText().toString());
                                    confi_operador.setText(Spoperador.getSelectedItem().toString());
                                    confi_monto.setText(monto_recarga.getEditText().getText().toString());
                                    //-------------------------------------------------------
                                    confi_confirma.setOnClickListener(new View.OnClickListener() {
                                        @Override
                                        public void onClick(View v) {
                                            d.guardar_objetos(new Historial((num_telefono.getEditText().getText().toString()), (Spoperador.getSelectedItem().toString()), (monto_recarga.getEditText().getText().toString()), nom_usuario, email_usuario));
                                            mensaje("La recarga se realizó exitosamente");
                                            p.setSaldo(p.getSaldo()-Double.valueOf(monto_recarga.getEditText().getText().toString()));
                                            mon.setText(String.valueOf("Saldo: " + p.getSaldo()));
                                            Inicio.mostrarDatoss();
                                            dialog.dismiss();
                                        }
                                    });
                                    //---------------------------------------------------------
                                    confi_cancela.setOnClickListener(new View.OnClickListener() {
                                        @Override
                                        public void onClick(View v) {

                                            dialog.dismiss();
                                            mensaje("Se ha cancelado la recarga");
                                        }
                                    });
                                    //---------------------------------------------------------
                                    dialog.show();
                                }else {
                                    num_telefono.requestFocus();
                                    mensaje("Ojo recuerda que el numero telefonico debe ser de 10 caracteres");
                                }
                            }else {
                                    monto_recarga.requestFocus();
                                    mensaje("Ojo la recarga minimo es de $1000.");
                            }
                        }else {
                                monto_recarga.requestFocus();
                            mensaje("Ojo solo puedes recargar lo que tiene de saldo");
                        }
                        }else{
                            Spoperador.requestFocus();
                            mensaje("Por favor, Seleccione el tipo de operador");
                        }
                    }else{
                        monto_recarga.requestFocus();
                        mensaje("Por favor, Digite el monto de la recarga");
                    }
                }else{
                    num_telefono.requestFocus();
                    mensaje("Por favor, Digite el numero telefonico");
                }

            }

        });

        return v;
    }
    public void mensaje(String x){
        Toast.makeText(getContext(), x,Toast.LENGTH_SHORT).show();
    }
}
