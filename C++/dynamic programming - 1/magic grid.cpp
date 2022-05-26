
int getMinimumStrength(int** grid, int m, int n) {

	int dp[m][n];
	dp[m - 1][n - 1] = 1;

	for (int  i = n - 2 ; i >= 0 ; i--)
	{
		dp[m - 1][i] = dp[m - 1][i + 1] - grid[m - 1][i + 1] ;
	}

	for (int  i = m - 2 ; i >= 0 ; i--)
	{
		dp[i][n - 1] = dp[i + 1][n - 1] - grid[i + 1][n - 1];
	}

	for (int  i = m - 2 ; i >= 0 ; i--)
	{
		for (int  j = n - 2; j >= 0; j--)
		{
			dp[i][j] = min(dp[i + 1][j] - grid[i + 1][j] , dp[i][j + 1] - grid[i][j + 1]);
            if(dp[i][j]<=0)
                dp[i][j]=1;
		}
	}
	
	return dp[0][0];



}

 
