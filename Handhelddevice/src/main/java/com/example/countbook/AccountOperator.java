package com.example.countbook;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

public class AccountOperator {
    private AccountDBHelper accountDBHelper;
    private SQLiteDatabase db;

    public static final String DATE="date";

    public AccountOperator(Context context){
        accountDBHelper=new AccountDBHelper(context,"db_account",null,1);
        db=accountDBHelper.getWritableDatabase();
    }


    public void insert(Account bean){
        db.execSQL("insert into Accounts (title,money,content,date,author) values(?,?,?,?,?)",new Object[]{bean.title,bean.money,bean.content,bean.date,bean.author});
    }

    public void update(Account bean){
        db.execSQL("update Accounts set content=?,money=?,title=? where id=?",new Object[]{bean.content,bean.money,bean.title,bean.id});
    }

    public void deletebycontent(String content,String author){
        db.execSQL("delete from Accounts where content=? and author=?", new String[]{content,author});
    }

    public void deleteall(String author){
        db.execSQL("delete from Accounts where author=?",new String[]{author});
    }

    public Account find(String content){
        Account bean=null;
        Cursor c=db.rawQuery("select * from Accounts where content=?",new String[]{content});
        while(c.moveToNext()) {
            bean.id = c.getInt(c.getColumnIndex("id"));
            bean.title = c.getString(c.getColumnIndex("title"));
            bean.money = c.getInt(c.getColumnIndex("money"));
            bean.date = c.getString(c.getColumnIndex("date"));
            bean.author = c.getString(c.getColumnIndex("author"));
        }
        return bean;
    }

    public Cursor findall(String author){
        Cursor c=db.rawQuery("select * from Accounts where author = ? order by date ASC",new String[]{author});
        return c;
    }


}
