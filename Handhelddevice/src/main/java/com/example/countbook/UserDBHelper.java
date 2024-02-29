package com.example.countbook;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class UserDBHelper extends SQLiteOpenHelper {
    public UserDBHelper(Context context,String name, SQLiteDatabase.CursorFactory factory, int version){
        super(context,name,factory,1);
    }
    @Override
    public void onCreate(SQLiteDatabase db) {
        String created="create table Users ("
                +"id integer primary key autoincrement, "
                +"username text, "
                +"password text)";
        db.execSQL(created);
    }


    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
}
