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

bool valid(int x, int y, int n, int m)
{
	return (x >= 0 and y >= 0 and x < n and y < m);
}
void solve()
{
	int n, m;
	cin >> n >> m ;

	int matrix[n][m];
	for (int i = 0 ; i < n; i++)
		for (int j = 0 ; j < m ; j++)
			cin >> matrix[i][j];

	int sum[n][m];
	int s = 0;
	for (int i = 0 ; i < n ; i++)
	{
		s += matrix[i][0];
		sum[i][0] = s;
	}
	s = 0;
	for (int i = 0 ; i < m; i++)
	{
		s += matrix[0][i];
		sum[0][i] = s;
	}
	for (int i = 1; i < n ; i++)
	{
		for (int j = 1; j < m ; j++)
			sum[i][j] = matrix[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
	}
	int ans = INT_MIN;
	for (int i = 0 ; i < n; i++)
	{
		for (int  j = 0 ; j < m ; j++)
		{
			for (int x = 0 ; x <= i ; x++)
			{
				for (int y = 0 ; y <= j ; y++)
				{
					int ans1 = sum[i][j], ans2 = 0, ans3 = 0, ans4 = 0;
					if (valid(i, y - 1, n, m)) ans2 = sum[i][y - 1];
					if (valid(x - 1, j, n, m)) ans3 = sum[x - 1][j];
					if (valid(x - 1, y - 1, n, m)) ans4 = sum[x - 1][y - 1];
					int area = ans1 - ans2 - ans3 + ans4;
					ans = max(ans , area);
				}
			}
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

