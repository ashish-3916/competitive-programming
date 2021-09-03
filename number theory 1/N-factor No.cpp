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
const int N = 1000005;
int dp[11][N];
vector<int> prime;
vector<int> isprime(N , 0);
void sieve()
{
    for (int i = 2 ; i <= N  ; i++)
    {
        if (!isprime[i])
        {
            for (int j =  i ; j <= N ; j += i)
                isprime[j]++;
        }
    }
}
void pre() {
    sieve();
  
    for (int i = 0 ; i < 11 ; i++) {
        for (int j = 1 ; j < N ; j++)
            if (isprime[j] ==  i)
                dp[i][j] =  1 +  dp[i][j - 1];
            else dp[i][j] = dp[i][j - 1] ;
    }

}
void solve()
{
    int l , r , n ;
    cin >> l >> r >> n ;


    cout << dp[n][r] -  dp[n][l - 1] << endl ;
}
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    pre();
    int t;
    cin >> t;
    while (t--)
    {solve();}
    return 0;

}

