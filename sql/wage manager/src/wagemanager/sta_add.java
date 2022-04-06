package wagemanager;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import java.sql.*;

public class sta_add extends JFrame{
	public void create_sta_add() {
		setSize(500, 400);
		setLocation(500, 300);
		setLayout(null);
		ImageIcon pic = new ImageIcon("e:\\图片\\科技背景.jpg");
		JLabel L2 = new JLabel(pic);
		pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
		L2.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
		JTextField stanum = new JTextField();
		JTextField staname = new JTextField();
		JTextField stasex = new JTextField();
		JTextField dtnum = new JTextField();
		JTextField wyear = new JTextField();
		JTextField wbk = new JTextField();
		JTextField depnum = new JTextField();
		JTextField bw = new JTextField();
		JTextField allo = new JTextField();
		JTextField whop = new JTextField();
		JTextField pm = new JTextField();
		JLabel stanu = new JLabel("员 工  号:");
		JLabel stana = new JLabel("员工姓名:");
		JLabel stase = new JLabel("员工性别:");
		JLabel dtnu = new JLabel ("职务编号:");
		JLabel wyea = new JLabel ("工       龄:");
		JLabel wb = new JLabel   ("工资等级:");
		JLabel depnu = new JLabel("部  门  号:");
		JLabel bw_1 = new JLabel("基本工资:");
		JLabel allo_1 = new JLabel("津       贴:");
		JLabel whop_1 = new JLabel("代扣款项:");
		JLabel pm_1 = new JLabel("奖       金:");
		JButton addbtn = new JButton("增加员工");
		stanu.setForeground(Color.white);
		stana.setForeground(Color.white);
		stase.setForeground(Color.white);
		dtnu.setForeground(Color.white);
		wyea.setForeground(Color.white);
		wb.setForeground(Color.white);
		depnu.setForeground(Color.white);
		bw_1.setForeground(Color.white);
		allo_1.setForeground(Color.white);
		whop_1.setForeground(Color.white);
		pm_1.setForeground(Color.white);
		
		stanu.setBounds(90, 20, 60, 20);
		stana.setBounds(90, 45, 60, 20);
		stase.setBounds(90, 70, 60, 20);
		dtnu.setBounds(90, 95, 60, 20);
		wyea.setBounds(90, 120, 60, 20);
		wb.setBounds(90, 145, 60, 20);
		depnu.setBounds(90, 170, 60, 20);
		bw_1.setBounds(90, 195, 60, 20);
		allo_1.setBounds(90, 220, 60, 20);
		whop_1.setBounds(90, 245, 60, 20);
		pm_1.setBounds(90, 270, 60, 20);
		
		stanum.setBounds(150, 20, 220, 20);
		staname.setBounds(150, 45, 220, 20);
		stasex.setBounds(150, 70, 220, 20);
		dtnum.setBounds(150, 95, 220, 20);
		wyear.setBounds(150, 120, 220, 20);
		wbk.setBounds(150, 145, 220, 20);
		depnum.setBounds(150, 170, 220, 20);
		bw.setBounds(150, 195, 220, 20);
		allo.setBounds(150, 220, 220, 20);
		whop.setBounds(150, 245, 220, 20);
		pm.setBounds(150, 270, 220, 20);
		addbtn.setBounds(190, 300, 90, 30);
		
		add(stanum);
		add(staname);
		add(stasex);
		add(dtnum);
		add(wyear);
		add(wbk);
		add(depnum);
		add(stanu);
		add(stana);
		add(stase);
		add(dtnu);
		add(wyea);
		add(wb);
		add(depnu);
		add(bw);
		add(allo);
		add(whop);
		add(pm);
		add(bw_1);
		add(allo_1);
		add(whop_1);
		add(pm_1);
		add(addbtn);
		add(L2);
		//stadd.setBounds(x, y, width, height);
		setVisible(true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		addbtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
				String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=课设";
				String userName="sa";String userPwd="188754752";
				try{
					Class.forName(driverName);
					//System.out.println("加载驱动成功！");
				}catch(Exception ea){
					ea.printStackTrace();System.out.println("加载驱动失败！");
				}
				
				try(Connection dbConn=DriverManager.getConnection(dbURL,userName,userPwd)){
					try(PreparedStatement st = dbConn.prepareStatement("insert into staff values(?,?,?,?,?,?,?)")){
						st.setString(1, stanum.getText());
						st.setString(2, staname.getText());
						st.setString(3, stasex.getText());
						st.setString(4, dtnum.getText());
						st.setString(5, wyear.getText());
						st.setString(6, wbk.getText());
						st.setString(7, depnum.getText());
						st.executeUpdate();
					}
					try(PreparedStatement st = dbConn.prepareStatement("insert into wage values(?,?,?,?,?)")){
						st.setString(1, stanum.getText());
						st.setString(2, bw.getText());
						st.setString(3, allo.getText());
						st.setString(4, whop.getText());
						st.setString(5, pm.getText());
						st.executeUpdate();
					}
					//System.out.println("连接数据库成功！");
					
					dbConn.close();
				}catch(Exception ea){
					ea.printStackTrace();System.out.print("SQL Server连接失败！");
				}
			}
		});
	}
}
