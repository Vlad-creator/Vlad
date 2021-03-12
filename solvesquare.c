
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define INF 1000
#define CORR "correct\n"
#define FAIL "failed"

//---------------------------------------------------
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots ,
//!       returns INF
//---------------------------------------------------
int solvesquare (double a, double b, double c, double* x1, double* x2);

//---------------------------------------------------
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 Pointer to the 1st root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots ,
//!       returns INF
//---------------------------------------------------
int solvelinear (double b, double c, double* x1);

//---------------------------------------------------
//! UNIT TEST
//---------------------------------------------------
void check();

//---------------------------------------------------

//! @param [in] n n-double type number
//! @param [in] eps eps-const
//!
//! @return is the number equal to zero
//---------------------------------------------------
int isZero(double n, double eps);

//---------------------------------------------------
//! @param [out] a Pointer to the coefficient of x^2
//! @param [out] b Pointer to the coefficient of x^1
//! @param [out] c Pointer to the coefficient of x^0
//---------------------------------------------------
void input (double *a, double *b, double *c);

//---------------------------------------------------
//! @param [in] nsolves nsolves- number of solves
//! @param [in] x1-1st root
//! @param [in] x2-2nd root
//! @note print of solvesquare
//---------------------------------------------------
void otvet(int nsolves , double x1 , double x2);




int main()
{
    double eps = 0.002;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int norm = 0, nsolves = 0;

    check();
    printf("SOLVE SQUARE\n");
    printf("enter a b c\n");
    input(&a, &b, &c);

    nsolves = solvesquare(a, b, c, &x1, &x2);
    otvet(nsolves , x1 , x2);
    return 0;
}

int isZero(double n, double eps)
{
    if (fabs(n) < eps)
        return 0;
    else
        return 1;
}

int solvesquare (double a, double b, double c, double* x1, double* x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    double eps = 0.002;

    if (a == 0)
        solvelinear (b, c, x1);
    else
    {
        double d = (b * b) - (4 * a * c);
        if (d < 0)
            return 0;
        if (isZero(d, eps) == 0)
        {
            *x1 = -b / (2 * a);
            return 1;
        }
        if (d > 0)
        {
            *x1 = (-b + sqrt(d)) / (2 * a);
            *x2 = (-b - sqrt(d)) / (2 * a);
            return 2;
        }
    }


}

int solvelinear (double b, double c, double* x1)
{
    if (b == 0)
        return (c == 0) ? INF : 0;
    else
    {
        *x1 = -c / b;
        return 1;
    }
}

void check()
{
    printf ("chtobi proverit rabotosposobnost vvedite 1 inache 0 \n");
    int chekk;
    scanf ("%d", &chekk);
    if (chekk == 1)
    {
        double x3 = 0, x4 = 0;
        if (solvesquare(0, 0, 0, &x3, &x4) == INF)
            if (x3 == 0)
                printf (CORR);
            else
                printf (FAIL);
        if (solvesquare(1, 2, 1, &x3, &x4) == 1)
            if (x3 == -1)
                printf (CORR);
            else
                printf (FAIL);
        if (solvesquare(0, 0, 1, &x3, &x4) == 0)
            if (x3 == -1)
                printf (CORR);
            else
                printf (FAIL);
        if (solvesquare(0, 1, -1, &x3, &x4) == 1)
            if (x3 == 1)
                printf (CORR);
            else
                printf (FAIL);
        if (solvesquare(1, 0, -1, &x3, &x4) == 2)
            if (x3 == 1)
                printf (CORR);
            else
                printf (FAIL);
    }

}

void input (double *a, double *b, double *c)
{
    int norm;
    norm = scanf("%lg %lg %lg", a, b, c);
    while (norm != 3)
    {
        char* s = (char*)calloc(100, sizeof(char));
        scanf ("%s", s);
        printf ("VVEDITE CHISLO \n");
        norm = scanf("%lg %lg %lg", a, b, c);

    }
}

void otvet (int nsolves , double x1 , double x2)
{
    switch (nsolves)
    {
    case 0:
        printf ("noup");
        break;
    case 1:
        printf ("1 solve - %g", x1);
        break;
    case 2:
        printf ("2 solve - %g %g", x1, x2);
        break;
    case INF:
        printf ("Not a limit");
        break;
    default :
        printf ("ERROR");
    }
}
