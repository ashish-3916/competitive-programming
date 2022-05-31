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
	int n , m;
	cin >> n >> m;
	int arr[n + 1][m + 1];
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1; j <= m ; j++)
			cin >> arr[i][j];

	int dp[n + 1][m + 1];
    // dp[i][j] stores the starting index of nondecresing sequence till this i  for the jth column
	memset(dp, 0 , sizeof(dp));
	for (int j = 1 ; j <= m ; j++)
	{
		dp[1][j] = 1;
	}
    
	for (int j = 1; j <= m; j++)
	{
		for (int i = 2; i <= n ; i++)
		{
			if (arr[i][j] >= arr[i - 1][j])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = i;
		}
	}
	/*for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}*/
	int yes[n + 1]; // yes stores the minimum L we can take to get YES for a given R 
	for (int i = 1 ; i <= n ; i++)
	{
		int mn = n + 1;
		for (int j = 1 ; j <= m ; j++)
			mn = min(dp[i][j], mn);

		yes[i] = mn;
	}
	/*cout << endl;
	for (int i = 1 ; i <= n ; i++)
		cout << yes[i] << " ";
	*/
	int k;
	cin >> k ;
	for (int i = 0 ; i < k ; i++)
	{
		int l  , r;
		cin >> l >> r;

		if (yes[r] <= l)
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

