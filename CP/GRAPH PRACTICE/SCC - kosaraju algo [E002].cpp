//https://www.codechef.com/problems/CHEFRRUN
const int N  = 1e5 + 1 ;
vector<ll> graph[N];
vector<ll> transpose[N];
vector<ll>visited(N);
vector<ll>skips(N);
vector<ll>scc;
vector<ll>out_time;
ll n , x;

void dfs(ll sv)
{
	visited[sv] = 1;

	for (ll child :  graph[sv])
		if (!visited[child])
			dfs(child);

	out_time.push_back(sv);

}
void dfs1(ll sv)
{
	visited[sv] = 1;

	for (ll child :  transpose[sv])
		if (!visited[child])
			dfs1(child);

	scc.push_back(sv);
}

void solve()
{

	scc.clear(); out_time.clear();
	for (ll i = 0; i < N ; i++)
	{
		graph[i].clear();
		transpose[i].clear();
		visited[i] = 0;
		skips[i] = 0;
	}

	cin >> n;
	for (ll i = 0 ; i < n ; i++)
	{
		cin >> x;
		skips[i] = x;

		ll a  = i ;
		ll b = (i + x + 1) % n;

		if (a == b)continue ; // self loop , will handle later, test case 2

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


	reverse(all(out_time));

	ll ans = 0 ;
	for (int i : out_time)
	{
		if (!visited[i])
		{
			scc.clear();
			dfs1(i);

			ll s = scc.size();
			if (s > 1)
				ans += s;

			else if (s == 1) /// check for self loop
			{
				ll a  = scc[0] ;
				ll b = (scc[0] + skips[scc[0]] + 1) % n;
				if (a == b) // if present
					ans++;
			}

		}
	}

	cout << ans << endl;
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
	while (t--)
	{solve();}
	return 0;

}

