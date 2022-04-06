import java.awt.Button;
import java.awt.Container;
import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SpringLayout;

public class V {

    // TITLE
    final private static String MENU_DLG_TITLE = "MVC";

    // Frame
    private JFrame frame = new JFrame(MENU_DLG_TITLE);

    // Container
    private Container con = frame.getContentPane();

    Font font = new Font("test", 20, 20);

    JLabel lable = new JLabel(font.getName());
    Button enlarge = new Button("enlarge");
    Button abridge = new Button("abridge");

    public V() {
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        SpringLayout lay = new SpringLayout();
        con.setLayout(lay);

        lay.putConstraint(SpringLayout.WEST, lable, 120,SpringLayout.WEST, con);
        lay.putConstraint(SpringLayout.NORTH, lable, 180, SpringLayout.NORTH, con);

        lay.putConstraint(SpringLayout.WEST, enlarge, 80, SpringLayout.WEST, con);
        lay.putConstraint(SpringLayout.NORTH, enlarge, 380, SpringLayout.NORTH,	con);

        lay.putConstraint(SpringLayout.WEST, abridge, 140, SpringLayout.WEST,con);
        lay.putConstraint(SpringLayout.NORTH, abridge, 380, SpringLayout.NORTH,	con);

        con.add(lable);
        con.add(enlarge);
        con.add(abridge);

        C c = new C(this, new M());

        enlarge.addActionListener(c);
        abridge.addActionListener(c);

        frame.setBounds(520, 80, 300, 450);
        frame.setVisible(true);
    }

    public Button getEnlarge() {
        return enlarge;
    }

    public void setEnlarge(Button enlarge) {
        this.enlarge = enlarge;
    }

    public Button getAbridge() {
        return abridge;
    }

    public void setAbridge(Button abridge) {
        this.abridge = abridge;
    }

    public JFrame getFrame() {
        return frame;
    }

    public void setFrame(JFrame frame) {
        this.frame = frame;
    }

    public Container getCon() {
        return con;
    }

    public void setCon(Container con) {
        this.con = con;
    }

    public JLabel getLable() {
        return lable;
    }

    public void setLable(JLabel lable) {
        this.lable = lable;
    }

}