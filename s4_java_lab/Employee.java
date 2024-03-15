//4.  Construct a Java class to store some employee details and 
//    provide methods to set and get values.

import java.util.Scanner;

public class Employee {
    String name, designation, id;
    double salary;

    public void setValues(String n, String d, String i, double s) {
        name = n;
        designation= d;
        id = i;
        salary = s;
    }

    public void getValues() {
        System.out.println();
        System.out.println("Employee details: ");
        System.out.println("Name: " + name);
        System.out.println("Designation: " + designation);
        System.out.println("Id: " + id);
        System.out.println("Salary: $" + salary);
    }

    public static void main(String args[]) {
        String n, d, i;
        double s;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter Employee details: ");
        System.out.print("Enter name: ");
        n = input.nextLine();
        System.out.print("Enter designation: ");
        d = input.nextLine();
        System.out.print("Enter id: ");
        i = input.nextLine();
        System.out.print("Enter salary: ");
        s = input.nextDouble();
        
        Employee e1 = new Employee();
        e1.setValues(n,d,i,s);
        e1.getValues();
    }
}