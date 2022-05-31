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
bool myfunction(pair<int, int> const p1 , pair<int, int>const p2)
{
	double a1 = p1.F / (p1.S * 1.0);
	double a2 = p2.F / (p2.S * 1.0);
	if (a1 == a2) /// if ratio are equal , return with max value
		return p1.F > p2.F;
	return a1 > a2; // ratio is greater
}
void solve()
{
	int n, k ;
	cin >> n >> k ;
	// value   weight

	vector<pair<int, int>> arr(n);
	for (int i = 0 ; i < n ; i++)
	{
		cin >> arr[i].F >> arr[i].S;
	}

	sort(all(arr) , myfunction);

	double cost = 0 ;

	for (int i = 0; i < n; ++i)
	{
		if (arr[i].S <= k)
		{
			cost += arr[i].F;
			k -= arr[i].S;
		}
		else if (k > 0)
		{
			// we take fraction of it
			double price = (arr[i].F / (arr[i].S * 1.0)) * k ;
			cost += price;
			break;
		}
		//cout << k << endl;
	}
	cout << fixed << setprecision(6) << cost << endl;

}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

