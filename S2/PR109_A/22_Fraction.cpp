// Description

// Please create a class Fraction represent a fraction number.

// Create a default constructor to set the fraction number to 0.

// Create a constructor Fraction(int numerator, int denominator)

// The class Fraction should include the following function member at least,

// int getNumerator(); // return the numerator of the fraction number.

// int getDenominator(); // return the denominator of the fraction number.

// void setNumerator(int ); // use the parameter to set numerator of the fraction.

// void setDenominator(int ); // use the parameter to set denominator of the fraction.

// void display(); // display the irreducible fractions the format "(numerator/denominator)".
// e.g. (5/9).you should not display denominator if denominator is 1.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

class Fraction
{
private:
    int numerator;
    int denominator;

    void copy(Fraction &that)
    {
        this->numerator = that.numerator;
        this->denominator = that.denominator;
    }
    void reductionOfFraction()
    {
        if (denominator == 0)
            return;
        if (denominator < 0 && numerator < 0)
        {
            denominator = -denominator;
            numerator = -numerator;
        }
        int scale = (numerator > denominator) ? numerator : denominator;
        int i = scale;
        while (i > 0 && !(numerator % i == 0 && denominator % i == 0))
            --i;
        if (i != 1)
        {
            numerator /= i;
            denominator /= i;
        }
    }
    void reductionToCommonDenominator(Fraction &that)
    {
        if (this->denominator != that.denominator)
        {
            this->denominator *= std::abs(that.denominator);
            this->numerator *= std::abs(that.denominator);
            that.denominator *= std::abs(this->denominator);
            that.numerator *= std::abs(this->denominator);
        }
    }

public:
    Fraction()
    {
        numerator = 0;
        denominator = 0;
    }
    Fraction(int numerator, int denominator)
    {
        Fraction::numerator = numerator;
        Fraction::denominator = denominator;
    }
    Fraction(Fraction &that)
    {
        copy(that);
        reductionOfFraction();
    }
    int getDenominator() const
    {
        return denominator;
    }
    int getNumerator() const
    {
        return numerator;
    }
    void setDenominator(int that)
    {
        denominator = that;
    }
    void setNumerator(int that)
    {
        numerator = that;
    }
    void display()
    {
        reductionOfFraction();

        //*this = temp;
        std::cout << "(" << numerator;
        if (denominator != 1)
            std::cout << "/" << denominator;
        std::cout << ")";
    }

    bool operator==(Fraction &that)
    {
        that.reductionOfFraction();
        this->reductionOfFraction();
        return this->denominator == that.denominator && this->numerator == that.numerator;
    }
    bool operator!=(Fraction &that)
    {
        return !(*this == that);
    }

    Fraction operator=(Fraction &that)
    {
        if (*this != that)
            copy(that);
        return *this;
    }

    Fraction &operator+(Fraction &that)
    {
        static Fraction temp;
        that.reductionOfFraction();
        this->reductionOfFraction();
        if (this->denominator == that.denominator)
        {
            temp.denominator = denominator;
            temp.numerator = this->numerator + that.numerator;
        }
        else
        {
            Fraction temp1(*this), temp2(that);
            temp1.reductionToCommonDenominator(temp2);
            temp.denominator = temp1.denominator;
            temp.numerator = temp1.numerator + temp2.numerator;
        }
        temp.reductionOfFraction();
        return temp;
    }
    Fraction &operator-(Fraction &that)
    {
        static Fraction temp;
        that.reductionOfFraction();
        this->reductionOfFraction();
        if (this->denominator == that.denominator)
        {
            temp.denominator = denominator;
            temp.numerator = this->numerator - that.numerator;
        }
        else
        {
            Fraction temp1(*this), temp2(that);
            temp1.reductionToCommonDenominator(temp2);
            temp.denominator = temp1.denominator;
            temp.numerator = temp1.numerator - temp2.numerator;
        }
        temp.reductionOfFraction();
        return temp;
    }
    Fraction &operator*(Fraction &that)
    {
        static Fraction temp;
        temp.denominator = this->denominator * that.denominator;
        temp.numerator = this->numerator * that.numerator;
        temp.reductionOfFraction();
        return temp;
    }
    Fraction &operator/(Fraction &that)
    {
        static Fraction temp;
        temp.denominator = this->denominator * that.numerator;
        temp.numerator = this->numerator * that.denominator;
        temp.reductionOfFraction();
        return temp;
    }

    friend std::ostream &operator<<(std::ostream &outputStream, Fraction &that)
    {
        that.display();
        return outputStream;
    }

    Fraction &operator!()
    {
        static Fraction temp;
        temp.denominator = numerator;
        temp.numerator = denominator;
        return temp;
    }
};