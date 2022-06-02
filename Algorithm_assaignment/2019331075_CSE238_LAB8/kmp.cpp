#include<iostream>
#include<string>

#define MAX 100000
using namespace std;

int a[MAX];

void build_function(string pattern, int m)
{

    a[0] = 0;
    a[1] = 0;

    for(int i = 2; i <= m; i++)
    {

        int j = a[i - 1];
        while(true)
        {

            if(pattern[j] == pattern[i - 1])
            {
                a[i] = j + 1;
                break;
            }

            if(j == 0)
            {
                a[i] = 0;
                break;
            }

            j = a[j];
        }
    }
}


int kmp(string text, string pattern)
{    int cnt=0;
    int n = text.size();
    int m = pattern.size();
    build_function(pattern, m);

    int i = 0;


    int j = 0;

    while(true)
    {
        if(j == n)
        {
            return cnt;
        }


        if(text[j] == pattern[i])
        {
            i++;
            j++;
            if(i == m)
            {
                cnt++;
            }
        }
        else
        {
            if (i == 0)
            {

                j++;
            }
            else
            {

                i = a[i];
            }
        }
    }
    return cnt;
}
int main()
{
    //freopen("00_input.txt","r+",stdin);
    int t;
    scanf("%d",&t);
    int i=1;
    while(i<=t)
    {
    char text[1000001],pattern[1000001];
    scanf("%s %s",text,pattern);
    //int cnt=0;
    int k=kmp(text,pattern);
    cout<<"Case "<<i<<": "<<k<<endl;
    //else cout<<"Does not exist"<<endl;
    i++;
    }
    return 0;

}
