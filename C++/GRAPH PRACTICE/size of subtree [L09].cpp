const int N = 1e5 + 1 ;
vector<int>graph[N];
vector<bool>visited(N , false);
vector<int>subsize(N);

void dfs(int sv )
{
	visited[sv] = 1;

	int sz  = 1 ;

	for (int child  :  graph[sv])
	{	
		if (!visited[child])
		{
			dfs(child);

			sz += subsize[child];
		}
	}
	subsize[sv] = sz ;
}

void solve()
{
	int n  ;
	cin >> n  ;

	int m = n - 1;
	int x , y;
	while (m--)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1);

	for (int i = 1 ; i <= n ; i++)
		cout << subsize[i] << " ";
}
