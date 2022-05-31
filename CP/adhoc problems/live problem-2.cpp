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

bool myfunc(const array<int , 2> & p1 , const array<int , 2> & p2)
{
	if (p1[0] == p2[0])
		return p1[1] > p2[1];
	return p1[0] > p2[0];
}
void solve()
{
	int n;
	cin >> n;
	vector<array<int , 2 > > points (n);
	for (int i = 0 ; i < n ; i++ )
		cin >> points[i][0] >> points[i][1];

	sort(all(points), myfunc);

	/*	for (int i = 0 ; i < n ; i++ )
			cout << points[i][0] << points[i][1];*/

	ll ans = points[0][0] * points[0][1];
	for (int i = 0 ; i < n ; i++)
	{
		ans += points[i][0] * points[i][1];

		ans -= points[i][0] * ( min(points[i - 1][1], points[i][1] ));  // sub some overlaaping part
	}

	cout << ans << endl;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}

