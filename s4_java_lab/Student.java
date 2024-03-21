//8.  Develop a Java program using constructor overloading to display
//    student details.
import java.util.Scanner;

public class Student {
    String name, department;
    int id;

    public Student(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public Student(String name, int id, String department) {
        this.name = name;
        this.id = id;
        this.department = department;
    }

    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.println("Department: " + department);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Student 1: ");
        System.out.print("Enter name: ");
        String n = scanner.nextLine();
        System.out.print("Enter id: ");
        int i = scanner.nextInt();
        Student student1 = new Student(n, i);
        
        System.out.println("\nStudent 2: ");
        System.out.print("Enter name: ");
        scanner.nextLine();
        n = scanner.nextLine();
        System.out.print("Enter id: ");
        i = scanner.nextInt();
        System.out.print("Enter department: ");
        scanner.nextLine();
        String d = scanner.nextLine();
        Student student2 = new Student(n, i, d);

        System.out.println();
        System.out.println("Student 1 Details:");
        student1.displayDetails();
        System.out.println();

        System.out.println("Student 2 Details:");
        student2.displayDetails();
        System.out.println();
    }
}
