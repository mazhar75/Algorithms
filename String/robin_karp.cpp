#include<bits/stdc++.h>
using namespace std;
const int MXN = 1010;
const int BASE [] = {1231, 1567};
const int MOD [] = {1000000000 + 7, 1000000000 + 9};
#define ll long long int

string text, pattern;
ll HASH[2][MXN], POW[2][MXN];

void init()
{
    POW[0][0] = POW[1][0] = 1;
    for(int b = 0; b<2; b++)
    {
        for(int j = 1; j<MXN; j++)
        {
            POW[b][j] = (POW[b][j-1]*BASE[b])%MOD[b];
        }
    }
}

pair<ll, ll> initHash(string str)
{
    int len = str.size();
    HASH[0][0] = HASH[1][0] = 0;
    for(int b = 0; b < 2; b++)
    {
        for(int i = 1; i<=len; i++)
        {
            HASH[b][i] = (HASH[b][i-1] * BASE[b] + (str[i-1] - 'a' + 1)) % MOD[b];
        }
    }
    return make_pair(HASH[0][len], HASH[1][len]);
}

ll getHash(int left, int right, int hsh)
{
    int len = (right - left + 1);
    ll ret = (HASH[hsh][right] - HASH[hsh][left-1]*POW[hsh][len])%MOD[hsh];
    if(ret < 0) ret += MOD[hsh];
    return ret;
}

pair<ll, ll> getHash(int left, int right)
{
    ll hsh0 = getHash(left, right, 0);
    ll hsh1 = getHash(left, right, 1);

    return make_pair(hsh0, hsh1);
}

int main()
{
     freopen("00_input.txt", "r", stdin);
    init();

    int n;
    cin>>n;
    vector<string>vec(n);
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
    }
    int q;
    cin>>q;
    string text="";
    while(q--)
    {
        string s,p;
        cin>>s;

        string c;
        int k;
        if(s=="SEED")
        {
            text = ""; // here
            cin>>c;
            text+=c;
            //cout<<"text = " << text<<endl; // here
        }
        else if(s=="UPDATE")
        {
            cin>>p>>c>>k;
            if(p=="RIGHT")
            {
                for(int i=0; i<k; i++)
                {
                    text+=c;

                }
                //cout<<"text = " << text<<endl; // here

            }
            else
            {
                string x="";
                for(int i=0; i<k; i++)
                {
                    x+=c;
                }
                text=x+text;
                //cout<<"text = " << text<<endl; // here


            }


        }

        else
        {
            //cout<<"text = " << text<<endl; // here
            bool flag=true;
            for(int i=0; i<n; i++)
            {
                string pattern=vec[i];

                pair<ll, ll> patHash = initHash(pattern);
                // cout<<pattern << " : "<<patHash.first<<" "<<patHash.second<<endl;
                pair<ll, ll> txtHash = initHash(text);

                /*** HERE ***/
                if (patHash == txtHash) {
                    printf("Exists.\n");
                    flag = false;
                    break;
                }

            //     for(int i = 0; i < text.size() - pattern.size() + 1; i++)
            //     {
            //         int left = i+1;
            //         int right = (i + pattern.size() - 1) + 1;
            //         auto curHash = getHash(left, right);

            //         if(curHash == patHash)
            //         {
            //             printf("Exists\n"); // here
            //             // text=""; // here
            //             flag=false;
            //         }
            //         if(!flag)break;
            //     }
            //     if(!flag)break;
            }
            if(flag)
            {
                cout<<"Doesn't exist"<<endl; // here
                // text=""; here
            }
        }

    }

    return 0;
}
