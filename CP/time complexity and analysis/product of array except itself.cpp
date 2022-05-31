/*

{              1,         a[0],    a[0]*a[1],    a[0]*a[1]*a[2],  }
{ a[1]*a[2]*a[3],    a[2]*a[3],         a[3],                 1,  }

*/  
  
  
  vector<int> productExceptSelf(vector<int>& arr) {
    int n=arr.size();
    
    vector<int>ans(n);
    int p=1;
    for(int i=0;i<n;i++)
    {
        ans[i]=p;
        p=p*arr[i];
    }
   
    p=1;
     for(int i=n-1;i>=0;i--)
     {   ans[i]*=p;
        p=p*arr[i];
    
    }
    return ans;
}
