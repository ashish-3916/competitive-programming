// catalan no ->    nCr[2n][n] / (n+1)  


const int mod = 1000000000 + 7;
long long add(long long a , long long b)
{
    long long ans = ((a%mod)+(b%mod))%mod;
    return ans;
}
long long mul(long long a,long long b, long long mod) 
{ 
    long long res = 0; // Initialize result  
    a %= mod; 
    while (b) 
    { 
        if (b & 1) 
            res = (res + a) % mod; 
        a = (2 * a) % mod; 
        b >>= 1; // b = b / 2 
    } 
    return res; 
} 



int countBST( int n)
{
  int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2 ; i<=n ;i++)
    {
		int res = 0 ;
        for(int k =1 ; k<=i ;k++)
        {
            res = add(res, mul(dp[k-1],dp[i-k],mod));
        }
        dp[i]=res;
    }
    return dp[n];
}


int memo[1000+1];
int countBST( int n)
{
   if(n==0 or n==1)
       return 1;
    if(memo[n])return memo[n];
    int res =0 ;
    for(int  k=1 ; k<=n ;k++)
    {
        res = add(res,moduloMultiplication(countBST(k-1) , countBST(n-k),mod) );
    } 
    return memo[n]=res;
}



int countBST( int n)
{
   if(n==0 or n==1)
       return 1;
    int res =0 ;
    for(int  k=1 ; k<=n ;k++)
    {
        res += countBST(k-1) * countBST(n-k);
    } 
    return res;
}


