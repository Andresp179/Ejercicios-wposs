package com.example.bitmap_mejorado.Fragments;

import static com.example.bitmap_mejorado.Metodos.Datos.mostrar;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.example.bitmap_mejorado.Adapter.Adapter;
import com.example.bitmap_mejorado.Metodos.Datos;
import com.example.bitmap_mejorado.Metodos.Elements;
import com.example.bitmap_mejorado.R;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link Fragment_elemento_de_datos_definido_por_iso#newInstance} factory method to
 * create an instance of this fragment.
 */
public class Fragment_elemento_de_datos_definido_por_iso extends Fragment implements Adapter.RecyclerItemClick{

    public static RecyclerView recyclerView;
    public static Adapter adapter;
    Datos d=new Datos();

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public Fragment_elemento_de_datos_definido_por_iso() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Fragment_elemento_de_datos_definido_por_iso.
     */
    // TODO: Rename and change types and number of parameters
    public static Fragment_elemento_de_datos_definido_por_iso newInstance(String param1, String param2) {
        Fragment_elemento_de_datos_definido_por_iso fragment = new Fragment_elemento_de_datos_definido_por_iso();
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
        // Inflate the layout for this fragment
        View v= inflater.inflate(R.layout.fragment_elemento_de_datos_definido_por_iso, container, false);
        recyclerView = v.findViewById(R.id.rvLista);
        llevar_datos();
        mostrarDatos();
        return v;
    }

