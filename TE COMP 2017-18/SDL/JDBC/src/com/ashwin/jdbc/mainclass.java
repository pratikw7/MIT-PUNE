//Student teacher using JDBC
package com.ashwin.jdbc;
import java.sql.*;
public class mainclass {
	public static void main(String args[]) throws SQLException
	{
		try{
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/sdl","root","tiger");
			PreparedStatement query = con.prepareStatement("select * from Stud");
			ResultSet rs = query.executeQuery();
			while(rs.next())
			{
				System.out.println(rs.getString("name"));
			}
			query = con.prepareStatement("select * from Stud");
			rs = query.executeQuery();
			while(rs.next())
			{
				System.out.println(rs.getString("rollno"));
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
