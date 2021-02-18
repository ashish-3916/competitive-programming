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
ll sum(ll n)
{
	ll ans = 0;
	while (n > 0)
	{
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

void solve()
{
	ll n;
	cin >> n;
	cout << sum(n) << endl;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t;
	cin >> t;
	while (t--)
	{solve();}
	return 0;
}

