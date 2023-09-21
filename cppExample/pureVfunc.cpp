#include <iostream>

using namespace std;

class Main_Class {
	private:
	int i, m, n;

	public:
	Main_Class()
	{
	}

	virtual ~Main_Class()
	{
	}

	virtual void function(void) = 0;
};

class Derived_Class_1: public Main_Class {

	public:
	 virtual void function(void) { cout << "Derived Class 1 public method" << endl;}
};

class Derived_Class_2: public Main_Class {
	public:
	virtual void function(void) { cout << "Derived Class 2 public method" << endl;}
};


int main(int argn, char** ptr)
{
	Main_Class *mainObj;
	
	Derived_Class_1 *derivedObj1 = new Derived_Class_1();
	Derived_Class_2 *derivedObj2 = new Derived_Class_2();
        
        mainObj = derivedObj1;
	mainObj->function();

	mainObj = derivedObj2;
	mainObj->function();

	delete derivedObj1;
	delete derivedObj2;
	
	return 0;
}
