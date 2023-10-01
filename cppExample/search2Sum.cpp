#include <iostream>

using namespace std;

int out(int* numArr, int numSize, int target)
{
	int i = 0;
	int j = 0;
	int sum = 0;

	for (i = 0; i < numSize; i++) 
	{
		for (j = i + 1; j < numSize; j++) 
		{
			sum = numArr[i] + numArr[j];
			if (sum == target)
			{
				printf("[%d %d]", i, j);
			}
		}
	}
	return 0;

}


int main(void)
{
	int arr[] = { 2, 1, 4, 3 };
	int ret;
	ret = out(arr, sizeof(arr), 5);
	return ret;
}
