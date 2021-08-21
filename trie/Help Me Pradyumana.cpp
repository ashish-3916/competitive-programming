#include <bits/stdc++.h>
using namespace std;


class Trie
{
    bool isEnd ;
    map<char, Trie*>m;

public:
    Trie() {
        isEnd = false;
    }

    void insert(string &s )
    {
        Trie * root =  this;

        for (char c : s )
        {
            if (!root->m.count(c))
                root->m[c] = new Trie();

            root = root->m[c];
        }
        root->isEnd = true;
    }

    void print(Trie * root , string pre ,  vector<string> &res)
    {
        if (root->isEnd)
            res.push_back(pre);
        for (auto i : root->m)
        {
            char c = i.first ;
            Trie* child = i.second;
            print(child , pre + c , res);
        }
        return ;
    }

    vector<string> search(string &s)
    {
        Trie * root =  this;

        for (char c : s)
        {
            if (!root->m.count(c))
            {
                insert(s);
                return {"No suggestions"};
            }
            root = root->m[c];
        }
        vector<string > ans ;
        print(root , s , ans);
        return ans ;
    }
};


void solve()
{
    int n ;
    cin >> n ;

    Trie * root = new Trie();
    string s ;
    while (n--)
    {
        cin >> s ;
        root->insert(s);
    }
    int q ;
    cin >> q ;

    while (q--) {
        cin >> s ;
        vector<string> ans = root->search(s);

        for (string ss : ans)
            cout << ss << endl;
    }
}
int main() {
    // your code goes here
    solve();
    return 0;
}
