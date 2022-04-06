package com.watcher;

        import java.util.ArrayList;
        import java.util.List;

public class concretewatched1 implements AbtstractWatched {
    private List<AbstractWatcher> list = new ArrayList<AbstractWatcher>();

    public void addWatcher(AbstractWatcher abstractWatcher) {
        list.add(abstractWatcher);
    }
    public void removeWatcher(AbstractWatcher abstractWatcher) {
        list.remove(abstractWatcher);
    }
    public void notifyWatchers(String str) {
        System.out.println("歹徒即将威胁到人质的安全/刘铭源2018214937");
        for (AbstractWatcher abstractWatcher : list) {
            abstractWatcher.redo();
        }
    }
}
