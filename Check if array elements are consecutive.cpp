#include <bits/stdc++.h>
using namespace std;

bool areConsecutive(int arr[], int n)
{
	sort(arr,arr+n);

	for(int i=1;i<n;i++)
	{
		if(arr[i]!=arr[i-1]+1)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int arr[]= {5, 4, 2, 3, 1, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	if(areConsecutive(arr, n) == true)
		cout<<" Array elements are consecutive ";
	else
		cout<<" Array elements are not consecutive ";
	return 0;
}
