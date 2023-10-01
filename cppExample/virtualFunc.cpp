//Example of virtual function
//Prithwiraj Shome

#include <iostream>

using namespace std;

typedef enum area_type {
	CIRCLE_AREA,
	RECTANGLE_AREA,
	UNKNOWN
}AREA_TYPE;


//Base class
typedef class Shape {
protected:
	AREA_TYPE type = UNKNOWN;
	double height = 0;
	double width = 0;
	double radius = 0;
	const double pi = 3.14;

public:
	Shape() {};
	Shape(double h, double w, double r)
	{
		height = h;
		width = w;
		radius = r;
	}
	void setType(AREA_TYPE t)
	{
		type = t;
	}
	virtual void show() // Virtual function but not Pure
	{
		if (type == RECTANGLE_AREA) {
			cout << "Height = " << height << endl;
			cout << "Width = " << width << endl;
		}
		else if (type == CIRCLE_AREA) {
			cout << "Radius = " << radius << endl;
		}
	}
	//  Virtual Function
	virtual double area(void) // Virtual function but not Pure
	{
		
		if (type == RECTANGLE_AREA)
		{
			cout << "Base Class Rectangle Area : ";
			return (height * width);
		}
		else if (type == CIRCLE_AREA)
		{
			cout << "Base Class Circle Area : ";
			return (pi * radius * radius);
		}
		else {
			cout << "Base Class Area Error: ";
			return 0;
		}
	}
}SHAPE;

typedef class Rectangle : public SHAPE {

public:
	Rectangle(double h, double w)
	{
		height = h;
		width = w;
	}

	double area(void)
	{
		return (height * width);
	}

	void show()
	{
		cout << "Rectangle Height = " << height << endl;
		cout << "Rectangle Width = " << width << endl;
	}

}RECTANGLE;

typedef class Circle : public SHAPE {

public:
	Circle(double r)
	{
		radius = r;
	}
	double area(void)
	{
		return (pi * radius * radius);
	}

	void show()
	{
		cout << "Circle Radius = " << radius << endl;
	}
}CIRCLE;

int main(void)
{
	SHAPE* rPtr = new RECTANGLE(3, 4);
	rPtr->show();
	cout << "Rectangle area is = " << rPtr->area() << " unit square" << endl;

	SHAPE * cPtr = new CIRCLE(1);
	cPtr->show();
	cout << "Circle Area is = " << cPtr->area() << " unit square" << endl;

	SHAPE* basePtr = new SHAPE(2,3,4);
	basePtr->setType(CIRCLE_AREA);
	basePtr->show();
	cout << basePtr->area() << endl;

	basePtr->setType(RECTANGLE_AREA);
	basePtr->show();
	cout << basePtr->area() << endl;

}