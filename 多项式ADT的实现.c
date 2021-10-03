#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED
#define MaxDegree 100
struct P
{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
};
typedef struct P  * Polynomial;
#endif // POLYNOMIAL_H_INCLUDED
#include "polynomial.h"
#include <stdio.h>
#include <stdlib.h>
int Max(int a,int b)
{
    return a > b? a:b;
}

void Error(char * e)
{

}
void ZeroPolynomial(Polynomial Poly)
{
    int i;

    for( i = 0; i <= MaxDegree; i++)
        Poly->CoeffArray[i] = 0;
    Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial Poly1,const Polynomial Poly2,Polynomial PolySum)
{
    int i;

    ZeroPolynomial(PolySum);
    PolySum->HighPower = Max(Poly1->HighPower,Poly2->HighPower);

    for( i = PolySum->HighPower; i >= 0; i--)
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
//  printf("%d ",PolySum->HighPower);
}

void MultPolynomial(const Polynomial Poly1,const Polynomial Poly2,const Polynomial PolyProd)
{
    int i,j;

    ZeroPolynomial(PolyProd);
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

    if( PolyProd->HighPower > MaxDegree)
        Error("Exceeded  array size");
    else
        for(i = 0; i <= Poly1->HighPower; i++)
            for(j = 0; j <= Poly2->HighPower; j++)
                PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i]*Poly2->CoeffArray[j];
}

int main()
{
    Polynomial a;
    a = malloc(sizeof(struct P));
    ZeroPolynomial(a);
    a -> HighPower = 4;
    int i;
    for(i = 0; i < 5 ; i++)
    {
        // scanf("%d",(a->CoeffArray)[i]);
        a->CoeffArray[i] = i;
    }
    Polynomial b;
    b = malloc(sizeof(struct P));
    ZeroPolynomial(b);
    b -> HighPower = 4;
    for(i = 0; i < 5 ; i++)
    {
        // scanf("%d",(b->CoeffArray)[i]);
        b->CoeffArray[i] = i;
    }
    Polynomial sum;
    sum = malloc(sizeof(struct P));
  //  AddPolynomial(a,b,sum);
  //  for(i = 0; i < 5 ; i++)
   //     printf("%d ",sum->CoeffArray[i]);
    MultPolynomial(a,b,sum);
    for(i = 0; i < a->HighPower+b->HighPower+1 ; i++)
        printf("%d ",sum->CoeffArray[i]);
}
