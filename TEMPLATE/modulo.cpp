const int mod = 1e9+7;
long long add(long long a , long long b)
{
    long long ans = ((a%mod)+(b%mod))%mod;
    if(ans<0)ans+=mod;
    return ans;
}
long long mul(long long a,long long b) 
{ 
    long long res = 0;
    a %= mod; 
    while (b) 
    { 
        if (b & 1) 
            res = (res + a) % mod; 
        a = (2 * a) % mod;
        b >>= 1; 
    } 
    return res; 
}
ll power(long long x, ll y)
{   int p = mod;
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}
