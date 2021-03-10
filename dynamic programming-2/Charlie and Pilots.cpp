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

/// at any points caption <= assistants

int half;
int findsum(int capt[], int ass[], int n , int diff, int ** dp)
{
	if (n == 0)
		return 0;
	if (dp[n][diff] != -1)
		return dp[n][diff];
	if (diff == 0)
	{
		return dp[n][diff] = ass[0] + findsum(capt + 1 , ass + 1 , n - 1 , diff + 1, dp);
	}
	if (diff == n)
	{
		return dp[n][diff] = capt[0] + findsum(capt + 1 , ass + 1 , n - 1 , diff - 1, dp); // just not updating it
	}
	int choice1 = ass[0] + findsum(capt + 1 , ass + 1 , n - 1 , diff + 1, dp);
	int choice2 = capt[0] + findsum(capt + 1 , ass + 1 , n - 1 , diff - 1, dp);
	return dp[n][diff] = min(choice2, choice1);
}
void solve()
{
	int n;
	cin >> n ;
	half = n / 2;
	int caption[n];
	int ass[n];
	int ** dp = new int * [n + 1];
	for (int i = 0; i <= n; i++)
	{
		dp[i] = new int [half + 1];
		for (int j = 0 ; j <= half; j++)
			dp[i][j] = -1;
	}

	for (int i = 0 ; i < n ; i++)
	{
		cin >> caption[i] >> ass[i];
	}

	int ans = findsum(caption , ass  , n  , 0  , dp) ;
	cout << ans << endl;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

/* 
// runtime error bcz of constraints 

int findsum(int caption[], int ass[] , int size , int c , int a , int ***dp)
{
	if (size == 0)
		return 0;
	if (dp[size][c][a] != -1)
		return dp[size][c][a];
	int choice1 = 0 , choice2 = 0;

	if (a > c)
	{
		if (a < half)
		{
			choice1 = findsum(caption + 1, ass + 1, size - 1 , c + 1 , a, dp) + caption[0];
			choice2 = findsum(caption + 1, ass + 1, size - 1 , c , a + 1, dp) + ass[0];
			return dp[size][c][a] = min( choice2, choice1);
		}
		else
		{
			return dp[size][c][a] = findsum(caption + 1, ass + 1, size - 1 , c + 1 , a, dp) + caption[0];
		}
	}
	else if ( a == c)
	{
		return dp[size][c][a] = findsum(caption + 1, ass + 1, size - 1 , c , a + 1, dp) + ass[0];
	}
	
}
*/
