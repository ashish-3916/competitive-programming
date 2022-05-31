#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcountll(n)
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


double findArea(vector<int>&X , vector<int>&Y) {
	int n = X.size();

	double ans = 0 ;
	for (int i = 1 ; i < n - 1 ; i++) {
		int x1 = X[i] - X[0];
		int y1 = Y[i] - Y[0];
		int x2 = X[i + 1] - X[0];
		int y2 = Y[i + 1] - Y[0];
		ans += x1 * y2 - x2 * y1 ;
	}

	return abs(ans) / 2;
}
void solve()
{
	string s ;
	cin >> s ;
	int n = s.size();
	vector<int> dis(n);
	for (int i = 0 ; i < n ; i++)
		cin >> dis[i];

	int x = 0 , y = 0 ;
	vector<int>X(n) , Y(n);

	for (int i = 0 ; i < n ; i++ ) {
		char c  =  s[i];
		if (c == 'E') x += dis[i];
		else if (c == 'W') x -= dis[i];
		else if (c == 'N')y += dis[i];
		else if (c == 'S')y -= dis[i];
		X[i] = x , Y[i] = y;
	}
	cout << findArea(X , Y);
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}
