package ExceptionTest;

import java.util.InputMismatchException;
import java.util.Scanner;

public class BankDemo {
	
	public static void main(String[] args) {
		
		int choice, flag = 0;
		double amount, number;

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter account number: ");
		number = sc.nextDouble();
		try {
			String s = null;
			System.out.println(s.length());
		} catch (NullPointerException r) {
			System.out.println("Caught " + r.getClass().getSimpleName());
		}
		CheckingAccount a = new CheckingAccount(number);
		do {
			System.out.println("1 Withdraw cash");
			System.out.println("2 Deposit cash");
			System.out.println("3 Please your enter your account number.");
			System.out.println("4 View balance");
			System.out.println("5 Exit");
			choice = sc.nextInt();
			switch (choice) {
			case 1:
				if (flag == 1) {
					try {
						System.out.println("Enter amount to withdraw.");
						amount = sc.nextDouble();
						a.withdraw(amount);
					} catch (InsufficientFundsException e) {					
						e.printStackTrace();
					} catch (ArithmeticException e) {
						e.printStackTrace();
					} catch (InputMismatchException e) {
						System.out.println("Please enter a valid number.");						
					}
				} else {
					System.out.println("Please enter valid account number.");
				}
				break;
			case 2:
				if (flag == 1) {
					System.out.println("Enter amount to deposit.");
					amount = sc.nextDouble();
					a.deposit(amount);
				} else {
					System.out.println("Please enter valid account number.");
				}
				break;
			case 3:
				System.out.println("Enter account number.");
				number = sc.nextDouble();
				flag = a.checknumber(number);
				break;
			case 4:
				if (flag == 1) {
					amount = a.getBalance();
					System.out.println("Balance is " + amount);
				} else {
					System.out.println("Please enter valid account number.");
				}
				break;
			default:
				choice = -1;
				break;
			}			
		} while (choice != -1);
	}

}
