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

        System.out.println("Choose a shape to calculate area: ");
        System.out.println("1. Circle");
        System.out.println("2. Square");
        System.out.println("3. Rectangle");
        System.out.print("Enter choice: ");
        int choice = scanner.nextInt();
        double area = 0;

        switch (choice) {
            case 1:
                System.out.print("Enter radius of the circle: ");
                int radius = scanner.nextInt();
                area = calculateArea(radius);
                System.out.println("Area of the circle: " + area);
                break;
            case 2:
                System.out.print("Enter side length of the square: ");
                double sideLength = scanner.nextInt();
                area = calculateArea(sideLength);
                System.out.println("Area of the square: " + area);
                break;
            case 3:
                System.out.print("Enter length of the rectangle: ");
                double length = scanner.nextInt();
                System.out.print("Enter width of the rectangle: ");
                double width = scanner.nextInt();
                area = calculateArea(length, width);
                System.out.println("Area of the rectangle: " + area);
                break;
            default:
                System.out.println("Invalid choice!");
        }

        scanner.close();
    }
}
