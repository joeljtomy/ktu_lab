#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    printf(" Hello.c executing\n");
    printf("First content of passed array is %s\n", argv[0]);

    return 0;
}

/*Execution format
Gcc –o execv execv.c
Gcc –o hello hello.c
./execv
*/

