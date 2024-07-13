#include<iostream>
using namespace std;
#define sz 26
struct node{
    bool ending;
    node *next[sz];
    int cnt[sz];
    node(){
        ending = false;
        for(int i=0;i<sz;i++){
            next[i]=NULL;
            cnt[i]=0;
        }
    }
};
struct TRIE{
    node *root;
    TRIE();
    void InsertIntoTrie(string s);
    int SearchIntoTrie(string s);
};
TRIE::TRIE(){
    root = new node();
}
void TRIE::InsertIntoTrie(string s){
    node *cur = root;
    int now, len = s.size();
    for (int i  = 0; i<len; i++)
    {
        now = s[i] - 'a';
        if(cur->next[now] == NULL)
            cur->next[now] =  new node();
        
         
        cur = cur->next[now];
        cur->cnt[now]++;   
       
    }
    cur->ending =  true;
}

int  TRIE::SearchIntoTrie(string s){
    node *cur = root;
    int now, len = s.size();
    for (int i = 0; i < len; i++) {
        now = s[i] - 'a';
        if (cur->next[now] == NULL) {
            return 0;
        }
        cur = cur->next[now];
    }

   
    int total = 0;
    for (int i = 0; i < sz; i++) {
        total += cur->cnt[i];
    }

    return total;
}




int main(){
    int n, q;
    //string s;
    TRIE tr;

    cin>>n>>q;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        tr.InsertIntoTrie(s);
    }
    for(int i=0;i<q;i++){
        cin>>s;
        int ans=tr.SearchIntoTrie(s);
        cout<<ans<<endl;
    }
    return 0;
}