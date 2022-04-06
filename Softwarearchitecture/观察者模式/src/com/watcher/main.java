package com.watcher;

public class main {
    public static void main(String[] args) {
        concretewatched1 a = new concretewatched1();
        concretewatcher1 b = new concretewatcher1();
        concretewatcher2 c = new concretewatcher2();
        a.addWatcher(b);
        a.addWatcher(c);
        a.notifyWatchers("被观察者变化/刘铭源2018214937");
    }
}
