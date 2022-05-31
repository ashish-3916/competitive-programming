#include <bits/stdc++.h>
using namespace std;

int dirn[3][2] = { {0, 1}, {1, 0}, {1, 1}};

bool valid(int x , int y, int m, int n)
{
	return (x >= 0  and y >= 0  and x < m  and y < n);
}

int minCostPath_dp(int **graph, int m, int n, int x, int y)
{
	vector< vector< int> > dp (m, vector<int >(n, INT_MAX));

	dp[m - 1][n - 1] = graph[m - 1][n - 1];
	for (int i = n - 2 ; i >= 0 ; i--)
	{
		dp[m - 1][i] = graph[m - 1][i] + dp[m - 1][i + 1];
	}
	for (int i = m - 2 ; i >= 0 ; i--)
	{
		dp[i][n - 1] = graph[i][n - 1] + dp[i + 1][n - 1];
	}

	for (int i = m - 2 ; i >= 0 ; i--)
	{
		for (int j = n - 2 ; j >= 0 ; j--)
		{
			dp[i][j] = graph[i][j] + min({ dp[i][j + 1] , dp[i + 1][j], dp[i + 1][j + 1]});
		}
	}
	return dp[0][0];
}

int helper(int **graph, int m, int n, int x, int y, vector< vector< int> >& dp)
{
	if (x == m - 1 and y == n - 1)
		return graph[x][y];

	int ans = INT_MAX;
	for (int i = 0 ; i < 3; i++)
	{
		int nx = x + dirn[i][0];
		int ny = y + dirn[i][1];
		int sans;
		if (valid(nx, ny, m, n))
		{	if (dp[nx][ny] != INT_MAX)
				sans = dp[nx][ny];
			else
				sans = dp[nx][ny] = helper(graph , m, n , nx, ny, dp);

			ans = min(ans, sans);
		}
	}
	return dp[x][y] = graph[x][y] + ans ;
}
int minCostPath_memo(int **graph, int m, int n, int x, int y)
{
	vector< vector< int> > dp (m, vector<int >(n, INT_MAX));
	return helper( graph, m, n, 0, 0, dp);
}

int minCostPath_rec(int **graph, int m, int n, int x, int y)
{
	if (x == m - 1 and y == n - 1)
		return graph[x][y];

	int ans = INT_MAX;
	for (int i = 0 ; i < 3; i++)
	{
		int nx = x + dirn[i][0];
		int ny = y + dirn[i][1];

		if (valid(nx, ny, m, n))
		{
			int sans = minCostPath_rec(graph , m, n , nx, ny);
			ans = min(ans, sans);
		}
	}
	return graph[x][y] + ans ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << "recursive : " << minCostPath_rec(arr, n, m, 0, 0) << endl;
	cout << "memo : " << minCostPath_memo(arr, n, m, 0, 0) << endl;
	cout << "dp : " << minCostPath_dp(arr, n, m, 0, 0) << endl;

}
