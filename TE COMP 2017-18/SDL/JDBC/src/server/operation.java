package server;
import common.Student;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class operation {
	
	public static void AddStudent(Student s) throws SQLException, ClassNotFoundException
	{
		Class.forName("com.mysql.jdbc.Driver");
		Connection connectSQL = DriverManager.getConnection("jdbc:mysql://localhost:3306/JDBC?useSSL=true","root","root");
		PreparedStatement query1 = connectSQL.prepareStatement("Insert into students values(?,?,?,?)");
        query1.setInt(1,s.GetRoll());
        query1.setString(2, s.GetName());
        query1.setFloat(3, s.GetMarks());
        query1.setString(4, s.GetClass());
        query1.execute();
	}
	public static String ShowDatabase() throws SQLException, ClassNotFoundException
	{
		Class.forName("com.mysql.jdbc.Driver");
		Connection connectSQL = DriverManager.getConnection("jdbc:mysql://localhost:3306/JDBC?useSSL=true","root","root");
		String senddata2 = new String();
    	PreparedStatement query2 = connectSQL.prepareStatement("Select * from students");
    	ResultSet rs = query2.executeQuery();
		while(rs.next())
			senddata2+=rs.getInt(1)+"\t"+rs.getString(2)+"\t"+rs.getFloat(3)+"\t"+rs.getString(4)+"\n";
    	return senddata2;
	}
	public static String Delete(int roll) throws SQLException, ClassNotFoundException
	{
		String ret;
		Class.forName("com.mysql.jdbc.Driver");
		Connection connectSQL = DriverManager.getConnection("jdbc:mysql://localhost:3306/JDBC?useSSL=true","root","root");
		PreparedStatement query3 = connectSQL.prepareStatement("delete from students where Roll=?");
        query3.setInt(1, roll);
		try {
			query3.execute();
			ret = "Successfully deleted";
		}
		catch(Exception e)
		{
			ret = "Could not find student";
		}
		return ret;
	}
	public static String ShowFailedStudents() throws SQLException, ClassNotFoundException
	{
		String ret = new String();
		Class.forName("com.mysql.jdbc.Driver");
		Connection connectSQL = DriverManager.getConnection("jdbc:mysql://localhost:3306/JDBC?useSSL=true","root","root");
		PreparedStatement query4 = connectSQL.prepareStatement("Select * from students where Marks<=40");
    	ResultSet rs3 = query4.executeQuery();
		while(rs3.next())
			ret+=rs3.getInt(1)+"\t"+rs3.getString(2)+"\t"+rs3.getFloat(3)+"\t"+rs3.getString(4)+"\n";
		return ret;
	}
	public static String Search(int roll) throws SQLException, ClassNotFoundException
	{
		String ret = "Not found!";
		Class.forName("com.mysql.jdbc.Driver");
		Connection connectSQL = DriverManager.getConnection("jdbc:mysql://localhost:3306/JDBC?useSSL=true","root","root");
		PreparedStatement query5 = connectSQL.prepareStatement("Select * from students where Roll="+roll);
        ResultSet rs5 = query5.executeQuery();
        if(rs5.next())
        	ret = (rs5.getInt(1)+"\t"+rs5.getString(2)+"\t"+rs5.getFloat(3)+"\t"+rs5.getString(4)+"\n");
        
		return ret;
	}
	public static String CalculateAverage() throws SQLException, ClassNotFoundException
	{
		String ret = "Not found!";
		Class.forName("com.mysql.jdbc.Driver");
		Connection connectSQL = DriverManager.getConnection("jdbc:mysql://localhost:3306/JDBC?useSSL=true","root","root");
		PreparedStatement query6 = connectSQL.prepareStatement("Select avg(Marks) from students");
        ResultSet rs6 = query6.executeQuery();
        if(rs6.next())
        	ret = (rs6.getFloat(1)+"\n");
		return ret;
	}
}
