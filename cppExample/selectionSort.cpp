// Selection sort
// Author: Prithwiraj Shome
#include <iostream>
using namespace std;

//Input the elements
int main()
{
	int numTotal;
	int min;
	
	cout << "Enter total number of elements to be sorted: " << endl;
	cin >> numTotal;
	
	int* arr = (int*)malloc(sizeof(int) * numTotal);
	cout << "Enter the elements: " << endl;

	for (int i = 0; i < numTotal; i++)
	{
	    cin >> arr[i];
	}
	
	//Selection Sort
	for (int i = 0; i < numTotal; i++)
	{
		min = arr[i];
	    for (int c = (i+1); c < (numTotal); c++)
	    {
			if (min > arr[c]) {
				arr[i] = arr[c];
				arr[c] = min;
				min = arr[i];
			}
	    }

	}

	cout << "Sorted elements are:" << endl;
	for (int i = 0; i < numTotal; i++)
		cout << arr[i] << endl;

	return 0;
}
