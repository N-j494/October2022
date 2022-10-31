#include <bits/stdc++.h>
using namespace std;

int countOne(int arr[], int n){
	int i = 0;

	int len = 0;

	int ans = 0;
	
	while(i < n){

		if(arr[i] == 1){
			len = 0;
			while(i < n && arr[i] == 1){
				i++;
				len++;
			}
			ans += (len*(len+1)) / 2;
		}
		i++;
	}
	
	return ans;
}

int findSubarrayCount(int arr[], int n, int k)
{
	int start = 0, endval = 0, p = 1,
		countOnes = 0, res = 0;

	while (endval < n)
	{
		p *= (arr[endval]);
		if(p > k)
		{
			while(start <= endval && p > k)
			{
				p /= arr[start];
				start++;
			}
		}
		
		
		if(p == k)
		{
			countOnes = 0;
			while(endval + 1 < n && arr[endval + 1] == 1)
			{
				countOnes++;
				endval++;
			}
			res += (countOnes + 1);
			while(start <= endval && arr[start] == 1 && k!=1)
			{
				res += (countOnes + 1);
				start++;
			}
			start++;
		}

		endval++;
	}
	return res;
}
int main()
{
	int arr1[] = { 2, 1, 1, 1, 3, 1, 1, 4};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int k = 1;
	
	if(k != 1)
		cout << findSubarrayCount(arr1, n1, k) << "\n";
	else
		cout << countOne(arr1, n1) << "\n";
	
	int arr2[] = { 2, 1, 1, 1, 4, 5};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	k = 4;
	
	if(k != 1)
		cout << findSubarrayCount(arr2, n2, k) << "\n";
	else
		cout << countOne(arr2, n2) << "\n";
	return 0;
}

