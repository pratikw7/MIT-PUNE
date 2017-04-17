package company.com;


public class Employee {
	public String Name;
	protected String designation;
	protected String department;
	int age;
	int salary;
	private int empId;
	
	
	public Employee(String n, String des, String dep, int a, int s, int eid)
	{
		Name = n;
		designation = des;
		department = dep;
		age = a;
		salary = s;
		empId = eid;
	}
	public Employee()
	{
		
	}
	public void vSetSalary(int s)
	{
		salary = s;
	}
	int iGetSalary()
	{
		return salary;
	}
	
	int iGetEmpId()
	{
		return empId;
	}
	
	void vSetEmpId(int n)
	{
		empId = n;
	}
	void vSetDesignation(String s)
	{
		designation = s;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

}
