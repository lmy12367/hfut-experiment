package wagemanager;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowStateListener;
/*import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;*/
import java.sql.*;
import javax.swing.*;

import org.omg.CORBA.PUBLIC_MEMBER;

public class windows extends JFrame{
	String stan = null;
	public void get1(String a) {
		stan = a;
	}
	protected void openthis() {
		
		setEnabled(true);
	}
	protected void closethis() {
		setEnabled(false);
	}
	public static void main(String[] args) {		
		windows win=new windows();
		win.create();
	}
	public void create() {
		setTitle("Ա����Ϣ");
		JLabel L1 = new JLabel("Ա    ��    ��    ��");
		L1.setFont(new Font (Font.DIALOG, Font.BOLD, 25));
		//this.getContentPane().setBackground(Color.white);
		L1.setForeground(Color.white);
		//����
		ImageIcon pic = new ImageIcon("e:\\ͼƬ\\�Ƽ�����.jpg");
		JLabel L2 = new JLabel(pic);
		pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
		L2.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
		ImageIcon wage = new ImageIcon("e:\\ͼƬ\\����.jpg");
		wage.setImage(wage.getImage().getScaledInstance(75, 75,Image.SCALE_DEFAULT));
		JLabel wage_pic = new JLabel(wage);
		wage_pic.setBounds(100, 250, 75, 75);
		ImageIcon sta = new ImageIcon("e:\\ͼƬ\\Ա��.jpg");
		sta.setImage(sta.getImage().getScaledInstance(75, 75,Image.SCALE_DEFAULT));
		JLabel sta_pic = new JLabel(sta);
		sta_pic.setBounds(100, 150, 75, 75);
		JButton button1 = new JButton("Ա����Ϣ");
		JButton button2 = new JButton("������Ϣ");
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
			public void actionPerformed(ActionEvent e) {
				closethis();
				//JScrollPane js1 = new JScrollPane(new JTextArea());
				JFrame windows2 = new JFrame("Ա����");
				windows2.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
				windows2.setSize(500, 400);
				windows2.setLocation(500, 300);
				Container co = windows2.getContentPane();
				//JPanel p = new JPanel();
				co.setLayout(null);
							
				JButton b1=new JButton("��ѯ�ҵ���Ϣ");
				JButton b2=new JButton("�޸��ҵ���Ϣ");
				ImageIcon pic = new ImageIcon("e:\\ͼƬ\\�Ƽ�����.jpg");
				JLabel L_2 = new JLabel(pic);
				pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
				L_2.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
								
				b1.setBounds(40, 50, 200, 30);
				b2.setBounds(240, 50, 200, 30);
			
				co.add(b1);				
				co.add(b2);			
				co.add(L_2);
				windows2.setVisible(true); 
				windows2.addWindowListener(new WindowAdapter() {
					public void windowClosing(WindowEvent e) {
						openthis();
					}
				});	
				b1.addActionListener(new ActionListener() {//Ա����Ϣ��ѯ������
					
					@Override
					public void actionPerformed(ActionEvent arg0) {
						JFrame w3 = new JFrame("Ա����Ϣ��ѯ��");
						w3.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
						w3.setSize(500, 400);
						w3.setLocation(500, 300);		
						Container c1 = w3.getContentPane();
						c1.setLayout(null);
						JButton search = new JButton("��ѯ");
						JTextField t1 = new JTextField(20);
						JTextField t2 = new JTextField(20);
						JTextField t3 = new JTextField(20);
						JTextField t4 = new JTextField(20);
						JTextField t5 = new JTextField(20);
						JTextField t6 = new JTextField(20);
						JTextField t7 = new JTextField(20);
					//	JTextField t8 = new JTextField(20);
						
						JLabel lab1 = new JLabel("Ա  �� ��:");
						JLabel lab2 = new JLabel("Ա������:");
						JLabel lab3 = new JLabel("Ա���Ա�:");
						JLabel lab4 = new JLabel("ְ������:");						
						JLabel lab5 = new JLabel("��       ��:");
						JLabel lab6 = new JLabel("���ʵȼ�:");
						JLabel lab7 = new JLabel("��  ��  ��:");
					//	JLabel lab5 = new JLabel("ְ����:");
						
						lab1.setForeground(Color.white);
						lab2.setForeground(Color.white);
						lab3.setForeground(Color.white);
						lab4.setForeground(Color.white);
						lab5.setForeground(Color.white);
						lab6.setForeground(Color.white);
						lab7.setForeground(Color.white);
					//	lab8.setForeground(Color.white);
						
						
						ImageIcon pic = new ImageIcon("e:\\ͼƬ\\�Ƽ�����.jpg");
						JLabel L_3 = new JLabel(pic);
						pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
						L_3.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
						
						lab1.setBounds(85, 20, 200, 20);
						lab2.setBounds(85, 50, 200, 20);
						lab3.setBounds(85, 80, 200, 20);
						lab4.setBounds(85, 110,200, 20);
						lab5.setBounds(85, 140, 200, 20);
						lab6.setBounds(85, 170, 200, 20);
						lab7.setBounds(85, 200, 200, 20);
					//	lab8.setBounds(85, 230, 200, 20);
						search.setBounds(160, 260, 120, 20);
						
						
						t1.setBounds(140, 20, 200, 20);
						t2.setBounds(140, 50, 200, 20);
						t3.setBounds(140, 80, 200, 20);
						t4.setBounds(140, 110,200, 20);
						t5.setBounds(140, 140, 200, 20);
						t6.setBounds(140, 170, 200, 20);
						t7.setBounds(140, 200, 200, 20);
					//	t8.setBounds(140, 230, 200, 20);
						
						c1.add(t1);
						c1.add(t2);
						c1.add(t3);
						c1.add(t4);
						c1.add(t5);
						c1.add(t6);
						c1.add(t7);
					//	c1.add(t8);
						c1.add(lab1);
						c1.add(lab2);
						c1.add(lab3);
						c1.add(lab4);
						c1.add(lab5);
						c1.add(lab6);
						c1.add(lab7);
					//	c1.add(lab8);
						c1.add(search);
						c1.add(L_3);
						search.addActionListener(new ActionListener() {//�����ݿ��ѯ
							
							@Override
							public void actionPerformed(ActionEvent e) {
								String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";//�������ݿ�
								String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=����";
								String userName="sa";String userPwd="188754752";
								try{
									Class.forName(driverName);
									//System.out.println("���������ɹ���");
								}catch(Exception ex){
									ex.printStackTrace();
									System.out.println("��������ʧ�ܣ�");
								}
								
								try(Connection dbConn=DriverManager.getConnection(dbURL,userName,userPwd)){												
									try(Statement st = dbConn.createStatement()){
										try (ResultSet rs = st.executeQuery("SELECT stanum,staname,stasex,dtnum,wyear,wbk,depnum FROM staff WHERE stanum="+stan+"")){
											String stanum = null;
											String staname = null;
											String stasex = null;
											
											String dtnum = null;
											int wyear = 0;
											int wbk = 0;
											String depnum = null;
											
											while(rs.next()) {
												stanum = rs.getString(1);										
												staname = rs.getString(2);
												stasex = rs.getString(3);
												dtnum  = rs.getString(4);
												wyear  = rs.getInt(5);
												wbk    = rs.getInt(6);
												depnum = rs.getString(7);          							
												
												t1.setText(stanum);
												t2.setText(staname);
												t3.setText(stasex);
												
												t4.setText(dtnum);			
												t5.setText(String.valueOf(wyear));
												t6.setText(String.valueOf(wbk));	
												t7.setText(depnum);
											}
											//System.out.println(bw);
										}
									}
									//System.out.println("�������ݿ�ɹ���");
									
									dbConn.close();
								}catch(Exception ex){
									ex.printStackTrace();
									System.out.print("SQL Server����ʧ�ܣ�");
								}
								
								
							}
						});
						
						
						
						w3.setVisible(true);
						
					}
				});
				b2.addActionListener(new ActionListener() {					
					@Override
					public void actionPerformed(ActionEvent arg0) {//Ա����Ϣ�޸ļ�����
						JFrame w3 = new JFrame("Ա����Ϣ�޸Ĵ�");
						w3.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
						w3.setSize(500, 400);
						w3.setLocation(500, 300);		
						Container c1 = w3.getContentPane();
						c1.setLayout(null);
						
						JTextField t3 = new JTextField(10);
						JTextField t4 = new JTextField(10);
					
						JLabel lab3 = new JLabel("�û���:");
						JLabel lab4 = new JLabel("��   ��:");
						lab3.setForeground(Color.white);
						lab4.setForeground(Color.white);
						JButton jb0 = new JButton("�����޸�");
						ImageIcon pic = new ImageIcon("e:\\ͼƬ\\�Ƽ�����.jpg");
						JLabel L_4 = new JLabel(pic);
						pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
						L_4.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
						
						lab3.setBounds(85, 100, 100, 20);
						lab4.setBounds(85, 140, 100, 20);
						
						t3.setBounds(140, 100, 200, 20);
						t4.setBounds(140, 140, 200, 20);
						jb0.setBounds(160, 250, 120, 20);
						
						c1.add(t3);
						c1.add(t4);
						
						c1.add(lab3);
						c1.add(lab4);
						
						c1.add(jb0);
						c1.add(L_4);
						jb0.addActionListener(new ActionListener() {//�����ݿ����޸���Ϣ
							
							@Override
							public void actionPerformed(ActionEvent e) {
								
									
									try{
										String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";//�������ݿ�
										String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=����";
										String userName="sa";String userPwd="188754752";
										Class.forName(driverName);	
										try {
										Connection dbConn=DriverManager.getConnection(dbURL,userName,userPwd);
										String sql1 = "update users set passwords  = ? where  users_name=? ";

										//String sql2 = "update users set users_name  = ? where  stanum='20180001' ";
										PreparedStatement ps = dbConn.prepareStatement(sql1);
										//PreparedStatement ps0 = dbConn.prepareStatement(sql2);
										ps.setString(2, t3.getText());
										ps.setString(1, t4.getText());
										System.out.println(t3.getText());
										int count=ps.executeUpdate();
										int count0 = ps.executeUpdate();
											if(count>0&&count0>0) {
												System.out.println("�޸ĳɹ�");
												
											}
											else {
												System.out.println("�޸�ʧ��");
												JOptionPane.showMessageDialog(null,"�޸�ʧ�ܣ�","����",JOptionPane.ERROR_MESSAGE);
											}
										dbConn.close();
										} catch (SQLException e1) {
										
											e1.printStackTrace();
											//System.out.println("���������ɹ���");
											JOptionPane.showMessageDialog(null,"���ݿ�����ʧ�ܣ�","����",JOptionPane.ERROR_MESSAGE);
									
										}
										
									}catch(Exception ex){
										ex.printStackTrace();
										System.out.println("��������ʧ�ܣ�");
										JOptionPane.showMessageDialog(null,"��������ʧ�ܣ�","����",JOptionPane.ERROR_MESSAGE);
									}
									String usr = "y0000001";
								
								
							}
						});
						w3.setVisible(true);
					}
				});
			}						
		});                                                                                                                                                                                                                                                                          
		                                                                                                                                                                                                                                                                       
		
		button2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
					
				JFrame windows3 = new JFrame("������Ϣ��ѯ��");				
				windows3.setSize(500, 400);			
				windows3.setLocation(500, 300);
				windows3.setVisible(true);
				windows3.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
				Container c2 = windows3.getContentPane();
				c2.setLayout(null);
				JTextField t1 = new JTextField(10);
				JTextField t2 = new JTextField(10);
				JTextField t3 = new JTextField(10);
				JTextField t4 = new JTextField(10);
				JTextField t5 = new JTextField(10);
				JTextField t6 = new JTextField(10);
			//	JTextField t7 = new JTextField(10);
				JLabel lab1 = new JLabel("Ա  �� ��:");
				
				JLabel lab2 = new JLabel("��������:");
				JLabel lab3 = new JLabel("��       ��:");
				JLabel lab4 = new JLabel("���ۿ���:");
				JLabel lab5 = new JLabel("��       ��:");
				JLabel lab6 = new JLabel("��       ��:");
			//	JLabel lab2 = new JLabel("ְ������:");
				
				JButton jb0 = new JButton("��   ѯ");
				ImageIcon pic = new ImageIcon("e:\\ͼƬ\\�Ƽ�����.jpg");
				JLabel L_5 = new JLabel(pic);
				pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
				L_5.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
				lab1.setForeground(Color.white);
				lab2.setForeground(Color.white);
				lab3.setForeground(Color.white);
				lab4.setForeground(Color.white);
				lab5.setForeground(Color.white);
				lab6.setForeground(Color.white);
			//	lab7.setForeground(Color.white);
				
				lab1.setBounds(85, 20, 100, 20);
				lab2.setBounds(85, 60, 100, 20);
				lab3.setBounds(85, 100, 100, 20);
				lab4.setBounds(85, 140, 100, 20);
				lab5.setBounds(85, 180, 100, 20);
				lab6.setBounds(85, 220, 100, 20);
			//	lab7.setBounds(85, 260, 100, 20);
				t1.setBounds(140, 20, 200, 20);
				t2.setBounds(140, 60, 200, 20);
				t3.setBounds(140, 100, 200, 20);
				t4.setBounds(140, 140, 200, 20);
				t5.setBounds(140, 180, 200, 20);
				t6.setBounds(140, 220, 200, 20);
			//	t7.setBounds(140, 260, 200, 20);
				jb0.setBounds(160, 300, 120, 20);
				c2.add(t1);
				c2.add(t2);
				c2.add(t3);
				c2.add(t4);
				c2.add(t5);
				c2.add(t6);
			//	c2.add(t7);
				c2.add(lab1);
				c2.add(lab2);
				c2.add(lab3);
				c2.add(lab4);
				c2.add(lab5);
				c2.add(lab6);
			//	c2.add(lab7);
				c2.add(jb0);
				c2.add(L_5);
				closethis();
				windows3.addWindowListener(new WindowAdapter() {
				public void windowClosing(WindowEvent e) {
						openthis();
					}
				});
				jb0.addActionListener(new ActionListener() {

					@Override
					public void actionPerformed(ActionEvent e) {
						String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
						String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=����";
						String userName="sa";String userPwd="188754752";
						try{
							Class.forName(driverName);
							//System.out.println("���������ɹ���");
						}catch(Exception ex){
							ex.printStackTrace();
							System.out.println("��������ʧ�ܣ�");
						}
						try(Connection dbConn=DriverManager.getConnection(dbURL,userName,userPwd)){												
							try(Statement st = dbConn.createStatement()){
								try (ResultSet rs = st.executeQuery("SELECT stanum,bw,allo,whop,pm FROM wage WHERE stanum="+stan+"")){
									String stanum = null;
								//	String notp = null;
									int bw = 0;
									int allo = 0;
									int whop = 0;
									int pm = 0;
									int sum = 0;
									while(rs.next()) {
										stanum = rs.getString(1);										
									//	notp = rs.getString(2);
										bw = rs.getInt(2);
										allo = rs.getInt(3);
										whop = rs.getInt(4);
										pm = rs.getInt(5);
										sum = bw+allo+whop+pm;										
										t1.setText(stanum);
									//	t2.setText(notp);
										t2.setText(String.valueOf(bw));
										t3.setText(String.valueOf(allo));
										t4.setText(String.valueOf(whop));
										t5.setText(String.valueOf(pm));
										t6.setText(String.valueOf(sum));										
									}
									//System.out.println(bw);
								}
							}
							//System.out.println("�������ݿ�ɹ���");
							
							dbConn.close();
						}catch(Exception ex){
							ex.printStackTrace();
							System.out.print("SQL Server����ʧ�ܣ�");
						}
					}
				});
			}						
		});	   
	}
}
