package com.company;

public  class ConcreteFactoryB extends AbstractFactory{
    @Override
    public AbstractHero createProductHero() {
        ConcreteHeroB Ch = new ConcreteHeroB();
        return  Ch;
    }

    @Override
    public AbstractGood createProductGood() {
        return new ConcreteGoodB();
    }
}
