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
	for (int i = 0; i < numTotal-1; i++)
	{
		for (int cnt = 0; cnt < (numTotal - i-1); cnt++) {
			if (arr[cnt] > arr[cnt + 1])
			{
					temp = arr[cnt];
					arr[cnt] = arr[cnt + 1];
					arr[cnt + 1] = temp;
			}
		}
	}

	cout << "Sorted elements are:" << endl;
	for (int i = 0; i < numTotal; i++)
		cout << arr[i] << endl;

	free(arr);

	return 0;
}
