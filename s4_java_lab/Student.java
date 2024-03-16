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
        Student student1 = new Student("John", 20);
        Student student2 = new Student("Alice", 22, "Computer Science");

        System.out.println("Student 1 Details:");
        student1.displayDetails();
        System.out.println();

        System.out.println("Student 2 Details:");
        student2.displayDetails();
        System.out.println();
    }
}
