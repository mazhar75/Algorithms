#include<iostream>
#include<algorithm>
using namespace std;
long long int dp[10000];

long long int fibonacci(long long int n)
{
    //cout<<dp[n]<<" ";
    if(n==0)return 0;
    if(n==1)return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n]=fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    for(int i=0; i<10000; i++)
    {
        dp[i]=-1;
    }
    long long int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
    return 0;
}
