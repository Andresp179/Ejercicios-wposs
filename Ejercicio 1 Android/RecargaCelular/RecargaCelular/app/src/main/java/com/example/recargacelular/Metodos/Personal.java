package com.example.recargacelular.Metodos;

public class Personal {
public String Nombre;
public String Apellido;
public String Cedula;
public String Correo;
public double saldo;
public String clave;

    public Personal(String nombre, String apellido, String cedula, String correo, double saldo, String clave) {
        Nombre = nombre;
        Apellido = apellido;
        Cedula = cedula;
        Correo = correo;
        this.saldo = saldo;
        this.clave = clave;
    }

    public String getNombre() {
        return Nombre;
    }

    public void setNombre(String nombre) {
        Nombre = nombre;
    }

    public String getApellido() {
        return Apellido;
    }

    public void setApellido(String apellido) {
        Apellido = apellido;
    }

    public String getCedula() {
        return Cedula;
    }

    public void setCedula(String cedula) {
        Cedula = cedula;
    }

    public String getCorreo() {
        return Correo;
    }

    public void setCorreo(String correo) {
        Correo = correo;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public String getClave() {
        return clave;
    }

    public void setClave(String clave) {
        this.clave = clave;
    }
}
