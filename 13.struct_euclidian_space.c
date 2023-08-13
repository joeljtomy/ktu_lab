// code without fixing question
#include <stdio.h>

struct Distance {
    float distance
};

int main() {
    struct Distance d1, d2;

    printf("Enter the first distance: ");
    scanf("%f", &d1.distance);

    printf("Enter the second distance: ");
    scanf("%f", &d2.distance);

    printf("The total distance is: %f\n", d1.distance + d2.distance);

    return 0;
}

//question fixed code

#include <stdio.h>

struct Point {
    int x,
    int y
};

int main() {
    struct Point p1, p2, p3;

    printf("Enter the first point: ");
    scanf("x: %d", &p1.x);
    scanf("y: %d", &p1.y);

    printf("Enter the second point: ");
    scanf("x: %d", &p2.x);
    scanf("y: %d", &p2.y);

    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;

    printf("After adding two points the result is, x: %d, y: %d\n", p3.x, p3.y);

    return 0;
}
