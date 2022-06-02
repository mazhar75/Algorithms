#include<iostream>
using namespace std;
#define sz 1000
int lps[1000];

void lps_create(string str)
{
    int l=str.length();
    int s=1;
    int p=0;
    lps[0]=0;
    while(s<l)
    {
        if(str[s]==str[p])//jodi match oy taile duitai increment oibo
        {
            lps[s]=p+1;
            s++;
            p++;
        }
        else
        {
            if(p==0)
            {
                lps[s]=0;  // p 0 oile sure kunu match nai er lagi lps[s]=0;                s++;
            }
            else p=lps[p-1];// jodi p!=0 oy and unmatch oy taile ager index or
                            // lps khujar try korbo and dekhbo match suffix pay
                            // kina

        }

    }


}
bool match(string text,string pattern,int lps[]){
 int l=text.length();
 int l1=pattern.length();
 int s=0,p=0;
 while(s<l){
    if(text[s]==pattern[p]){
      s++;
      p++;
      if(p==l1)return true;
    }
    else {
    if(p>0)p=lps[p-1];
    else s++;
    }
    if(p==l1)return true;

}
//if(p==l1)return true;
 return false;


}
int main()
{
    string text,pattern;
    cin>>text>>pattern;
    int l1=text.length();
    int l2=pattern.length();

    lps_create(pattern);

    if(match(text,pattern,lps))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
