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

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll>arr(n), dp(n), pre(n);//prefix
	for (ll i = 0 ; i < n ; i++)
		cin >> arr[i];
	sort(all(arr));

	pre[0] = arr[0];
	for (ll i = 1; i < n; i++)
		pre[i] = arr[i] + pre[i - 1];

	dp[1] = arr[1] - arr[0];

	for (ll i = 2 ; i < k ; i++)
	{
		dp[i] = dp[i - 1] + ( i * arr[i]) - pre[i - 1] ;
	}


	for (ll i = k ; i < n ; i++)
	{
		dp[i] = dp[i - 1] - ( arr[i - k] * (k - 1) ) + ( arr[i] * (k - 1) ) - ( 2 * (pre[i - 1] - pre[i - k]) );
	}

	ll ans = LONG_MAX;

	for (ll i = k - 1 ; i < n ; i++)
		ans = min(ans , dp[i]);

	cout << ans << endl;



}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	solve();

	return 0;
}

