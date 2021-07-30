struct trie
{
    unordered_map<char, trie *> m;
    bool end;

    trie() {
        end = false;
    }
};
bool search(trie * root , string s)
{
     trie * curr =  root ;

     for(char  c : s)
     {
        if(!curr->m.count(ch))  
            return false;
        curr = curr->m[ch];
     }

     return curr->end;

}
void insert(trie * root , string s)
{
    trie * curr =  root ;
    for (char ch : s)
    {
        if (!curr->m.count(ch))
            curr->m[ch] = new trie;

        curr = curr->m[ch];
    }
    curr->end = true;
}
