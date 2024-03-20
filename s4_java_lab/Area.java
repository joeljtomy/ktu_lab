//6.  Develop a java program to find area of a circle,square and
//    rectangle using method overloading.
import java.util.Scanner;

public class AreaCalculator {

    public static double calculateArea(int radius) {
        return Math.PI * radius * radius;
    }

    public static double calculateArea(double sideLength) {
        return sideLength * sideLength;
    }

    public static double calculateArea(double length, double width) {
        return length * width;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter radius of the circle: ");
        int radius = scanner.nextInt();
        System.out.println("Area of the circle: " + calculateArea(radius));

        System.out.print("Enter side length of the square: ");
        double sideLength = scanner.nextInt();
        System.out.println("Area of the square: " + calculateArea(sideLength));

        System.out.print("Enter length of the rectangle: ");
        double length = scanner.nextInt();
        System.out.print("Enter width of the rectangle: ");
        double width = scanner.nextInt();
        System.out.println("Area of the rectangle: " + calculateArea(length, width));

    }
}
