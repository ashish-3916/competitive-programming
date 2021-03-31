// directi
/*
idea : if same component than they are replacebale 
*/

void dfs(vector<int> * graph , vector<int> &visited, int sv , int no)
{
	visited[sv] = no;

	for (int child : graph[sv])
	{
		if (!visited[child])
			dfs(graph , visited , child , no);
	}
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> given (n), req(n);
	for (int i = 0; i < n ; i++)cin >> given[i];
	for (int i = 0; i < n ; i++)cin >> req[i];

	vector<int>graph[n + 1];
	while (m--)
	{
		int a , b ;
		cin >> a >> b ;
		a--;
		b--;
		graph[given[a]].push_back(given[b]);
		graph[given[b]].push_back(given[a]);
	}

	vector<int> visited(n + 1, 0);
	int no = 1;

	for (int i = 1 ; i <= n ; i++)
	{
		if (!visited[i])
		{
			dfs(graph , visited , i , no);
		}
		no++;
	}
	//debug(visited);
	bool flag = true ;

	for (int i = 0 ; i < n ; i++)
	{
		if (given[i] != req[i])
		{
			if (visited[given[i]] != visited[req[i]])
			{
				flag = false;
				break;
			}
		}
	}
	if (flag)
		cout << "YES" << endl;
	else cout << "NO" << endl;
}

