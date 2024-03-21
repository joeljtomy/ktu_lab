//7.  Develop a Java program to display Fibonacci series with and without 
//    recursion using method overloading.
import java.util.Scanner;
public class FibonacciSeries {

    void series(int count) {
        int first = 0, second = 1;

        System.out.print(first + " " + second + " ");

        for (int i = 2; i < count; i++) {
            int next = first + second;
            System.out.print(next + " ");
            first = second;
            second = next;
        }
        System.out.println();
    }

    void series(int count, int first, int second) {
        if (count <= 0) return;
        
        System.out.print(first + " ");
        series(count - 1, second, first + second);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the length of Fibonacci series: ");
        int count = scanner.nextInt();

        Fibonacci fibonacci = new Fibonacci();
        System.out.println("Fibonacci Series without recursion:");
        fibonacci.series(count);

        System.out.println("Fibonacci Series with recursion:");
        fibonacci.series(count, 0, 1);

    }
}
