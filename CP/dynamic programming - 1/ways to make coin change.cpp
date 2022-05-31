#include <iostream>
using namespace std;
int dp2[11][1001];
int countWaysToMakeChange(int arr[], int n, int value) {
	//Write your code here

	if (value == 0)
		return 1;
	if (value < 0)
		return 0;
	if (n == 0)
		return 0;

	int ans1 = 0 , ans2 = 0;

	if (dp2[n][value])return dp2[n][value];
	ans1 = countWaysToMakeChange(arr, n , value - arr[0]); // take it
	ans2 = countWaysToMakeChange(arr + 1, n - 1, value); // leave it



	return dp2[n][value] = ans1 + ans2 ;
}



int countWaysToMakeChange_dp(int arr[], int n, int val) {

	int dp[n + 1][val + 1];

	for (int i = 0; i <= val ; i++)  // n=0
	{
		dp[0][i] = 0;
	}

	for (int i = 0; i <= n ; i++) // val==0
	{
		dp[i][0] = 1;
	}

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1; j <= val; j++)
		{
			if (arr[i - 1] <= j)
			{
				dp[i][j] = dp[i][j - arr[i - 1]] + dp[i - 1][j];  /// take it or leave it
			}
			else
				dp[i][j] = dp[i - 1][j];  // leave it
		}
	}

	return dp[n][val];
}


