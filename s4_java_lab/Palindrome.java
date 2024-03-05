//2.  Develop a Java Program to check whether a number is palindrome or not.

import java.util.Scanner;

public class Palindrome {

    public boolean isPalindrome(int number) {
        int originalNumber = number;
        int reversedNumber = 0;
        while (number > 0) {
            int digit = number % 10;
            reversedNumber = reversedNumber * 10 + digit;
            number /= 10; 
        }
        return originalNumber == reversedNumber;
    }

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = input.nextInt();
        Palindrome p = new Palindrome();

        if (p.isPalindrome(number)) {
            System.out.println(number + " is a Palindrome.");
        } else {
            System.out.println(number + " is not a Palindrome.");
        }
    }
}