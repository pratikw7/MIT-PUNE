package server;
import common.Student;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.rmi.server.Operation;
import java.sql.*;
import java.util.ArrayList;


public class Server {
	
	public static void main(String[] args) throws SQLException {
		try{
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
                        s = (Student) oin.readObject();
                        operation.AddStudent(s);
                        dout.writeUTF("Insertion successful");
                        break;
                    case 2:
                    	
                    	dout.writeUTF(operation.ShowDatabase());
                        break;
                    case 3:
                        roll = din.readInt();
                        System.out.println(roll);
                        dout.writeUTF(operation.Delete(roll));
                        break;
                    case 4:
                    	dout.writeUTF(operation.ShowFailedStudents());
                        break;
                    case 5:
                        roll = din.readInt();
                        dout.writeUTF(operation.Search(roll));
                        break;
                    case 6:
                    	dout.writeUTF(operation.CalculateAverage());
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

}
