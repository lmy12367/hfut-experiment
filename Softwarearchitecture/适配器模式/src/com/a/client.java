package com.a;

public class client {
    public static void main(String[] args) {
        Adapter adapter=new Adapter(new Source());
        adapter.targetmethod();
    }
}
