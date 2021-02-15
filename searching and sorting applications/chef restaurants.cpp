//https://www.codechef.com/problems/CHEFRES
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

bool myfunc(const array<int, 2> &p1, const array<int, 2>&p2)
{
	return p1[0] < p2[0];
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector < array<int, 2> >intervals(n);
	for (int i = 0; i < n; i++)
	{
		cin >> intervals[i][0] >> intervals[i][1];
	}
	sort(all(intervals), myfunc);
 // sort based on opening intervals

// separate check for first and last position
	// for rest check for previous interval , else it will go to interval given by upper bound
	vector<int>open(n);
	for (int i = 0; i < n ; i++)
		open[i] = intervals[i][0];
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		int position =  upper_bound(all(open), x) - open.begin() ;
		if (position == 0)
		{
			cout << open[0] - x << endl;
		}
		else if (position == n)
		{
			if (x >= intervals[n - 1][1])
				cout << -1 << endl;
			else
			{
				cout << 0 << endl;
			}

		}
		else
		{
			if (x >= intervals[position - 1][1])
				cout << (open[position] - x) << endl;
			else
				cout << 0 << endl;
		}
	}


}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{solve();}
	return 0;
}

