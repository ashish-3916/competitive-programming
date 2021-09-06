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

const int mod = 1e9 + 7;

ll power(long long x, ll y)
{   ll p = mod;
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
void multiply(vector<vector<ll>> &M , vector<vector<ll>> &A) {
    ll M11 = ((M[0][0] * A[0][0]) + ( M[0][1] * A[1][0])) % (mod - 1 );
    ll M12 = ((M[0][0] * A[0][1]) + ( M[0][1] * A[1][1])) % (mod - 1 );
    ll M21 = ((M[1][0] * A[0][0]) + ( M[1][1] * A[1][0])) % (mod - 1 );
    ll M22 = ((M[1][0] * A[0][1]) + ( M[1][1] * A[1][1])) % (mod - 1 );

    M[0][0] = M11 , M[0][1] = M12 , M[1][0] = M21 , M[1][1] = M22;
}
void power1(vector<vector<ll>> &M , ll k) {
    if (k == 0 or k == 1)
        return ;
    power1(M , k / 2);
    multiply(M, M);
    if (k & 1) {
        vector<vector<ll> > A {{1, 1}, {1, 0}};
        multiply(M, A);
    }
}
ll fib(ll n) {
    if (n == 0) return  0 ;
    vector<vector<ll> > M {{1, 1}, {1, 0}};
    power1(M , n - 1);
    return M[0][0];
}


void solve()
{
    ll f0 , f1 , n;
    cin >> f0 >> f1 >>  n ;
    if (n == 0) {cout << f0 << endl; return ;}
    if (n == 1) {cout << f1 << endl; return ;}

    ll X =  fib(n);
    ll Y =  fib(n - 1);

    ll G0 = (1 + f0) % mod ;
    ll G1 = (1 + f1) % mod ;

    ll p1 =  power(G1 , X) ;
    ll p2 =  power(G0 , Y);

    ll ans = (p1 * p2 ) % mod ;

    cout << ((ans  - 1) + mod) % mod  << endl;


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

    int t;
    cin >> t;
    while (t--)
    {solve();}
    return 0;

}

