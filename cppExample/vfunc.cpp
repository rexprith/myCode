#include <iostream>

using namespace std;

class Base_Class {
	private:
	int i, m, n;

	public:
	Base_Class()
	{
		
	}

	virtual ~Base_Class()
	{
	}	

	virtual void function(void) {cout << "Base class virtual method"<< endl;}
};

class Derived_Class_1: public Base_Class {

	public:
	Derived_Class_1()
	{
	}
	~Derived_Class_1()
	{
	}
	void function(void) { cout << "Derived Class 1 virtual method" << endl;}
};

class Derived_Class_2: public Base_Class {
	public:
	Derived_Class_2()
	{
	}
	~Derived_Class_2()
	{
	}
	void function(void) { cout << "Derived Class 2 virtual method" << endl;}
};


int main(int argn, char** ptr)
{
	Base_Class *mainObj;
	Base_Class *baseObj = new Base_Class();	
	Derived_Class_1 *derivedObj1 = new Derived_Class_1();
	Derived_Class_2 *derivedObj2 = new Derived_Class_2();
        
	mainObj = baseObj;
	mainObj->function();

        mainObj = derivedObj1;
	mainObj->function();

	mainObj = derivedObj2;
	mainObj->function();

	delete baseObj;
       	delete derivedObj1;
	delete derivedObj2;
	
	return 0;
}
