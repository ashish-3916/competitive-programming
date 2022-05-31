/*
Euler Totient Function
    phi-function ϕ(n), counts the number of integers between 1 and n inclusive, which are coprime to n  ie. gcd(m , n) = 1 , where m counts in  ϕ(n)
 1. ϕ(p)=p−1.  if p is prime
 2. ϕ(AB) = ϕ(A)*ϕ(B)  ,   if gcd(A,B)=1;
 3. ϕ(p^k) = p^k - (# of all multiples of p i.e. 1,p,2p,3p,......(p^(k-1))p)
           = p^k - p^(k-1)


    n=(p1^a1)⋅(p2^a2)⋯(pk^ak)   , where p1 p2 p3 ...pk are primes
    ϕ(n)=ϕ((p1^a1).(p2^a2)⋯(pk^ak) )  
    ϕ(n)=ϕ(p1^a1)⋅ϕ(p2^a2)⋯ϕ(pk^ak)   .... by prop 2
        =(p1^a1−p1^(a1−1))⋅(p2^a2−p2^(a2−1))⋯(pk^ak−pk^(ak−1))  ... by prop 3
        =n⋅(1−1/p1)⋅(1−1/p2)⋯(1−1/pk)
*/
const int N =  1e5 ;
vector<int> PHI(N);

void phi1ToN(int n) {
    PHI[0] = 0;
    PHI[1] = 1;
    for (int i = 2; i <= n; i++)
        PHI[i] = i;

    for (int i = 2; i <= n; i++) {
        if (PHI[i] == i) {
            for (int j = i; j <= n; j += i)
                PHI[j] -= PHI[j] / i;
        }
    }
}
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
