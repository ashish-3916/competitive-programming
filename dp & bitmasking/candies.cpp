//spoj 

/*
#define ll long long 
vector<int> dp(1<<16 , -1);
ll solve2(int like[][MAXN] , int p , int  n , int mask)
{
    if(p>=n)
        return 1 ;
    if(dp[mask]!=-1)
        return dp[mask];
    ll res = 0 ;
    for(int i = 0 ; i<n ; i++)
        if(like[p][i] and !(mask&(1<<i)))
           res+= solve2(like , p+1 , n , mask|(1<<i) );
    return dp[mask] = res;
}
long long solve(int like[][MAXN],int n)
{
	return solve2(like , 0  , n  , 0);
}
*/

#define ll long long 
long long solve(int like[][MAXN],int n)
{
	vector<ll> dp(1<<n , 0);
    dp[0]=1 ;
    
    for(int mask = 0 ; mask < (1<<n) -1 ; mask++)
    {
        int person  = __builtin_popcountll(mask) ; // people got candies ;
        
        for(int i = 0 ; i< n ; i++)
            if(!(mask&(1<<i)) and like[person][i])
                dp[mask|(1<<i)]+=dp[mask];
    }
    return dp[(1<<n)-1] ;
}
