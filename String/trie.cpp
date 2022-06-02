#include<iostream>
#define sz 100000
using namespace std;
#define trie_sz 26
struct node
{
    node *next[trie_sz];
    bool ending;
    node()
    {
        ending = false;
        for(int i=0; i<trie_sz; i++)
        {
            next[i]=NULL;
        }
    }


};
struct trie
{
    node *root;
    trie();
    void insert_into_trie(string &str);
    bool search_into_trie(string &str);


};
trie::trie()
{
    root = new node();
}
void trie::insert_into_trie(string &str)
{
    int l=str.length();
    node *cur=root;
    int now;
    for(int i=0; i<l; i++)
    {
        now=str[i]-'a';
        if(cur->next[now]==NULL)
        {
            cur->next[now] = new node();
        }

        cur=cur->next[now];



    }
    cur->ending = true;

}
bool trie::search_into_trie(string &str)
{
    node *cur = root;
    int now, len = str.size();
    for (int i = 0; i<len; i++)
    {
        now = str[i] - 'a';
        if(cur->next[now] == NULL) return false;
        cur = cur->next[now];
    }
    return cur->ending;

}
int main()
{
    int n, q;
    string str;
    trie *tr = new trie();

    cin >> n;
    for (int i = 0; i<n; i++)
    {
        cin >> str;
        tr->insert_into_trie(str);
    }

    cin >> q;

    for (int i = 0; i<q; i++)
    {
        cin >> str;
        cout << str <<" does " << (tr->search_into_trie(str)?"":"not ") << "exist!" << endl;
    }
    return 0;
}
