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

void dfs(vector<vector<int>>&graph , int n , vector<bool>&visited , int sv, vector<int>&path)
{
	visited[sv] = true;
	path.push_back(sv);

	for (int i = 0; i < n ; i++)
		if (graph[sv][i] and !visited[i])
			dfs(graph, n, visited , i , path);



}
void solve()
{
	int v, e ;
	cin >> v >> e;

	vector<vector<int>> graph(v , vector<int>(v , 0));

	for (int i = 0 ; i < e  ; i++)
	{
		int s , e ;
		cin >> s >> e ;
		graph[s][e] = 1;
		graph[e][s] = 1;
	}
	vector<bool>visited(v + 1 , false);

	for (int i = 0 ; i < v ; i++)
	{	if (!visited[i])
		{
			vector<int> ans;
			dfs(graph , v , visited , i , ans);

			sort(all(ans));

			for (int i = 0; i < ans.size(); ++i)
			{
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}

}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);




	solve();

	return 0;
}

