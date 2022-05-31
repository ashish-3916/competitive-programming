//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
vector<int> arr[1001];
int visited[1001];
int dis[1001];

void dfs(int sv , int d)
{
	visited[sv] = 1;
	dis[sv] = d;

	for (int child : arr[sv])
		if (!visited[child])
			dfs(child , d + 1);
}
void solve()
{
	int n ;
	cin >> n ;


	for (int  i = 0; i < n - 1 ; i++)
	{
		int a  , b ;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1, 0);
	int q;
	cin >> q;
	int ans  = 0;
	int Distance = 1110;
	while (q--)
	{
		int x ;
		cin >> x ;

		if (Distance >  dis[x])
		{
			ans = x  ;
			Distance = dis[x];
		}
		else if ( Distance == dis[x])
			ans = min(ans , x);

	}
	cout << ans << endl;


}
