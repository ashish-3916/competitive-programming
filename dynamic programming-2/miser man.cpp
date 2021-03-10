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

bool valid( int i, int j , int n , int m)
{
	return ( i >= 0 and j >= 0  and i < n and j < m);
}
void solve()
{
	int n, m;
	cin >> n >> m;
	int grid[n][m];
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < m ; j++)
			cin >> grid[i][j];

	int dp [n][m];

	for (int i = 0 ; i < m ; i++)
		dp[n - 1][i] = grid[n - 1][i];
	for (int i =  n - 2 ; i >= 0 ; i--)
	{
		for (int j = 0 ; j < m ; j++)
		{
			int choice1 = INT_MAX, choice2 = INT_MAX, choice3 = INT_MAX;
			if (valid(i + 1, j - 1 , n, m))
				choice1 = dp[i + 1][j - 1];
			if (valid(i + 1, j , n, m))
				choice2 = dp[i + 1][j];
			if (valid(i + 1 , j + 1 , n, m))
				choice3 = dp[i + 1][j + 1];

			dp[i][j] = min(choice1, min(choice2, choice3)) + grid[i][j];
		}
	}

	int fare = INT_MAX;

	for (int i = 0 ; i < m ; i++)
		fare = min(fare, dp[0][i]);

	cout << fare << endl;


}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

