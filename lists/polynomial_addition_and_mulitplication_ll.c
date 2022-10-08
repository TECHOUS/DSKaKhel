#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int exp;
    struct node* next;
};

struct node* accept(struct node* poly, float c, int e)
{
    struct node* p, * t;
    t = (struct node*)malloc(sizeof(struct node));
    t->coeff = c;
    t->exp = e;

    if (poly == NULL || e > poly->exp)
    {
        t->next = poly;
        poly = t;
    }

    else
    {
        p = poly;
        while (p->next != NULL && p->next->exp >= e)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
    return poly;
}

struct node* accept_add(struct node* poly, float c, int e)
{
    struct node* p, * t;
    t = (struct node*)malloc(sizeof(struct node));
    t->coeff = c;
    t->exp = e;
    if (poly == NULL)
    {
        t->next = poly;
        poly = t;
    }

    else
    {
        p = poly;
        while (p->next != NULL)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
    return poly;
}

struct node* create(struct node* poly)
{
    int n, e;
    float c;
    printf("Enter the number of terms : ");
    scanf("%d", &n);
    for (int i = 1;i <= n;i++)
    {
        printf("Enter the coefficient for the term %d : ", i);
        scanf("%f", &c);
        printf("Enter the exponent for the term %d : ", i);
        scanf("%d", &e);
        poly = accept(poly, c, e);
    }
    return poly;
}

void display(struct node* p)
{
    if (p == NULL)
    {
        printf("Zero polynomial\n");
        return;
    }
    while (p != NULL)
    {
        printf("(%.1fx^%d)", p->coeff, p->exp);
        p = p->next;
        if (p != NULL)
            printf(" + ");
        else
            printf("\n");
    }
}

void poly_add(struct node* p1, struct node* p2)
{
    struct node* result;
    result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            result = accept_add(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p2->exp > p1->exp)
        {
            result = accept_add(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else if (p1->exp == p2->exp)
        {
            result = accept_add(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        result = accept_add(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        result = accept_add(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    printf("Hence, resultant polynomial after adding is : ");
    display(result);
    printf("\n");
}

void poly_multiply(struct node* p1, struct node* p2)
{
    struct node* result;
    struct node* p2_t = p2;
    result = NULL;
    if (p1 == NULL || p2 == NULL)
    {
        printf("Multiplied polynomial is equal to zero polynomial\n");
        return;
    }
    while (p1 != NULL)
    {
        p2 = p2_t;
        while (p2 != NULL)
        {
            result = accept(result, p1->coeff * p2->coeff, p1->exp + p2->exp);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    printf("Hence, resultant polynomial after multiplying is = ");
    display(result);
    printf("\n");
}

int main()
{
    struct node* poly1 = NULL, * poly2 = NULL, * poly3 = NULL, * poly4 = NULL;
    int c = 1;
    while (c != 0)
    {
        printf("Enter 1. to add two polynomials:\n");
        printf("Enter 2. to multiply two polynomials:\n");
        printf("Enter 0. to exit:\n");
        int w;
        scanf("%d", &w);
        switch (w)
        {
        case 1:
            printf("For 1st polynomial :\n");
            poly1 = create(poly1);

            printf("For 2nd polynomial :\n");
            poly2 = create(poly2);

            printf("Hence, 1st Polynomial is :  ");
            display(poly1);
            printf("Hence, 2nd Polynomial is :  ");
            display(poly2);
            poly_add(poly1, poly2);
            break;

        case 2:

            printf("For 1st polynomial :\n");
            poly3 = create(poly3);

            printf("For 2nd polynomial :\n");
            poly4 = create(poly4);

            printf("Hence, 1st Polynomial is :  ");
            display(poly3);
            printf("Hence, 2nd Polynomial is :  ");
            display(poly4);
            poly_multiply(poly3, poly4);
            break;

        case 0:
            printf("Exiting the program\n");
            c = 0;
            break;

        default:
            printf("Invalid option!");
            break;
        }
    }
    return 0;
}

