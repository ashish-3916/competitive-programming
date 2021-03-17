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

class node
{
public:
	int sum;
	int pre;
	int suf;
	int ans;

	node() {}
	node(int a , int b , int c, int d)
	{
		sum = a;
		pre = b;
		suf = c;
		ans = d;
	}
	~node() {}

};

void buildTree(node seg[]  , int arr[] , int si , int ss , int se)
{

	if (ss == se)
	{
		node present;
		present.suf = present.pre = present.ans = present.sum = arr[ss];
		seg[si] = present;
		return;

	}

	int mid = (ss + se) / 2 ;

	buildTree(seg , arr , 2 * si , ss , mid);
	buildTree(seg , arr , 2 * si + 1 , mid + 1 , se);


	node left = seg[2 * si] ;
	node right = seg[2 * si + 1];

	node present ;

	present.sum = left.sum + right.sum;
	present.pre = max(left.pre , left.sum + right.pre);
	present.suf = max(right.suf , right.sum + left.suf);
	present.ans = max({left.ans , right.ans , left.suf + right.pre});


	seg[si] = present;
	return;
}
node query(node seg[] , int si , int ss , int se , int qs , int qe )// ss qs qe se
{
	if (qs > se or qe < ss) // ss se // outside the range
	{
		node present;
		present.suf = present.pre = present.ans = present.sum =  -15008 ;
		return present;
	}

	if (qs <= ss and qe >= se) // completely inside    qs  ss  se qe
	{
		return seg[si];
	}
	int mid = (ss + se) / 2 ;
	node left = query(seg, 2 * si , ss, mid, qs, qe);
	node right = query(seg , 2 * si + 1 , mid + 1 , se, qs, qe);

	node present;

	present.sum = left.sum + right.sum;
	present.pre = max(left.pre , left.sum + right.pre);
	present.suf = max(right.suf , right.sum + left.suf);
	present.ans = max({left.ans , right.ans , left.suf + right.pre});

	return present;
}
void solve()
{
	int n;
	cin >> n ;
	int arr[n];
	for (int i = 0 ; i < n ; i++)
		cin >> arr[i];
	node seg[4 * n];

	buildTree(seg , arr , 1 , 0 , n - 1);
	/*for (int i = 1 ; i < 2 * n ; i++)
		cout << seg[i].sum << " " << seg[i].pre << " " << seg[i].suf << " " << seg[i].ans << " " << endl;
	*/
	int t;
	cin >> t;
	while (t--)
	{
		int l, r ;
		cin >> l >> r;

		node res = query(seg, 1 , 0, n - 1  , l - 1 , r - 1);
		cout << res.ans << endl;
	}
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

