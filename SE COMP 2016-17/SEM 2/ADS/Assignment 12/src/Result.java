import StudentPackage.ExternalMarks;
import StudentPackage.InternalMarks;
import StudentPackage.StudentInfo;


public class Result extends StudentInfo implements InternalMarks,ExternalMarks 
{

	@Override
	public float ExternalCalc(StudentInfo stud) 
	{	
		float extm;
		extm=(stud.external1+stud.external2+stud.external3+stud.external4+stud.external5)/5;
		System.out.println("Total External Marks Are : "+extm);
		return extm;
		
	}

	@Override
	public float InternalCalc(StudentInfo stud) 
	{	
		float intm;
		intm=(stud.internal1+stud.internal2+stud.internal3+stud.internal4+stud.internal5)/5;
		System.out.println("Total Internal Marks Are : "+intm);
		return intm;
		
	}
	public void results(StudentInfo stud2)
	{
		StudentInfo stud1=stud2;
		float Finalresult;
		float externalf,internalf;
		externalf=ExternalCalc(stud1);
		internalf=InternalCalc(stud1);
		Finalresult=(externalf+internalf)/2;
		System.out.println("The Final Result: "+Finalresult);
	}
	

}
