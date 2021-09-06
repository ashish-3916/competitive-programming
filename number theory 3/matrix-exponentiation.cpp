https://leetcode.com/problems/fibonacci-number/discuss/1444388/matrix-exponentiation


Topics :  exponentation and matrix exponentation
Soln -> O(logn)

let's start 
```
// exponentation
a^x can be calulated in logn as follows 
    a^x = a^(x/2) * a^(x/2)       ..... if x is even
    a^x = a^(x/2) * a^(x/2) * a   ..... if x is odd
```
```
// matrix exponentation
any general recursive reln can be represented as 
        M * currentState = nextState    (M is a matrix , we currently dont know)
fibbo relation ->  f(n) = f(n-1) + f(n-2)   and f(0)=0 and f(1) = 1 
so we have f(0) and f(1) [i.e. 2 states] hence M would be of 2 X 2

        | a  b |  *  | f(n-1) |  =  | f(n)  |
        | c  d |     | f(n-2) |     | f(n-1)|

i.e.       M    *  currentState  =  nextState 

now lets calulate M 
    
    a*f(n-1) + b*f(n-2) = f(n)
    c*f(n-1) + d*f(n-2) = f(n-1)
    a=1, b=1, c=1, d=0
    
    lets calulate for f(2)
    | 1  1 |  *  | f(1) |  =  | f(2) |
    | 1  0 |     | f(0) |     | f(1) |
    
    lets calulate for f(3)
    | 1  1 |  *  | f(2) |  =  | f(3) |
    | 1  0 |     | f(1) |     | f(2) |
    
    ie
    
    | 1  1 |  *  | 1 1 | * | f(1) |  =  | f(3) |
    | 1  0 |     | 1 0 |   | f(0) |     | f(2) |
    
    ie
    for general n 
    M^(n-1) * | f(1) |  =  | f(n)   |
              | f(0) |     | f(n-1) |
              
    how to find M^(n-1) ? use  exponentation !
    
    let A = M^(n-1) ;
    
    then f(n) = A[0][0] * f(1) + A[0][1] * f(0)
         f(n) = A[0][0]   //   f(0) = 0 and f(1) = 1 
```

```
// O(logN)
class Solution {
    void multiply(vector<vector<int>> &M ,vector<vector<int>> &A){
        int M11 = M[0][0] * A[0][0] + M[0][1] * A[1][0];
        int M12 = M[0][0] * A[0][1] + M[0][1] * A[1][1];
        int M21 = M[1][0] * A[0][0] + M[1][1] * A[1][0];
        int M22 = M[1][0] * A[0][1] + M[1][1] * A[1][1];
        
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
public:
    int fib(int n) {
       if(n==0) return  0 ;
        vector<vector<int> > M {{1,1},{1,0}};
        power(M , n-1);
        return M[0][0];
    }
};
```
BONUS -> 

f(n) = a*f(n-1) + b*f(n-2) + c*f(n-3) + d

[4*4] * [[f(n-1) f(n-2) f(n-3) d]] = [[f(n) f(n-1) f(n-2) d]]

if f(n) is defined for even and odd -> calculate saperately 
