
const int N = 30001 ;
vector<int>graph[N];
vector<bool>visited(N);
vector<int>arr(N);

bool dfs(int sv , int fv)
{
	visited[sv] = 1 ;

	for (int child :  graph[sv])
	{
		if (child == fv)
			return true;

		if (dfs(child, fv))
			return true ;
	}
	return false;
}
void solve()
{

	int n , t ;
	cin >> n >> t;

	int a  ;

	for (int i = 1 ; i < n ; i++)
	{
		cin >> a ;

		graph[i].push_back(a + i) ;

	}

	if (dfs(1 , t))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();

	return 0;
}
