
package assignment1;

import java.util.Enumeration;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Vector;

public class Teacher {
	private static Vector<Student>studentDatabase = new Vector<Student>();
	private static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) {
		int input;
		String holdY;
		int roll;
		Student s;
		do
		{
			//failure students
			System.out.println("1 Insert new student");
			System.out.println("2 Show database");
			System.out.println("3 Delete student");
			System.out.println("4 Modify student");
			System.out.println("5 Search student");
			System.out.println("6 Calculate average of student");
			input = in.nextInt();
			switch (input) {
			case 1:
				Student temp = new Student();
				temp.InsertNewRecord();
				studentDatabase.add(temp);
				break;
			case 2:
				showDatabase();
				break;
			case 3:
				System.out.println("Enter roll no. of student");
				roll = in.nextInt();
				s = search(roll);
				if(s!=null)
				{
					studentDatabase.remove(s);
					System.out.println("Successfully deleted");
				}
				break;
			case 4:
				System.out.println("Enter roll no. of student");
				roll = in.nextInt();
				s = search(roll);
				if(s!=null)
					s.InsertNewRecord();
				break;
			case 5:
				System.out.println("Enter roll no. of student");
				roll = in.nextInt();
				s = search(roll);
				s.DisplayRecord();
			case 6:
				System.out.println("Enter roll no. of student");
				roll = in.nextInt();
				s = search(roll);
				if(s!=null)
					System.out.println("Average marks are:"+calculateAverage(s));
				break;
			default:
				break;
			}
			System.out.println("Enter y to continue ");
			holdY = in.next();
		}while(holdY.charAt(0)=='y');
		/*ystem.out.println("Average marks are: "+calculateAverage(S));*/
		
	}
	private static float calculateAverage(Student other)
	{
		float []marks= other.GetMarks();
		float sum = 0;
		for (float i : marks) {
			sum += i;
		}
		return sum/marks.length;
	}
	private static void showDatabase()
	{
		Enumeration<Student> e = studentDatabase.elements();
		while(e.hasMoreElements())
		{
			e.nextElement().DisplayRecord();
		}
	}
	private static Student search(int roll)
	{
		for(Student s:studentDatabase)
		{
			if(s.GetRoll() == roll)
			{
				return s;
			}
		}
		Student s = null;
		System.out.println("Student not found!");
		return s;
	}

}

