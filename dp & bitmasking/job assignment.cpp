/*
naive  -> check all possibility   O(n!)
better -> dp with bitmasks (n*(2^n))
more better -> Hungarian ALgo (n^3)
best  -> branch and bound
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


int n ;
vector<vector<int>>cost;

void func_dp() //  O(n*(2^n));
{

    vector<int> dp(1 << n , INT_MAX) ;
    dp[0] = 0 ;

    for (int mask = 0 ; mask < ((1 << n) - 1) ; mask++) {
        int cnt = __builtin_popcountll(mask) ; // first cnt people assigned job
        //debug(cnt);
        for (int job = 0 ; job < n ; job++)
        {
            if ( !(mask & (1 << job)) ) // if this job isnt assigned
                dp[mask | (1 << job)] = min(dp[mask | (1 << job)] , dp[mask] + cost[cnt][job]);
        }

    }
    // debug(dp);
    cout << "dp : " << dp[(1 << n) - 1] << endl;

}

int recu(int p  , int mask)
{
    if (p >= n )
        return 0 ;
    int res = INT_MAX;
    for (int i = 0 ; i < n ; i++)
        if (!(mask & (1 << i)))
            res = min( res , recu(p + 1 , mask | (1 << i)) + cost[p][i]);
    return res;
}
void func_recu() // O(n!)  just checking all possibilites , if we do memo  its O(n*(2^n));
{
    cout << "recurized : " << recu(0, 0) << endl;
}

void solve()
{
    cin >> n ;
    int x ;
    for (int i = 0 ; i < n ; i++)
    {
        vector<int> res ;
        for (int  j = 0 ; j < n ; j++)
            cin >> x  , res.push_back(x);
        cost.push_back(res);
    }
    func_recu();
    func_dp() ;
    /*
    4
    10  2  6 5
    1  15 12 8
    7   8  9 3
    12 13  4 10
    */
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


    {solve();}
    return 0;

}

