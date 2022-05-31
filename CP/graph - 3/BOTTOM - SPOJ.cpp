#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define endl "\n" //delete if interactive
using namespace std;

// graph, transpose , visited , (out_time , scc)
const int N = 5001;
vector<int>graph[N];
vector<int>transpose[N];
vector<int>visited(N);
vector<ll>out_time, scc;

int n , e ;
void dfs(ll sv) // first call
{
	visited[sv] = 1;

	for (ll child :  graph[sv])
		if (!visited[child])
			dfs(child);

	out_time.push_back(sv);

}

void dfs1(ll sv) // second call
{
	visited[sv] = 1;

	for (ll child :  transpose[sv])
		if (!visited[child])
			dfs1(child);

	scc.push_back(sv); // this node is present in this scc
}

void init()
{
	scc.clear(); out_time.clear();
	for (ll i = 0; i < N ; i++)
	{
		graph[i].clear();
		transpose[i].clear();
		visited[i] = 0;
	}
}
void solve(int jj)
{
	init();
	n = jj;
	cin >> e;
	/*input graph */
	while (e--)
	{
		int a  , b ;
		cin >> a >> b;
		a--, b--;
		graph[a].push_back(b);
		transpose[b].push_back(a);
	}

	for (ll i = 0 ; i < n ; i++)
	{
		if (!visited[i])
			dfs(i);
	}

	for (ll i = 0 ; i < n ; i++)
	{
		visited[i] = 0;
	}

	reverse(all(out_time)); // or use stack , or maintain last index
	vector<vector<ll>>component;

	for (int i : out_time)
	{
		if (!visited[i])
		{
			scc.clear();
			dfs1(i);
			component.push_back(scc); // increases complexity;
		}
	}

	int no = 0;
	vector<int>comp(n );
	for (auto v : component) // finding component of every node
	{
		for (auto i : v)
			comp[i] = no;

		no++;
	}

	vector<bool> true_comp(component.size(), true); // store true value for rew comp , else false

	for (int  i = 0 ; i < n ; i++) // checking if connecetd nodes are present in diff comp
	{
		for (int child :  graph[i])
		{
			if (comp[i] != comp[child])
			{
				true_comp[comp[i]] = false;
				break;
			}

		}
	}

	vector<int>nodes;

	for (int  i = 0 ; i < component.size() ; i++)
	{
		if (true_comp[i]) // push alll nodes , so as to print
		{
			for (int i :  component[i])
				nodes.push_back(i + 1);
		}
	}

	sort(all(nodes));
	for (int i :  nodes)
		cout << i << " ";
	cout << endl;

}

int main() {
	// your code goes here

	while (1)
	{	int  x ;
		cin >> x;
		if (x == 0)
			break;
		else
			solve(x);
	}
	return 0;

}

