#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define endl "\n" //delete if interactive
using namespace std;


/*

so the idea is to sort on basis of x  and then ..
for each Y we check hw many values are smaller than this Y ie , bit[Y]
and this Y is smaller then all  i   whre    max_value >= i > Y so we need to add 1 to range (Y , max_val] , but
we instead update only at some node telling you have got a no smaller than you and that me !!

*/

const int N  = 1e5 + 1;
vector<int>bit(N, 0);
int LSB(int val)
{
	return val & -val ;
}
int query(int val)
{
	int ans  = 0 ;

	while (val != 0)
	{
		ans += bit[val];
		val -= LSB(val);
	}
	return ans  ;
}
void update(int val)
{
	while (val < N)
	{
		bit[val]++ ;
		val += LSB(val);
	}
}
class coder
{
public:
	int x , y , idx ;
};

bool func ( coder &A  , coder &B)
{
	if (A.x == B.x)
		return A.y < B.y;
	return A.x < B.x ;
}
void solve()
{
	int n ;
	cin >> n ;

	vector<coder> arr(n);
	for (int i = 0 ; i < n ; i++)
	{
		cin >> arr[i].x >> arr[i].y ;

		arr[i].idx = i;
	}

	sort(all(arr), func);
	vector<int> ans(n);
	for (int i = 0 ; i < n ;)
	{
		int val = arr[i].y ;

		int sp = i , ep ;
		int a = query(val);
		ans[arr[i].idx] = a;
		for ( ep = i + 1 ; arr[ep].x == arr[sp].x and arr[ep].y  == arr[sp].y  ; ep++)
		{
			a = query(val);
			ans[arr[ep].idx] = a;
		}
		for (int  j = sp ; j < ep ; j++)
			update(val);

		i = ep;
	}

	for (auto i : ans )
		cout << i << endl;


}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}
