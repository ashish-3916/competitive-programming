/*
alternate:
is single component and edges = verteces -1

*/
vector<int> arr[10001];
int visited[10001];


bool dfs(int sv , int parent)
{
	visited[sv] = 1;


	for (int child : arr[sv])
	{
		if (visited[child] and child != parent)
			return false;
		if (!visited[child])
			if (!dfs(child , sv))
				return false;
	}
	return true;
}
void solve()
{
	int n , m;
	cin >> n >> m;


	for (int  i = 0; i < m ; i++)
	{
		int a  , b ;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	bool ans  = dfs( 1 , -1);

	for (int i = 1 ; i <= n ; i++)
	{
		if (!visited[i])
		{cout << "NO" << endl; return;} // more than 1 componenet
	}

	if (ans)
		cout << "YES" << endl;   // no cycle present
	else
		cout << "NO" << endl;
}

