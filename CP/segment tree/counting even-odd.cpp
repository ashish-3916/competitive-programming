#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define endl "\n" //delete if interactive
using namespace std;


void buildTree(pair<int, int> seg[], int arr[], int si, int ss, int se) //building minimum seg tree
{
	if (ss == se)
	{
		if (arr[ss] & 1)
			seg[si] = make_pair(0, 1);
		else
			seg[si] = make_pair(1, 0);
		return;
	}
	int mid = (ss + se) / 2;
	buildTree(seg, arr, 2 * si, ss, mid);
	buildTree(seg, arr, 2 * si + 1, mid + 1, se);

	seg[si] = make_pair(seg[2 * si].F + seg[2 * si + 1].F , seg[2 * si].S + seg[2 * si + 1].S );
}
void updateTree(pair<int, int> seg[] , int arr[], int si , int ss , int se , int idx , int val)
{
	if (ss == se)
	{
		arr[idx] = val;
		if (arr[ss] & 1)
			seg[si] = make_pair(0, 1);
		else
			seg[si] = make_pair(1, 0);
		return;
	}
	int mid = (ss + se) / 2;
	if (idx <= mid)
		updateTree(seg, arr, 2 * si, ss, mid, idx , val);
	else
		updateTree(seg, arr, 2 * si + 1, mid + 1, se , idx , val);

	seg[si] = make_pair(seg[2 * si].F + seg[2 * si + 1].F , seg[2 * si].S + seg[2 * si + 1].S );

}
pair<int, int> query(pair<int, int> seg[], int si, int ss , int se, int qs, int qe) // obv ss<=qs<=qe<=se
{
	if (qe < ss || qs > se) //completly outside
		return {0, 0};
	if (ss >= qs && se <= qe) //complety inside        qs   ss------se   qe
	{
		return seg[si];
	}
	int mid = (ss + se) / 2;
	pair<int, int> l = query(seg, 2 * si , ss, mid, qs, qe);
	pair<int, int> r = query(seg, 2 * si + 1, mid + 1, se, qs, qe);
	return make_pair(l.F + r.F , l.S + r.S );
}
void solve()
{
	int n ;
	cin >> n ;
	int arr[n];
	for (int i = 0 ; i < n ; i++ )
		cin >> arr[i];

	pair<int, int> seg[4 * n];

	buildTree(seg , arr , 1 , 0 , n - 1);
	/*for (int i = 1; i < 4 * n; ++i)
	{
		cout << seg[i].F << " " << seg[i].S << endl;
	}
	*/
	int q;
	cin >> q;

	while (q--)
	{
		int a , b, c ;
		cin >> a >> b >> c;
		if (a == 0)
		{
			updateTree(seg, arr, 1, 0, n - 1 , b - 1 , c);
		}
		else
		{
			pair<int, int>ans  = query(seg , 1 , 0 , n - 1  , b - 1 , c - 1);
			if (a == 1)
				cout << ans.F << endl;
			else
				cout << ans.S << endl;
		}
	}
}
// even odd
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();
	return 0;
}

