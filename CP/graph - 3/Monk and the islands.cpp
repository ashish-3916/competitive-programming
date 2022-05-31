
const int N = 10002;
vector<int> graph[N];
vector<bool>visited(N);

int bfs(int sv , int fv)
{
	queue<pair<int, int>> pn ; // vertex , depth 

	pn.push({sv , 0});

	while (!pn.empty())
	{
		pair<int, int>t = pn.front();

		pn.pop();

		visited[t.first] = 1 ;

		for (int child : graph [t.first])
		{
			if ( child == fv)
				return t.second + 1 ;

			if (!visited[child])
				pn.push({ child , t.second + 1}) ;
		}

	}
	return  0 ;
}

void init()
{
	for (int i = 0 ; i < N  ; i++)
	{
		visited[i] = 0;
		graph[i].clear();
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
		cin >> x >> y ;

		graph[x].push_back(y);
		graph[y].push_back(x);

	}

	int depth = bfs (1 ,  n);

	cout << depth << endl;


}
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

