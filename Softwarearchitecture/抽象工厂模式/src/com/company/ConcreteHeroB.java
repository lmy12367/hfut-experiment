package com.company;

public class ConcreteHeroB implements AbstractHero{
    public int AttackRange;
    public int Attack;
    public int Arror;
    public int blood;
    public float AttackSpeed;

    public String name;
    public String SkillQ;

    public void CreateHero(){
        this.name = "刘铭源two";
        this.Attack = 1000000;
        this.Arror = 1;
        this.AttackRange = 1000;
        this.AttackSpeed = 1000;
        this.blood = 1000;
        System.out.println("英雄：刘铭源two");
    };

    @Override
    public void setSkillQ() {
        this.SkillQ = "增加100000000攻速";
    }
}
