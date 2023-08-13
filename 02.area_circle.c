#include <stdio.h>
#define PI 3.14

int main() {
    float r, area;

    printf("Enter radius of the circle: ");
    scanf("%f", &r);
    area = PI * r * r;
    printf("The area of the circle is %f\n", area);

    return 0;
}

/*Algorithm
Step 1: Start
Step 2: Define constant PI = 3.14.
Step 3: Declare variables r and area.
Step 4: Read value of r.
Step 5: Calculate area (PI * r * r) and assign the value to area.
        area ← PI * r * r
Step 6: Display the area
Step 7: Stop
*/