/*
13
2 12 9 16 10 5 3 20 25 11 1 8 6 

output :
8 9 10 11 12 
*/

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    int sp=-1;
    int len=0;
    unordered_map<int, int> m;
    
    for(int i=0;i<n;i++)
        m[arr[i]]++;
    
    for(int i=0;i<n;i++)
    {
		if(m[arr[i]-1])continue;
        
        int s = arr[i];
        int l=1;
        while(m[s+1])
        {
            l++;
            s++;
        }
        if(l>len)
        {
            sp=arr[i];
            len=l;
        }
    }
    return {sp, sp+len-1};
}
