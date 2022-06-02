#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;
typedef long long int ll;


void simpleSieve(int limit,vector<int>&prime,vector<ll>&ans){
vector<bool> mark(limit + 1, true);
for(int p=2;p*p<limit;p++){
   if(mark[p]==true){
   for(int i=p*p;i<limit;i+=p)
      mark[i]=false;

   }

}
for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            ans.push_back(p);
        }
    }

}

void solve(long int n,vector<ll>&ans,vector<bool>&vec){

int limit = floor(sqrt(n))+1;
    vector<int> prime;


prime.reserve(limit);
simpleSieve(limit, prime,ans);
for(auto i=prime.begin();i!=prime.end();i++){
      vec[*i]=true;
    }
long long int low,high;
low=limit;
//cout<<low<<endl;
high=2*limit;
//cout<<high<<endl;
while (low < n)
    {
        if (high >= n)
           high = n;

        vector<bool>mark;
        mark.assign(limit+1,true);

        for (int i = 0; i < prime.size(); i++)
        {

            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];


            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }


        for (int i = low; i<high; i++)
            if (mark[i-low] == true)
                {ans.push_back(i);
                vec[i]=true;}

        low = low + limit;
        high = high + limit;
    }


}
int main(){
vector<ll>ans;
vector<bool>vec;
vec.assign(10000005,false);
solve(10000005,ans,vec);
int t;
cin>>t;
int i=1;
while(i<=t){
  ll n;
  cin>>n;

  ll cnt=0;

  ll j=0;
  while(ans[j]<=n/2){
  if(vec[ans[j]] && vec[n-ans[j]] && ans[j]!=1)
  cnt++;
  j++;

  }
  cout<<"Case"<<" "<<i<<": "<<cnt<<endl;
i++;
}

}
