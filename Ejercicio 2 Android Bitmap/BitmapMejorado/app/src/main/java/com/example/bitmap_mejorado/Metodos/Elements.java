package com.example.bitmap_mejorado.Metodos;

import android.os.Parcel;

public class Elements {
    public String Data_element;
    public String Type;
    public String Usage;

    public Elements(String data_element, String type, String usage) {
        Data_element = data_element;
        Type = type;
        Usage = usage;
    }
    protected  Elements (Parcel in){
        this.Data_element=in.readString();
        this.Type=in.readString();
        this.Usage=in.readString();
    }

    public String getData_element() {
        return Data_element;
    }

    public void setData_element(String data_element) {
        Data_element = data_element;
    }

    public String getType() {
        return Type;
    }

    public void setType(String type) {
        Type = type;
    }

    public String getUsage() {
        return Usage;
    }

    public void setUsage(String usage) {
        Usage = usage;
    }
}
