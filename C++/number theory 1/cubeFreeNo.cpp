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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int N = 1e6 + 1;
vector<bool> iscube(N , false) ;
vector<int> cube;
void generate_cube() {

    for (int i = 2 ; i * i * i < N ; i++)
    {
        if (!iscube[i * i * i])
        {   for (int j = i * i * i ; j < N ; j += i * i * i)
                iscube[j] = true;
        }

    }

    for (int i = 1 ; i < N ; i++)
        if (iscube[i])
            cube.push_back(i);

}
void solve()
{
    int n ;
    cin >> n ;

    auto val =  lower_bound(all(cube) , n);
    if (*val == n ) {
        cout << "Not Cube Free" << endl;
        return ;
    }

    int index =  val - cube.begin()  ;
    cout << n - index << endl;

}
int main() {
    // your code goes here

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    generate_cube();

    int t;
    cin >> t;

    for (int i = 1 ; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        solve();

    }
    return 0;

}

