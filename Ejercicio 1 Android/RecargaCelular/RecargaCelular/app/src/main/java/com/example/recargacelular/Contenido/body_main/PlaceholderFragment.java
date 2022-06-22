package com.example.recargacelular.Contenido.body_main;

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

import com.example.recargacelular.Fragments.Inicio;
import com.example.recargacelular.Fragments.Recarga;
import com.example.recargacelular.R;

/**
 * A placeholder fragment containing a simple view.
 */
public class PlaceholderFragment extends Fragment  {

    private static final String ARG_SECTION_NUMBER = "section_number";

    private com.example.recargacelular.Contenido.body_main.PageViewModel pageViewModel;

    public static Fragment newInstance(int index) {
        Fragment frag = null;
        switch (index){
              case 1:
                  Inicio inicio = new Inicio();
                 frag = inicio;
                break;
              case 2:
                Recarga recarga = new Recarga();
                frag = recarga;
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