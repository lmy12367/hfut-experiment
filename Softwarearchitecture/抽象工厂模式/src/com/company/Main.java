package com.company;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        ConcreteFactoryA a = new ConcreteFactoryA();
        a.createProductHero().CreateHero();
        a.createProductGood().Good();
        ConcreteFactoryB b = new ConcreteFactoryB();
        b.createProductHero().CreateHero();
        b.createProductGood().Good();
    }
}
