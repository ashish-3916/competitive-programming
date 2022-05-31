// https://www.geeksforgeeks.org/maximize-sum-selected-numbers-performing-following-operation/



int solve(int n,vector<int>A){
 
	int freq[1002];
    int dp [1002];
    
    for(int i=0 ;i<n ;i++)
        freq[A[i]]++;
    
    dp[0]=0;
    dp[1]=freq[1];
    
    for(int i=2 ; i<=1000 ;i++)
        dp[i] = max(dp[i-1] , dp[i-2] + i*freq[i] );

    return dp[1000];

}
