#include <iostream>
#include <bits/stdc++.h>
#define ll long long // delete if it causes problem
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define endl "\n" //delete if interactive
const int  mod = 1e9 + 7;
using namespace std;
long long add(long long a , long long b)
{
	long long ans = ((a % mod) + (b % mod)) % mod;
	return ans;
}
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll dp[500][101]; // dp[n][possible values of gcd] //  see constraints
void solve()
{
	
	ll n;
	cin >> n;
	ll arr[n];
	for (ll i = 0 ; i < n ; i++)
		cin >> arr[i];
	for (ll i = 0 ; i < n ; i++)
	{
		dp[i][arr[i]] = 1;
		for (ll j = i - 1 ; j >= 0 ; j--)
		{
			if (arr[i] > arr[j])
			{
				for (ll k = 0; k <= 100 ; k++)
				{

					ll new_gcd = __gcd(k, arr[i]);

					dp[i][new_gcd] = add(dp[i][new_gcd], dp[j][k]);
				}
			}
		}
	}

	ll ans = 0 ;
	for (ll i = 0 ; i < n ; i++)
		ans = add( dp[i][1] , ans );
	cout << ans << endl;


}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

