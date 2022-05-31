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
class warrior
{
public:
	int first , second , index ;
	warrior() {}
	~warrior() {}

};

void buildTree(int seg[], warrior arr[], int si, int ss, int se) 
{
	if (ss == se)
	{
		seg[si] = ss;
		return;
	}
	int mid = (ss + se) / 2;
	buildTree(seg, arr, 2 * si, ss, mid);
	buildTree(seg, arr, 2 * si + 1, mid + 1, se);

	int i = seg[2 * si];
	int j = seg[2 * si + 1];

	if (arr[i].first >  arr[j].first)
		seg[si] = i;
	else if (arr[i].first <  arr[j].first)
		seg[si] = j;
	else
	{
		if (arr[i].second >  arr[j].second)
			seg[si] = j;
		else if (arr[i].second <  arr[j].second)
			seg[si] = i;
		else
			seg[i] = min(i, j);
	}
	return;
}

int query(int seg[], warrior arr[], int si, int ss , int se, int qs, int qe) // obv ss<=qs<=qe<=se
{
	if (qe < ss || qs > se) //completly outside
		return -1;
	if (ss >= qs && se <= qe) //complety inside        qs   ss------se   qe
	{
		return seg[si];
	}
	int mid = (ss + se) / 2;
	int i = query(seg, arr, 2 * si , ss, mid, qs, qe);
	int j = query(seg, arr, 2 * si + 1, mid + 1, se, qs, qe);
	if (i == -1)
		return j;
	if (j == -1)
		return i;

	if (arr[i].first >  arr[j].first)
		return i;
	else if (arr[i].first <  arr[j].first)
		return j;
	else
	{
		if (arr[i].second >  arr[j].second)
			return j;
		else if (arr[i].second <  arr[j].second)
			return i;
		else
			return min(i, j);
	}



}
void solve()
{
	int n ;
	cin >> n ;
	warrior arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i]. first;
		arr[i].index = i;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].second;

	}

	int seg[4 * n];

	buildTree(seg , arr, 1 , 0 , n - 1);

	int q;
	cin >> q;
	while (q--)
	{
		int l , r ;
		cin >> l >> r;

		int ans  = query(seg , arr , 1 , 0 , n - 1 , l - 1 , r - 1 );
		cout << ans + 1 << endl;
	}
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

