import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class C implements ActionListener{
    private V v ;
    private M m;

    public C(V v,M m){
        this.v = v;
        this.m = m;
    }

    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == v.getEnlarge()) {
            m.setSize(m.getSize() + 5);
            m.setStyle(m.getStyle() + 5);
        }else{
            m.setSize(m.getSize() - 5);
            m.setStyle(m.getStyle() - 5);
        }

        System.out.println("m.Style:" + m.getStyle());
        System.out.println("m.Size:" + m.getSize());
        Font font = new Font(v.getLable().getText(),m.getStyle(),m.getSize());
        v.getLable().setFont(font);

    }

    public V getV() {
        return v;
    }

    public void setV(V v) {
        this.v = v;
    }

    public M getM() {
        return m;
    }

    public void setM(M m) {
        this.m = m;
    }
}
