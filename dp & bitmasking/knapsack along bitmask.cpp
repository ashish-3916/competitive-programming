//Mehta and Bank Robbery

#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;

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

int primes[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

// use pair<ll , ll> instead array<int, 2> it will pass and idk why !!
void solve()
{
    int n, w;
    cin >> n >> w;
    vector<array<ll , 2>> arr(n); // value , weight
    for (ll i = 0 ; i < n ; i++)
        cin >> arr[i][0] >> arr[i][1];
    sort(all(arr));

    ll dp[2][n + 1][w + 1];
    memset(dp , 0 , sizeof dp);

    //now at the dp[0][i][j] the answer of out typical knapsack problem must be there
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[0][i][j] = dp[0][i - 1][j];
            if (j >= arr[i - 1][1])
            {
                dp[0][i][j] = max(dp[0][i][j], dp[0][i - 1][j - arr[i - 1][1]] + arr[i - 1][0]);
            }
        }
    }
    for (int prime = 1; prime <= 10; prime++)
    {
        int p = prime % 2;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                dp[p][i][j] = dp[p][i - 1][j];
                if (j > arr[i - 1][1])
                {
                    dp[p][i][j] = max(dp[p][i][j], max(arr[i - 1][0] + dp[p][i - 1][j - arr[i - 1][1]], dp[p ^ 1][i - 1][j - arr[i - 1][1]] + arr[i - 1][0] * primes[prime]));
                }
            }
        }
    }
    cout << dp[0][n][w] << endl;
}
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

/*
vector<int> primes{2,3,5,7,11,13,17,19,23,29};

int dp[2001][2001][(1<<10)];

int solve(vector<int>&profit , vector<int> & weight , int index ,int n , int W , int mask)
{
    if(n ==index or W == 0)
        return 0 ; 

    if(dp[index][W][mask]!=-1)
        return dp[index][W][mask];
        
    if(weight[index] <=W)// 2 choices 
    {
        int choice1 =  solve(profit , weight , index+1 , n, W , mask); 

        int choice2 = solve(profit , weight , index+1 , n , W- weight[index]  ,mask) + profit[index]*1;

        for(int i = 0 ;i<10 ; i++)
        {
            if(!(mask&(1<<i)))
                choice2 = max(choice2 , solve( profit , weight, index+1 , n , W-weight[index], mask|(1<<i))  + profit[index] * primes[i] );
        } 

        return dp[index][W][mask]=max(choice1 , choice2);
    }
    else
        return dp[index][W][mask]= solve(profit , weight , index+1 , n, W , mask);


}
void solve1()
{
    memset(dp , -1 , sizeof dp);
    int n , w ;
    cin>> n >> w;
    vector<int>profit(n) , weight(n);

    for(int i =0 ; i<n ; i++)
        cin>> profit[i]>> weight[i];

    cout<< solve(profit , weight , 0 ,n , w , 0)<< endl;
}
*/
