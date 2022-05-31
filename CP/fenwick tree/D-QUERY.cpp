#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin() , x.end()
#define endl "\n" //delete if interactive
using namespace std;

const int N  = 3 * 1e5 + 1 ;
const int M = 1e6 + 1;
class event
{
public:
    int start , end , index ;
    event() {}
};
bool func (const event &a , const event &b)
{
    return a.end < b.end ;
}

vector<int> BIT(N , 0);
int LSB(int i)
{
    return i & -i;
}
void update(int index, int value , int n)
{
    while (index < n)
    {
        BIT[index] += value;
        index += LSB(index);
    }
}
int query(int index)
{
    int ans = 0;
    while (index > 0)
    {
        ans += BIT[index];
        index -= LSB(index);
    }
    return ans ;
}

void solve()
{
    int n;
    cin >> n ;
    vector<int>arr(n + 1);
    for (int i = 1 ; i <= n ; i++)
        cin >> arr[i];

    int q ;
    cin >> q ;
    vector<event> queries(q);
    for (int i = 0; i < q ; i++)
    { cin >> queries[i].start >> queries[i].end  ; queries[i].index = i;}

    sort(all(queries), func);

    int total = 0 ;
    vector<int>last_index(M , -1);
    vector<int>res(q);
    int k = 0;
    for (int i = 1; i <= n ; i++)
    {
        if (last_index[arr[i]] != -1)
            update(last_index[arr[i]] , -1 , n + 1);
        else
            total++;

        update(i , 1, n + 1);
        last_index[arr[i]] = i;

        while (k < q  and queries[k].end == i)
        {
            res[queries[k].index] = total - query(queries[k].start - 1);
            k++;
        }
    }

    for (int i : res)
        cout << i << endl;

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
