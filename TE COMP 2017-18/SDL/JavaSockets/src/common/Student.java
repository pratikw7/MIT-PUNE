package common;


import java.io.Serializable;

public class Student implements Serializable {
		private float marks[];
		private int rollno;
		private String name;
		private String classndiv;
		public void InsertNewRecord(String Name, String Classndiv, int Roll, float Marks[])
		{
			marks = new float[5];
			name = Name;
			classndiv = Classndiv;
			rollno =  Roll;
			for (int i = 0; i < marks.length; i++) {
				marks[i] = Marks[i];
			}
		}
		@Override
		public String toString()
		{
			String ret ="\nName of student is: "+name+"\nClass/Division of student is: "+classndiv+"\n Roll number: "+rollno;
			for (int i = 0; i < marks.length; i++) {
				ret+="\nMarks of subject "+i+" is: "+marks[i];
			}
			return ret;
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