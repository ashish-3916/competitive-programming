#include <bits/stdc++.h>
const int INF = 100;
int dp[101][(1<<10)];
int solve (int n , vector<string> &arr,int index , int mask)
{
    int check = __builtin_popcount(mask);
    
    if(check==1)
        return 0;
    if(index == arr[0].size())//4
        return INF;
    
    if(dp[index][mask]!=-1)
        return dp[index][mask];
    int ans1 =  solve(n , arr , index+1 , mask);
    //cout<< ans1<< endl;
    
    int mask0 = 0 , mask1 = 0 ; 
    for(int i = 0 ; i<n ; i++)
    {
		if((mask&(1<<i))) // we have to check for the string
        {
            if(arr[i][index]=='1')
                mask1 = mask1|(1<<i);
            else 
                mask0=mask0|(1<<i);
        }
    }
    int ans2 =  check + solve(n , arr , index+1 , mask0) + solve(n , arr , index+1 , mask1);
    
    return dp[index][mask]=min(ans1 , ans2);
    
}
int minimumTouchesRequired(int n, vector<string> &v ) {
    memset(dp , -1 , sizeof dp);
    return solve(n , v , 0 ,(1<<n)-1 ) ; // mask represents string we have to check;
}
