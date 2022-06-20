package com.example.bitmap_mejorado.body_main;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;

import com.example.bitmap_mejorado.Fragments.Fragment_elemento_de_datos_definido_por_iso;
import com.example.bitmap_mejorado.Fragments.Fragment_first_bitmap;
import com.example.bitmap_mejorado.Fragments.Fragment_second_bitmap;

import com.example.bitmap_mejorado.R;

/**
 * A placeholder fragment containing a simple view.
 * puto el que lo lea y el que lo siga leyendo >_>
 * ya borrelo lk
 */
public class PlaceholderFragment extends Fragment  {

    private static final String ARG_SECTION_NUMBER = "section_number";

    private com.example.bitmap_mejorado.body_main.PageViewModel pageViewModel;

    public static Fragment newInstance(int index) {
        Fragment frag = null;
        switch (index){
              case 1:
                  Fragment_first_bitmap primer = new Fragment_first_bitmap();
                 frag = primer;
                break;
              case 2:
                Fragment_second_bitmap segundo = new Fragment_second_bitmap();
                frag = segundo;
                break;
            case 3:
                Fragment_elemento_de_datos_definido_por_iso mostrar= new Fragment_elemento_de_datos_definido_por_iso();
                frag = mostrar;
                break;
              }
        return frag;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        pageViewModel = new ViewModelProvider(this).get(PageViewModel.class);
        int index = 1;
        if (getArguments() != null) {
            index = getArguments().getInt(ARG_SECTION_NUMBER);
        }
        pageViewModel.setIndex(index);
    }

    @Override
    public View onCreateView(
            @NonNull LayoutInflater inflater, ViewGroup container,
            Bundle savedInstanceState) {
        View root = inflater.inflate(R.layout.fragment_prueba2, container, false);
        final TextView textView = root.findViewById(R.id.section_label);
        pageViewModel.getText().observe(getViewLifecycleOwner(), new Observer<String>() {
            @Override
            public void onChanged(@Nullable String s) {
                textView.setText(s);
            }
        });
        return root;
    }
}