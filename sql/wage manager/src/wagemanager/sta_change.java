package wagemanager;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowStateListener;
import java.security.PKCS12Attribute;
import java.sql.*;
import java.util.Vector;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
public class sta_change extends JFrame{
	public  void create_stacha() {
		setTitle("Ա����Ϣ");		
		Container c1 = getContentPane();
		setLayout(null);			
		setSize(500, 400);
		setLocation(500, 300);
		setVisible(true);	
		ImageIcon pic = new ImageIcon("e:\\ͼƬ\\�Ƽ�����.jpg");
		JLabel L2 = new JLabel(pic);
		pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
		L2.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
		JButton button1 = new JButton("�޸�");
		JTextField t1 = new JTextField(null);
		JTextField t2 = new JTextField(null);
		//JTextField t3 = new JTextField(20);
		//JTextField t4 = new JTextField(20);
		JTextField t5 = new JTextField(null);
		//JTextField t6 = new JTextField(20);
		JTextField t7 = new JTextField(null);
		JTextField t8 = new JTextField(null);
		JLabel lab1 = new JLabel("Ա  �� ��:");
		JLabel lab2 = new JLabel("Ա������:");
		//JLabel lab3 = new JLabel("Ա���Ա�:");
		//JLabel lab4 = new JLabel("ְ������:");
		JLabel lab5 = new JLabel("ְ����:");
		//JLabel lab6 = new JLabel("��       ��:");
		JLabel lab7 = new JLabel("���ʵȼ�:");
		JLabel lab8 = new JLabel("��  ��  ��:");
		lab1.setForeground(Color.white);
		lab2.setForeground(Color.white);
		lab5.setForeground(Color.white);
		lab7.setForeground(Color.white);
		lab8.setForeground(Color.white);
		lab1.setBounds(85, 20, 200, 20);
		lab2.setBounds(85, 60, 200, 20);
		//lab3.setBounds(85, 80, 200, 20);
		//lab4.setBounds(85, 80, 200, 20);
		lab5.setBounds(85, 100, 200, 20);
		//lab6.setBounds(85, 170, 200, 20);
		lab7.setBounds(85, 140, 200, 20);
		lab8.setBounds(85, 180, 200, 20);
		button1.setBounds(160, 250, 120, 20);
		t1.setBounds(140, 20, 200, 20);
		t2.setBounds(140, 60, 200, 20);
		//t3.setBounds(140, 80, 200, 20);
		//t4.setBounds(140, 80, 200, 20);
		t5.setBounds(140, 100, 200, 20);
		//t6.setBounds(140, 170, 200, 20);
		t7.setBounds(140, 140, 200, 20);
		t8.setBounds(140, 180, 200, 20);
		c1.add(t1);
		c1.add(t2);
		//c1.add(t3);
		//c1.add(t4);
		c1.add(t5);
		//c1.add(t6);
		c1.add(t7);
		c1.add(t8);
		c1.add(lab1);
		c1.add(lab2);
		//c1.add(lab3);
		//c1.add(lab4);
		c1.add(lab5);
		//c1.add(lab6);
		c1.add(lab7);
		c1.add(lab8);
		c1.add(button1);
		c1.add(L2);
		button1.addActionListener(new ActionListener() {		
			@Override
			public void actionPerformed(ActionEvent e) {				
				try {
					String driverName = "com.microsoft.sqlserver.jdbc.SQLServerDriver";// �������ݿ�
					String dbURL = "jdbc:sqlserver://localhost:1433;DatabaseName=����";
					String userName = "sa";
					String userPwd = "188754752";
					String usr = t1.getText();
					Class.forName(driverName);
					try {
						Connection dbConn = DriverManager.getConnection(dbURL, userName, userPwd);
						int count2 = 0;
						int count4 = 0;
						int count5 = 0;
						int count6 = 0;
						if(!t2.getText().trim().equals("")) {
							String sql2 = "update staff set staname  = ? where  stanum="+ usr + "";
							PreparedStatement ps2 = dbConn.prepareStatement(sql2);
							ps2.setString(1, t2.getText());
							count2 = ps2.executeUpdate();
						}
						if(!t5.getText().trim().equals("")) {
							String sql4 = "update staff set dtnum  = ? where  stanum="+ usr + "";
							PreparedStatement ps4 = dbConn.prepareStatement(sql4);
							ps4.setString(1, t5.getText());
							count4 = ps4.executeUpdate();
						}
						if(!t7.getText().trim().equals("")) {
							String sql5 = "update staff set wbk  = ? where  stanum="+ usr + "";
							PreparedStatement ps5 = dbConn.prepareStatement(sql5);
							ps5.setString(1, t7.getText());
							count5 = ps5.executeUpdate();
						}
						if(!t8.getText().trim().equals("")) {
							String sql6 = "update staff set depnum  = ? where  stanum="+ usr + "";
							PreparedStatement ps6 = dbConn.prepareStatement(sql6);	
							ps6.setString(1, t8.getText());
							count6 = ps6.executeUpdate();
						}
						
						if (count2 > 0) {
							System.out.println("Ա�������޸ĳɹ�");
						}
						if(count4 > 0) {
							System.out.println("ְ�����޸ĳɹ�");
						}
						if(count5 > 0) {
							System.out.println("���ʵȼ��޸ĳɹ�");
						}
						if(count6 > 0) {
							System.out.println("���ź��޸ĳɹ�");
						}
						if(!(count2 > 0||count4 > 0||count5 > 0||count6 > 0)){
							System.out.println("�޸�ʧ��");
							JOptionPane.showMessageDialog(null, "�޸�ʧ�ܣ�", "����",
									JOptionPane.ERROR_MESSAGE);
						}
						dbConn.close();
					} catch (SQLException e1) {

						e1.printStackTrace();
						// System.out.println("���������ɹ���");
						JOptionPane.showMessageDialog(null, "���ݿ�����ʧ�ܣ�", "����",
								JOptionPane.ERROR_MESSAGE);

					}

				} catch (Exception ex) {
					ex.printStackTrace();
					System.out.println("��������ʧ�ܣ�");
					JOptionPane.showMessageDialog(null, "��������ʧ�ܣ�", "����", JOptionPane.ERROR_MESSAGE);
				}
				
				
			}
		});
		
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);

	}
	public static void main(String[] args) {
		sta_change ss = new sta_change();
		ss.create_stacha();
	}
}
