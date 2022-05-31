
int maxMoneyLooted(int *arr, int n)
{
	int dp[n+1];
    dp[0]=0;
    dp[1]=arr[0];
    for(int i=2;i<=n;i++)
    {
		dp[i]=max (arr[i-1]+dp[i-2] , dp[i-1]); // take care of indexing
    }
    return dp[n];
}



int dp[10002];
int maxMoneyLooted_memo(int *arr, int n)
{
	if(n<=0)
        return 0;
    if(dp[n])return dp[n];
    int ans1= maxMoneyLooted(arr+1,n-1);
    int ans2= arr[0]+maxMoneyLooted(arr+2,n-2);
    
    return dp[n]=max(ans1,ans2);
}


int maxMoneyLooted_rec(int *arr, int n)
{
	if(n<=0)
        return 0;
    
    int ans1= maxMoneyLooted(arr+1,n-1);
    int ans2= arr[0]+maxMoneyLooted(arr+2,n-2);
    
    return max(ans1,ans2);
}
