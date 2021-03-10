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

int dp[31][10][2];
int profit(int arr[] , int n  , int k  , int status) // status tells if transaction is going on or not
{

	if (n == 0)
		return 0;
	if (k <= 0)
		return 0 ;
	if (dp[n][k][status] )
		return dp[n][k][status];
	if (status)
	{
		int c1 = profit( arr + 1 , n - 1 , k , 1 );
		int c2 = profit(arr + 1 , n - 1 , k - 1, 0 ) + arr[0];
		return dp[n][k][status] = max(c1, c2);
	}
	else
	{	
		int c1 = profit(arr + 1 , n - 1 , k , 0 );
		//if (k > 0)
		int	c2 = profit( arr + 1 , n - 1 , k , 1 ) - arr[0];
		return dp[n][k][status] = max(c1, c2);

	}
}

void solve()
{
	int k , n;
	cin >> k >> n ;
	int arr[n];
	for (int i = 0 ; i < n ; i++)
		cin >> arr[i];
	for (int i = 0 ; i < 31 ; i++)
		for (int j = 0; j < 10 ; j++)
			for (int k = 0; k < 2 ; k++)
				dp[i][j][k] = 0;

	int choice1 = 	profit(arr + 1, n - 1 , k, 0 );
	int choice2 =	profit(arr + 1, n - 1 , k, 1 ) - arr[0];

	cout << max(choice1, choice2) << endl;

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

