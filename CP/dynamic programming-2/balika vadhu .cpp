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

/*
int maxsum(string s, string t, int k)
{
	int m = s.size();
	int n = t.size();

	if (k == 0)
		return 0;
	if (n == 0 or m == 0)
		return -1;

	if (s[0] == t[0])
	{	int ans1 = 0, ans2 = 0;
		ans1 = maxsum(s.substr(1), t.substr(1), k);

		int a2 = maxsum(s.substr(1), t.substr(1), k - 1);
		if (a2 != -1)
			ans2 = a2 + (int)s[0];
		else
			ans2 = -1;

		return max(ans2, ans1);
	}
	else
	{
		int ans1 = maxsum(s.substr(1), t, k);
		int ans2 = maxsum(s, t.substr(1), k);
		return max(ans2, ans1);
	}


}
*/


int maxsum(string s, string t, int k , int ***dp)
{
	int n = s.size();
	int m = t.size();

	if (k == 0)
		return 0;
	if (n == 0 or m == 0)
		return -1;

	if (dp[n][m][k] != -2)
		return dp[n][m][k];
	if (s[0] == t[0])
	{	int ans1 = 0, ans2 = 0;
		ans1 = maxsum(s.substr(1), t.substr(1), k, dp);

		int a2 = maxsum(s.substr(1), t.substr(1), k - 1, dp);
		if (a2 != -1)
			ans2 = a2 + (int)s[0];
		else
			ans2 = -1;

		return dp[n][m][k] = max(ans2, ans1);
	}
	else
	{
		int ans1 = dp[n - 1][m][k] = maxsum(s.substr(1), t, k, dp);
		int ans2 = dp[n][m - 1][k] = maxsum(s, t.substr(1), k, dp);
		return dp[n][m][k] = max(ans2, ans1);
	}

}

void solve()
{
	int ***dp = new int**[101];
	for (int i = 0 ; i < 101 ; i++)
	{
		dp[i] = new int * [101];
		for (int j = 0 ; j < 101 ; j++)
		{
			dp[i][j] = new int[101];
			for (int k = 0 ; k < 101 ; k++)
				dp[i][j][k] = -2;

		}
	}
	int k;
	string s, t;
	cin >> s >> t >> k;

	int res = maxsum(s, t, k, dp) ;
	if (res == -1)
		cout << 0 << endl;
	else
		cout << res << endl;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	int t;
	cin >> t;
	while (t--)
	{solve();}
	return 0;
}

