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

void solve()
{
    int n ;
    cin >> n ;


    vector<int> visited(n + 1 , 0);

    vector<int> ans ;

    for (int i = n ; i > 0 ; i--)
    {
        if (!visited[i]) {
            vector<int> factor;
            int k = i ;
            for (int j = 2 ; j * j <= i ; j++) {
                int cnt = 0;
                while (k and (k % j == 0))
                    k /= j , cnt++;
                if (cnt)factor.push_back(j);
            }
            if (k > 1)factor.push_back(k);
        
            vector<int> res ;

            for (int f : factor) {
                int gg = f ;

                while (gg <= i)
                {
                    if (!visited[gg])res.push_back(gg);
                    visited[gg] = 1;
                    gg += f;
                }

            }
            sort(all(res) , greater<int>());
            for (int x : res)
                ans.push_back(x);
        }
    }
    for (int i : ans )
        cout << i << " ";
    cout << 1;
}
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();

    return 0;
}
