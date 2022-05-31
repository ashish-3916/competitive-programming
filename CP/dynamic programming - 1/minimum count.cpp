

int minCount(int n)
{
    int dp [n+1];
    dp[0]=1;
    for(int i = 1 ; i<= n ; i++)
    {
        if(i<=3)
            dp[i]=i;
        else if (sqrt(i) - floor(sqrt(i)) == 0)
            dp[i] =1;
        else
        {	int res =i;
            for (int x = 1; x*x <= i; x++) 
            {
                int temp = x * x;
                res = min(res, 1 + dp[i - temp]);
            }
            dp[i]=res;

        }

    }
    return dp[n];
}


/*int dp[10000+1];
int minCount(int n)
{
	if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if (n <= 3)
        return n;

    int res = n; 
	if(dp[n])return dp[n];
    for (int x = 1; x*x <= n; x++) 
    {
        int temp = x * x;
        res = min(res, 1 + minCount(n - temp));
    }
    return dp[n]=res;
}*/
