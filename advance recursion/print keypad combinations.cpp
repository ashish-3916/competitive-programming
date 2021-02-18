#include <iostream>
#include <string>
using namespace std;
string key[]={"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void helper(int no , string ans)
{
    if(no==0  or no==1)
    {
        cout<< ans<< endl;
        return;
    }

    int last=  no%10;
    string s  = key[last];
    int n =s.size();

    for(int i=0 ; i<n ; i++)
    {
        helper(no/10 , s[i]+ans);
    }


}

void printKeypad(int num){

    string ans ="";
    helper(num, ans);


}
