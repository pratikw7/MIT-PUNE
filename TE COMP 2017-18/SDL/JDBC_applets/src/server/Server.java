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
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


public class Server {
	ExecutorService pool = null;
	public Server() {
		pool = Executors.newFixedThreadPool(5);
	}
	public void startServer()
	{
		try{
			ServerSocket ss = new ServerSocket(3000);
			while(true) {
			System.out.println("Waiting for client to join...");
			Socket cs = ss.accept();
			System.out.println("Found");
			ServerThread clientThread = new ServerThread(cs);
			pool.execute(clientThread);
			//ss.close();
			}
		}
		catch (Exception e) {
			
		}
	}
	public static void main(String[] args) throws SQLException {
		new Server().startServer();

	}

}
class ServerThread implements Runnable
{
	Socket cs = null;
	public ServerThread(Socket Socket) {
		this.cs = Socket;
		
	}
	@Override
	public void run() {
		try{
			
			DataInputStream din = new DataInputStream(cs.getInputStream());
			DataOutputStream dout = new DataOutputStream(cs.getOutputStream());
            ObjectInputStream oin = new ObjectInputStream(cs.getInputStream());
            //ObjectOutputStream oout = new ObjectOutputStream(cs.getOutputStream());
            Student s;
            int input,roll;
            do
            {
                input = din.readInt();
                System.out.println("Choice: "+ input);
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
                //input = din.readInt();
            }while(true);
			
			//System.out.println("Closed");
		}
		catch(Exception e){
			e.printStackTrace();
		}
		
	}
}
