import java.util.Scanner;


public class MainClass 
{

	public static void main(String[] args) 
	{	
		int n,i;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Number Of Students : ");
		n=sc.nextInt();
		Result r[]=new Result[10];
		for(i=0;i<n;i++)
		{
			r[i]=new Result();
		}
		int x;
		String y;
		do
		{
			System.out.println("1 Enter Student Details");
			System.out.println("2 Display Results");
			System.out.println("3 Display Student Details");
			x=sc.nextInt();
			switch(x)
			{
				case 1:
					for(i=0;i<n;i++)
					{
						r[i].EnterDetails();
					}
					break;
				case 2:
					break;
				case 3:
					for(i=0;i<n;i++)
					{
						r[i].DisplayDetails();
					}
					break;
				
			}
			System.out.println("Do You Want To Continue?(y) ");
			y=sc.next();
			
		}while(y.compareTo("y")==0);
		

	}

}
