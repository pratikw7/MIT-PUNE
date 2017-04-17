package ExceptionTest;

public class InsufficientFundsException extends Exception {
	
	private static final long serialVersionUID = 1L;
	
	private double amount;

	public InsufficientFundsException(double amount) {
		this.amount = amount;
	}
	
	@Override
	public String getMessage() {
		return "Insufficient balance. You need " + amount + " more.";
	}

	public double getAmount() {
		return amount;
	}
}
