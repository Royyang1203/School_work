// Description

// Please create a class Fraction represent a fraction number.

// Create a default constructor to set the fraction number to 0.

// Create a constructor Fraction(int numerator, int denominator)

// The class Fraction should include the following function member at least,

// int getNumerator(); // return the numerator of the fraction number.

// int getDenominator(); // return the denominator of the fraction number.

// void setNumerator(int ); // use the parameter to set numerator of the fraction.

// void setDenominator(int ); // use the parameter to set denominator of the fraction.

// void display(); // display the irreducible fractions the format "(numerator/denominator)". e.g. (5/9). you should not display denominator ifdenominator is 1.

// Please override operator +, -, *, / and = make the following statement work.

// Fraction a, b, c, d, e, f;

// a = (((b + c) - d) * e) / f;

// Please override operator <<make the following statement work.

// cout<<a;

// Please override operator ! to return reciprocal of the fraction number.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

class Fraction;

extern std::ostream &operator<<(std::ostream &outputStream, Fraction &that);

class Fraction
{
private:
    int numerator;
    int denominator;

    void copy(const Fraction &that)
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
            int n1 = std::abs(that.denominator);
            int n2 = std::abs(this->denominator);
            this->denominator *= n1;
            this->numerator *= n1;
            that.denominator *= n2;
            that.numerator *= n2;
        }
    }

public:
    Fraction(int numerator = 0, int denominator = 1)
    {
        Fraction::numerator = numerator;
        Fraction::denominator = denominator;
    }
    Fraction(const Fraction &that)
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

    bool operator==(const Fraction &that) const
    {
        Fraction a = *this, b = that;
        a.reductionOfFraction();
        b.reductionOfFraction();
        return a.denominator == b.denominator && a.numerator == b.numerator;
    }
    bool operator!=(const Fraction &that) const
    {
        return !(*this == that);
    }

    Fraction &operator=(const Fraction &that)
    {
        if (*this != that)
            copy(that);
        return *this;
    }

    const Fraction operator+(const Fraction &that) const
    {
        Fraction temp(this->getNumerator() * that.getDenominator() + this->getDenominator() * that.getNumerator(), this->getDenominator() * that.getDenominator());
        temp.reductionOfFraction();
        return temp;
    }
    const Fraction operator-(const Fraction &that) const
    {
        Fraction temp = that;
        temp.numerator *= -1;
        Fraction res = *this + temp;
        return res;
    }
    const Fraction operator*(const Fraction &that) const
    {
        Fraction temp(this->getNumerator() * that.getNumerator(), this->getDenominator() * that.getDenominator());
        temp.reductionOfFraction();
        return temp;
    }
    const Fraction operator/(const Fraction &that) const
    {
        Fraction temp(this->getNumerator() * that.getDenominator(), this->getDenominator() * that.getNumerator());
        temp.reductionOfFraction();
        return temp;
    }

    friend std::ostream &operator<<(std::ostream &outputStream, Fraction &that);

    Fraction operator!() const
    {
        return Fraction(this->denominator, this->numerator);
    }
};

std::ostream &operator<<(std::ostream &outputStream, Fraction &that)
{
    that.display();
    return outputStream;
}

int main()
{
    const Fraction n1(8, 3), n2(4, 9), n3(5, 9), n4(1, 2);
    Fraction n;
    n = n3 + n4 * n1;

    // a = b = c = 3;
    //n1 = !n1;

    std::cout << n << std::endl;
}

// _____________________________________________________________

// class Fraction
// {
// private:
//     int numerator = 0;
//     int denominator = 0;
//     void reduction ()
//     {
//         int s = numerator < denominator ? numerator : denominator;
//         for (int i = s ; i > 1; -- i)
//         {
//             if (numerator % i == 0 && denominator % i == 0)
//             {
//                 numerator /= i;
//                 denominator /= i;
//                 return;
//             }
//         }
//         return;
//     }

// public:
//     Fraction () = default;
//     Fraction (int n, int d) : numerator(n), denominator(d) {}

//     int getNumerator () const
//     {
//         return numerator;
//     }
//     int getDenominator () const
//     {
//         return denominator;
//     }
//     void setNumerator (int n)
//     {
//         numerator = n;
//     }
//     void setDenominator (int d)
//     {
//         denominator = d;
//     }
//     void display () const
//     {
//         Fraction f(numerator, denominator);
//         f.reduction();
//         std::cout << "(" << f.numerator;

//         if (f.denominator != 1)
//             std::cout << "/" << f.denominator;

//         std::cout << ")";
//     }

//     Fraction operator + (const Fraction &that) const
//     {
//         return Fraction(this->numerator * that.denominator + that.numerator * this->denominator,
//                         that.denominator * this->denominator);
//     }
//     Fraction operator - (const Fraction &that) const
//     {
//         return Fraction(this->numerator * that.denominator - that.numerator * this->denominator,
//                         that.denominator * this->denominator);
//     }
//     Fraction operator * (const Fraction &that) const
//     {
//         return Fraction(this->numerator * that.numerator,
//                         that.denominator * this->denominator);
//     }
//     Fraction operator / (const Fraction &that) const
//     {
//         return Fraction(this->numerator * that.denominator,
//                         that.numerator * this->denominator);
//     }

