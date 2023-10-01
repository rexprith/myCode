//Example of pure virtual function -- Abstract CLass -- Runtime Polymorphism
//Prithwiraj Shome

#include <iostream>

using namespace std;

typedef class Shape {
protected:
	double height = 0;
	double width = 0;
	double radius = 0;
	const double pi = 3.14;

public:
	void set_height_width(double h, double w)
	{
		height = h;
		width = w;
	}

	void set_radius(double r)
	{
		radius = r;
	}
	virtual void show() = 0; //Pure virtual function -- will be defined in derived classes
	virtual double area() = 0; //Pure virtual function -- will be defined in derived classes

}SHAPE;

typedef class Rectangle : public SHAPE {

public:
	Rectangle(double h, double w)
	{
		height = h;
		width = w;

	}

	double area()
	{
		return (height * width);
	}

	void show()
	{
		cout << "Height = " << height << endl;
		cout << "Width = " << width << endl;
	}

}RECTANGLE;

typedef class Circle : public SHAPE {

public:
	Circle(double r)
	{
		radius = r;
	}
	double area()
	{
		return (pi * radius * radius);
	}

	void show()
	{
		cout << "Radius = " << radius << endl;
	}
}CIRCLE;

int main(void)
{

	SHAPE * sPtr = new RECTANGLE(3,4); // Notice the pointer is of base class type but instance is of derived class type

	sPtr->show();
	cout << "Rectangle area is = " << sPtr->area() << " unit square" << endl;
	sPtr->set_height_width(2, 2);
	sPtr->show();
	cout << "Rectangle area is = " << sPtr->area() << " unit square" << endl;

	SHAPE * cPtr = new CIRCLE(1); // Notice the pointer is of base class type but instance is of derived class type

	cPtr->show();
	cout << "Circle Area is = " << cPtr->area() << " unit square" << endl;
	cPtr->set_radius(5);
	cPtr->show();
	cout << "Circle Area is = " << cPtr->area() << " unit square" << endl;
}