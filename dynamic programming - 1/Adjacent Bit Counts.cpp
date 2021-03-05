#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define endl "\n" //delete if interactive
using namespace std;
const int  mod = 1e9 + 7;

//n , k  <=100
long long add(long long a , long long b)
{
	long long ans = ((a % mod) + (b % mod)) % mod;
	return ans;
}
/*
ll dp[101][101][2];
ll solve2( ll n, ll k , ll first)
{
	if (n == 1)
	{
		if (k == 0)
			return 1;
		return 0;
	}
	if (k < 0)
		return 0 ;

	if(dp[n][k][first]!=-1)
        return dp[n][k][first];
	if (first == 0)
	{
		ll ans1 =dp[n-1][k][0] =  solve2(n - 1, k, 0);
		ll ans2 =dp[n-1][k][1] =  solve2(n - 1, k, 1);
		return dp[n][k][first]= add(ans1, ans2);
	}
	else
	{
		ll ans1 =dp[n-1][k][0] = solve2(n - 1, k , 0);
		ll ans2 =dp[n-1][k-1][1] =  solve2(n - 1, k - 1, 1);
		return dp[n][k][first] = add(ans2, ans1);
	}
}
void solve()
{
	ll t, n , k;
	cin >> t >> n >> k;

	memset(dp,-1, sizeof(dp));
	ll ans1  = solve2(n , k, 0);
	ll ans2 = solve2(n , k, 1);
	ll res = add(ans1, ans2);

	cout << res << endl;

}
*/
int dp[101][100][2];
void solve_dp()
{
	
	int n= 100;
    int k= 99;
	//int dp[n + 1][k + 1][2] = {0};
	//memset(dp, 0, sizeof(dp));

	dp[1][0][1] = dp[1][0][0] = 1;
    for(int i =2 ;i<=n ;i++)
    {
        for(int j = 0 ; j<=k   and (j<=(i-1)) ; j++)  // we can have atmost n-1 bitscounts for string of size n 
        {
            for(int l=0 ; l<2 ;l++)
            {
                if(l==0)
                {
                    dp[i][j][l] = add(dp[i-1][j][0], dp[i-1][j][1]);
                }
                else
                {
                    if(j==0) // bits count cant be negative
                        dp[i][j][l] = dp[i-1][j][0];
                    else
                        dp[i][j][l]= add( dp[i-1][j][0], dp[i-1][j-1][1]);
                }
            }
        }
    }    
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    solve_dp();

	int t;
	cin >> t;
	for (int i = 1 ; i <= t ; i++ )
	{	
        int tt , n, k;
        cin>>tt>>n>>k;
        int ans = add(dp[n][k][0] , dp[n][k][1]) ; 
        cout << i << " "<< ans<< endl;
		
	}
	return 0;
}

