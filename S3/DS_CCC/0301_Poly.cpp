#include "exercise_3_Term.cpp"
#include <iostream>

class Poly
{
public:
    int n_terms;                    // number of terms in the polynomial
    Term *p;                        // the pointer to the first term in the linked list
    Poly() : n_terms(0), p(NULL) {} // default constructor
    Poly(Poly &p);                  // copy constructor
    void Add(Term *t);              // add a single term pointed by t to the polynomial
    void Add(Poly *p);              // add a polynomial pointed by p to this polynomial (update this polynomial with the result directly)
    void Mul(Term *t);              // multiply the polynomial with a single term pointed by t (update this polynomial with the result directly)
    void Mul(Poly *p);              // multiply the polynomial with a polynomial pointed by p (update this polynomial with the result directly)
    void Print();                   // display the polynomial
};

Poly::Poly(Poly &poly)
{
    Term *q = poly.p; // get the first term of the source poly
    p = NULL;         // clear the list of this polynomial
    while (q)         // add to this polynomial by copying terms in the source poly one by one
    {
        Term *t = new Term(*q); // copy the current term of the source poly
        Add(t);                 // add the term to this polynomial
        q = q->next;            // get the next term of the source poly
    }
}

void Poly::Print()
{
    Term *q = p;              // start from the first term
    while (q && q->coef == 0) // find the first term with a non-zero coefficient
        q = q->next;
    if (q) // output the found first term
        std::cout << q->coef << "x^" << q->exp;
    q = q->next; // get the next term
    while (q)    // visit the terms one by one for output
    {
        int c = q->coef; // if positive coefficient, then preced this term with a plus sign
        char op = '+';   // plus sign
        if (q->coef < 0) // otherwise, preced this term with a minus sign
        {
            op = '-';
            c = -c; // change the sign of coeff since it has been preceded with a minus
        }
        if (q->coef != 0) // output this term if coeff is not zero
            std::cout << op << c << "x^" << q->exp;
        q = q->next; // get the next term
    }
    std::cout << std::endl;
}

/**
 * @brief add a single term pointed by t to the polynomial
 *
 * @param that
 */
void Poly::Add(Term *that)
{
    if (p == NULL)
    {
        p = that;
        return;
    }
    Term *cur = p;
    while (cur->next != NULL && cur->next->exp <= that->exp)
    {
        cur = cur->next;
    }

    if (cur->exp == that->exp)
    {
        cur->coef += that->coef;
    }
    else if (cur->exp > that->exp)
    {
        that->next = p;
        p = that;
    }
    else
    {
        that->next = cur->next;
        cur->next = that;
    }
}

/**
 * @brief add a polynomial pointed by p to this polynomial (update this polynomial with the result directly)
 *
 * @param that
 */
void Poly::Add(Poly *that)
{
    Term *ptr = that->p;
    while (ptr)
    {
        Term *temp = new Term(*ptr);
        Add(temp);
        // std::cout << ptr->coef << " " << ptr->exp << std::endl;
        ptr = ptr->next;
        // Print();
        // delete temp;
    }
}

/**
 * @brief multiply the polynomial with a single term pointed by t (update this polynomial with the result directly)
 *
 * @param t
 */
void Poly::Mul(Term *t)
{
    Term *ptr = this->p;
    while (ptr != NULL)
    {
        ptr->exp += t->exp;
        ptr->coef *= t->coef;
        ptr = ptr->next;
    }
}

/**
 * @brief multiply the polynomial with a polynomial pointed by p (update this polynomial with the result directly)
 *
 * @param p
 */
void Poly::Mul(Poly *that)
{
    Poly *temp = new Poly(*this);
    this->p = NULL;
    Term *cur = that->p;
    while (cur != NULL)
    {
        Poly *t = new Poly(*temp);
        t->Mul(cur);
        this->Add(t);
        // delete t;
        cur = cur->next;
    }
    // delete temp;
}
