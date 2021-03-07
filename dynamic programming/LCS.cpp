int lcs(string s, string t)
{
    int s1= s.size();
    int s2 = t.size();
    
    int dp[s1+1][s2+1];
    
    for(int i=0 ;i <=s1 ; i++)
    {
        for(int j=0 ;j<=s2;j++)
        {
            if(i==0 or j==0)
             dp[i][j]=0;
            
            else
            {
               if(s[s1-i]==t[s2-j]) // important 
                   dp[i][j]=1+ dp[i-1][j-1];
                else
                    dp[i][j]= max( dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    int ans = dp[s1][s2];
    return ans;
}


/*
int dp[1001][1001];

int LCS(string s, string t)
{
    int i = s.size();
    int j= t.size();
	if(!s.size() or !t.size())
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[0]==t[0])
        return dp[i][j]=LCS(s.substr(1), t.substr(1)) + 1 ;
    
    int ans1 = LCS(s, t.substr(1));
    int ans2 = LCS(s.substr(1), t);
    
    return dp[i][j]=max(ans1,ans2) ;
    
}
int lcs(string s , string t)
{
    memset(dp,-1,sizeof(dp));
    return LCS(s,t);
}
*/
