package com.company;

public  class ConcreteFactoryA extends AbstractFactory{
    @Override
    public AbstractHero createProductHero() {
        ConcreteHeroA Ch = new ConcreteHeroA();
        return  Ch;
    }

    @Override
    public AbstractGood createProductGood() {
        return new ConcreteGoodA();
    }
}
