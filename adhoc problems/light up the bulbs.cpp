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
	ll n, rev , flip ;
	cin >> n >> rev >> flip ;
	string s;
	cin >> s;

	ll cost = 0 ;
	if (rev > flip)  // if rev is greater , its better to flip the segment
	{


		for (ll i = 0 ; i < n ; i++)
		{
			if (s[i] == '0' and i == n - 1)
			{
				cost += flip ; continue;
			}
			if (s[i] == '0' and s[i + 1] == '1')
				cost += flip;
		}
	}
	else
	{ // its beeter to merge all segments and flip them all in one go
		
		ll cnt = 0;
		for (int i = 0 ; i < n ; i++)
		{
			if (s[i] == '0' and i == n - 1)
			{
				cnt++ ; continue;
			}
			if (s[i] == '0' and s[i + 1] == '1')
				cnt++;
		}
		
		if (cnt>0)
		{
            ll p =rev * (cnt - 1);
			cost = p + flip;
		}
		else
			cost = 0;

	}
	cout << cost << endl;

}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t = 1;
	//cin >> t;
	while (t--)
	{solve();}
	return 0;
}

