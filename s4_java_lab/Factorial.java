import java.util.Scanner;

public class Factorial {
    public int calculateFactorial(int number) {
        if (number == 0) return 1;
        return number * this.calculateFactorial(number - 1);
    }

    public static void main(String args[]) {
        System.out.print("Enter a number: ");
        Scanner input = new Scanner(System.in);
        int number = input.nextInt();
        if (number < 0) {
            System.out.println("Negative number is not allowed");
            return;
        }
        
        Factorial object = new Factorial();
        int result = object.calculateFactorial(number);
        System.out.println("Factorial of " + number + " = " + result);
    }
}   