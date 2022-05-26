#include <string>
using namespace std;
string key[]={" ", " ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
    if(num==0 or num==1)
    {    output[0]="";
       return 1;
    }
    
    int last = num%10 ;
    string s = key[last];
    int n =s.size();
    string smalloutput[10000];
    
    int size =  keypad(num/10 ,  smalloutput);
    int k= 0 ;
    for(int i=0 ; i< size ; i++)
    {
		for(int j=0;j<n ; j++)
            output[k++]=smalloutput[i] + s[j];
    }
    
    return k;
    
    
}
