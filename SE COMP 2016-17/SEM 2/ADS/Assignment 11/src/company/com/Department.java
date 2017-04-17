package company.com;

public class Department {
	public int DepType;
	public int NumberofEmployees;	

	enum Departments
	{
		Design,Manufacture,QA,Programming,Management;
	}
	
	public Department() {
		
	}
	public Department(int NEmployees)
	{
		NumberofEmployees = NEmployees;
	}

}
