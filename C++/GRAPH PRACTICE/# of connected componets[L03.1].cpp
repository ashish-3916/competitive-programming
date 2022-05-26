//https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

void dfs(vector<int> arr[]  , vector<bool>&visited , int sv)
{
	visited[sv] = 1;

	for (int child : arr[sv] )
		if (!visited[child])
			dfs(arr , visited , child);
}
void solve()
{
	int n , e ;
	cin >> n >> e;

	vector<int> arr[n + 1];
	for (int  i = 0; i < e ; i++)
	{
		int a  , b ;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	vector<bool> visited(n + 1, false);

	int ans  = 0 ;

	for (int i = 1 ; i <= n ; i++)
	{
		if (!visited[i])
			ans++ , dfs(arr , visited  , i);
	}
	cout << ans << endl;
}


