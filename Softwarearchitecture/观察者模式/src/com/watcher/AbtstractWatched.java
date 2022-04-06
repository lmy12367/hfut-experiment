package com.watcher;

import java.util.ArrayList;
import java.util.List;

public interface AbtstractWatched {
    List<AbstractWatcher> list = new ArrayList<AbstractWatcher>();
    // 添加观察者
    public void addWatcher(AbstractWatcher abstractWatcher);

    // 移除观察者
    public void removeWatcher(AbstractWatcher abstractWatcher);

    // 通知观察者
    public void notifyWatchers(String str);
}
