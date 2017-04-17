import company.com.Employee;
public class CommissionEmployee extends Employee{
	public CommissionEmployee()
	{
		
	}
	public CommissionEmployee(String n, String des, String dep, int age, int salary, int eid,int sale)
	{
		super( n,  des,  dep,  age,  salary,  eid);
		vSetSalary((int)(sale*0.3));
	}

}
