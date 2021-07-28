const int N = 1e5;
vector<int> graph[N];
int Par[N];

void dfs(int cur, int par) {
    Par[cur] = par;
    for (auto x : graph[cur]) 
        if (x != par) // x is child node
            dfs(x, cur);
}
void solve(){
    // x -> y 
    dfs(y , 0 );
    while(x){cout<< x << " " ;  x = Par[x] ;}
}
