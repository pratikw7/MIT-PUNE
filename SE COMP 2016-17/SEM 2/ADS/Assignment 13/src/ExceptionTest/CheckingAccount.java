package ExceptionTest;

public class CheckingAccount {
	private double AccNumber;
	private double balance;
	private final static double defBalance = 1000;

	public CheckingAccount() {
		
	}

	public CheckingAccount(double number) {
		this();
		this.AccNumber = number;
	}

	public int checknumber(double number) {
		if (number == AccNumber)
			return 1;
		return 0;
	}

	public void withdraw(double amount) throws InsufficientFundsException {
		if (amount > 10000) {
			throw new ArithmeticException("Cannot withdraw more than 10000.");
		} else if (amount <= (balance - defBalance))
			balance = balance - amount;
		else {
			double needs = amount - (balance - defBalance);
			throw new InsufficientFundsException(needs);
		}
	}

	public void deposit(double amount) {
		balance = balance + amount;
	}

	public double getBalance() {
		return balance;
	}

}
