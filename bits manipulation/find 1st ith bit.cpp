int returnFirstSetBit(int n){
   for(int i=0 ;i<31 ;i++)
       if(n& 1<<i)
           return 1<<i;
}


int returnFirstSetBit(int n){ 
   return n &(-1*n) ; 
}
