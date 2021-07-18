#include <iostream>

using namespace std;

class Fraction
{
    public:
        Fraction();
        Fraction(int x, int y);

        int GCD(int fracA, int FracB);

        void subtract(Fraction fracA, Fraction fracB);
        void multiply(Fraction fracA, Fraction fracB);
        void divide(Fraction fracA, Fraction fracB);
        void add(Fraction fracA, Fraction fracB);
        void lowestForm();
        void printResult();
        void compare(Fraction fracA, Fraction fracB);

    private:
        int xNum;
        int yDen;
};

Fraction::Fraction(): Fraction(0,1) {}

Fraction::Fraction(int x, int y): xNum(x), yDen(y) {}

int Fraction::GCD(int fracA, int fracB)//returns greatest common denominator
{
    if(fracA == 0)
    {
        return fracB;
    }
    return GCD(fracB%fracA, fracA);
}

void Fraction::lowestForm()//returns its simplified form I should really have jsut called this simplify
{
    int commonFactor = GCD(xNum, yDen);

    xNum = xNum/commonFactor;
    yDen = yDen/commonFactor;
}

void Fraction::add(Fraction fracA, Fraction fracB)
{
    xNum =(fracA.xNum * fracB.yDen) + (fracB.xNum*fracA.yDen);
    yDen = (fracA.yDen * fracB.yDen);
    lowestForm();
    cout<<"The fraction added result: "<<endl;
    cout<<xNum<<"/"<<yDen<<endl;
}

void Fraction::multiply(Fraction fracA, Fraction fracB)
{
    xNum = (fracA.xNum * fracB.xNum);
    yDen = (fracA.yDen * fracB.yDen);
    lowestForm();
    cout<<"The Fractions multiplied result: "<<endl;
    cout<<xNum<<"/"<<yDen<<endl;
}

void Fraction::subtract(Fraction fracA, Fraction fracB)
{
    xNum = (fracA.xNum * fracB.yDen) - (fracB.xNum * fracA.yDen);
    yDen = (fracA.yDen * fracB.yDen);
    lowestForm();
    cout<<"The fractions subtracted result: "<<endl;
    cout<<xNum<<"/"<<yDen<<endl;
}

void Fraction::divide(Fraction fracA, Fraction fracB)
{
    xNum = (fracA.xNum * fracB.yDen);
    yDen = (fracA.yDen * fracB.xNum);
    lowestForm();
    cout<<"The fractions divided result: "<<endl;
    cout<<xNum<<"/"<<yDen<<endl;
}

void Fraction::compare(Fraction fracA, Fraction fracB)
{       
    int fraction = (fracA.xNum*fracB.yDen) - (fracA.yDen*fracB.xNum);

    if(fraction == 0)
    {
        cout<<"The fractions are the same!";
        cout<<endl;
    }
    if(fraction>0)
    {
        fracA.printResult();
        cout<<" is greater than ";
        fracB.printResult();
        cout<<endl;
    }
    else
    {
        fracB.printResult();
        cout<<" is greater than ";
        fracA.printResult();
        cout<<endl;
    }
}

void Fraction::printResult()
{
    lowestForm();
    cout<<xNum<<"/"<<yDen;
}

int main()
{
     bool calculateAgain;
    do
    {
        int numerator1, numerator2, denominator1, denominator2;
        char choice;
       

        cout<<"please enter numbers for first fraction separated by a space - (numerator/denominator): ";
        cin>>numerator1>>denominator1;
        cout<<"please enter numbers for second fraction separated by a space - (numerator/denominator): ";
        cin>>numerator2>>denominator2;

        Fraction fraction1(numerator1,denominator1);
        Fraction fraction2(numerator2,denominator2);
        Fraction fraction;

        
        fraction.add(fraction1, fraction2);
        fraction.multiply(fraction1, fraction2);
        fraction.subtract(fraction1, fraction2);
        fraction.divide(fraction1, fraction2);
        fraction.compare(fraction1, fraction2);

        cout<<"would you like to do another calculation? (Y/N): ";
        cin>>choice;

        if(choice == 'Y' || choice == 'y')
        {
            calculateAgain = true;
        }
        else
        {
            calculateAgain = false;
        }

    }while(calculateAgain == true);


    return 0;
}