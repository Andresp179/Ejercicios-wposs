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
 * Use the {@link Fragment_second_bitmap#newInstance} factory method to
 * create an instance of this fragment.
 */
public class Fragment_second_bitmap extends Fragment {

    CheckBox c65,c66,c67,c68,c69,c70,c71,c72,c73,c74,c75,c76,c77,c78,c79,c80,
            c81,c82,c83,c84,c85,c86,c87,c88,c89,c90,c91,c92,c93,c94,c95,c96,
            c97,c98,c99,c100,c101,c102,c103,c104,c105,c106,c107,c108,c109,c110,c111,c112,
            c113,c114,c115,c116,c117,c118,c119,c120,c121,c122,c123,c124,c125,c126,c127,c128;
    Button mostarar2;
    EditText et_hexadeciaml2;
    char dato2[]=new char[16];
    boolean bit2[]=new boolean[64];
    int txt2[]=new int[16];
    int o2;
    public static List<CheckBox> lista2 = new ArrayList<>();

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public Fragment_second_bitmap() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Fragment_second_bitmap.
     */
    // TODO: Rename and change types and number of parameters
    public static Fragment_second_bitmap newInstance(String param1, String param2) {
        Fragment_second_bitmap fragment = new Fragment_second_bitmap();
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
        View v= inflater.inflate(R.layout.fragment_second_bitmap, container, false);
        //---------------------------------------------------------------------------------------
        mostarar2=v.findViewById(R.id.button2);
        et_hexadeciaml2=v.findViewById(R.id.editTextHexadeciaml_second);
        c65=(CheckBox) v.findViewById(R.id.B65);
        c66=(CheckBox) v.findViewById(R.id.B66);
        c67=(CheckBox) v.findViewById(R.id.B67);
        c68=(CheckBox) v.findViewById(R.id.B68);
        c69=(CheckBox) v.findViewById(R.id.B69);
        c70=(CheckBox) v.findViewById(R.id.B70);
        c71=(CheckBox) v.findViewById(R.id.B71);
        c72=(CheckBox) v.findViewById(R.id.B72);
        c73=(CheckBox) v.findViewById(R.id.B73);
        c74=(CheckBox) v.findViewById(R.id.B74);
        c75=(CheckBox) v.findViewById(R.id.B75);
        c76=(CheckBox) v.findViewById(R.id.B76);
        c77=(CheckBox) v.findViewById(R.id.B77);
        c78=(CheckBox) v.findViewById(R.id.B78);
        c79=(CheckBox) v.findViewById(R.id.B79);
        c80=(CheckBox) v.findViewById(R.id.B80);
        c81=(CheckBox) v.findViewById(R.id.B81);
        c82=(CheckBox) v.findViewById(R.id.B82);
        c83=(CheckBox) v.findViewById(R.id.B83);
        c84=(CheckBox) v.findViewById(R.id.B84);
        c85=(CheckBox) v.findViewById(R.id.B85);
        c86=(CheckBox) v.findViewById(R.id.B86);
        c87=(CheckBox) v.findViewById(R.id.B87);
        c88=(CheckBox) v.findViewById(R.id.B88);
        c89=(CheckBox) v.findViewById(R.id.B89);
        c90=(CheckBox) v.findViewById(R.id.B90);
        c91=(CheckBox) v.findViewById(R.id.B91);
        c92=(CheckBox) v.findViewById(R.id.B92);
        c93=(CheckBox) v.findViewById(R.id.B93);
        c94=(CheckBox) v.findViewById(R.id.B94);
        c95=(CheckBox) v.findViewById(R.id.B95);
        c96=(CheckBox) v.findViewById(R.id.B96);
        c97=(CheckBox) v.findViewById(R.id.B97);
        c98=(CheckBox) v.findViewById(R.id.B98);
        c99=(CheckBox) v.findViewById(R.id.B99);
        c100=(CheckBox) v.findViewById(R.id.B100);
        c101=(CheckBox) v.findViewById(R.id.B101);
        c102=(CheckBox) v.findViewById(R.id.B102);
        c103=(CheckBox) v.findViewById(R.id.B103);
        c104=(CheckBox) v.findViewById(R.id.B104);
        c105=(CheckBox) v.findViewById(R.id.B105);
        c106=(CheckBox) v.findViewById(R.id.B106);
        c107=(CheckBox) v.findViewById(R.id.B107);
        c108=(CheckBox) v.findViewById(R.id.B108);
        c109=(CheckBox) v.findViewById(R.id.B109);
        c110=(CheckBox) v.findViewById(R.id.B110);
        c111=(CheckBox) v.findViewById(R.id.B111);
        c112=(CheckBox) v.findViewById(R.id.B112);
        c113=(CheckBox) v.findViewById(R.id.B113);
        c114=(CheckBox) v.findViewById(R.id.B114);
        c115=(CheckBox) v.findViewById(R.id.B115);
        c116=(CheckBox) v.findViewById(R.id.B116);
        c117=(CheckBox) v.findViewById(R.id.B117);
        c118=(CheckBox) v.findViewById(R.id.B118);
        c119=(CheckBox) v.findViewById(R.id.B119);
        c120=(CheckBox) v.findViewById(R.id.B120);
        c121=(CheckBox) v.findViewById(R.id.B121);
        c122=(CheckBox) v.findViewById(R.id.B122);
        c123=(CheckBox) v.findViewById(R.id.B123);
        c124=(CheckBox) v.findViewById(R.id.B124);
        c125=(CheckBox) v.findViewById(R.id.B125);
        c126=(CheckBox) v.findViewById(R.id.B126);
        c127=(CheckBox) v.findViewById(R.id.B127);
        c128=(CheckBox) v.findViewById(R.id.B128);
        set_ArrayList2();
        //----------------------------------------------------------------------------------------
        //------------------------------------------------------------------------------------------
        mostarar2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(validar_Bit2(et_hexadeciaml2.getText().toString())==true){
                    set_datos2();


                    int caso=1,P=0;
                    for(int i2=0; i2 < 64; i2++){
                        if(caso==5){
                            caso=1;
                            P++;
                        }
                        switch(caso){
                            case 1:{
                                if((dato2[P]=='8')||dato2[P]=='9'||dato2[P]=='A'||dato2[P]=='B'||dato2[P]=='C'||dato2[P]=='D'||dato2[P]=='E'||dato2[P]=='F'||dato2[P]=='a'||dato2[P]=='b'||dato2[P]=='c'||dato2[P]=='d'||dato2[P]=='e'||dato2[P]=='f'){
                                    bit2[i2]=true;
                                }else{
                                    bit2[i2]=false;
                                }
                                caso++;
                                break;
                            }
                            case 2:{
                                if(dato2[P]=='4'||dato2[P]=='5'||dato2[P]=='6'||dato2[P]=='7'||dato2[P]=='C'||dato2[P]=='D'||dato2[P]=='E'||dato2[P]=='F'||dato2[P]=='c'||dato2[P]=='d'||dato2[P]=='e'||dato2[P]=='f'){
                                    bit2[i2]=true;
                                }
                                else{
                                    bit2[i2]=false;
                                }
                                caso++;
                                break;
                            }
                            case 3:{
                                if(dato2[P]=='2'||dato2[P]=='3'||dato2[P]=='6'||dato2[P]=='7'||dato2[P]=='A'||dato2[P]=='B'||dato2[P]=='E'||dato2[P]=='F'||dato2[P]=='a'||dato2[P]=='b'||dato2[P]=='e'||dato2[P]=='f'){
                                    bit2[i2]=true;
                                }else{
                                    bit2[i2]=false;
                                }
                                caso++;
                                break;
                            }
                            case 4:{
                                if(dato2[P]=='1'||dato2[P]=='3'||dato2[P]=='5'||dato2[P]=='7'||dato2[P]=='9'||dato2[P]=='B'||dato2[P]=='D'||dato2[P]=='F'||dato2[P]=='b'||dato2[P]=='d'||dato2[P]=='f'){
                                    bit2[i2]=true;
                                }else{
                                    bit2[i2]=false;
                                }
                                caso++;
                                break;
                            }
                        }
                    }

                }
                moslista2();
            }
        });
        //------------------------------------------------------------------------------------------
        for ( o2=0;o2<64;o2++) {
            int finalO = 0;

            lista2.get(o2).setOnClickListener(new View.OnClickListener() {
                //c1.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    // Toast.makeText(MainActivity.this, "un click.-- ",Toast.LENGTH_SHORT).show();
                    //mostrar();
                    mostrarChecks2();
                }

            });
        }
        //---------------------------------------------------------------------------------------------
        return v;
    }

    private boolean validar_Bit2(String txt){
        if( txt.length()<=16){
            return true;
        }
        Toast.makeText(getContext(), "Ingresa solo entre [ 0 – 16 ] caracteres hexadecimales.",Toast.LENGTH_SHORT).show();
        return false;
    }
    private void set_datos2(){
        String TEX=et_hexadeciaml2.getText().toString();
        for (int a=0;a<16;a++){
            dato2[a]=0;
            if (a<TEX.length()){
                dato2[a]=TEX.charAt(a);
            }
        }
    }
    private void moslista2(){
        for (int w=0;w<lista2.size();w++){


            if (bit2[w]==true){
                // Toast.makeText(MainActivity.this, "pos w: "+w+" bol: "+"TRUEEE",Toast.LENGTH_SHORT).show();
                lista2.get(w).setChecked(true);
            }else{
                //  Toast.makeText(MainActivity.this, "pos w: "+w+" bol: "+bit[w],Toast.LENGTH_SHORT).show();
                lista2.get(w).setChecked(false);
            }
        }

    }
    public void mostrarChecks2(){
        int caso=1,p=0;
        int m=0;
        String t="";
        for (int r=0;r<64;){




            if(lista2.get(r).isChecked()){

                m+=8;

            }else{
                //et_hexadeciaml.setText("*0*");
            }
            if(lista2.get(r+3).isChecked()){
                m++;

            }else{
                //et_hexadeciaml.setText("*0*");
            }
            if(lista2.get(r+2).isChecked()){
                m+=2;
            }else{
                // et_hexadeciaml.setText("*0*");
            }
            if(lista2.get(r+1).isChecked()){

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
        et_hexadeciaml2.setText(t);

    }
    public void  onclick(View view){
        if (view.getId()==R.id.button);
        // validar();
    }
    public void  validar2(){
        String cad="Selecciono: \n";
        if (c65.isChecked()==true){
            cad+="Opcion1";

        }
        if(c66.isChecked()){
            cad+="Opcion2";
        }
        Toast.makeText(getContext(), " "+cad,Toast.LENGTH_SHORT).show();
        // Toast.makeText(getApplicationContext(),cad,Toast.LENGTH_SHORT).show();

    }
    public void mostrar2(){
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

    public void set_ArrayList2(){
        lista2.add(c65);
        lista2.add(c66);
        lista2.add(c67);
        lista2.add(c68);
        lista2.add(c69);
        lista2.add(c70);
        lista2.add(c71);
        lista2.add(c72);
        lista2.add(c73);
        lista2.add(c74);
        lista2.add(c75);
        lista2.add(c76);
        lista2.add(c77);
        lista2.add(c78);
        lista2.add(c79);
        lista2.add(c80);
        lista2.add(c81);
        lista2.add(c82);
        lista2.add(c83);
        lista2.add(c84);
        lista2.add(c85);
        lista2.add(c86);
        lista2.add(c87);
        lista2.add(c88);
        lista2.add(c89);
        lista2.add(c90);
        lista2.add(c91);
        lista2.add(c92);
        lista2.add(c93);
        lista2.add(c94);
        lista2.add(c95);
        lista2.add(c96);
        lista2.add(c97);
        lista2.add(c98);
        lista2.add(c99);
        lista2.add(c100);
        lista2.add(c101);
        lista2.add(c102);
        lista2.add(c103);
        lista2.add(c104);
        lista2.add(c105);
        lista2.add(c106);
        lista2.add(c107);
        lista2.add(c108);
        lista2.add(c109);
        lista2.add(c110);
        lista2.add(c111);
        lista2.add(c112);
        lista2.add(c113);
        lista2.add(c114);
        lista2.add(c115);
        lista2.add(c116);
        lista2.add(c117);
        lista2.add(c118);
        lista2.add(c119);
        lista2.add(c120);
        lista2.add(c121);
        lista2.add(c122);
        lista2.add(c123);
        lista2.add(c124);
        lista2.add(c125);
        lista2.add(c126);
        lista2.add(c127);
        lista2.add(c128);
    }
}