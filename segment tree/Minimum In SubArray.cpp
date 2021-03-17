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


void buildTree(int seg[], int arr[], int si, int ss, int se) //building minimum seg tree
{
	if (ss == se)
	{
		seg[si] = arr[ss];
		return;
	}
	int mid = (ss + se) / 2;
	buildTree(seg, arr, 2 * si, ss, mid);
	buildTree(seg, arr, 2 * si + 1, mid + 1, se);

	seg[si] = min(seg[2 * si] , seg[2 * si + 1]);
}
void updateTree(int seg[] , int arr[], int si , int ss , int se , int idx , int val)
{
	if (ss == se)
	{
		arr[idx] = val;
		seg[si] = val;
		return;
	}
	int mid = (ss + se) / 2;
	if (idx <= mid)
		updateTree(seg, arr, 2 * si, ss, mid, idx , val);
	else
		updateTree(seg, arr, 2 * si + 1, mid + 1, se , idx , val);

	seg[si] = min(seg[2 * si] , seg[2 * si + 1]);

}
int query(int seg[], int si, int ss , int se, int qs, int qe) // obv ss<=qs<=qe<=se
{
	if (qe < ss || qs > se) //completly outside
		return INT_MAX;
	if (ss >= qs && se <= qe) //complety inside        qs   ss------se   qe
	{
		return seg[si];
	}
	int mid = (ss + se) / 2;
	int l = query(seg, 2 * si , ss, mid, qs, qe);
	int r = query(seg, 2 * si + 1, mid + 1, se, qs, qe);
	return min(l , r);
}
void solve()
{
	int n , q;
	cin >> n >> q;
	int arr[n];
	for (int i = 0 ; i < n ; i++)
		cin >> arr[i];

	int seg[4 * (n)];

	buildTree(seg, arr, 1 , 0 , n - 1);



	while (q--)
	{
		char c;
		cin >> c;
		if (c == 'q') //query
		{	int l , r;
			cin >> l >> r;

			int ans = query(seg , 1 , 0, n - 1, l - 1, r - 1);
			cout << ans << endl;
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

