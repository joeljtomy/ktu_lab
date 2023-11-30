// 6.  Apply linked list concept to perform polynomial addition.

#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coef;
    int expo;
    struct Term *next;
} Term;

Term *insertTerm(Term **head, int coef, int exp) {
    Term *newTerm = malloc(sizeof(Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    newTerm->coef = coef;
    newTerm->expo = exp;
    if (*head == NULL || exp > (*head)->expo) {
        newTerm->next = *head;
        *head = newTerm;
    } else {
        Term *ptr = *head;
        while (ptr->next != NULL && ptr->next->expo >= exp)
            ptr = ptr->next;
        newTerm->next = ptr->next;
        ptr->next = newTerm;
    }
    return newTerm;
}

Term *createPoly() {
    int n, coef, expo, i;
    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n);
    Term *poly = NULL;
    for (i = 0; i < n; i++) {
        printf("Enter coef & expo of term %d: ", i + 1);
        scanf("%d %d", &coef, &expo);
        insertTerm(&poly, coef, expo);
    }
    return poly;
}

Term *addPolynomials(Term *poly1, Term *poly2) {
    Term *result = NULL;
    Term *prev = NULL;
    int coef, expo;

    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 != NULL && poly2 != NULL) {
            if (poly1->expo == poly2->expo) {
                coef = poly1->coef + poly2->coef;
                expo = poly1->expo;
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else if (poly1->expo > poly2->expo) {
                coef = poly1->coef, expo = poly1->expo;
                poly1 = poly1->next;
            } else {
                coef = poly2->coef, expo = poly2->expo;
                poly2 = poly2->next;
            }
        } else if (poly1 != NULL) {
            coef = poly1->coef, expo = poly1->expo;
            poly1 = poly1->next;
        } else if (poly2 != NULL) {
            coef = poly2->coef, expo = poly2->expo;
            poly2 = poly2->next;
        }

        if (prev && prev->expo == expo) prev->coef += coef;
        else prev = insertTerm(&result, coef, expo);
    }
    return result;
}

void displayPolynomial(Term *poly) {
    if (poly == NULL) {
        printf("Empty");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coef, poly->expo);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
}

int main() {
    printf("Enter polynomial 1:\n");
    Term *poly1 = createPoly();

    printf("\nEnter polynomial 2:\n");
    Term *poly2 = createPoly();

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);

    printf("\nPolynomial 2: ");
    displayPolynomial(poly2);

    Term *result = addPolynomials(poly1, poly2);
    printf("\nSum of Polynomials: ");
    displayPolynomial(result);

    return 0;
}

/*Algorithm
Step 1: Start.

*/
