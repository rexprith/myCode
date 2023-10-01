// Bubble sort
// Author: Prithwiraj Shome
#include <iostream>
using namespace std;

//Input the elements
int main()
{
	int numTotal;
	int temp;
	cout << "Enter total number of elements to be sorted: " << endl;
	cin >> numTotal;
	int* arr = (int*)malloc(sizeof(int) * numTotal);
	cout << "Enter the elements: " << endl;

	for (int i = 0; i < numTotal; i++)
	{
		cin >> arr[i];
	}
	
	//Bubble sort
	for (int i = 0; i < numTotal; i++)
	{
		if (arr[i] > arr[i+1])
		{
			if ((i + 1) < numTotal) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}	
	}

	cout << "Sorted elements are:" << endl;
	for (int i = 0; i < numTotal; i++)
		cout << arr[i] << endl;

	return 0;
}
