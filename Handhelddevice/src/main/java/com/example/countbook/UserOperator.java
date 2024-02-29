package com.example.countbook;


import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import java.util.ArrayList;
import java.util.List;

public class UserOperator {
    private UserDBHelper UserDBHelper;
    private SQLiteDatabase db;
    public UserOperator(Context context){
        UserDBHelper=new UserDBHelper(context,"db_user",null,1);
        db=UserDBHelper.getWritableDatabase();
    }


    //增加一条用户信息
    public void addUser(User bean){
        db.execSQL("insert into Users (username,password) values(?,?)",new Object[]{bean.username,bean.password});
    }
    //更新用户密码
    public void updateUser(User bean){
        db.execSQL("update Users set password = ? where username = ?",new Object[]{bean.password,bean.username});
    }
    //删除某位用户
    public void deleteUser(String username){
        db.execSQL("delete from Users where username=?",new String[]{username});
    }
    //判断用户是否存在
    public User isExit(String name){
        User bean=null;
        Cursor c=db.rawQuery("select * from Users where username=?",new String[]{name});
        while(c.moveToNext()){
            bean=new User();
            bean.setUsername(c.getString(c.getColumnIndex("username")));
            bean.setPassword(c.getString(c.getColumnIndex("password")));
        }
        c.close();
        return bean;
    }
    //获取所有用户
    public List<User> getallUser(){
        List<User> list=new ArrayList<>();
        Cursor c=db.rawQuery("select * from Users",null);
        while(c.moveToNext()){
            User bean=new User();
            bean.setUsername(c.getString(c.getColumnIndex("username")));
            bean.setPassword(c.getString(c.getColumnIndex("password")));
            list.add(bean);
        }
        c.close();
        return list;
    }


}