    @Override
    public void OnClick(Elements item) {

    }
    public void mostrarDatos(){
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));
        adapter = new Adapter(mostrar, this);
        recyclerView.setAdapter(adapter);
    }

    public void llevar_datos(){
        mostrar.add(new Elements("Bit 001","b 64","Mapa de bits extendido") );
        mostrar.add(new Elements("Bit 002","n. 19","Número de cuenta principal (PAN)") );
        mostrar.add(new Elements("Bit 003","n 6","Código de procesamiento") );
        mostrar.add(new Elements("Bit 004","n 12","Monto, transacción") );
        mostrar.add(new Elements("Bit 005","n 12","Monto, Liquidación") );
        mostrar.add(new Elements("Bit 006","n 12","Monto, facturación al titular de la tarjeta") );
        mostrar.add(new Elements("Bit 007","n 10","Fecha y hora de transmisión") );
        mostrar.add(new Elements("Bit 008","n 8","Monto, tarifa de facturación del titular de la tarjeta") );
        mostrar.add(new Elements("Bit 009","n 8","Tasa de conversión, liquidación") );
        mostrar.add(new Elements("Bit 010","n 8","Tasa de conversión, facturación al titular de la tarjeta") );
        mostrar.add(new Elements("Bit 011","n 6","Número de auditoría de seguimiento de sistemas") );
        mostrar.add(new Elements("Bit 012","n 6","Hora, transacción local") );
        mostrar.add(new Elements("Bit 013","n 4","Fecha, transacción local (MMdd)") );
        mostrar.add(new Elements("Bit 014","n 4","Fecha, vencimiento") );
        mostrar.add(new Elements("Bit 015","n 4","Fecha, Liquidación") );
        mostrar.add(new Elements("Bit 016","n 4","Fecha, conversión") );
        mostrar.add(new Elements("Bit 017","n 4","Fecha, captura") );
        mostrar.add(new Elements("Bit 018","n 4","Tipo de comerciante") );
        mostrar.add(new Elements("Bit 019","n 3","Código de país de la institución adquirente") );
        mostrar.add(new Elements("Bit 020","n 3","PAN extendido, código de país") );
        mostrar.add(new Elements("Bit 021","n 3","Institución expedidora. código de país") );
        mostrar.add(new Elements("Bit 022","n 3","Modo de entrada de punto de servicio") );
        mostrar.add(new Elements("Bit 023","n 3","Número de PAN de la aplicación") );
        mostrar.add(new Elements("Bit 024","n 3","Código de función (ISO 8583: 1993) / Identificador internacional de red (?)") );
        mostrar.add(new Elements("Bit 025","n 2","Código de condición del punto de servicio") );
        mostrar.add(new Elements("Bit 026","n 2","Código de captura de punto de servicio") );
        mostrar.add(new Elements("Bit 027","n 1","Autorización de la longitud de la respuesta de identificación") );
        mostrar.add(new Elements("Bit 028","n 8","Monto, tarifa de transacción") );
        mostrar.add(new Elements("Bit 029","n 8","Monto. tarifa de liquidación") );
        mostrar.add(new Elements("Bit 030","n 8","Monto, tarifa de procesamiento de la transacción") );
        mostrar.add(new Elements("Bit 031","n 8","Monto, tarifa de procesamiento de liquidación") );
        mostrar.add(new Elements("Bit 032","n 11","Adquirir el código de identificación de la institución") );
        mostrar.add(new Elements("Bit 033","n 11","Código de identificación de la institución remitente") );
        mostrar.add(new Elements("Bit 034","n 28","Número de cuenta principal, extendido") );
        mostrar.add(new Elements("Bit 035","z 37","Datos de la pista 2") );
        mostrar.add(new Elements("Bit 036","z 104","Datos de la pista 3") );
        mostrar.add(new Elements("Bit 037","an 12","Número de referencia de recuperación") );
        mostrar.add(new Elements("Bit 038","an 6","Respuesta de identificación de autorización") );
        mostrar.add(new Elements("Bit 039","an 2","Código de respuesta") );
        mostrar.add(new Elements("Bit 040","an 3","Código de restricción de servicio") );
        mostrar.add(new Elements("Bit 041","ans 8","Identificación del terminal del aceptador de tarjetas") );
        mostrar.add(new Elements("Bit 042","ans 15","Código de identificación del aceptador de tarjetas") );
        mostrar.add(new Elements("Bit 043","ans 40","Nombre / ubicación del aceptador de la tarjeta") );
        mostrar.add(new Elements("Bit 044","an ..25","Datos de respuesta adicionales") );
        mostrar.add(new Elements("Bit 045","an ..76","Datos de la pista 1") );
        mostrar.add(new Elements("Bit 046","an ..999","Datos adicionales - ISO") );
        mostrar.add(new Elements("Bit 047","an ..999","Datos adicionales - Nacional") );
        mostrar.add(new Elements("Bit 048","an ..999","Datos adicionales - Privado") );
        mostrar.add(new Elements("Bit 049","a 3","Código de moneda, transacción") );
        mostrar.add(new Elements("Bit 050","an 3","Código de moneda, liquidación") );
        mostrar.add(new Elements("Bit 051","a 3","Código de moneda, facturación del titular de la tarjeta") );
        mostrar.add(new Elements("Bit 052","b 16","Datos del número de identificación personal") );
        mostrar.add(new Elements("Bit 053","n 18","Información de control relacionada con la seguridad") );
        mostrar.add(new Elements("Bit 054","an ..120","Cantidades adicionales") );
        mostrar.add(new Elements("Bit 055","ans ..999","ISO reservado") );
        mostrar.add(new Elements("Bit 056","ans ..999","ISO reservado") );
        mostrar.add(new Elements("Bit 057","ans ..999","Nacional Reservado") );
        mostrar.add(new Elements("Bit 058","ans ..999","Nacional Reservado") );
        mostrar.add(new Elements("Bit 059","ans ..999","Reservado para uso nacional") );
        mostrar.add(new Elements("Bit 060","an ..7","Aviso / código de motivo (privado reservado)") );
        mostrar.add(new Elements("Bit 061","ans ..999","Reservado Privado") );
        mostrar.add(new Elements("Bit 062","ans ..999","Reservado Privado") );
        mostrar.add(new Elements("Bit 063","ans ..999","Reservado Privado") );
        mostrar.add(new Elements("Bit 064","b 16","Código de autenticación de mensajes (MAC)") );

        //--------------------------------------------------------------------------------------------------
        mostrar.add(new Elements("Bit 065","b 16","Mapa de bits, terciario") );
        mostrar.add(new Elements("Bit 066","n 1","Código de liquidación") );
        mostrar.add(new Elements("Bit 067","n 2","Código de pago extendido") );
        mostrar.add(new Elements("Bit 068","n 3","Código de país de la institución receptora") );
        mostrar.add(new Elements("Bit 069","n 3","Código de condado de la institución del asentamiento") );
        mostrar.add(new Elements("Bit 070","n 3","Código de información de gestión de red") );
        mostrar.add(new Elements("Bit 071","n 4","Número de mensaje ") );
        mostrar.add(new Elements("Bit 072","ans ..999","Registro de datos (ISO 8583: 1993)") );
        mostrar.add(new Elements("Bit 073","n 6","Fecha, Acción") );
        mostrar.add(new Elements("Bit 074","n 10","Créditos, número") );
        mostrar.add(new Elements("Bit 075","n 10","Créditos, número de reversión") );
        mostrar.add(new Elements("Bit 076","n 10","Débitos, número") );
        mostrar.add(new Elements("Bit 077","n 10","Débitos, número de reversión") );
        mostrar.add(new Elements("Bit 078","n 10","Número de transferencia") );
        mostrar.add(new Elements("Bit 079","n 10","Transferencia, número de reversión") );
        mostrar.add(new Elements("Bit 080","n 10","Número de consultas") );
        mostrar.add(new Elements("Bit 081","n 10","Autorizaciones, número") );
        mostrar.add(new Elements("Bit 082","n 12","Créditos, monto de la tarifa de procesamiento") );
        mostrar.add(new Elements("Bit 083","n 12","Créditos, monto de la tarifa de transacción") );
        mostrar.add(new Elements("Bit 084","n 12","Débitos, monto de la tarifa de procesamiento") );
        mostrar.add(new Elements("Bit 085","n 12","Débitos, monto de la tarifa de transacción") );
        mostrar.add(new Elements("Bit 086","n 15","Créditos, cantidad") );
        mostrar.add(new Elements("Bit 087","n 15","Créditos, monto de reversión") );
        mostrar.add(new Elements("Bit 088","n 15","Débitos, monto") );
        mostrar.add(new Elements("Bit 089","n 15","Débitos, monto de reversión") );
        mostrar.add(new Elements("Bit 090","n 42","Elementos de datos originales") );
        mostrar.add(new Elements("Bit 091","an 1","Código de actualización de archivo") );
        mostrar.add(new Elements("Bit 092","n 2","Código de seguridad de archivo") );
        mostrar.add(new Elements("Bit 093","n 5","Indicador de respuesta") );
        mostrar.add(new Elements("Bit 094","an 7","Indicador de servicio") );
        mostrar.add(new Elements("Bit 095","an 42","Cantidades de reemplazo") );
        mostrar.add(new Elements("Bit 096","an 8","Código de seguridad del mensaje") );
        mostrar.add(new Elements("Bit 097","n 16","Importe, liquidación neta") );
        mostrar.add(new Elements("Bit 098","ans 25","Tenedor") );
        mostrar.add(new Elements("Bit 099","n ..11","Código de identificación de la institución de liquidación") );
        mostrar.add(new Elements("Bit 100","n ..11","Código de identificación de la institución receptora") );
        mostrar.add(new Elements("Bit 101","ans 17","Nombre del archivo") );
        mostrar.add(new Elements("Bit 102","ans ..28","Identificación de cuenta 1") );
        mostrar.add(new Elements("Bit 103","ans ..28","Identificación de cuenta 2") );
        mostrar.add(new Elements("Bit 104","ans ..100","Descripción de la transacción") );
        mostrar.add(new Elements("Bit 105","ans ..999","Reservado para uso ISO") );
        mostrar.add(new Elements("Bit 106","ans ..999","Reservado para uso ISO") );
        mostrar.add(new Elements("Bit 107","ans ..999","Reservado para uso ISO") );
        mostrar.add(new Elements("Bit 108","ans ..999","Reservado para uso ISO") );
        mostrar.add(new Elements("Bit 109","ans ..999","Reservado para uso ISO") );
        mostrar.add(new Elements("Bit 110","ans ..999","Reservado para uso ISO") );
        mostrar.add(new Elements("Bit 111","ans ..999","Reservado para uso ISO") );
        mostrar.add(new Elements("Bit 112","ans ..999","Reservado para uso nacional") );
        mostrar.add(new Elements("Bit 113","n ..11","Código de identificación de la institución del agente autorizador") );
        mostrar.add(new Elements("Bit 114","ans ..999","Reservado para uso nacional") );
        mostrar.add(new Elements("Bit 115","ans ..999","Reservado para uso nacional") );
        mostrar.add(new Elements("Bit 116","ans ..999","Reservado para uso nacional") );
        mostrar.add(new Elements("Bit 117","ans ..999","Reservado para uso nacional") );
        mostrar.add(new Elements("Bit 118","ans ..999","Reservado para uso nacional") );
        mostrar.add(new Elements("Bit 119","ans ..999","Reservado para uso nacional") );
        mostrar.add(new Elements("Bit 120","ans ..999","Reservado para uso privado") );
        mostrar.add(new Elements("Bit 121","ans ..999","Reservado para uso privado") );
        mostrar.add(new Elements("Bit 122","ans ..999","Reservado para uso privado") );
        mostrar.add(new Elements("Bit 123","ans ..999","Reservado para uso privado") );
        mostrar.add(new Elements("Bit 124","ans ..255","Texto de información") );
        mostrar.add(new Elements("Bit 125","ans ..50","Información de gestión de red") );
        mostrar.add(new Elements("Bit 126","ans ..6","ID de seguimiento del emisor") );
        mostrar.add(new Elements("Bit 127","ans ..999","Reservado para uso privado") );
        mostrar.add(new Elements("Bit 128","b 16","Código de autenticación de mensajes") );

    }
}