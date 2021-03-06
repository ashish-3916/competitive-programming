// soln 1 :
#include <bits/stdc++.h>
using namespace std;
#define maxn 100100
#define llg int

llg n,a[maxn],k,x,t;
int main()
{

	cin>>n>>k>>x;
	
	for (llg i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	while ((double)clock()/(double)CLOCKS_PER_SEC<0.75)
	{
		t++;
		if (t>k) break;
		for (llg i=1;i<=n;i+=2) a[i]^=x;
		sort(a+1,a+n+1);
		
	}
	cout<<a[n]<<" "<<a[1];
	return 0;
}

// soln2 (better)

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

void solve()
{
	int n , k, x , a;
	cin >> n >> k >> x ;

	int arr[1024] = {0};


	for (int i = 0; i < n; ++i)
	{
		cin >> a ;
		arr[a]++;
	}

	for (int i = 0; i < k; ++i)
	{
		ll sum = 0;
		int alt[1024] = {0};
		for (int j = 0 ; j < 1024 ; j++)
		{
			if (arr[j] == 0)
				continue;

			if (sum & 1)
			{
				sum += arr[j];

				alt[j] += (arr[j] + 2 - 1) / 2;
				ll xo = j ^ x;
				alt[xo] += arr[j] / 2;

			}
			else
			{
				sum += arr[j];

				alt[j] += arr[j] / 2;
				ll xo = j ^ x;
				alt[xo] += (arr[j] + 2 - 1) / 2;
			}
		}
		for (int m = 0 ; m < 1024 ; m++)
		{
			arr[m] = alt[m];
		}
	}


	int mx, mn;
	for (int i = 0 ; i < 1024 ; i++)
		if (arr[i])
		{mn = i; break;}

	for (int i = 1023 ; i >= 0; i--)
		if (arr[i])
		{mx = i; break;}

	cout << mx << " " << mn << endl;


}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

