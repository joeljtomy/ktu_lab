import java.util.Scanner;

public class Factorial {
    public int calculate(int number) {
        if (number == 0) return 1;
        return number * this.calculate(number - 1);
    }

    public static void main(String args[]) {
        Factorial factorial = new Factorial();
        System.out.print("Enter a number: ");
        Scanner input = new Scanner(System.in);
        int number = input.nextInt();
        if (number < 0) {
            System.out.println("Negative number is not allowed");
            return;
        }
        int result = factorial.calculate(number);
        System.out.println("Factorial of " + number + " = " + result);
    }
}   