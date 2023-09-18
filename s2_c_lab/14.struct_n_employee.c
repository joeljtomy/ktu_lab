#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    int salary;
    char name[50];
};

int main() {
    int n;

    printf("Enter the total number of employees: ");
    scanf("%d", &n);
    while (getchar() != '\n');

    struct Employee employees[n];

    printf("Enter the details of employees:\n");
    for(int i = 0;i < n;i++) {
        printf("Employee %d :\n", i + 1);
        printf("Name : ");
        gets(employees[i].name);
        printf("Id : ");
        scanf("%d", &employees[i].id);
        printf("Salary : ");
        scanf("%d", &employees[i].salary);
        while (getchar() != '\n');
    }
    
    printf("\nList of all employees :\n\n");
    for(int i = 0;i < n;i++) {
        printf("Employee %d :\n", i + 1);
        printf("Name : %s\n", employees[i].name);
        printf("Id : %d\n", employees[i].id);
        printf("Salary : %d\n\n", employees[i].salary);
    }
    return 0;
}