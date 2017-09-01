package client;
import common.Student;

import java.awt.Event;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.nio.channels.ShutdownChannelGroupException;
import java.util.Scanner;

import javax.swing.*;

public class client extends JFrame{

	static Socket cs = null;
	static DataInputStream din = null;
	static DataOutputStream dout = null;
	static ObjectOutputStream oout = null;
    private static Scanner in = new Scanner(System.in);
    static JFrame MainUI = null;
    static JFrame InsertUI = null;
    static JFrame DeleteUI = null;
    
	public static void main(String[] args) throws IOException {
		try{
            cs = new Socket("localhost",3000);
            System.out.println("Client");
			din = new DataInputStream(cs.getInputStream());
			dout = new DataOutputStream(cs.getOutputStream());
            oout = new ObjectOutputStream(cs.getOutputStream());
            
            ShowMainUI();
			/*int input,roll;
			do
			{
				System.out.println("1 Insert new student");
				System.out.println("2 Show database");
				System.out.println("3 Delete student");
				System.out.println("4 Show failed students");
				System.out.println("5 Search student");
				System.out.println("6 Calculate average of students");
				input = in.nextInt();
				sw
					case 5:
                        dout.writeInt(5);
						System.out.println("Enter roll no. of student");
						roll = in.nextInt();
						dout.writeInt(roll);
						System.out.println(din.readUTF());
                        break;
                    case 6:
                        dout.writeInt(6);
                        System.out.println("Average marks of students\n");
						System.out.println(din.readUTF());
						break;
					default:
						break;
				}
				System.out.println("Enter 0 to continue ");
				input = in.nextInt();
				dout.writeInt(input);
			}while(input==0);*/
            //dout.close();   //Close data output stream
            //cs.close();     //Close socket
		}
		catch(Exception e){
			System.out.println(e);
		}
		finally
		{
/*			System.out.println("Closing client");
			cs.close();
			din.close();
			dout.close();
			oout.close();*/
			
		}

	}
	
