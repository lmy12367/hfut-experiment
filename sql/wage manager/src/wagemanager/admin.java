package wagemanager;
import java.sql.*;
import java.text.MessageFormat;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.table.DefaultTableModel;
import javax.swing.*;

public class admin extends JFrame{
	String stanu = null;
	public void create_admin() {
		
		setTitle("管理员");
		JLabel L1 = new JLabel("管   理   员   界   面");
		L1.setFont(new Font (Font.DIALOG, Font.BOLD, 25));
		L1.setForeground(Color.white);
		//this.getContentPane().setBackground(Color.blue);
		//背景
		ImageIcon pic = new ImageIcon("e:\\图片\\科技背景.jpg");
		JLabel L2 = new JLabel(pic);
		pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
		L2.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
		
		
		ImageIcon wage = new ImageIcon("e:\\图片\\工资.jpg");
		wage.setImage(wage.getImage().getScaledInstance(75, 75,Image.SCALE_DEFAULT));
		JLabel wage_pic = new JLabel(wage);
		wage_pic.setBounds(100, 250, 75, 75);
		ImageIcon sta = new ImageIcon("e:\\图片\\员工.jpg");
		sta.setImage(sta.getImage().getScaledInstance(75, 75,Image.SCALE_DEFAULT));
		JLabel sta_pic = new JLabel(sta);
		sta_pic.setBounds(100, 150, 75, 75);
		JButton button1 = new JButton("员工管理");
		JButton button2 = new JButton("工资管理");
		Container c = getContentPane();
		setLayout(null);
		button1.setBounds(200, 150, 200, 75);
		button2.setBounds(200, 250, 200, 75);
		L1.setBounds(145, 50, 275, 75);
		add(button1);
		add(button2);
		add(wage_pic);
		add(sta_pic);
		add(L1);
		add(L2);
		setSize(500, 400);
		setLocation(500, 300);
		setVisible(true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		button1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent arg0) {
				admin_sta ads1 = new admin_sta();
				ads1.create_adsta();
			}
		});
		button2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent arg0) {
				admin_wage adw1 = new admin_wage();
				adw1.create_adwage();
			}
			
			
		});
		
		
	}
	
	
	
	
	public static void main(String[] args) {
		admin a1 = new admin();
		a1.create_admin();
	}

}
