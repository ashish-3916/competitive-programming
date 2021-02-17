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

bool myfunc(const array<int, 2>&p1 , const array<int, 2 >&p2 )
{
	return p1[1] < p2[1];
}

void solve()
{
	int n;
	cin >> n;
	vector<array < int , 2 >> activity(n);
	for (int i = 0 ; i < n ; i++)
	{
		cin >> activity[i][0] >> activity[i][1];
	}
	sort(all(activity) , myfunc);
	int ans = 1 ;
	int end_time =  activity[0][1];
	for (int i = 0 ; i < n ; i++)
	{
		if (activity[i][0] >= end_time)
		{
			ans += 1;
			end_time = activity[i][1];
		}
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

