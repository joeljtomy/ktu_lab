//8.  Create a class distance with data members feet and inches. It contains a 
//    default constructor and a parameterized constructor and three methods 
//    setdistance, showdistance and convertdistance. The convert distance 
//    function converts the distance in feet and inches into cm, Develop a java 
//    program to implement this scenario.
import java.util.Scanner;

public class Distance {
    int feet, inches;

    Distance() {
        feet = 0;
        inches = 0;
    }

    Distance(int f, int i) {
        feet = f;
        inches = i;
    }

    void setDistance(int f, int i) {
        feet = f;
        inches = i;
    }

    void showDistance() {
        System.out.println("Distance = " + feet + "feet " + inches + "inches.");
    }

    void convertDistance() {
        double cm = (feet * 12 * 2.54) + (inches * 2.54);
        System.out.println(feet + "feet " + inches + "inches = " + cm + "cm.");
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        Distance d1 = new Distance();

        System.out.println("Enter Distance 1");
        System.out.print("Enter feet: ");
        int f = scanner.nextInt();
        System.out.print("Enter inches: ");
        int i = scanner.nextInt();
        d1.setDistance(f, i);

        System.out.println("Enter Distance 2");
        System.out.print("Enter feet: ");
        f = scanner.nextInt();
        System.out.print("Enter inches: ");
        i = scanner.nextInt();
        Distance d2 = new Distance(f, i);

        System.out.println("\nDistance object 1:");
        d1.showDistance();
        System.out.println("Distance object 2:");
        d2.showDistance();

        System.out.println("\nDistance 1 to cm");
        d1.convertDistance();
        System.out.println("Distance 2 to cm");
        d2.convertDistance();
    }
}
