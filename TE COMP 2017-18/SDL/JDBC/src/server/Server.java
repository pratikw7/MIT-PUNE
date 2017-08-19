package server;
import common.Student;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.*;
import java.util.ArrayList;


public class Server {
	private static ArrayList<Student> studentDatabase = new ArrayList<Student>();
	public static void main(String[] args) throws SQLException {
		try{
			Class.forName("com.mysql.jdbc.Driver");
			Connection connectSQL = DriverManager.getConnection("jdbc:mysql://localhost:3306/JDBC","root","root");
			PreparedStatement query = connectSQL.prepareStatement("select * from students");
			ResultSet rs = query.executeQuery();
			while(rs.next())
			{
				System.out.println(rs.getString("name"));
			}
			ServerSocket ss = new ServerSocket(3000);
			System.out.println("Waiting for client to join...");
			Socket cs = ss.accept();
			System.out.println("Found");
			DataInputStream din = new DataInputStream(cs.getInputStream());
			DataOutputStream dout = new DataOutputStream(cs.getOutputStream());
            ObjectInputStream oin = new ObjectInputStream(cs.getInputStream());
            ObjectOutputStream oout = new ObjectOutputStream(cs.getOutputStream());
            Student s;
            int input,roll;
            do
            {
                input = din.readInt();
                switch (input) {
                    case 1:
                        studentDatabase.add((Student) oin.readObject());
                        dout.writeUTF("Insertion successful");
                        break;
                    case 2:
                        dout.writeUTF(studentDatabase.toString());
                        break;
                    case 3:
                        roll = din.readInt();
                        System.out.println(roll);
                        s = search(roll);
						if(s!=null)
						{
							studentDatabase.remove(s);
							dout.writeUTF("Successfully deleted");
							break;
						}
						dout.writeUTF("Could not find student");
                        break;
                    case 4:
                        roll = din.readInt();
                        s = search(roll);
						if(s!=null) {
                            dout.writeUTF("found");
                            studentDatabase.set( studentDatabase.indexOf(s),(Student) oin.readObject());
                        }
                        else
                            dout.writeUTF("not found");
                        break;
                    case 5:
                        roll = din.readInt();
                        s = search(roll);
                        if(s!=null)
                            oout.writeObject(s);
                        break;
                    case 6:
                        roll = din.readInt();
						s = search(roll);
						/*if(s!=null)
							dout.writeUTF("Average marks are:"+calculateAverage(s));*/
                        break;
                    default:
                        break;
                }
                input = din.readInt();
            }while(input==0);
			ss.close();
			System.out.println("Closed");
		}
		catch(Exception e){
			e.printStackTrace();
		}

	}


      /*  private static float calculateAverage(ArrayList<Student> other)
	{
		*//*float []marks= other.GetMarks();
		float sum = 0;
		for (float i : marks) {
			sum += i;
		}
		return sum/marks.length;*//*
	}*/

	private static Student search(int roll)
	{
		for(Student s:studentDatabase)
		{
			if(s.GetRoll() == roll)
			{
				return s;
			}
		}
		System.out.println("Student not found!");
		return null;
	}
}
