package com.company;

public class ConcreteHeroA implements AbstractHero{
    public int AttackRange;
    public int Attack;
    public int Arror;
    public int blood;
    public float AttackSpeed;

    public String name;
    public String SkillQ;

    public void CreateHero(){
        this.name = "刘铭源one";
        this.Attack = 1000;
        this.Arror = 1000;
        this.AttackRange = 1000;
        this.AttackSpeed = 1000;
        this.blood = 1000;
        System.out.println("英雄：刘铭源one");
    };

    @Override
    public void setSkillQ() {
        this.SkillQ = "增加50护甲";
    }
}
