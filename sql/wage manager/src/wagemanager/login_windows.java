package wagemanager;

import java.awt.Color;
import java.awt.Font;
import java.awt.Image;
import java.awt.event.*;
import javax.swing.*;
import java.sql.*;


public class login_windows extends JFrame{
	public void create_login(login_windows l1) {
		setTitle("��ӭʹ�ù�˾���ʹ���ϵͳ");
		setLayout(null);
		this.getContentPane().setBackground(Color.white);
		JButton button1 = new JButton("����Ա");
		JButton button2 = new JButton("��   ��");
		JButton button3 = new JButton("��   ¼");
		button3.setEnabled(false);
		setSize(500, 400);
		setLocation(500, 300);
		JTextField users_name = new JTextField();
		JPasswordField password = new JPasswordField();
		users_name.setEnabled(false);
		password.setEnabled(false);
		JLabel users = new JLabel("�û���:");
		JLabel pass = new JLabel("��   ��:");
		JLabel s1 = new JLabel("��    ɭ");
		JLabel s2 = new JLabel("Ǯ����");
		JLabel s3 = new JLabel("����Դ");
		JLabel s4 = new JLabel("�żͳ�");
		s1.setFont(new Font (Font.DIALOG, Font.BOLD, 12));
		s2.setFont(new Font (Font.DIALOG, Font.BOLD, 12));
		s3.setFont(new Font (Font.DIALOG, Font.BOLD, 12));
		s4.setFont(new Font (Font.DIALOG, Font.BOLD, 12));
		s1.setForeground(Color.white);
		s2.setForeground(Color.white);
		s3.setForeground(Color.white);
		s4.setForeground(Color.white);
		
		users.setForeground(Color.white);
		pass.setForeground(Color.white);
		ImageIcon pic = new ImageIcon("e:\\ͼƬ\\�Ƽ�����.jpg");
		JLabel L2 = new JLabel(pic);
		pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
		L2.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
		
		s1.setBounds(375, 310, 60, 20);
		s2.setBounds(375, 330, 60, 20);
		s3.setBounds(430, 310, 60, 20);
		s4.setBounds(430, 330, 60, 20);
		users.setBounds(85, 185, 70, 30);
		pass.setBounds(85, 230, 70, 30);
		users_name.setBounds(155, 180, 230, 30);
		password.setBounds(155, 230, 230, 30);
		button1.setBounds(100, 100, 100, 30);
		button2.setBounds(275, 100, 100, 30);
		button3.setBounds(200, 285, 100, 30);
		add(users_name);
		add(password);
		add(button1);//����Ա
		add(button2);//Ա��
		add(button3);
		add(users);
		add(pass);
		add(s1);
		add(s2);
		add(s3);
		add(s4);
		add(L2);
		setVisible(true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		button2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				button3.setEnabled(true);
				users_name.setEnabled(true);
				password.setEnabled(true);
				button3.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
						String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=����";
						String userName="sa";String userPwd="188754752";
						try{
							Class.forName(driverName);
							//System.out.println("���������ɹ���");
						}catch(Exception es){
							es.printStackTrace();System.out.println("��������ʧ�ܣ�");
						}
						String u1 = users_name.getText();
						char[] p1 = password.getPassword();
						String pp = String.valueOf(p1);
						String sta_name = null;
						//System.out.println(u1);
						//System.out.println(p1);
						try(Connection dbConn=DriverManager.getConnection(dbURL,userName,userPwd)){
							try(Statement st = dbConn.createStatement()){
								try (ResultSet rs = st.executeQuery("SELECT users_name,passwords,stanum FROM users WHERE users_name="+"'"+u1+"'"+"and passwords="+"'"+pp+"'"+" ")){
									//System.out.println(p1);
									while(rs.next()) {
										if(rs.getString(1).equals(u1) && rs.getString(2).equals(pp)) {
											windows w1 = new windows();
											w1.create();
											l1.dispose();
											sta_name = rs.getString(3);
											w1.get1(sta_name);
											//System.out.println(sta_name);
										}	
									}
								
									//	System.out.println(pp);
								}
							}
							//System.out.println("�������ݿ�ɹ���");
						
							dbConn.close();
						}catch(Exception es){
							es.printStackTrace();System.out.print("SQL Server����ʧ�ܣ�");
						}
				
					}
					
			});
			}	
		});
		button1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				button3.setEnabled(true);
				users_name.setEnabled(true);
				password.setEnabled(true);
				button3.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
						String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=����";
						String userName="sa";String userPwd="188754752";
						try{
							Class.forName(driverName);
							//System.out.println("���������ɹ���");
						}catch(Exception es){
							es.printStackTrace();System.out.println("��������ʧ�ܣ�");
						}
						String u1 = users_name.getText();
						char[] p1 = password.getPassword();
						String pp = String.valueOf(p1);
						String sta_name = null;
						//System.out.println(u1);
						//System.out.println(p1);
						try(Connection dbConn=DriverManager.getConnection(dbURL,userName,userPwd)){
							try(Statement st = dbConn.createStatement()){
								try (ResultSet rs = st.executeQuery("SELECT users_name,passwords,stanum,aut FROM users WHERE users_name="+"'"+u1+"'"+" and passwords="+"'"+pp+"'"+" ")){
									//System.out.println(p1);
									while(rs.next()) {
										if(rs.getString(1).equals(u1) && rs.getString(2).equals(pp) && rs.getString(4).equals("9")) {
											admin ad = new admin();
											ad.create_admin();
											l1.dispose();
											sta_name = rs.getString(3);
											//ad.get1(sta_name);
											//System.out.println(sta_name);
										}
										else{
											//System.out.println("11111");
										}
									}
								
									//	System.out.println(pp);
								}
							}
							//System.out.println("�������ݿ�ɹ���");
						
							dbConn.close();
						}catch(Exception es){
							es.printStackTrace();System.out.print("SQL Server����ʧ�ܣ�");
						}
				
					}
					
			});
			}
		});

	}
	public static void main(String[] args) {
		login_windows l1 = new login_windows();
		l1.create_login(l1);
	}


}