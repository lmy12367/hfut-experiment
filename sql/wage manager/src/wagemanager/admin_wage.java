package wagemanager;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import javax.swing.*;
import javax.swing.table.*;


public class admin_wage extends JFrame{
	public void create_adwage() {
		setSize(500, 400);
		setLocation(500, 300);
		setLayout(null);
		ImageIcon pic = new ImageIcon("e:\\图片\\科技背景.jpg");
		JLabel L2 = new JLabel(pic);
		pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
		L2.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
		JButton click = new JButton("查询工资");
		JButton change = new JButton("修改工资");
		click.setBounds(150, 100, 200, 75);
		change.setBounds(150, 210, 200, 75);
		add(click);
		add(change);
		add(L2);
		setVisible(true);
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		click.addActionListener(new ActionListener() {			
			@Override
			public void actionPerformed(ActionEvent e) {
				JFrame w2 = new JFrame("查询工资");
				w2.setBounds(500, 300, 600, 445);
				w2.setLayout(null);
				DefaultTableModel model=new DefaultTableModel();
				JTable table=new JTable(model);
				JScrollPane jsp=new JScrollPane(table);
				jsp.setBounds(0, 0, 585, 400);
				w2.add(jsp);
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
					try(Statement st = dbConn.createStatement()){
						try (ResultSet rs = st.executeQuery("SELECT * FROM wage")){
							ResultSetMetaData rsmd=rs.getMetaData();
						    int numb=rsmd.getColumnCount();
						    for(int i=1;i<=numb;i++){
						    	model.addColumn(rsmd.getColumnName(i));
						    }
						    String[] row=new String[numb];
							while(rs.next()) {
					    		//将查询到的每行数据赋入数组内
					    		for(int i=0;i<numb;i++)
					    			row[i]=rs.getString(i+1);
					    		model.addRow(row);
							}
							//System.out.println(bw);
						}
					}
					//System.out.println("连接数据库成功！");
					
					dbConn.close();
				}catch(Exception ea){
					ea.printStackTrace();System.out.print("SQL Server连接失败！");
				}
				
				w2.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
				w2.setVisible(true);
			}
					
			
		});
		change.addActionListener(new ActionListener() {			
			@Override
			public void actionPerformed(ActionEvent e) {
				JFrame wch = new JFrame("修改工资");
				wch.setBounds(500, 300, 500, 400);
				wch.setLayout(null);
				JTextField t1 = new JTextField(10);
				JTextField t2 = new JTextField(10);
				JTextField t3 = new JTextField(10);
				JTextField t4 = new JTextField(10);
				JTextField t5 = new JTextField(10);
				JLabel lab1 = new JLabel("员  工 号:");
				JLabel lab2 = new JLabel("基本工资:");
				JLabel lab3 = new JLabel("津       贴:");
				JLabel lab4 = new JLabel("代扣款项:");
				JLabel lab5 = new JLabel("奖       金:");
				JButton jb0 = new JButton("修     改");
				ImageIcon pic = new ImageIcon("e:\\图片\\科技背景.jpg");
				JLabel L_5 = new JLabel(pic);
				pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
				L_5.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
				lab1.setForeground(Color.white);
				lab2.setForeground(Color.white);
				lab3.setForeground(Color.white);
				lab4.setForeground(Color.white);
				lab5.setForeground(Color.white);				
				lab1.setBounds(85, 20, 100, 20);
				lab2.setBounds(85, 60, 100, 20);
				lab3.setBounds(85, 100, 100, 20);
				lab4.setBounds(85, 140, 100, 20);
				lab5.setBounds(85, 180, 100, 20);
				t1.setBounds(140, 20, 200, 20);
				t2.setBounds(140, 60, 200, 20);
				t3.setBounds(140, 100, 200, 20);
				t4.setBounds(140, 140, 200, 20);
				t5.setBounds(140, 180, 200, 20);
				jb0.setBounds(160, 300, 120, 20);
				wch.add(t1);
				wch.add(t2);
				wch.add(t3);
				wch.add(t4);
				wch.add(t5);
				wch.add(lab1);
				wch.add(lab2);
				wch.add(lab3);
				wch.add(lab4);
				wch.add(lab5);
				wch.add(jb0);
				wch.add(L_5);
				wch.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
				wch.setVisible(true);
				jb0.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						
						try {
							String driverName = "com.microsoft.sqlserver.jdbc.SQLServerDriver";// 连接数据库
							String dbURL = "jdbc:sqlserver://localhost:1433;DatabaseName=课设";
							String userName = "sa";
							String userPwd = "188754752";
							String usr = t1.getText();
							Class.forName(driverName);
							try {
								Connection dbConn = DriverManager.getConnection(dbURL, userName, userPwd);
								int count2 = 0;
								int count3 = 0;
								int count4 = 0;
								int count5 = 0;
								if(!t2.getText().trim().equals("")) {
									String sql3 = "update wage set bw  = ? where  stanum="+ usr + "";
									PreparedStatement ps3 = dbConn.prepareStatement(sql3);
									ps3.setString(1, t2.getText());
									count2 = ps3.executeUpdate();
								}
								if(!t3.getText().trim().equals("")) {
									String sql4 = "update wage set allo  = ? where  stanum="+ usr + "";									
									PreparedStatement ps4 = dbConn.prepareStatement(sql4);
									ps4.setString(1, t3.getText());
									count3 = ps4.executeUpdate();
								}
								if(!t4.getText().trim().equals("")) {
									String sql5 = "update wage set whop  = ? where  stanum="+ usr + "";
									PreparedStatement ps5 = dbConn.prepareStatement(sql5);
									ps5.setString(1, t4.getText());
									count4 = ps5.executeUpdate();
								}
								if(!t5.getText().trim().equals("")) {
									String sql6 = "update wage set pm  = ? where  stanum="+ usr + "";
									PreparedStatement ps6 = dbConn.prepareStatement(sql6);
									ps6.setString(1, t5.getText());
									count5 = ps6.executeUpdate();
								}

								if (count2 > 0) {
									System.out.println("基本工资修改成功");
								}if(count3 > 0) {
									System.out.println("津贴修改成功");
								}if(count4 >0) {
									System.out.println("代扣款项修改成功");
								}if(count5>0) {
									System.out.println("奖金修改成功");
								}
								if(!(count2 > 0||count3 > 0||count4 > 0||count5 > 0)) {
									System.out.println("修改失败");
									JOptionPane.showMessageDialog(null, "修改失败！", "错误",
											JOptionPane.ERROR_MESSAGE);
								}
								dbConn.close();
							} catch (SQLException e1) {

								e1.printStackTrace();
								// System.out.println("加载驱动成功！");
								JOptionPane.showMessageDialog(null, "数据库连接失败！", "错误",
										JOptionPane.ERROR_MESSAGE);

							}

						} catch (Exception ex) {
							ex.printStackTrace();
							System.out.println("加载驱动失败！");
							JOptionPane.showMessageDialog(null, "加载驱动失败！", "错误", JOptionPane.ERROR_MESSAGE);
						}
						
					}
				});	
			}
		});
	}

	public static void main(String[] args) {
	
	//

	}
}
