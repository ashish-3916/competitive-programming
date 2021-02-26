/*
take care when 0 occures , rest is ez

if 0 occurs no code is possible ie code cant start with zero
*/

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
#define mod 1000000007
using namespace std;

ll arr[5002];
ll count(string s )
{

	if (s.size() == 0 || (s.size() == 1 and s[0] != '0'))
		return 1;

    if (s[0] == '0')
		return 0;

	if (arr[s.size()] > 0)
		return arr[s.size()];
    


	ll ans1 = 0, ans2 = 0;

	ans1 = (count(s.substr(1)))%mod;

	int ones =  s[1] - '0';
	int tens = s[0] - '0';
	int no = tens * 10 + ones;

	if (no < 27)
	{
		ans2 = (count(s.substr(2)))%mod;
	}
	return arr[s.size()] = (ans1 + ans2)%mod;
}

void solve()
{
	string s ;
	cin >> s;
	while (s != "0")
	{	memset(arr, 0 , sizeof(arr));
		ll ans  = count(s);
		cout << ans << endl;
		cin >> s;
	}

}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	solve();
	return 0;
}

