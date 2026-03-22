#include <iostream>
#include <vector>
using namespace std;

class Figure
{
public:
    virtual double Area() const = 0;
    virtual void Show() const = 0;
    virtual ~Figure() {}
};

class Triangle : public Figure
{
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double Area() const override
    {
        return 0.5 * base * height;
    }

    void Show() const override
    {
        cout << "Triangle: base = " << base
            << ", height = " << height
            << ", area = " << Area() << endl;
    }
};

class Rectangle : public Figure
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double Area() const override
    {
        return width * height;
    }

    void Show() const override
    {
        cout << "Rectangle: width = " << width
            << ", height = " << height
            << ", area = " << Area() << endl;
    }
};

class Circle : public Figure
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Area() const override
    {
        return 3.14159 * radius * radius;
    }

    void Show() const override
    {
        cout << "Circle: radius = " << radius
            << ", area = " << Area() << endl;
    }
};

int main()
{
    vector<Figure*> figures;

    figures.push_back(new Triangle(6, 4));
    figures.push_back(new Rectangle(5, 3));
    figures.push_back(new Circle(2.5));

    cout << "Polymorphism demonstration:" << endl;
    for (Figure* f : figures)
    {
        f->Show();
    }

    for (Figure* f : figures)
    {
        delete f;
    }

    return 0;
}