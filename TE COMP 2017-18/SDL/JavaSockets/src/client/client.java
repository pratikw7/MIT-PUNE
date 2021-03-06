package client;
import common.Student;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.sql.Connection;
import java.sql.DriverManager;
import java.util.Scanner;

public class client {

    private static Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		try{
			Socket cs = new Socket("localhost",3000);
            System.out.println("Client");
			DataInputStream din = new DataInputStream(cs.getInputStream());
			DataOutputStream dout = new DataOutputStream(cs.getOutputStream());
            ObjectOutputStream oout = new ObjectOutputStream(cs.getOutputStream());
			ObjectInputStream oin = new ObjectInputStream(cs.getInputStream());

            //dout.writeUTF("Hello friend");
			//dout.flush();

			int input,roll;
			do
			{
			    //TODO add failed student
				System.out.println("1 Insert new student");
				System.out.println("2 Show database");
				System.out.println("3 Delete student");
				System.out.println("4 Modify student");
				System.out.println("5 Search student");
				System.out.println("6 Calculate average of student");
				input = in.nextInt();
				switch (input) {
					case 1:
                        dout.writeInt(1);
                        Student temp = new Student();
                        InsertStudentValues(temp);
                        oout.writeObject(temp);
                        System.out.println(din.readUTF());
                        break;
					case 2:
                        dout.writeInt(2);
                        System.out.println(din.readUTF());
                        break;
					case 3:
                        dout.writeInt(3);
						System.out.println("Enter roll no. of student");
						roll = in.nextInt();
						dout.writeInt(roll);
                        System.out.println(din.readUTF());
						break;
					case 4:
                        dout.writeInt(4);
						System.out.println("Enter roll no. of student");
                        roll = in.nextInt();
                        dout.writeInt(roll);
                        if(din.readUTF().equals("found"))
                        {
                            Student s=new Student();
                            InsertStudentValues(s);
                            oout.writeObject(s);
                        }
						break;
					case 5:
                        dout.writeInt(5);
						System.out.println("Enter roll no. of student");
						roll = in.nextInt();
						dout.writeInt(roll);
						Student s = (Student)oin.readObject();
                        System.out.println(s.toString());
                        break;
                    case 6:
                        dout.writeInt(6);
						System.out.println("Enter roll no. of student");
                        roll = in.nextInt();
                        dout.writeInt(roll);
							System.out.println(din.readUTF());
						break;
					default:
						break;
				}
				System.out.println("Enter 0 to continue ");
				input = in.nextInt();
				dout.writeInt(input);
			}while(input==0);
            dout.close();   //Close data output stream
            cs.close();     //Close socket
		}
		catch(Exception e){
			System.out.println(e);
		}

	}
    private static void InsertStudentValues(Student other) {
        float marks[] = new float[5];
        System.out.println("Enter name of Student: ");
        String name = in.next();
        System.out.println("Class/Divison of Student: ");
        String classndiv = in.next();
        System.out.println("Enter Roll NO. of student: ");
        int rollno = in.nextInt();
        for (int i = 0; i < marks.length; i++) {
            System.out.println("Enter marks of subject " + i + " :");
            marks[i] = in.nextFloat();
        }
        other.InsertNewRecord(name,classndiv,rollno,marks);
    }

}
