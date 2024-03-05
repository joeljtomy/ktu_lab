//1. Develop a Java Program to display the details of bank account using Class.

import java.util.Scanner;

public class BankAccount {
    String number, holderName;
    double balance;

    public void addAccountDetails() {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter Account details: ");
        this.number = input.nextLine();
        this.holderName = input.nextLine();
        this.balance = input.nextDouble();
    }

    public void displayAccountDetails() {
        System.out.println("Account Number: " + number);
        System.out.println("Account Holder Name: " + holderName);
        System.out.println("Account Balance: $" + balance);
    }

    public static void main(String[] args) {
        BankAccount myAccount = new BankAccount();
        myAccount.addAccountDetails();
        myAccount.displayAccountDetails();
    }
}
