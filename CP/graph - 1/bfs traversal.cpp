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

void bfs(vector<vector<int>>& graph , int n, vector<bool>&visited , int sv )
{
	queue<int> q ;

	q.push(sv);

	while (!q.empty())
	{
		int top = q.front() ;
		q.pop();
		cout << top << " ";
		visited[top] = true;


		for (int i = 0 ; i < n ; i++ )
		{
			if (graph[top][i] and !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}

	}
}
void solve()
{
	int v, e ;
	cin >> v >> e;

	vector<vector<int>> graph(v, vector<int>(v , 0));

	for (int i = 0 ; i < e  ; i++)
	{
		int s , e ;
		cin >> s >> e ;
		graph[s][e] = 1;
		graph[e][s] = 1;
	}
	vector<bool>visited(v , false);

	for (int i = 0; i < v ; i++)
	{
		if (visited[i] == false)
		{
			bfs(graph , v, visited , i);
			//cout << endl;
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

