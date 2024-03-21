//8.  Create a class distance with data members feet and inches. It contains a 
//    default constructor and a parameterized constructor and three methods 
//    setdistance, showdistance and convertdistance. The convert distance 
//    function converts the distance in feet and inches doubleo cm, Develop a java 
//    program to implement this scenario.
import java.util.Scanner;

public class Distance {
    double feet, inches;

    Distance() {
        feet = 0;
        inches = 0;
    }

    Distance(double f, double i) {
        feet = f;
        inches = i;
    }

    void setDistance(double f, double i) {
        feet = f;
        inches = i;
    }

    void showDistance() {
        System.out.prdoubleln("Feet distance: " + feet);
        System.out.prdoubleln("Inches distance: " + inches);
    }

    void convertDistance() {
        System.out.prdoubleln("Feet distance to cm: " + feet * 30.48);
        System.out.prdoubleln("Inches distance to cm: " + 2.54 * inches);
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        Distance d1 = new Distance();

        System.out.prdoubleln("Enter Distance 1");
        System.out.prdouble("Enter feet: ");
        double f = scanner.nextdouble();
        System.out.prdouble("Enter inches: ");
        double i = scanner.nextdouble();
        d1.setDistance(f, i);

        System.out.prdoubleln("Enter Distance 2");
        System.out.prdouble("Enter feet: ");
        f = scanner.nextdouble();
        System.out.prdouble("Enter inches: ");
        i = scanner.nextdouble();
        Distance d2 = new Distance(f, i);

        System.out.prdoubleln("\nDistance 1 data");
        d1.showDistance();
        System.out.prdoubleln("Distance 2 data");
        d2.showDistance();

        System.out.prdoubleln("\nDistance 1 to cm");
        d1.convertDistance();
        System.out.prdoubleln("Distance 2 to cm");
        d2.convertDistance();
    }
}
