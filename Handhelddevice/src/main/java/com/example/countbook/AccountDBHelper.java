package com.example.countbook;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class AccountDBHelper extends SQLiteOpenHelper {

    public AccountDBHelper(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, "db_account", factory, version);
    }


    @Override
    public void onCreate(SQLiteDatabase db) {
        String creat="create table Accounts ("
                +"id integer primary key autoincrement, "
                +"title text, "
                +"money int, "
                +"content text, "
                +"date varchar, "
                +"author text)";
        db.execSQL(creat);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
}
