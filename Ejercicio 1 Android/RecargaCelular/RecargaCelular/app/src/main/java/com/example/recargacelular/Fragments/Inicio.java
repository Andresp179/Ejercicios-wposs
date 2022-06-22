package com.example.recargacelular.Fragments;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.recargacelular.Adapter.Adapter;
import com.example.recargacelular.Metodos.Datos;
import com.example.recargacelular.Metodos.Historial;
import com.example.recargacelular.Metodos.Personal;
import com.example.recargacelular.R;

import java.time.Period;
import java.util.ArrayList;

import static com.example.recargacelular.MainActivity.ape_usuario;
import static com.example.recargacelular.MainActivity.email_usuario;
import static com.example.recargacelular.MainActivity.monto_usuario;
import static com.example.recargacelular.MainActivity.nom_usuario;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link Inicio#newInstance} factory method to
 * create an instance of this fragment.
 */

public class Inicio extends Fragment implements Adapter.RecyclerItemClick{
    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    public static RecyclerView recyclerView;
    public static Adapter adapter;
    public static Datos d=new Datos();
    TextView nom;
    public static TextView mon;
    public static Personal p;

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public Inicio() {
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
    public static Inicio newInstance(String param1, String param2) {
        Inicio fragment = new Inicio();
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
    public void mostrarDatos(){
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));
        adapter = new Adapter(d.recargas_realizaa, this, email_usuario);
        recyclerView.setAdapter(adapter);
    }

    public static void mostrarDatoss(){
        recyclerView.setLayoutManager(new LinearLayoutManager(recyclerView.getContext()));
        adapter = new Adapter(d.recargas_realizaa, item -> recyclerView.getContext(),email_usuario);
        recyclerView.setAdapter(adapter);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_inicio, container, false);
        nom = v.findViewById(R.id.tvNombre);
        mon= v.findViewById(R.id.tvMont);
        nom.setText("Nombre Del Usuario: "+nom_usuario+" "+ape_usuario);
        mon.setText(String.valueOf("Saldo: "+monto_usuario));
        p=null;
        p=d.Validador(email_usuario);
        recyclerView = v.findViewById(R.id.rvLista);
        mostrarDatos();

        return v;
    }

    @Override
    public void OnClick(Historial item) {

    }
}
