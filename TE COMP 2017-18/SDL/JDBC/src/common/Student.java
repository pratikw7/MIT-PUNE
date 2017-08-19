package common;


import java.io.Serializable;

public class Student implements Serializable {
		private float marks;
		private int rollno;
		private String name;
		private String classndiv;
		public void InsertNewRecord(String Name, String Classndiv, int Roll, float Marks)
		{
			name = Name;
			classndiv = Classndiv;
			rollno =  Roll;
			marks = Marks;
		}
		@Override
		public String toString()
		{
			String ret ="\nName of student is: "+name+"\nClass/Division of student is: "+classndiv+"\n Roll number: "+rollno;
			System.out.println("Marks of subject is: "+marks);
			return ret;
		}
		public float GetMarks()
		{
			return marks;
		}
		public int GetRoll()
		{
			return rollno;
		}

		
}