package wagemanager;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import java.sql.*;

public class sta_delete extends JFrame{
	public void create_stadel() {
		setSize(500, 400);
		setLocation(500, 300);
		setLayout(null);
		ImageIcon pic = new ImageIcon("e:\\ͼƬ\\�Ƽ�����.jpg");
		JLabel L2 = new JLabel(pic);
		pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
		L2.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
		
		JLabel dellab = new JLabel("��������Ҫɾ��Ա����Ա����");
		dellab.setFont(new Font (Font.DIALOG, Font.BOLD, 14));
		dellab.setForeground(Color.white);
		JButton delbtn = new JButton("ɾ��");
		JTextField del = new JTextField();
		dellab.setBounds(150, 60, 200, 40);
		del.setBounds(150, 100, 200, 30);
		delbtn.setBounds(200, 180, 100, 30);
		add(dellab);
		add(del);
		add(delbtn);
		add(L2);
		setVisible(true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		delbtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
				String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=����";
				String userName="sa";String userPwd="188754752";
				try{
					Class.forName(driverName);
					//System.out.println("���������ɹ���");
				}catch(Exception ea){
					ea.printStackTrace();System.out.println("��������ʧ�ܣ�");
				}
				
				try(Connection dbConn=DriverManager.getConnection(dbURL,userName,userPwd)){
					try(PreparedStatement st = dbConn.prepareStatement("delete from staff where stanum = "+del.getText()+"")){
						
						st.executeUpdate();
					}
					//System.out.println("�������ݿ�ɹ���");
					try(PreparedStatement st = dbConn.prepareStatement("delete from wage where stanum = "+del.getText()+"")){	
						st.executeUpdate();
					}
					dbConn.close();
				}catch(Exception ea){
					ea.printStackTrace();System.out.print("SQL Server����ʧ�ܣ�");
				}
			}
		});
	}
}
