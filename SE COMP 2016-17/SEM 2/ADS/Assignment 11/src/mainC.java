import company.com.SalariedEmployee;


public class mainC {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		SalariedEmployee ash = new SalariedEmployee("ashwin", "CEO","Engineering" ,1, 20);
		SalariedEmployee random = new SalariedEmployee("random", "Manager","Design" ,3, 30);
		ash.vDisplay();
		random.vDisplay();

	}

}
