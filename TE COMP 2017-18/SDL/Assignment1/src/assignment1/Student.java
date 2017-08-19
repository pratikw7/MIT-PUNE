package assignment1;

import java.util.Scanner;

public class Student {
		private float marks[];
		private int rollno;
		private String name;
		private String classndiv;
		private Scanner in = new Scanner(System.in);
		public void InsertNewRecord()
		{
			marks = new float[5]; 
			System.out.println("Enter name of Student: ");
			name = in.next();
			System.out.println("Class/Divison of Student: ");
			classndiv = in.next();
			System.out.println("Enter Roll NO. of student: ");
			rollno =  in.nextInt();
			for (int i = 0; i < marks.length; i++) {
				System.out.println("Enter marks of subject "+i+" :");
				marks[i] = in.nextFloat();
			}
		}
		public void DisplayRecord()
		{
			System.out.println("Name of student is: "+name);
			System.out.println("Class/Division of student is: "+classndiv);
			for (int i = 0; i < marks.length; i++) {
				System.out.println("Marks of subject "+i+" is: "+marks[i]);
			}
		}
		public float[] GetMarks()
		{
			return marks;
		}
		public int GetRoll()
		{
			return rollno;
		}
		
		
}