bool isSubsetPresent(int arr[] , int n , int sum)
{
	int dp[n + 1][sum + 1];
	for (int i = 0; i <= n ; i++)
	{
		for (int j = 0 ;j<=sum ; j++)
		{
			if(i==0)
				dp[i][j]=0;
			else if(j==0)
				dp[i][j]=1;
			else
				{
					if(arr[i-1]> j)
						dp[i][j]=dp[i-1][j];
					else
						dp[i][j] = dp[i-1][j] | dp[i-1][j-arr[i-1]];
				}

		}
	}
	return dp[n][sum];
}
/*
bool isSubsetPresent(int *arr, int n, int sum)
{
    if(sum==0)
        return true;

    if(n==0)
        return false;

    if(arr[0]> sum)
        return isSubsetPresent(arr+1 , n-1 , sum);

    bool ans1 = isSubsetPresent(arr+1 , n-1 , sum);
    bool ans2 = isSubsetPresent(arr+1 , n-1 , sum-arr[0]);
    return (ans1 | ans2);

}
*/
