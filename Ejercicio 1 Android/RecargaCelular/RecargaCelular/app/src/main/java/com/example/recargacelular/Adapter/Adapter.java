package com.example.recargacelular.Adapter;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.recargacelular.Metodos.Historial;
import com.example.recargacelular.R;

import java.text.DecimalFormat;
import java.util.ArrayList;

import static com.example.recargacelular.MainActivity.email_usuario;

public class Adapter extends RecyclerView.Adapter<Adapter.ViewHolderDatos> {

    ArrayList<Historial> listaDatos;
    ArrayList<Historial> originalLista =new ArrayList<>();
    String tipo ;
    ImageView ivIcono;
    private RecyclerItemClick itemClick;

    public Adapter(ArrayList<Historial> listaDatos){
        this.listaDatos = listaDatos;
    }

    public Adapter(ArrayList<Historial> listaDatos, RecyclerItemClick itemClick, String condicion) {
        this.listaDatos = listaDatos;
        this.itemClick = itemClick;
        for(int x=0;x<listaDatos.size();x++){
            if(listaDatos.get(x).getCorreo_usu().equalsIgnoreCase(condicion)) {
                originalLista.add((Historial) listaDatos.get(x));
            }
        }

    }

    @NonNull
    @Override
    public ViewHolderDatos onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_list, null, false);
        return new ViewHolderDatos(v);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolderDatos holder, int position) {
            DecimalFormat formatter = new DecimalFormat("###,###,###.00");
            holder.tvNumero_telefonico.setText(originalLista.get(position).getNumero());
            holder.tvTipo_operador.setText(originalLista.get(position).getOperador());
            holder.tvMonto_recarga.setText("$ " + formatter.format(Integer.parseInt(originalLista.get(position).getMonto())));
            tipo = originalLista.get(position).getOperador();
            setImage();

            final Historial i = originalLista.get(position);
            holder.itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    itemClick.OnClick(i);
                }
            });


    }

    @Override
    public int getItemCount() {
        return originalLista.size();
    }



    public class ViewHolderDatos extends RecyclerView.ViewHolder {

        TextView tvNumero_telefonico, tvTipo_operador, tvMonto_recarga;

        public ViewHolderDatos(@NonNull View itemView) {
            super(itemView);

            ivIcono = itemView.findViewById(R.id.ivImagen);
            tvNumero_telefonico = itemView.findViewById(R.id.tvNumero);
            tvTipo_operador = itemView.findViewById(R.id.tvOperador);
            tvMonto_recarga = itemView.findViewById(R.id.tvMonto);

        }
    }


    public  interface RecyclerItemClick {
        void OnClick(Historial item);
    }

    public void setImage(){
        if (tipo.equalsIgnoreCase("Claro")) ivIcono.setImageResource(R.drawable.claro);
        if (tipo.equalsIgnoreCase("Movistar")) ivIcono.setImageResource(R.drawable.movistar);
        if (tipo.equalsIgnoreCase("Tigo")) ivIcono.setImageResource(R.drawable.tigo);
        if (tipo.equalsIgnoreCase("Wom")) ivIcono.setImageResource(R.drawable.wom);

    }

}
