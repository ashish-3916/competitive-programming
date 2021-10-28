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

struct pt
{
	int x , y ;
};
bool comp(pt &a , pt &b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
bool ccw(pt a , pt b , pt c) {
	int x1 = b.x - a.x;
	int y1 = b.y - a.y ;
	int x2 = c.x - a.x;
	int y2 = c.y - a.y ;

	return x1 * y2 - x2 * y1 > 0 ;
}
bool cw(pt a , pt b , pt c) {
	int x1 = b.x - a.x;
	int y1 = b.y - a.y ;
	int x2 = c.x - a.x;
	int y2 = c.y - a.y ;

	return x1 * y2 - x2 * y1 < 0 ;
}
void convex_hull(vector<pt> &arr) {
	int n = arr.size();
	sort(all(arr) , comp) ;
	pt first = arr[0] , last  = arr[n - 1];

	vector<pt> left , right;

	left.push_back(first) ;
	right.push_back(first);

	for (int i = 1 ; i < n ; i++) {

		// if present in left
		if ( i == n - 1  or ccw(first , last , arr[i])) {
			while (left.size() >= 2  and !cw(left[left.size() - 2] , left[left.size() - 1] , arr[i]))
				left.pop_back();
			left.push_back(arr[i]);
		}
		// if present in right
		if (i == n - 1 or  cw(first , last , arr[i])) {
			while (right.size() >= 2  and !ccw(right[right.size() - 2] , right[right.size() - 1] , arr[i]))
				right.pop_back();
			right.push_back(arr[i]);
		}
	}


	vector<pt> res ;
	for (int i = 0 ; i < left.size() ; i++)
		res.push_back(left[i]);

	for (int i = right.size() - 2 ; i > 0 ; i--)
		res.push_back(right[i]);


	// for (int i = 0 ; i < res.size() ; i++)
	// 	cout << res[i].x << " " << res[i].y << endl;


	double ans = 0 ;

	for (int i = 0 ; i < res.size() ; i++) {
		pt p = res[i];
		pt q = i ? res[i - 1] : res.back();

		double len =  sqrt((p.x - q.x) * (p.x - q.x)  + (p.y - q.y) * (p.y - q.y) * 1.0 );
		ans += len ;
	}
	cout << fixed << setprecision(1) << ans << endl;

}
void solve()
{
	int n ;
	cin >> n ;
	vector<pt> arr(n);
	for (int i = 0 ; i < n ; i++)
		cin >> arr[i].x >> arr[i].y;

	convex_hull(arr);
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}
