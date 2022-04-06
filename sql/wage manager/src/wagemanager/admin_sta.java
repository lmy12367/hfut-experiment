package wagemanager;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import javax.swing.*;
import javax.swing.table.*;




public class admin_sta extends JFrame{
	public void create_adsta() {
		JFrame windows2 = new JFrame("管理员工窗");
		windows2.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		windows2.setSize(500, 400);
		windows2.setLocation(500, 300);
		Container co = windows2.getContentPane();
		// JPanel p = new JPanel();
		co.setLayout(null);
		ImageIcon pic = new ImageIcon("e:\\图片\\科技背景.jpg");
		JLabel L2 = new JLabel(pic);
		pic.setImage(pic.getImage().getScaledInstance(500, 400,Image.SCALE_DEFAULT));
		L2.setBounds(0, 0, pic.getIconWidth(), pic.getIconHeight());
		
		JButton b1 = new JButton("查询员工信息");
		JButton b2 = new JButton("修改员工信息");
		JButton b3 = new JButton("增加员工信息");
		JButton b4 = new JButton("删除员工信息");

		b1.setBounds(60, 50, 150, 30);
		b2.setBounds(260, 50, 150, 30);
		b3.setBounds(60, 100, 150, 30);
		b4.setBounds(260, 100, 150, 30);
		
		co.add(b1);
		co.add(b2);
		co.add(b3);
		co.add(b4);
		co.add(L2);
		windows2.setVisible(true);
		
	    b1.addActionListener(new ActionListener() {			
			@Override
			public void actionPerformed(ActionEvent e) {
				JFrame w2 = new JFrame("查询员工信息");
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
						try (ResultSet rs = st.executeQuery("SELECT * FROM staff")){
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
	    b2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				sta_change stach = new sta_change();
				stach.create_stacha();
			}
	    });
	    b3.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				sta_add s1 = new sta_add();
				s1.create_sta_add();
			}
	    });
	    b4.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				sta_delete d1 = new sta_delete();
				d1.create_stadel();
					
			}
	    });
		
}
	
	public static void main(String[] args) {
	
		admin_sta ad = new admin_sta();
		ad.create_adsta();

	}
	
}
