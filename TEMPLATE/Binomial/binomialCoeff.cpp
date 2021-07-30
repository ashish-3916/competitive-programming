const int mod = 1000000000 + 7;
int add(int a, int b)
{
    int ans  =  ((a % mod) + (b % mod)) % mod;
    return ans;
}

int binomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;

    // Caculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previously
            // stored values
            else
                C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
        }
    }

    return C[n][k];
}
