int knapsack(int W[] , int V [] , int n , int req)
{
	int dp [n+1][req+1];
    
    for(int i = 0;i<=n ;i++)
    {
        for(int j=0 ;j<=req ;j++)
        {
			if(i==0 or j==0)
                dp[i][j]=0;
            else
            {
                if(W[i-1] > j) /// take care of indexing
                    dp[i][j] = dp[i-1][j];
                else 
                {
					dp[i][j]=  max( V[i-1] + dp[i-1][j-W[i-1]] , dp[i-1][j]);
                }
            }
        }
    }
    return dp[n][req];

}
/*
int knapsack(int* weight, int* value, int n, int maxWeight) {
	
    if(n==0)
        return 0;
    if(maxWeight==0)
        return 0;
    int ans1=0 , ans2=0;
    
	if(weight[0] > maxWeight)
        return knapsack( weight+1 , value+1 , n-1 , maxWeight);
    
     ans1  = value[0]+ knapsack( weight+1 , value+1 , n-1 , maxWeight-weight[0]);
     ans2 =knapsack( weight+1 , value+1 , n-1 , maxWeight);
    return max(ans1, ans2);
}
*/
