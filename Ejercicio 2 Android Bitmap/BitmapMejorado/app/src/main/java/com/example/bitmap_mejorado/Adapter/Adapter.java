package com.example.bitmap_mejorado.Adapter;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.bitmap_mejorado.Metodos.Elements;

import com.example.bitmap_mejorado.R;

import java.util.ArrayList;

public class Adapter extends RecyclerView.Adapter<Adapter.ViewHolderDatos> {

    ArrayList<Elements> listaDatos;
    String tipo ;
    private RecyclerItemClick itemClick;

    public Adapter(ArrayList<Elements> listaDatos){
        this.listaDatos = listaDatos;
    }

    public Adapter(ArrayList<Elements> listaDatos, RecyclerItemClick itemClick) {
        this.listaDatos = listaDatos;
        this.itemClick = itemClick;

    }

    @NonNull
    @Override
    public ViewHolderDatos onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_list, null, false);
        return new ViewHolderDatos(v);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolderDatos holder, int position) {

            holder.tvNumero_bit.setText(listaDatos.get(position).getData_element());
            holder.tvTipo.setText(listaDatos.get(position).getType());
            holder.tvuso.setText(listaDatos.get(position).getUsage());


            final Elements i = listaDatos.get(position);
            holder.itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    itemClick.OnClick(i);
                }
            });


    }

    @Override
    public int getItemCount() {
        return listaDatos.size();
    }



    public class ViewHolderDatos extends RecyclerView.ViewHolder {

        TextView tvNumero_bit, tvTipo, tvuso;

        public ViewHolderDatos(@NonNull View itemView) {
            super(itemView);

            tvNumero_bit = itemView.findViewById(R.id.tvBit);
            tvTipo = itemView.findViewById(R.id.tvType);
            tvuso = itemView.findViewById(R.id.tvUsage);

        }
    }


    public  interface RecyclerItemClick {
        void OnClick(Elements item);
    }



}