	static void ShowMainUI()
	{
		MainUI = new JFrame("Client");
		MainUI.setSize(350, 400);
		//Insert
		JButton Button_Insert = new JButton("Insert");
		Button_Insert.setBounds(10, 10, 100, 25);
		Button_Insert.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				ShowInsertUI();
				MainUI.setVisible(false);
				
				
			}
		});
		//Show
		JButton Button_ShowDB = new JButton("Show Database");
		Button_ShowDB.setBounds(10, 50, 150, 25);
		Button_ShowDB.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				try
				{
					dout.writeInt(2);

                String value = "Roll---Name-----Marks---Class\n";
                value += din.readUTF();
				JOptionPane.showMessageDialog(MainUI,value );
				}
				catch(IOException e)
				{
					e.printStackTrace();
				}
			}
		});
		//Delete
		JButton Button_Delete = new JButton("Delete Student");
		Button_Delete.setBounds(10, 90, 150, 25);
		Button_Delete.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				ShowDeleteUI();
				MainUI.setVisible(false);
			}
		});
		//Failed
		JButton Button_ShowFS = new JButton("Failed Students");
		Button_ShowFS.setBounds(10, 130, 150, 25);
		Button_ShowFS.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				try{
					dout.writeInt(4);
					String res = "Roll---Name----Marks----Class\n";
					res+=din.readUTF();
					JOptionPane.showMessageDialog(MainUI,res);
				}
				catch(Exception e)
				{
					e.printStackTrace();
				}
			}
		});
		//Search
		JButton Button_Search = new JButton("Search Student");
		Button_Search.setBounds(10, 170, 150, 25);
		Button_Search.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				ShowSearchUI();
				MainUI.setVisible(false);
				
			}
		});
		//Average
		JButton Button_Average = new JButton("Average Marks");
		Button_Average.setBounds(10, 210, 150, 25);
		Button_Average.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				try
				{
					dout.writeInt(6);
					String result = "Average marks of all students\n";
					result+=din.readUTF();
					JOptionPane.showMessageDialog(MainUI,result);
				}catch(Exception E)
				{
					E.printStackTrace();
				}
			}
		});
		MainUI.setLayout(null);
		MainUI.add(Button_ShowDB);
		MainUI.add(Button_Insert);
		MainUI.add(Button_Delete);
		MainUI.add(Button_ShowFS);
		MainUI.add(Button_Search);
		MainUI.add(Button_Average);
		MainUI.setVisible(true);
		
	}
	static void ShowDeleteUI()
	{
		DeleteUI = new JFrame("Delete Student");
		DeleteUI.setSize(350, 400);
		JLabel Label_RollNo = new JLabel("Roll No.:");
		Label_RollNo.setBounds(10, 10, 100, 25);
		JTextField Text_Roll = new JTextField();
		Text_Roll.setBounds(150,10,100,25);
		JButton Button_Delete = new JButton("Delete");
		Button_Delete.setBounds(150,50,100,25);
		Button_Delete.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				try
				{
					
				
					String inp = Text_Roll.getText();
					if(inp.equals(""))
						JOptionPane.showMessageDialog(DeleteUI,"Enter a roll number");
					else
					{
						dout.writeInt(3);
						int r = Integer.parseInt(inp);
						System.out.println(r);
						dout.writeInt(r);
						JOptionPane.showMessageDialog(DeleteUI,din.readUTF());
					}
				}
				catch(IOException e)
				{
					e.printStackTrace();
				}
			}
		});
		JButton Button_Back = new JButton("Back");
		Button_Back.setBounds(10, 250, 75, 25);
		Button_Back.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				MainUI.setVisible(true);
				DeleteUI.setVisible(false);
			}
		});
		DeleteUI.add(Text_Roll);
		DeleteUI.add(Label_RollNo);
		DeleteUI.add(Button_Back);
		DeleteUI.add(Button_Delete);
		DeleteUI.setLayout(null);
		DeleteUI.setVisible(true);
	}
	static void ShowInsertUI()
	{
		InsertUI = new JFrame("Insert Student");
		InsertUI.setSize(350, 400);
		
		JButton Button_Back = new JButton("Back");
		Button_Back.setBounds(10, 300, 75, 25);
		Button_Back.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				MainUI.setVisible(true);
				InsertUI.setVisible(false);
			}
		});
		JLabel Label_Roll = new JLabel("Roll No");
		Label_Roll.setBounds(10, 10, 100, 25);
		JLabel Label_Name = new JLabel("Name");
		Label_Name.setBounds(10, 40, 100, 25);
		JLabel Label_Marks = new JLabel("Marks");
		Label_Marks.setBounds(10, 70, 100, 25);
		JLabel Label_Class = new JLabel("Class");
		Label_Class.setBounds(10, 100, 100, 25);
		JTextField Text_Roll = new JTextField();
		Text_Roll.setBounds(120, 10, 100, 25);
		JTextField Text_Name = new JTextField();
		Text_Name.setBounds(120, 40, 100, 25);
		JTextField Text_Marks = new JTextField();
		Text_Marks.setBounds(120, 70, 100, 25);
		JTextField Text_Class = new JTextField();
		Text_Class.setBounds(120, 100, 100, 25);
		JButton Button_Insert = new JButton("Insert");
		Button_Insert.setBounds(100, 150, 100, 25);
		Button_Insert.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent arg0) {
				try
				{

					String inp_Roll = Text_Roll.getText();
					String inp_Name = Text_Name.getText();
					String inp_Class = Text_Class.getText();
					String inp_Marks = Text_Marks.getText();
					if(inp_Roll.equals("")||inp_Name.equals("")||inp_Class.equals("")||inp_Marks.equals(""))
						JOptionPane.showMessageDialog(InsertUI,"Insert all values");
					else
					{
						dout.writeInt(1);
						Student temp = new Student();
                        temp.InsertNewRecord(inp_Name,inp_Class,Integer.parseInt(inp_Roll),Float.parseFloat(inp_Marks));
                        oout.writeObject(temp);
                        JOptionPane.showMessageDialog(InsertUI,din.readUTF());
					}
				}
				catch(IOException e)
				{
					e.printStackTrace();
				}
			}
		});
		InsertUI.add(Text_Roll);
		InsertUI.add(Text_Name);
		InsertUI.add(Text_Marks);
		InsertUI.add(Text_Class);
		InsertUI.add(Label_Roll);
		InsertUI.add(Label_Name);
		InsertUI.add(Label_Marks);
		InsertUI.add(Label_Class);
		InsertUI.add(Button_Insert);
		InsertUI.add(Button_Back);
		InsertUI.setLayout(null);
		InsertUI.setVisible(true);
	}
	static void ShowSearchUI()
	{
		JFrame SearchUI = new JFrame("Search Student");
		SearchUI.setSize(350, 400);
		JLabel Label_RollNo = new JLabel("Roll No.:");
		Label_RollNo.setBounds(10, 10, 100, 25);
		JTextField Text_Roll = new JTextField();
		Text_Roll.setBounds(150,10,100,25);
		JButton Button_Search = new JButton("Search");
		Button_Search.setBounds(150,50,100,25);
		Button_Search.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				try
				{
					
				
					String inp = Text_Roll.getText();
					if(inp.equals(""))
						JOptionPane.showMessageDialog(SearchUI,"Enter a roll number");
					else
					{
						dout.writeInt(5);
						int r = Integer.parseInt(inp);
						System.out.println(r);
						dout.writeInt(r);
						JOptionPane.showMessageDialog(SearchUI,din.readUTF());
					}
				}
				catch(IOException e)
				{
					e.printStackTrace();
				}
			}
		});
		JButton Button_Back = new JButton("Back");
		Button_Back.setBounds(10, 250, 75, 25);
		Button_Back.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				MainUI.setVisible(true);
				SearchUI.setVisible(false);
			}
		});
		SearchUI.add(Text_Roll);
		SearchUI.add(Label_RollNo);
		SearchUI.add(Button_Back);
		SearchUI.add(Button_Search);
		SearchUI.setLayout(null);
		SearchUI.setVisible(true);
	}
}
