package com.a;

public class Adapter implements AbstractTarget{
    private Source source;
    //在构造方法中指定
    public Adapter(Source source) {
        super();
        this.source = source;
    }

    @Override
    public void targetmethod() {
        System.out.println("没适配之前：输出5V/2018214937刘铭源");
        int result=this.source.sourceMethod();
        System.out.println("适配之后：输出"+result+"v/2018214937刘铭源");
    }
}
