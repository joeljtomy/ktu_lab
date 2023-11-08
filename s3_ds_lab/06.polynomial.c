// 6.  Apply linked list concept to perform polynomial addition.

#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coef;
    int expo;
    struct Term *next;
};

struct Term *createTerm(int coef, int exp)
{
    struct Term *term = (struct Term *)malloc(sizeof(struct Term));
    term->coef = coef;
    term->expo = exp;
    term->next = NULL;
    return term;
}

struct Term *insertTerm(struct Term **head, int coef, int exp)
{
    struct Term *newTerm = createTerm(coef, exp);
    if (*head == NULL || exp > (*head)->expo)
    {
        newTerm->next = *head;
        *head = newTerm;
    }
    else
    {
        struct Term *current = *head;
        while (current->next != NULL && current->next->expo >= exp)
        {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
    return newTerm;
}

struct Term *createPoly()
{
    int n, coef, expo, i;
    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n);
    struct Term *poly = NULL;
    for (i = 0; i < n; i++)
    {
        printf("Enter coef & expo of term %d: ", i + 1);
        scanf("%d %d", &coef, &expo);
        insertTerm(&poly, coef, expo);
    }
    return poly;
}

struct Term *addPolynomials(struct Term *poly1, struct Term *poly2)
{
    struct Term *result = NULL;
    struct Term *prev = NULL;
    int coef, expo;

    while (poly1 != NULL || poly2 != NULL)
    {
        if (poly1 != NULL && poly2 != NULL)
        {
            if (poly1->expo == poly2->expo)
            {
                coef = poly1->coef + poly2->coef;
                expo = poly1->expo;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
            else if (poly1->expo > poly2->expo)
            {
                coef = poly1->coef, expo = poly1->expo;
                poly1 = poly1->next;
            }
            else
            {
                coef = poly2->coef, expo = poly2->expo;
                poly2 = poly2->next;
            }
        }
        else if (poly1 != NULL)
        {
            coef = poly1->coef, expo = poly1->expo;
            poly1 = poly1->next;
        }
        else if (poly2 != NULL)
        {
            coef = poly2->coef, expo = poly2->expo;
            poly2 = poly2->next;
        }

        if (prev && prev->expo == expo)
        {
            prev->coef += coef;
        }
        else
        {
            prev = insertTerm(&result, coef, expo);
        }
    }
    return result;
}

void displayPolynomial(struct Term *poly)
{
    if (poly == NULL)
    {
        printf("0\n");
        return;
    }

    while (poly != NULL)
    {
        printf("%dx^%d", poly->coef, poly->expo);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main()
{
    printf("Enter polynomial 1:\n");
    struct Term *poly1 = createPoly();

    printf("\nEnter polynomial 2:\n");
    struct Term *poly2 = createPoly();

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);

    printf("\nPolynomial 2: ");
    displayPolynomial(poly2);

    struct Term *result = addPolynomials(poly1, poly2);
    printf("\nSum of Polynomials: ");
    displayPolynomial(result);

    return 0;
}

/*Algorithm
Step 1: Start.

*/
