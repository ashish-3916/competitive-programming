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

/*
int arr[n];
int size=4*(n);
    int seg[size];
    buildTree(seg,arr,1,0,n-1);
    updateTree(seg,arr,1,0,n-1,idx, val)
    int ans=query(seg,1,0,n-1,l,r);
*/

void lazyProp(ll seg[] , ll lazy[], ll si , ll ss , ll se , ll qs , ll qe , ll val)
{
	if (lazy[si] != 0) // pending updates
	{

		seg[si] += (se - ss + 1) * lazy[si];
		if (ss != se)
		{
			lazy[2 * si] += lazy[si] ;
			lazy[2 * si + 1] += lazy [si];
		}
		lazy[si] = 0;
	}

	if (ss > qe || se < qs) // completely ouside
		return;

	if (ss >= qs && se <= qe) // qs ss se qe
	{
		seg[si] += (se - ss + 1) * val;
		if (ss != se)
		{
			lazy[2 * si] += val ;
			lazy[2 * si + 1] += val;
		}
		return ;
	}

	ll mid = (ss + se) / 2;
	lazyProp(seg, lazy, 2 * si , ss , mid , qs , qe , val);
	lazyProp(seg, lazy, 2 * si + 1 , mid + 1 , se , qs , qe , val);

	seg[si] = seg[2 * si] + seg[2 * si + 1];
}
ll query(ll seg[], ll lazy[], ll si , ll ss , ll se , ll qs , ll qe) //note -> value stored by lazy node
{
	if (lazy[si] != 0) // pending updates
	{
		seg[si] += (se - ss + 1) * lazy[si];
		if (ss != se)
		{
			lazy[2 * si] += lazy[si] ;
			lazy[2 * si + 1] += lazy [si];
		}
		lazy[si] = 0;
	}

	// normal process
	if (ss > qe || se < qs) //completly outside
		return 0;

	if (ss >= qs && se <= qe) // overlapping
		return seg[si];

	ll mid = (ss + se) / 2;
	ll l = query(seg, lazy, 2 * si , ss , mid , qs , qe) ;
	ll r = query(seg, lazy, 2 * si + 1 , mid + 1 , se , qs , qe);

	return l + r;
}

void solve()
{
	ll n , q;
	cin >> n >> q;

	ll seg[4 * n] = {0};
	ll lazy[4 * n] = {0};

	//buildTree(seg , arr , 1 , 0, n - 1);


	while (q--)
	{
		ll x ;
		cin >> x ;
		if (x == 0)
		{
			ll  l , r, val;
			cin >> l >> r >> val;
			lazyProp(seg, lazy , 1 , 0, n - 1 , l - 1 , r - 1 , val );


		}
		else
		{
			ll l , r;
			cin >> l >> r;
			ll ans  = query(seg, lazy , 1 , 0 , n - 1 , l - 1 , r - 1 );
			cout << ans << endl;
		}
	}



}

int  main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t;
	cin >> t;
	while (t--)
	{solve();}
	return 0;
}

