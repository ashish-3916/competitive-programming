// not a good solution

void removeConsecutiveDuplicates(char *arr) {
	
    if(arr[0]=='\0')
        return ;
    
    if(arr[0]==arr[1])
    {
        for(int i = 0 ; arr[i]!='\0' ; i++)
            arr[i]=arr[i+1];
         removeConsecutiveDuplicates(arr);
    }
    else
     removeConsecutiveDuplicates(arr+1);


}
