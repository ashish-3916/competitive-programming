int editDistance(string s, string t)
{
    int s1 = s.size();
    int s2 = t.size();
    
    int dp[s1+1][s2+1];
    
    for(int i=0 ;i <=s1 ; i++)
    {
        for(int j=0 ;j<=s2;j++)
        {
            if(i==0 )
             dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            
            else
            {
               if(s[s1-i]==t[s2-j])
                   dp[i][j]= dp[i-1][j-1];
                else
                    dp[i][j]= 1+min( dp[i][j-1], min(dp[i-1][j] ,dp[i-1][j-1]) );
            }
        }
    }
    int ans = dp[s1][s2];
    return ans;
}
/*
int dp[1001][1001];
int solve(string s1, string s2)
{	
	int n = s1.size();
    int m = s2.size();
	if(n==0)
        return m;
    if(m==0)
        return n;
    if(dp[n][m]!=-1)
        return dp[n][m];
        
    if(s1[0]==s2[0])
        return dp[n-1][m-1]=solve(s1.substr(1), s2.substr(1));
    
    int ans1  =dp[n-1][m-1]= solve(s1.substr(1), s2.substr(1)); // replace this
    int ans2 = dp[n-1][m]=solve(s1.substr(1) , s2); // insert 
    int ans3 = dp[n][m-1]=solve(s1, s2.substr(1)); // delete 
    
    return dp[s1.size()][s2.size()]=1+min( min(ans1,ans2), ans3);
    
    
}
int editDistance(string s1, string s2)
{
    memset(dp, -1, sizeof(dp));
    return solve(s1,s2);
}
*/
