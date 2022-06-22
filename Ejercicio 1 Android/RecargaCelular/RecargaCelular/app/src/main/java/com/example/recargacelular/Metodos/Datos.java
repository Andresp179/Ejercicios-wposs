package com.example.recargacelular.Metodos;

import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Datos {
    public static ArrayList<Personal> Usuario = new ArrayList<>();
    public static ArrayList<Historial>recargas_realizaa = new ArrayList<>();


    public static void guardar_objetos(Object o) {
        System.out.println(o.getClass().getName());
        String nombre_clase = o.getClass().getName();
        StringTokenizer st = new StringTokenizer(nombre_clase, ".");//bloqueadir para no resivir mas datos een un programa selecciomado

        while (st.hasMoreTokens()) {
            nombre_clase = st.nextToken();
        }

        if (nombre_clase.equalsIgnoreCase("Personal")) {
            Usuario.add((Personal) o);
        }else if(nombre_clase.equalsIgnoreCase("Historial")){
            recargas_realizaa.add((Historial) o);
        }

    }

    public int login(String usuario, String contraseña){
        int x=0;
        Personal p =null;
        if(Usuario.size()!=0) {
            for (int i = 0; i < Usuario.size(); i++) {
                p = (Personal) Usuario.get(i);
                if (p.getCorreo().equalsIgnoreCase(usuario) && p.getClave().equalsIgnoreCase(contraseña)) {
                    x=1;
                }

            }
        }
        return x;
    }

    public Personal envio(String usuario, String contraseña){
        Personal p =null;
        if(Usuario.size()!=0) {
            for (int i = 0; i < Usuario.size(); i++) {
                p = (Personal) Usuario.get(i);
                if (p.getCorreo().equalsIgnoreCase(usuario) && p.getClave().equalsIgnoreCase(contraseña)) {
                    return p;
                }

            }
        }
        return null;
    }

    public Personal Validador(String usuario){
        Personal p =null;
        if(Usuario.size()!=0) {
            for (int i = 0; i < Usuario.size(); i++) {
                p = (Personal) Usuario.get(i);
                if (p.getCorreo().equalsIgnoreCase(usuario)) {
                    return p;
                }

            }
        }
        return null;
    }
    // validar Correo
    public boolean validarCorreo(String email) {
        // Patrón para validar el email
        Pattern pattern = Pattern.compile("^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@"
                + "[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$");

        Matcher mather = pattern.matcher(email);
        if (mather.find() == true) {
            return true;
        } else {
            return false;
        }
    }

    // validar password
    public boolean validarClave(String clave) {
        // Patrón para validar que el password contenga letras y numeros
        Pattern pattern = Pattern.compile("(([A-Za-z].[0-9])|([0-9].[A-Za-z]))");
        Matcher mather = pattern.matcher(clave);
        if (mather.find() == true) {
            return true;
        } else {
            return false;
        }
    }

    public boolean existencia(String email){
        Personal p =null;
        if(Usuario.size()!=0) {
            for (int i = 0; i < Usuario.size(); i++) {
                p = (Personal) Usuario.get(i);
                if (p.getCorreo().equalsIgnoreCase(email)) {
                    return true;
                }

            }
        }
        return false;
    }
}
