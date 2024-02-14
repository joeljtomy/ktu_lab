public class BankAccount {
    private String number;
    private String holderName;
    private double balance;

    public BankAccount(String number, String holderName, double balance) {
        this.number = number;
        this.holderName = holderName;
        this.balance = balance;
    }

    public void displayAccountDetails() {
        System.out.println("Account Number: " + number);
        System.out.println("Account Holder Name: " + holderName);
        System.out.println("Balance: $" + balance);
    }

    public static void main(String[] args) {
        BankAccount myAccount = new BankAccount("1234567890", "John Doe", 1000.0);

        myAccount.displayAccountDetails();
    }
}
