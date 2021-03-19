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

void bfs(vector<vector<int>>& graph , int n , vector<bool>&visited , int sv , int ev)
{
	queue<int > pn ;

	pn.push(sv);
	visited[sv] = 1;

	unordered_map<int, int> map;
	bool present = false;
	while (!pn.empty())
	{
		int top = pn.front();
		pn.pop();
		if (graph[top][ev])
		{
			map[ev] = top;
			present =  true;
			break;
		}

		for (int i = 0 ; i < n ; i++)
		{
			if (!visited[i] and graph[top][i])
			{
				pn.push(i);
				visited[i] = 1;
				map[i] = top;
			}
		}


	}
	if (present)
	{
		cout << ev << " ";

		while (map.count(ev))
		{
			cout << map[ev] << " ";

			ev = map[ev];
		}

	}

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

	bfs(graph , v , visited , a, b );




}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	solve();

	return 0;
}

