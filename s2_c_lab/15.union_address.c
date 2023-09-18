#include <stdio.h>
#include <string.h>
#define C_SIZE 20

union Address {
    char name[C_SIZE];
    char house[C_SIZE];
    char city[C_SIZE];
    char state[C_SIZE];
    char pincode[C_SIZE];
};

int main() {
    union Address addr;
    char address[200] = "\nAddress:";

    printf("Enter the Address:\n");
    
    printf("Name : ");
    gets(addr.name);
    strcat(address,"\nName: ");
    strcat(address,addr.name);
    
    printf("House name: ");
    gets(addr.house);
    strcat(address,"\nHouse name: ");
    strcat(address,addr.house);
    
    printf("City name: ");
    gets(addr.city);
    strcat(address,"\nCity name: ");
    strcat(address,addr.city);
    
    printf("State name: ");
    gets(addr.state);
    strcat(address,"\nState name: ");
    strcat(address,addr.state);
    
    printf("Pin code: ");
    gets(addr.pincode);
    strcat(address,"\nPin code: ");
    strcat(address,addr.pincode);

    printf("\n%s\n",address);
    return 0;
}