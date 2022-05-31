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

vector<int> dfs(vector<vector<int>>&graph , int n , vector<bool>&visited , int sv, int ev)
{
	if (sv == ev)
		return {ev};
	visited[sv] = true;

	for (int i = 0; i < n ; i++)
	{
		if (graph[sv][i] and !visited[i])
		{	vector<int>ans = dfs(graph, n, visited , i, ev);
			if (ans.size() > 0)
			{
				ans.push_back(sv);
				return ans;
			}
		}
	}
	return {};
}
void solve()
{
	int v, e ;
	cin >> v >> e;

	vector<vector<int>> graph(v + 1, vector<int>(v + 1, 0));

	for (int i = 0 ; i < e  ; i++)
	{
		int s , e ;
		cin >> s >> e ;
		graph[s][e] = 1;
		graph[e][s] = 1;
	}
	vector<bool>visited(v + 1 , false);

	int a , b;
	cin >> a >> b;
	

	vector<int> ans = dfs(graph , v , visited , a, b );

	
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}

}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	solve();

	return 0;
}

