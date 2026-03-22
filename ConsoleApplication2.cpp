#include <iostream>
using namespace std;

class Convert
{
protected:
    double value1;
    double value2;

public:
    Convert(double v)
    {
        value1 = v;
    }

    double GetInitial() const
    {
        return value1;
    }

    double GetConverted() const
    {
        return value2;
    }

    virtual void Compute() = 0;
    virtual ~Convert() {}
};

class LitersToGallons : public Convert
{
public:
    LitersToGallons(double v) : Convert(v) {}

    void Compute() override
    {
        value2 = value1 / 3.7854;
    }
};

class FahrenheitToCelsius : public Convert
{
public:
    FahrenheitToCelsius(double v) : Convert(v) {}

    void Compute() override
    {
        value2 = (value1 - 32) / 1.8;
    }
};

int main()
{
    Convert* p;

    LitersToGallons litersObj(4);
    FahrenheitToCelsius tempObj(70);

    p = &litersObj;
    cout << p->GetInitial() << " liters = ";
    p->Compute();
    cout << p->GetConverted() << " gallons" << endl;

    p = &tempObj;
    cout << p->GetInitial() << " Fahrenheit = ";
    p->Compute();
    cout << p->GetConverted() << " Celsius" << endl;

    return 0;
}
