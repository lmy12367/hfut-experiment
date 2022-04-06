package com.company;

public class ConcreteGoodA implements  AbstractGood{
    public String name = null;
    public Boolean Action = null;
    @Override
    public void Good() {
        System.out.println("携带：尚方宝剑/刘铭源2018214937");
        this.name = "尚方宝剑";
        this.Action = true;
    }
}
