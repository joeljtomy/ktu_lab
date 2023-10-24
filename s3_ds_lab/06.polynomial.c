// 6.  Apply linked list concept to perform polynomial addition. 

#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

struct Term* createTerm(int coef, int exp) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    term->coefficient = coef;
    term->exponent = exp;
    term->next = NULL;
    return term;
}

void insertTerm(struct Term** head, int coef, int exp) {
    struct Term* newTerm = createTerm(coef, exp);
    if (*head == NULL || exp > (*head)->exponent) {
        newTerm->next = *head;
        *head = newTerm;
    } else {
        struct Term* current = *head;
        while (current->next != NULL && current->next->exponent >= exp) {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent == poly2->exponent) {
            insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    insertTerm(&poly1, 4, 3);
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 5, 1);

    insertTerm(&poly2, 3, 2);
    insertTerm(&poly2, 2, 1);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Term* result = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    displayPolynomial(result);

    return 0;
}


/*Algorithm
Step 1: Start.

*/
