#include "exercise_3_Poly.cpp"
#include <iostream>
#include <ctime>

using namespace std;

Poly *GeneratePoly(int n)
{
    Poly *poly = new Poly();
    for (int i = 0; i < n; i++)
    {
        Term *t = new Term();
        t->coef = rand() % 100 - 50;
        t->exp = rand() % 20;
        // cout << t->coef << " " << t->exp << endl;
        poly->Add(t);
        // poly->Print();
    }
    return poly;
}

int main()
{

    // // srand(time(nullptr));
    // srand(1);
    // Poly *pl1 = GeneratePoly(8); // randomly generate a polynomial of at most 8 terms
    // pl1->Print();                // display the pl1
    // Poly *pl2 = GeneratePoly(3); // randomly generate a polynomial of at most 3 terms
    // pl2->Print();                // display the pl2
    // // pl1->Add(pl2);               // perform the polynomial mulitiplication between pl1 and pl2 and the result is stored on pl1
    // // pl1->Print();                // display the multiplication result

    // // Term *temp = new Term(*(pl2->p));
    // pl1->Mul(pl2); // perform the polynomial mulitiplication between pl1 and pl2 and the result is stored on pl1
    // pl1->Print();  // display the multiplication result

    srand(111);
    Poly *pl1 = GeneratePoly(4);
    pl1->Print();
    Poly *pl2 = GeneratePoly(6);
    pl2->Print();
    pl1->Mul(pl2);
    pl1->Print();
}
/**
 * output
 *
 * 30x^3+35x^4+13x^5-21x^6-21x^10-10x^13-1x^18
 * 17x^10+9x^14+8x^15
 * 510x^13+595x^14+221x^15-357x^16+270x^17+555x^18+397x^19-442x^20-168x^21-170x^23-189x^24-168x^25-90x^27-97x^28-9x^32-8x^33
 */