

const int N =  100001 ;
vector<int> graph[N];
vector<bool> visited(N) ;
vector<ll> arr(N);

ll dfs ( int sv)
{
	visited[sv] = 1;

	ll ans  = arr[sv] ;

	for (int child : graph[sv])
	{
		if (!visited[child])
		{
			ans += dfs(child);
		}
	}
	return ans ;
}
void init()
{
	for (int i = 0 ; i < N ; i++)
	{
		graph[i].clear();
		visited[i] = 0;
		arr[i] = 0;
	}

}

void solve()
{
	init();
	int n, m ;
	cin >> n >> m;

	while (m--)
	{
		int x , y ;
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);

	}

	for (int  i = 1 ; i <= n ; i++)
		cin >> arr[i];

	ll ans  = 0 ;

	for (int i = 1 ; i <= n ; i++)
	{
		if (!visited[i])
		{
			ll a = dfs(i);

			ans = max( ans  , a);
		}
	}
	cout << ans << endl;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{solve();}
	return 0;

}

