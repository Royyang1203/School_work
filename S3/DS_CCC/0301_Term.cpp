#include <iostream>

class Term
{
public:
    int coef;                               // coefficient
    int exp;                                // exponent
    Term *next;                             // pointer to the next term
    Term() : coef(0), exp(0), next(NULL) {} // default constructor
    Term(Term &t)                           // copy constructor
    {
        coef = t.coef;
        exp = t.exp;
        next = NULL;
    }
};