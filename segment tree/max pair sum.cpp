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

void buildTree(pair<int, int> seg[], int arr[], int si, int ss, int se) 
{
	if (ss == se)
	{
		seg[si] = make_pair(arr[ss], INT_MIN);
		return;
	}
	int mid = (ss + se) / 2;
	buildTree(seg, arr, 2 * si, ss, mid);
	buildTree(seg, arr, 2 * si + 1, mid + 1, se);

	pair<int, int> l  = seg[2 * si];
	pair<int, int> r = seg [2 * si + 1];

	if ( l.F > r.F)
	{
		int mx = l.F ;
		int smx = max( r.F , l.S);
		seg[si] = make_pair(mx, smx);
	}
	else
	{
		int mx = r.F ;
		int smx = max( l.F , r.S);
		seg[si] = make_pair(mx, smx);
	}
}
void updateTree(pair<int, int> seg[] , int arr[], int si , int ss , int se , int idx , int val)
{
	if (ss == se) // just additionl condn;
	{  
       arr[ss] = val;
       seg[si] = make_pair( val, INT_MIN );
    
		return;
	}
	int mid = (ss + se) / 2;
	if (idx <= mid)
		updateTree(seg, arr, 2 * si, ss, mid, idx , val);
	else
		updateTree(seg, arr, 2 * si + 1, mid + 1, se , idx , val);

	pair<int, int> l  = seg[2 * si];
	pair<int, int> r = seg [2 * si + 1];

	if ( l.F > r.F)
	{
		int mx = l.F ;
		int smx = max( r.F , l.S);
		seg[si] = make_pair(mx, smx);
	}
	else
	{
		int mx = r.F ;
		int smx = max( l.F , r.S);
		seg[si] = make_pair(mx, smx);
	}

}
pair<int, int> query(pair<int, int> seg[], int si, int ss , int se, int qs, int qe) // obv ss<=qs<=qe<=se
{
	if (qe < ss || qs > se) //completly outside
		return make_pair(INT_MIN, INT_MIN);
	if (ss >= qs && se <= qe) //complety inside        qs   ss------se   qe
	{
		return seg[si];
	}
	int mid = (ss + se) / 2;
	pair<int, int> l = query(seg, 2 * si , ss, mid, qs, qe);
	pair<int, int> r = query(seg, 2 * si + 1, mid + 1, se, qs, qe);

	if ( l.F > r.F)
	{
		int mx = l.F ;
		int smx = max( r.F , l.S);
		return make_pair(mx, smx);
	}
	else
	{
		int mx = r.F ;
		int smx = max( l.F , r.S);
		return make_pair(mx, smx);
	}

	

}
void solve()
{
	int n ;
	cin >> n ;
	int arr[n];
	for (int i = 0 ; i < n ; i++)
		cin >> arr[i];

	pair<int, int> seg[4 * (n)];
	memset(seg, 0 ,sizeof(seg));
	buildTree(seg, arr, 1 , 0 , n - 1);

	int q;
	cin >> q;
	while (q--)
	{
		char c;
		cin >> c;
		if (c == 'Q') //query
		{	int l , r;
			cin >> l >> r;

			pair<int, int> ans = query(seg , 1 , 0, n - 1, l - 1, r - 1);
			cout << ans.F + ans.S << endl;
		}
		else
		{
			int index, val;
			cin >> index >> val;
			updateTree(seg, arr, 1, 0, n - 1, index - 1, val);
		}
	}
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

