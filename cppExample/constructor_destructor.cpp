#include <iostream>

using namespace std;

class Base_Class {

	public:
	Base_Class () 	
	{
	   cout << "Base Class Constructor Executing" << endl;	
	}

	Base_Class(int x)
	{
	   cout << "Base Class Parameterized Constructor Executing " << endl;
	}
	
	virtual ~Base_Class() 
	{
	    cout << "Base Class Destructor Executing" << endl;	
	}
};

class Derived_Class_1: public Base_Class {

	public:
	Derived_Class_1()
	{
	    cout << "Derived Class 1 Constructor Executing" << endl;	
	}
	~Derived_Class_1()
	{
	    cout << "Derived CLass 1 Destructor Executing" << endl;
	}
};

class Derived_Class_2: public Base_Class {
	public:
	Derived_Class_2()
	{
	    cout << "Derived Class 2 Constructor Executing" << endl;	
	}
	~Derived_Class_2()
	{
	    cout << "Derived CLass 2 Destructor Executing" << endl;
	}
};


int main(int argn, char** ptr)
{
	Base_Class *baseObj = new Base_Class();
	cout << endl;	
	Base_Class *baseObj1 = new Base_Class(1);
	cout << endl;
	Derived_Class_1 *derivedObj1 = new Derived_Class_1();
	cout << endl;
	Derived_Class_2 *derivedObj2 = new Derived_Class_2();
        cout << endl;
	delete derivedObj2;
	cout << endl;
       	delete derivedObj1;
        cout << endl;	
	delete baseObj1;
	cout << endl;
	delete baseObj;
	cout << endl;
	
	return 0;
}
