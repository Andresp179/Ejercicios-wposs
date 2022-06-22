package com.example.recargacelular.Metodos;

import android.os.Parcel;

public class Historial {
    public String numero;
    public String operador;
    public String monto;
    public String nom_usu;
    public String correo_usu;

    public Historial(String numero, String operador, String monto, String nom_usu, String correo_usu) {
        this.numero = numero;
        this.operador = operador;
        this.monto = monto;
        this.nom_usu = nom_usu;
        this.correo_usu = correo_usu;
    }
    protected Historial (Parcel in){
        this.numero = in.readString();
        this.operador = in.readString();
        this.monto = in.readString();
        this.nom_usu = in.readString();
        this.correo_usu = in.readString();

    }

    public String getNumero() {
        return numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public String getOperador() {
        return operador;
    }

    public void setOperador(String operador) {
        this.operador = operador;
    }

    public String getMonto() {
        return monto;
    }

    public void setMonto(String monto) {
        this.monto = monto;
    }

    public String getNom_usu() {
        return nom_usu;
    }

    public void setNom_usu(String nom_usu) {
        this.nom_usu = nom_usu;
    }

    public String getCorreo_usu() {
        return correo_usu;
    }

    public void setCorreo_usu(String correo_usu) {
        this.correo_usu = correo_usu;
    }
}
