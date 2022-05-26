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


const int N = 1e5 + 1;
vector<int>graph[N];

vector<int>visited(N);
vector<int>out_time;


int n, m;

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

	for (ll child :  graph[sv])
		if (!visited[child])
			dfs1(child);
}

void init()
{
	out_time.clear();
	for (ll i = 0; i < N ; i++)
	{
		graph[i].clear();

		visited[i] = 0;
	}
}
void solve()
{
	init();

	cin >> n >> m;

	while (m--)
	{
		int a , b;
		cin >> a >> b;
		a--;
		b--;

		graph[a].push_back(b);

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

	int ans = 0;
	for (int i : out_time)
	{
		if (!visited[i])
		{
			ans++;

			dfs1(i);

		}
	}
	cout << ans << endl;
}
//debug(component)
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

