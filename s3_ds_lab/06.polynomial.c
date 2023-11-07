// 6.  Apply linked list concept to perform polynomial addition. 

#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coef;
    int expo;
    struct Term* next;
};

struct Term* createTerm(int coef, int exp) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    term->coef = coef;
    term->expo = exp;
    term->next = NULL;
    return term;
}

void insertTerm(struct Term** head, int coef, int exp) {
    struct Term* newTerm = createTerm(coef, exp);
    if (*head == NULL || exp > (*head)->expo) {
        newTerm->next = *head;
        *head = newTerm;
    } else {
        struct Term* current = *head;
        while (current->next != NULL && current->next->expo >= exp) {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

struct Term* recievePolynomial(struct Term** head) {
    int coef, exp, i;
    int numTerms;

    printf("Enter the number of terms for Polynomial: ");
    scanf("%d", &numTerms);

    for (i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coef, &exp);
        insertTerm(head, coef, exp);
    }
    return *head;
}

struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->expo == poly2->expo) {
            insertTerm(&result, poly1->coef + poly2->coef, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->expo > poly2->expo) {
            insertTerm(&result, poly1->coef, poly1->expo);
            poly1 = poly1->next;
        } else {
            insertTerm(&result, poly2->coef, poly2->expo);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coef, poly1->expo);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coef, poly2->expo);
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
        printf("%dx^%d", poly->coef, poly->expo);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    printf("Polynomial 1:\n");
    poly1 = recievePolynomial(&poly1);

    printf("Polynomial 2:\n");
    poly2 = recievePolynomial(&poly2);

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);

    printf("\nPolynomial 2: ");
    displayPolynomial(poly2);

    struct Term* result = addPolynomials(poly1, poly2);
    printf("\nSum of Polynomials: ");
    displayPolynomial(result);

    return 0;
}



/*Algorithm
Step 1: Start.

*/
