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
using namespace std;

ll count(ll arr[], ll n, ll val , ll f , ll s)
{
	ll big = 0 ; ll small = 0 ;
	for (ll i = 0 ; i < n; i++)
	{
		if (arr[i] > val)
		{
			big += arr[i] - val;
		}
		else
			small += val - arr[i];
	}

	if (big > small)return -1 ;

	ll p = big * f + (small - big ) * s;
	return p;
}
void solve()
{
	ll n, f, s;
	cin >> n >> f >> s;
	ll arr[n];
	ll high = 0 , low = 1001;
	for (ll i = 0 ; i < n ; i++)
	{	cin >> arr[i];
		high = max(arr[i], high);
		low = min(arr[i] , low);
	}

	ll ans  = INT_MAX;
	for (ll x = low ; x <= high ; x++)
	{
		ll small = count(arr , n, x , f , s);
		
		if (small == -1)continue;
		ans = min(ans , small);
	}
	cout << ans << endl;


}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

