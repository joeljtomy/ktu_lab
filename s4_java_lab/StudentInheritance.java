//10. Develop a Java program to read and print students data using inheritance.
//    Class person: name, age, gender 
//    Class student( inherits from person): mark1, mark2, mark3, total marks, grade.

import java.util.Scanner;

class Person {

  String name, gender;
  int age;

  Person(String name, int age, String gender) {
    this.name = name;
    this.age = age;
    this.gender = gender;
  }

  void displayDetails() {
    System.out.println("Name: " + name);
    System.out.println("Age: " + age);
    System.out.println("Gender: " + gender);
  }
}

class Student extends Person {

  int mark1, mark2, mark3, totalMarks;
  String grade;

  Student(
    String name,
    int age,
    String gender,
    int mark1,
    int mark2,
    int mark3
  ) {
    super(name, age, gender);
    this.mark1 = mark1;
    this.mark2 = mark2;
    this.mark3 = mark3;
    this.totalMarks = mark1 + mark2 + mark3;
    this.grade = calculateGrade();
  }

  String calculateGrade() {
    double average = totalMarks / 3;
    if (average >= 80) return "A";
    if (average >= 60) return "B";
    if (average >= 40) return "C";
    else return "Fail";
  }

  public void displayDetails() {
    super.displayDetails();
    System.out.println("Mark 1: " + mark1 + "/100");
    System.out.println("Mark 2: " + mark2 + "/100");
    System.out.println("Mark 3: " + mark3 + "/100");
    System.out.println("Total Marks: " + totalMarks + "/300");
    System.out.println("Grade: " + grade);
  }
}

public class StudentInheritance {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter student's name: ");
    String name = scanner.nextLine();

    System.out.print("Enter student's age: ");
    int age = scanner.nextInt();
    scanner.nextLine();

    System.out.print("Enter student's gender: ");
    String gender = scanner.nextLine();

    System.out.print("Enter mark 1 in 100: ");
    int mark1 = scanner.nextInt();

    System.out.print("Enter mark 2 in 100: ");
    int mark2 = scanner.nextInt();

    System.out.print("Enter mark 3 in 100: ");
    int mark3 = scanner.nextInt();

    Student student = new Student(name, age, gender, mark1, mark2, mark3);
    System.out.println("\nStudent Details:");
    student.displayDetails();
  }
}
