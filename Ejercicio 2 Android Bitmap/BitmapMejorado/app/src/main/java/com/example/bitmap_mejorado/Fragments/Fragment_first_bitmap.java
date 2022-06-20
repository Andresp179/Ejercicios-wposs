package com.example.bitmap_mejorado.Fragments;

import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;

import com.example.bitmap_mejorado.R;

import java.util.ArrayList;
import java.util.List;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link Fragment_first_bitmap#newInstance} factory method to
 * create an instance of this fragment.
 */
public class Fragment_first_bitmap extends Fragment {

    CheckBox c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16,
            c17,c18,c19,c20,c21,c22,c23,c24,c25,c26,c27,c28,c29,c30,c31,c32,
            c33,c34,c35,c36,c37,c38,c39,c40,c41,c42,c43,c44,c45,c46,c47,c48,
            c49,c50,c51,c52,c53,c54,c55,c56,c57,c58,c59,c60,c61,c62,c63,c64;
    Button mostarar;
    EditText et_hexadeciaml;
    char dato[]=new char[16];
    boolean bit[]=new boolean[64];
    int txt[]=new int[16];
    int o;
    public static List<CheckBox> lista = new ArrayList<>();

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public Fragment_first_bitmap() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Fragment_first_bitmap.
     */
    // TODO: Rename and change types and number of parameters
    public static Fragment_first_bitmap newInstance(String param1, String param2) {
        Fragment_first_bitmap fragment = new Fragment_first_bitmap();
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
        View v= inflater.inflate(R.layout.fragment_first_bitmap, container, false);
        //------------------------------------------------------------------------------------------
        mostarar=v.findViewById(R.id.button);
        et_hexadeciaml=v.findViewById(R.id.editTextHexadeciaml);
        c1=(CheckBox) v.findViewById(R.id.B1);
        c2=(CheckBox) v.findViewById(R.id.B2);
        c3=(CheckBox) v.findViewById(R.id.B3);
        c4=(CheckBox) v.findViewById(R.id.B4);
        c5=(CheckBox) v.findViewById(R.id.B5);
        c6=(CheckBox) v.findViewById(R.id.B6);
        c7=(CheckBox) v.findViewById(R.id.B7);
        c8=(CheckBox) v.findViewById(R.id.B8);
        c9=(CheckBox) v.findViewById(R.id.B9);
        c10=(CheckBox) v.findViewById(R.id.B10);
        c11=(CheckBox) v.findViewById(R.id.B11);
        c12=(CheckBox) v.findViewById(R.id.B12);
        c13=(CheckBox) v.findViewById(R.id.B13);
        c14=(CheckBox) v.findViewById(R.id.B14);
        c15=(CheckBox) v.findViewById(R.id.B15);
        c16=(CheckBox) v.findViewById(R.id.B16);
        c17=(CheckBox) v.findViewById(R.id.B17);
        c18=(CheckBox) v.findViewById(R.id.B18);
        c19=(CheckBox) v.findViewById(R.id.B19);
        c20=(CheckBox) v.findViewById(R.id.B20);
        c21=(CheckBox) v.findViewById(R.id.B21);
        c22=(CheckBox) v.findViewById(R.id.B22);
        c23=(CheckBox) v.findViewById(R.id.B23);
        c24=(CheckBox) v.findViewById(R.id.B24);
        c25=(CheckBox) v.findViewById(R.id.B25);
        c26=(CheckBox) v.findViewById(R.id.B26);
        c27=(CheckBox) v.findViewById(R.id.B27);
        c28=(CheckBox) v.findViewById(R.id.B28);
        c29=(CheckBox) v.findViewById(R.id.B29);
        c30=(CheckBox) v.findViewById(R.id.B30);
        c31=(CheckBox) v.findViewById(R.id.B31);
        c32=(CheckBox) v.findViewById(R.id.B32);
        c33=(CheckBox) v.findViewById(R.id.B33);
        c34=(CheckBox) v.findViewById(R.id.B34);
        c35=(CheckBox) v.findViewById(R.id.B35);
        c36=(CheckBox) v.findViewById(R.id.B36);
        c37=(CheckBox) v.findViewById(R.id.B37);
        c38=(CheckBox) v.findViewById(R.id.B38);
        c39=(CheckBox) v.findViewById(R.id.B39);
        c40=(CheckBox) v.findViewById(R.id.B40);
        c41=(CheckBox) v.findViewById(R.id.B41);
        c42=(CheckBox) v.findViewById(R.id.B42);
        c43=(CheckBox) v.findViewById(R.id.B43);
        c44=(CheckBox) v.findViewById(R.id.B44);
        c45=(CheckBox) v.findViewById(R.id.B45);
        c46=(CheckBox) v.findViewById(R.id.B46);
        c47=(CheckBox) v.findViewById(R.id.B47);
        c48=(CheckBox) v.findViewById(R.id.B48);
        c49=(CheckBox) v.findViewById(R.id.B49);
        c50=(CheckBox) v.findViewById(R.id.B50);
        c51=(CheckBox) v.findViewById(R.id.B51);
        c52=(CheckBox) v.findViewById(R.id.B52);
        c53=(CheckBox) v.findViewById(R.id.B53);
        c54=(CheckBox) v.findViewById(R.id.B54);
        c55=(CheckBox) v.findViewById(R.id.B55);
        c56=(CheckBox) v.findViewById(R.id.B56);
        c57=(CheckBox) v.findViewById(R.id.B57);
        c58=(CheckBox) v.findViewById(R.id.B58);
        c59=(CheckBox) v.findViewById(R.id.B59);
        c60=(CheckBox) v.findViewById(R.id.B60);
        c61=(CheckBox) v.findViewById(R.id.B61);
        c62=(CheckBox) v.findViewById(R.id.B62);
        c63=(CheckBox) v.findViewById(R.id.B63);
        c64=(CheckBox) v.findViewById(R.id.B64);
        set_ArrayList();
        //------------------------------------------------------------------------------------------
        mostarar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(validar_Bit(et_hexadeciaml.getText().toString())==true){
                    set_datos();


                    int caso=1,P=0;
                    for(int i2=0; i2 < 64; i2++){
                        if(caso==5){
                            caso=1;
                            P++;
                        }
                        switch(caso){
                            case 1:{
                                if((dato[P]=='8')||dato[P]=='9'||dato[P]=='A'||dato[P]=='B'||dato[P]=='C'||dato[P]=='D'||dato[P]=='E'||dato[P]=='F'||dato[P]=='a'||dato[P]=='b'||dato[P]=='c'||dato[P]=='d'||dato[P]=='e'||dato[P]=='f'){
                                    bit[i2]=true;
                                }else{
                                    bit[i2]=false;
                                }
                                caso++;
                                break;
                            }
                            case 2:{
                                if(dato[P]=='4'||dato[P]=='5'||dato[P]=='6'||dato[P]=='7'||dato[P]=='C'||dato[P]=='D'||dato[P]=='E'||dato[P]=='F'||dato[P]=='c'||dato[P]=='d'||dato[P]=='e'||dato[P]=='f'){
                                    bit[i2]=true;
                                }
                                else{
                                    bit[i2]=false;
                                }
                                caso++;
                                break;
                            }
                            case 3:{
                                if(dato[P]=='2'||dato[P]=='3'||dato[P]=='6'||dato[P]=='7'||dato[P]=='A'||dato[P]=='B'||dato[P]=='E'||dato[P]=='F'||dato[P]=='a'||dato[P]=='b'||dato[P]=='e'||dato[P]=='f'){
                                    bit[i2]=true;
                                }else{
                                    bit[i2]=false;
                                }
                                caso++;
                                break;
                            }
                            case 4:{
                                if(dato[P]=='1'||dato[P]=='3'||dato[P]=='5'||dato[P]=='7'||dato[P]=='9'||dato[P]=='B'||dato[P]=='D'||dato[P]=='F'||dato[P]=='b'||dato[P]=='d'||dato[P]=='f'){
                                    bit[i2]=true;
                                }else{
                                    bit[i2]=false;
                                }
                                caso++;
                                break;
                            }
                        }
                    }

                }
                moslista();
            }
        });
        //------------------------------------------------------------------------------------------
        for ( o=0;o<64;o++) {
            int finalO = 0;

            lista.get(o).setOnClickListener(new View.OnClickListener() {
                //c1.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    // Toast.makeText(MainActivity.this, "un click.-- ",Toast.LENGTH_SHORT).show();
                    //mostrar();
                    mostrarChecks();
                }

            });
        }
        //---------------------------------------------------------------------------------------------
        return v;
    }
        private boolean validar_Bit(String txt){
            if( txt.length()<=16){
                return true;
            }
            Toast.makeText(getContext(), "Ingresa solo entre [ 0 – 16 ] caracteres hexadecimales.",Toast.LENGTH_SHORT).show();
            return false;
        }
        private void set_datos(){
            String TEX=et_hexadeciaml.getText().toString();
            for (int a=0;a<16;a++){
                dato[a]=0;
                if (a<TEX.length()){
                    dato[a]=TEX.charAt(a);
                }
            }
        }
        private void moslista(){
            for (int w=0;w<lista.size();w++){


                if (bit[w]==true){
                    // Toast.makeText(MainActivity.this, "pos w: "+w+" bol: "+"TRUEEE",Toast.LENGTH_SHORT).show();
                    lista.get(w).setChecked(true);
                }else{
                    //  Toast.makeText(MainActivity.this, "pos w: "+w+" bol: "+bit[w],Toast.LENGTH_SHORT).show();
                    lista.get(w).setChecked(false);
                }
            }

        }
    public void mostrarChecks(){
        int caso=1,p=0;
        int m=0;
        String t="";
        for (int r=0;r<64;){




            if(lista.get(r).isChecked()){

                m+=8;

            }else{
                //et_hexadeciaml.setText("*0*");
            }
            if(lista.get(r+3).isChecked()){
                m++;

            }else{
                //et_hexadeciaml.setText("*0*");
            }
            if(lista.get(r+2).isChecked()){
                m+=2;
            }else{
                // et_hexadeciaml.setText("*0*");
            }
            if(lista.get(r+1).isChecked()){

                m+=4;

            }else{
                //et_hexadeciaml.setText("*0*");
            }
            if (m==15){ t+="F"; }
            if (m==14){ t+="E"; }
            if (m==13){ t+="D"; }
            if (m==12){ t+="C"; }
            if (m==11){ t+="B"; }
            if (m==10){ t+="A"; }
            if (m<10 && m>0){ t+=m; }
            if (m<=0){ t+=0; }


            r+=4;

            // txt[p]=m;
            p++;
            m=0;
            /* contains
            switch(caso){
                case 1:{
                    if(lista.get(r).isChecked()==true){
                        txt[p]+=8;
                    }else{
                        txt[p]+=0;
                    }
                    caso++;
                    break;
                }
                case 2:{
                    if (lista.get(r).isChecked()==true){
                        txt[p]+=4;
                    }else{
                        txt[p]+=0;
                    }
                    caso++;
                    break;
                }
                case 3:{
                    if (lista.get(r).isChecked()==true){
                        txt[p]+=2;
                    }else{
                        txt[p]+=0;
                    }
                    caso++;
                    break;

                }

                case 4:{
                    if (lista.get(r).isChecked()==true){
                        txt[p]+=1;
                    }else{
                        txt[p]+=0;
                    }
                    caso++;
                    break;
                }
            }

             */
        }

        //for (int z=0;z<16;z++){
        //  t+=txt[z];
        //}
        et_hexadeciaml.setText(t);

    }
    public void  onclick(View view){
        if (view.getId()==R.id.button);
        // validar();
    }
    public void  validar(){
        String cad="Selecciono: \n";
        if (c1.isChecked()==true){
            cad+="Opcion1";

        }
        if(c2.isChecked()){
            cad+="Opcion2";
        }
        Toast.makeText(getContext(), " "+cad,Toast.LENGTH_SHORT).show();
        // Toast.makeText(getApplicationContext(),cad,Toast.LENGTH_SHORT).show();

    }
    public void mostrar(){
        //  et_hexadeciaml.setText(dato[0]+" ");
        // lista.add(c7);
        //  CheckBox cc1=c4;
        // lista.get(0).setChecked(true);
        //c4.setEnabled(true);
        //this.c5.setSelected(true);
        //c1.setEnabled(false);

        // for (int f=0;f<16;f++){
        //   txt[f]=0;
        // }
        //mostrarChecks();
        //String t=" ";
        //for (int z=0;z<16;z++){
        //  t+=txt[z];
        //}
        /*
        for (int f=0;f<64;f++){

        }

        et_hexadeciaml.setText("***** ");
        */



    }

    public void set_ArrayList(){
        lista.add(c1);
        lista.add(c2);
        lista.add(c3);
        lista.add(c4);
        lista.add(c5);
        lista.add(c6);
        lista.add(c7);
        lista.add(c8);
        lista.add(c9);
        lista.add(c10);
        lista.add(c11);
        lista.add(c12);
        lista.add(c13);
        lista.add(c14);
        lista.add(c15);
        lista.add(c16);
        lista.add(c17);
        lista.add(c18);
        lista.add(c19);
        lista.add(c20);
        lista.add(c21);
        lista.add(c22);
        lista.add(c23);
        lista.add(c24);
        lista.add(c25);
        lista.add(c26);
        lista.add(c27);
        lista.add(c28);
        lista.add(c29);
        lista.add(c30);
        lista.add(c31);
        lista.add(c32);
        lista.add(c33);
        lista.add(c34);
        lista.add(c35);
        lista.add(c36);
        lista.add(c37);
        lista.add(c38);
        lista.add(c39);
        lista.add(c40);
        lista.add(c41);
        lista.add(c42);
        lista.add(c43);
        lista.add(c44);
        lista.add(c45);
        lista.add(c46);
        lista.add(c47);
        lista.add(c48);
        lista.add(c49);
        lista.add(c50);
        lista.add(c51);
        lista.add(c52);
        lista.add(c53);
        lista.add(c54);
        lista.add(c55);
        lista.add(c56);
        lista.add(c57);
        lista.add(c58);
        lista.add(c59);
        lista.add(c60);
        lista.add(c61);
        lista.add(c62);
        lista.add(c63);
        lista.add(c64);
    }
}