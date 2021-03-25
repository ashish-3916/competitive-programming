//https://www.spoj.com/problems/BUGLIFE/
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

vector<int> arr[2001];
int  visited[2001];
int color[2001];

bool dfs(int sv , int col)
{
	visited[sv] = 1;
	color[sv] = col;

	for (int child : arr[sv])
	{
		if (!visited[child])
		{	if (!dfs(child , col ^ 1))
				return false;
		}
		else if (color[child] == color[sv])
			return false;
	}
	return true;



}
void solve()
{
	int n , m;
	cin >> n >> m;

	clr(visited); clr(color);
	for (int i = 1 ; i <= n ; i++)
		arr[i].clear();

	for (int i = 0; i < m; ++i)
	{
		int a , b ;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	bool ans = true;
	for (int i = 1 ; i <= n ; i++)
		if (!visited[i])
			ans = ans & dfs(i , 0);

	if (ans)
		cout << "No suspicious bugs found!" << endl;
	else
		cout << "Suspicious bugs found!" << endl;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	for (int i = 1 ; i <= t ; i++)
	{
		cout << "Scenario #" << i << ":\n";
		solve();
	}
	return 0;
}

