package company.com;
public class SalariedEmployee extends Employee {

	public SalariedEmployee(String n, String des, String dep,int empid, int a)
	{
		Name = n;
		designation = des;
		department = dep;
		age = a;
		vSetEmpId(empid);
		CalculateSalary(designation);
	}
	private void CalculateSalary(String desg)
	{
		if(desg.compareTo("CEO")==0)
			salary = 35000000;
		else if(desg.compareTo("CFO")==0)
			salary = 27000000;
		else if(desg.compareTo("Manager")==0)
			salary = 1900000;
		else if(desg.compareTo("Programmer")==0)
			salary = 2000000;
		else
			salary = 1000000;
		float HRA = 10000;
		float Telephone = 500;
		salary+=HRA+Telephone;
		
	}
	public void vDisplay() {
		System.out.println("Name: "+ Name);
		System.out.println("Designation: "+ designation);
		System.out.println("Department: "+ department);
		System.out.println("Age: "+ age);
		System.out.println("Employee id: "+ iGetEmpId());
		System.out.println("Salary: "+ salary);
		
	}
}
