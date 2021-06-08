
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long dp[1<<20];
long long find( int n, int mask)
{
    if (mask ==(1<<n)-1)
        return 1 ;
    if(dp[mask]!=-1)
        return dp[mask];
    long long res = 0 ;
    for (int i = 0 ; i < n ; i++) {
        if (!(mask & (1 << i))) // no not taken  , where   1<= no <=n ;
        {
            int flag=  true;
            // can we take this no?
            for (int j = 0 ; j < n ; j++)
                if ((mask & (1 << j))  and ((j + 1) & (i + 1)) == (i + 1) ) //Aj is set and Aj & Ai != Ai
                    flag = false;
            if(flag)
                res += find(n , mask | (1 << i));
        }
    }
    return dp[mask] =res ;
}
int main()
{
    int n ;
    cin >> n ;
    int mask = 0 ;
    long long ans = 0 ;
    memset(dp , -1 , sizeof dp);
    for (int i = 0 ; i < n ; i++)
        ans += find( n ,1<<i);
    cout << ans ;
}

