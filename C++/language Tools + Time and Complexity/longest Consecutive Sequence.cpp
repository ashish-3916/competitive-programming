#include<vector>
#include<unordered_map>
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
