import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

import javax.swing.*;
public class DBConnect {
	 static Connection con =null;
	 static Statement stmt = null;
	public static void DrawWindow()
	{
		JFrame frame = new JFrame();
		frame.setSize(500, 600);
		
		JButton bInsert = new JButton("Insert");
		JButton bDelete = new JButton("Delete");
		JButton bUpdate = new JButton("Update");
		JButton bSelect = new JButton("Show DB");
		bInsert.setBounds(100,300,100,50);
		bDelete.setBounds(300,300,100,50);
		bUpdate.setBounds(100,400,100,50);
		bSelect.setBounds(300,400,100,50);
		
		JLabel liCode = new JLabel("iCode");
		JLabel liname = new JLabel("iname");
		JLabel lPurchaseDate = new JLabel("purchaseDate");
		JLabel lPrice = new JLabel("Price");
		liCode.setBounds(100,100,100,50);
		liname.setBounds(100,150,100,50);
		lPurchaseDate.setBounds(100,200,100,50);
		lPrice.setBounds(100,250,100,50);
		
		final JTextField tfiCode = new JTextField();
		final JTextField tfname = new JTextField();
		final JTextField tfPurchaseDate = new JTextField();
		final JTextField tfPrice = new JTextField();
		tfiCode.setBounds(200, 120, 100, 25);
		tfname.setBounds(200, 170, 100, 25);
		tfPurchaseDate.setBounds(200, 210, 100, 25);
		tfPrice.setBounds(200, 260, 100, 25);
		
		bInsert.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String siCode = tfiCode.getText();
				String sName = tfname.getText();
				String sPurchaseDate = tfPurchaseDate.getText();
				String sPrice = tfPrice.getText();
				if(siCode.equals("")||sName.equals("")||sPurchaseDate.equals("")||sPrice.equals(""))
				{
					JOptionPane.showMessageDialog(frame, "Please enter all the details");
				}
				else
				{
					try
					{
						stmt.execute("Insert into INSTRUMENT values("+Integer.parseInt(siCode)+",'"+sName+"','"+sPurchaseDate+"','"+Float.parseFloat(sPrice)+"')");
						JOptionPane.showMessageDialog(frame, "Successfully inserted");
						//System.out.println("Insert into Details values("+Integer.parseInt(sRoll)+",'"+sName+"','"+sBranch+"')");
					}
					catch(SQLIntegrityConstraintViolationException E)
					{
						JOptionPane.showMessageDialog(frame, "Record already exists");
					}
					catch(Exception E)
					{
						E.printStackTrace();
						JOptionPane.showMessageDialog(frame, "Error Inserting");
					}
				}
				
			}
		});
		bDelete.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String siCode = tfiCode.getText();
				String sName = tfname.getText();
				String sPurchaseDate = tfPurchaseDate.getText();
				String sPrice = tfPrice.getText();
				if(siCode.equals("")&&sName.equals("")&&sPurchaseDate.equals("")&&sPrice.equals(""))
				{
					JOptionPane.showMessageDialog(frame, "Please few details to identify the value");
				}
				else
				{
					int icode=-1;
					float price=-1;
					String name, purchasedate;
					if(siCode.equals(""))
						icode = -1;
					else
						icode = Integer.parseInt(siCode);
					if(sName.equals(""))
						name = "-1";
					else
						name = sName;
					if(sPurchaseDate.equals(""))
						purchasedate = "-1";
					else
						purchasedate = sPurchaseDate;
					if(sPrice.equals(""))
						price = -1;
					else
						price = Float.parseFloat(sPrice);
					try
					{
						stmt.execute("Delete from INSTRUMENT where iCode="+icode+" OR iname='"+name+"' OR purchaseDate='"+purchasedate+"' OR price="+price);
						System.out.println("Delete from INSTRUMENT where iCode="+icode+" OR iname='"+name+"' OR purchaseDate='"+purchasedate+"' OR price="+price);
						//JOptionPane.showMessageDialog(frame, "Successfully Deleted");
						//System.out.println("Insert into Details values("+Integer.parseInt(sRoll)+",'"+sName+"','"+sBranch+"')");
					}
					catch(SQLIntegrityConstraintViolationException E)
					{
						JOptionPane.showMessageDialog(frame, "Integrity constraint error");
					}
					catch(Exception E)
					{
						E.printStackTrace();
						JOptionPane.showMessageDialog(frame, "Error Deleting");
					}
				}
				
			}
		});
		bSelect.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
					try
					{
						String savestr = "iCode---iName------Purchase date--Price\n";
						ResultSet rs = stmt.executeQuery("Select * from INSTRUMENT");
						//System.out.println("Delete from INSTRUMENT where iCode="+icode+" OR iname='"+name+"' OR purchaseDate='"+purchasedate+"' OR price="+price);
						while(rs.next())
							savestr+=rs.getInt(1)+"---"+rs.getString(2)+"----"+rs.getString(3)+"----"+rs.getFloat(4)+"\n";
						//System.out.println("Insert into Details values("+Integer.parseInt(sRoll)+",'"+sName+"','"+sBranch+"')");
						JOptionPane.showMessageDialog(frame, savestr);
					}
					catch(SQLIntegrityConstraintViolationException E)
					{
						JOptionPane.showMessageDialog(frame, "Integrity constraint error");
					}
					catch(Exception E)
					{
						E.printStackTrace();
						JOptionPane.showMessageDialog(frame, "Error Retrieving");
					}
				}
				
		});
		bUpdate.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String siCode = tfiCode.getText();
				String sName = tfname.getText();
				String sPurchaseDate = tfPurchaseDate.getText();
				String sPrice = tfPrice.getText();
				if(siCode.equals("")||sName.equals("")||sPurchaseDate.equals("")||sPrice.equals(""))
				{
					JOptionPane.showMessageDialog(frame, "Please fill all details");
				}
				else
				{
					JOptionPane.showMessageDialog(frame, "Usage: updates all values where iCode maches");

					try
					{
						stmt.execute("Update INSTRUMENT set iname='"+sName+"', purchaseDate='"+sPurchaseDate+"', price='"+Float.parseFloat(sPrice)+"' where iCode="+Integer.parseInt(siCode));
						
					}
					catch(SQLIntegrityConstraintViolationException E)
					{
						JOptionPane.showMessageDialog(frame, "Integrity constraint error");
					}
					catch(Exception E)
					{
						E.printStackTrace();
						JOptionPane.showMessageDialog(frame, "Error Updating");
					}
				}
				
			}
		});
		frame.add(bInsert);
		frame.add(bDelete);
		frame.add(bUpdate);
		frame.add(bSelect);
		frame.add(liCode);
		frame.add(liname);
		frame.add(lPrice);
		frame.add(lPurchaseDate);
		frame.add(tfiCode);
		frame.add(tfname);
		frame.add(tfPrice);
		frame.add(tfPurchaseDate);
		frame.setLayout(null);
		frame.setVisible(true);
	}
	public static void main(String[] args)
	{
		
		try
	    {
	    Class.forName("com.mysql.jdbc.Driver");
	    con=DriverManager.getConnection("jdbc:mysql://localhost:3306/EMINEM","root","root");
	    stmt=con.createStatement();
	    stmt.execute("create table if not exists INSTRUMENT (iCode int primary key, iname varchar(20), purchaseDate varchar(20), price float(5,2))");
	    }
		catch(Exception e){ 
			System.out.println(e);
	    }
		DrawWindow();
	}
}
/*Table details
 *  create table Details (Id int primary key, Name varchar(255), Branch varchar(255));
 * 
*/
