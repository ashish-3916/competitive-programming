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
0->entrance cost
1->fun sum
*/
array<int , 2> dp[101][501];
array<int , 2> maxfun(int cost[] , int fun[] , int n , int budget)
{
	if (n == 0)
		return {0, 0};
	if (budget == 0)
		return {0, 0};
	if (dp[n][budget][0] and dp[n][budget][1])
		return dp[n][budget];
	if (budget <  cost[0])
		return dp[n][budget] = maxfun(cost + 1 , fun + 1 , n - 1 , budget);
	array<int , 2> choice1 = maxfun( cost + 1 , fun + 1 , n - 1 , budget -  cost[0]); //fun[0] +
	array<int , 2> choice2 = maxfun(cost + 1 , fun + 1 , n - 1 , budget);

	choice1[0] += cost[0];
	choice1[1] += fun[0];

	if (choice1[1] > choice2[1]) // max fun
		return dp[n][budget] = choice1;
	if (choice1[1] < choice2[1])
		return dp[n][budget] = choice2;
	else
	{
		if (choice1[0] < choice2[0]) // less cost
			return dp[n][budget] = choice1;
    else
		 return dp[n][budget] = choice2;
	}

}

void solve(int budget , int n)
{
	for (int i = 0 ; i < 101 ; i++)
	{
		for (int j = 0 ; j < 501 ; j++)
			dp[i][j][0] = dp[i][j][1] = 0;
	}
	int cost[n], fun[n];
	for (int i = 0 ; i < n ; i++)
		cin >> cost[i] >> fun[i];

	array<int, 2> res = maxfun(cost, fun , n , budget);
	cout << res[0] << " " << res[1] << endl;



}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		int budget , n;
		cin >> budget >> n ;
		if (budget and n)
			solve(budget, n);
		else
			break;
	}

	return 0;
}

