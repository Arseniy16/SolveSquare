#include <stdio.h>
#include <math.h>
#include <assert.h>

//---------------------------------------------------------------

int SolveSquare(double a, double b, double c, double* x1, double* x2);

const int UNDEF = -1;

//----------------------------------------------------------------

int main ()
{
    printf ("#This is sguare equation solver\n"
           "#(c) ShtunderMIPT 2020\n\n");

    printf ("# Enter a, b, c : ");

    double a = 0, b = 0, c = 0;
    scanf ("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int korni = SolveSquare (a, b, c, &x1, &x2);

    switch(korni)
    {
        case 0: printf ("Net korney\n");
                break;
        case 1: printf ("x = %lg\n", x1);
                break;
        case 2: printf ("x1 = %lg, x2 = %lg\n", x1, x2);
                break;
        case UNDEF: printf ("Any number\n");
                break;
        default: printf ("main() ERROR: korni = %d\n", korni);
                return 1;
    }
    return 0;
}

//----------------------------------------------------------------

int SolveSquare (double a, double b, double c, double* x1, double* x2)
{
    /* проверка на конечность коэф-ов */
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    /* проверка на правильность */
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (a == 0)
    {
        if (b == 0)
        {
            return (c == 0) ? UNDEF : 0;
        }
        else /* if (b != 0) */
        {
            *x1 = -c / b;
            return 1;
        }
    }
    else    /* if (a != 0) */
    {
       double d = b*b - 4*a*c;
        if (d == 0)
        {
            *x1 = *x2 = -b / (2*a);
            return 1;
        }
        else if (d > 0)
        {
            double sqr = sqrt (d);
            *x1 = (-b + sqr) / (2*a);
            *x2 = (-b - sqr) / (2*a);
            return 2;
        }
        else    /* if(d < 0) */
            return 0;
    }

}

