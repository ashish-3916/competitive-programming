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

int kadane(vector<int> & sum)
{
	int n = sum.size();
	int curr = sum[0], best = sum[0];

	for (int i = 1; i < n ; i++)
	{
		if (curr + sum[i] > sum[i])
			curr += sum[i];
		else
			curr = sum[i];

		best = max(best, curr);
	}
	return best;
}
void solve()
{
	int n, m;
	cin >> n >> m ;

	int matrix[n][m];
	for (int i = 0 ; i < n; i++)
		for (int j = 0 ; j < m ; j++)
			cin >> matrix[i][j];

	int ans = INT_MIN;
	for (int l = 0 ; l < m ; l++)
	{	vector<int> sum(n, 0);
		for (int r = l ; r < m; r++)
		{
			for (int k = 0 ; k < n; k++)
				sum[k] += matrix[k][r];
			int res = kadane(sum);
			ans = max(ans, res);
		}
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