//     friend std::ostream &operator << (std::ostream &os, const Fraction &that)
//     {
//         that.display();
//         return os;
//     }

//     Fraction operator ! () const
//     {
//         return Fraction(denominator, numerator);
//     }

// };

// #include <iostream>
// #include <iomanip>
// #include <cstdlib>
// #include <cmath>

// class Fraction
// {
// private:
//     int numerator;
//     int denominator;

//     void copy(Fraction &that)
//     {
//         this->numerator = that.numerator;
//         this->denominator = that.denominator;
//     }
//     void reductionOfFraction()
//     {
//         if (denominator == 0)
//             return;
//         if (denominator < 0 && numerator < 0)
//         {
//             denominator = -denominator;
//             numerator = -numerator;
//         }
//         int scale = (numerator > denominator) ? numerator : denominator;
//         int i = scale;
//         while (i > 0 && !(numerator % i == 0 && denominator % i == 0))
//             --i;
//         if (i != 1)
//         {
//             numerator /= i;
//             denominator /= i;
//         }
//     }
//     void reductionToCommonDenominator(Fraction &that)
//     {
//         if (this->denominator != that.denominator)
//         {
//             int n1 = std::abs(that.denominator);
//             int n2 = std::abs(this->denominator);
//             this->denominator *= n1;
//             this->numerator *= n1;
//             that.denominator *= n2;
//             that.numerator *= n2;
//             //std::cout << this->numerator << "  " << that.numerator << std::endl;
//             //std::cout << this->denominator << "  " << that.denominator << std::endl;
//         }
//     }

// public:
//     Fraction()
//     {
//         numerator = 0;
//         denominator = 0;
//     }
//     Fraction(int numerator, int denominator)
//     {
//         Fraction::numerator = numerator;
//         Fraction::denominator = denominator;
//     }
//     Fraction(Fraction &that)
//     {
//         copy(that);
//         reductionOfFraction();
//     }
//     int getDenominator() const
//     {
//         return denominator;
//     }
//     int getNumerator() const
//     {
//         return numerator;
//     }
//     void setDenominator(int that)
//     {
//         denominator = that;
//     }
//     void setNumerator(int that)
//     {
//         numerator = that;
//     }
//     void display()
//     {
//         reductionOfFraction();

//         //*this = temp;
//         std::cout << "(" << numerator;
//         if (denominator != 1)
//             std::cout << "/" << denominator;
//         std::cout << ")";
//     }

//     bool operator==(Fraction &that)
//     {
//         that.reductionOfFraction();
//         this->reductionOfFraction();
//         return this->denominator == that.denominator && this->numerator == that.numerator;
//     }
//     bool operator!=(Fraction &that)
//     {
//         return !(*this == that);
//     }

//     Fraction operator=(Fraction &that)
//     {
//         if (*this != that)
//             copy(that);
//         return *this;
//     }

//     Fraction &operator+(Fraction &that)
//     {
//         static Fraction temp;
//         that.reductionOfFraction();
//         this->reductionOfFraction();
//         if (this->denominator == that.denominator)
//         {
//             temp.denominator = denominator;
//             temp.numerator = this->numerator + that.numerator;
//         }
//         else
//         {
//             Fraction temp1(*this), temp2(that);
//             temp1.reductionToCommonDenominator(temp2);
//             //std::cout << temp1 << "  " <<temp2 << std::endl;
//             temp.denominator = temp1.denominator;
//             temp.numerator = temp1.numerator + temp2.numerator;
//         }
//         temp.reductionOfFraction();
//         return temp;
//     }
//     Fraction &operator-(Fraction &that)
//     {
//         static Fraction temp;
//         that.reductionOfFraction();
//         this->reductionOfFraction();
//         if (this->denominator == that.denominator)
//         {
//             temp.denominator = denominator;
//             temp.numerator = this->numerator - that.numerator;
//         }
//         else
//         {
//             Fraction temp1(*this), temp2(that);
//             temp1.reductionToCommonDenominator(temp2);
//             temp.denominator = temp1.denominator;
//             temp.numerator = temp1.numerator - temp2.numerator;
//         }
//         temp.reductionOfFraction();
//         return temp;
//     }
//     Fraction &operator*(Fraction &that)
//     {
//         static Fraction temp;
//         temp.denominator = this->denominator * that.denominator;
//         temp.numerator = this->numerator * that.numerator;
//         temp.reductionOfFraction();
//         return temp;
//     }
//     Fraction &operator/(Fraction &that)
//     {
//         static Fraction temp;
//         temp.denominator = this->denominator * that.numerator;
//         temp.numerator = this->numerator * that.denominator;
//         temp.reductionOfFraction();
//         return temp;
//     }

//     friend std::ostream &operator<<(std::ostream &outputStream, Fraction &that)
//     {
//         that.display();
//         return outputStream;
//     }

//     Fraction &operator!()
//     {
//         static Fraction temp;
//         temp.denominator = numerator;
//         temp.numerator = denominator;
//         return temp;
//     }
// };