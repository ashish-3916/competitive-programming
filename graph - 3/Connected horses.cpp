//hacker earth 

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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ASHISH_DANGI
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
int n, m;
int c ;
const int mod = 1e9 + 7;
const int N  = 1000000;
int dp[N];
long long add(long long a , long long b)
{
	long long ans = ((a % mod) + (b % mod)) % mod;
	return ans;
}
long long mul(long long a, long long b, long long mod)
{
	long long res = 0; // Initialize result
	a %= mod;
	while (b)
	{
		if (b & 1)
			res = (res + a) % mod;
		a = (2 * a) % mod;
		b >>= 1; // b = b / 2
	}
	return res;
}

void factmod()
{

	dp[0] = 1;

	for (int i = 1; i <= N; i++)
		dp[i] = mul(dp[i - 1] , i,mod);

}
int dirn[8][2] = { { -2, 1}, { -1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, { -1, -2}, { -2, -1}};

bool valid (int x , int y)
{
	return ( x >= 0  and y >= 0  and  x < n and  y < m);
}
void dfs(vector<vector<int>>& graph , vector<vector<bool>>& visited, int cx , int cy)
{
	visited[cx][cy] = 1;
	c++;
	for (int i = 0 ; i < 8 ; i++)
	{
		int nx = cx + dirn[i][0];
		int ny = cy + dirn[i][1];

		if (valid(nx , ny) and !visited[nx][ny] and graph[nx][ny])
		{
			dfs(graph, visited , nx , ny);
		}
	}
}
void solve()
{

	cin >> n >> m;

	int q ;
	cin >> q;
	vector<vector<int>> graph(n , vector<int>(m, 0));
	while (q--)
	{
		int a , b ;
		cin >> a >> b;
		a--, b--;
		graph[a][b] = 1;
	}
	vector<int>total;

	vector<vector<bool>>visited(n , vector<bool>(m, 0));
	ll ans = 1;
	for (int i = 0 ; i < n ; ++i)
	{
		for (int  j = 0 ; j < m; j++ )
		{
			if (!visited[i][j] and graph[i][j])
			{	c = 0;
				dfs(graph , visited, i, j);
				ans = (ans * dp[c]) % mod;

			}
		}
	}

	cout << ans << endl;

}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	factmod();
	int t;
	cin >> t;
	while (t--)
	{solve();}
	return 0;

}

