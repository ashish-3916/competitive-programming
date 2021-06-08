//Mehta and Bank Robbery

/*
vector<int> primes{2,3,5,7,11,13,17,19,23,29};

int dp[2001][2001][(1<<10)];

int solve(vector<int>&profit , vector<int> & weight , int index ,int n , int W , int mask)
{
    if(n ==index or W == 0)
        return 0 ; 

    if(dp[index][W][mask]!=-1)
        return dp[index][W][mask];
        
    if(weight[index] <=W)// 2 choices 
    {
        int choice1 =  solve(profit , weight , index+1 , n, W , mask); 

        int choice2 = solve(profit , weight , index+1 , n , W- weight[index]  ,mask) + profit[index]*1;

        for(int i = 0 ;i<10 ; i++)
        {
            if(!(mask&(1<<i)))
                choice2 = max(choice2 , solve( profit , weight, index+1 , n , W-weight[index], mask|(1<<i))  + profit[index] * primes[i] );
        } 

        return dp[index][W][mask]=max(choice1 , choice2);
    }
    else
        return dp[index][W][mask]= solve(profit , weight , index+1 , n, W , mask);


}
void solve1()
{
    memset(dp , -1 , sizeof dp);
    int n , w ;
    cin>> n >> w;
    vector<int>profit(n) , weight(n);

    for(int i =0 ; i<n ; i++)
        cin>> profit[i]>> weight[i];

    cout<< solve(profit , weight , 0 ,n , w , 0)<< endl;
}
*/
