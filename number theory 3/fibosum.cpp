Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
  
#include<bits/stdc++.h>
const int mod = 1e9+7;
long long add(long long a , long long b)
{
	long long ans = ((a % mod) + (b % mod)) % mod;
	if (ans < 0)ans += mod;
	return ans;
}
long long mul(long long a, long long b)
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
    void multiply(vector<vector<int>> &M ,vector<vector<int>> &A){
        int M11 = add(mul(M[0][0] , A[0][0]) ,mul( M[0][1] , A[1][0]));
        int M12 = add(mul(M[0][0] , A[0][1]) ,mul( M[0][1] , A[1][1]));
        int M21 = add(mul(M[1][0] , A[0][0]) ,mul( M[1][1] , A[1][0]));
        int M22 = add(mul(M[1][0] , A[0][1]) ,mul( M[1][1] , A[1][1]));
        
        M[0][0] = M11 , M[0][1] =M12 , M[1][0] =M21 , M[1][1] = M22;   
    }
    void power(vector<vector<int>> &M , int k){  
        if(k==0 or k==1)
            return ;
        power(M , k/2);
        multiply(M,M);
        if(k&1){
            vector<vector<int> > A {{1,1},{1,0}};
            multiply(M, A);
        }
    }
    int fib(int n) {
       if(n==0) return  0 ;
        vector<vector<int> > M {{1,1},{1,0}};
        power(M , n-1);
        return M[0][0];
    }
unsigned long long fiboSum(unsigned long long l,unsigned long long r)
{
    
	int R =  fib(r+2);
    int L =  fib(l+1);
    //cout<< R<< " "<<L << endl; 
    int ans = add(R,-L);
    return ans;
}

