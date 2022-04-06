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
		ImageIcon pic = new ImageIcon("e:\\图片\\科技背景.jpg");
		JLabel L2 = new JLabel(pic);
		pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
		L2.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
		
		JLabel dellab = new JLabel("请输入想要删除员工的员工号");
		dellab.setFont(new Font (Font.DIALOG, Font.BOLD, 14));
		dellab.setForeground(Color.white);
		JButton delbtn = new JButton("删除");
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
				String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=课设";
				String userName="sa";String userPwd="188754752";
				try{
					Class.forName(driverName);
					//System.out.println("加载驱动成功！");
				}catch(Exception ea){
					ea.printStackTrace();System.out.println("加载驱动失败！");
				}
				
				try(Connection dbConn=DriverManager.getConnection(dbURL,userName,userPwd)){
					try(PreparedStatement st = dbConn.prepareStatement("delete from staff where stanum = "+del.getText()+"")){
						
						st.executeUpdate();
					}
					//System.out.println("连接数据库成功！");
					try(PreparedStatement st = dbConn.prepareStatement("delete from wage where stanum = "+del.getText()+"")){	
						st.executeUpdate();
					}
					dbConn.close();
				}catch(Exception ea){
					ea.printStackTrace();System.out.print("SQL Server连接失败！");
				}
			}
		});
	}
}
