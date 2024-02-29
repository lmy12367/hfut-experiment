package com.example.countbook;

public class Account {
    public int id;


    public String title;
    public int money;
    public String content;
    public String date;
    public String author;
public Account(){}

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public Account(int id, String title, int money, String content, String date, String author) {
        this.id = id;
        this.title = title;
        this.money = money;
        this.content = content;
        this.date=date;
        this.author = author;
    }


    public Account(String title, int money, String content,String date, String author) {
        this.title = title;
        this.money = money;
        this.content = content;
        this.date=date;
        this.author = author;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public int getMoney() {
        return money;
    }

    public void setMoney(int money) {
        this.money = money;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }
}
