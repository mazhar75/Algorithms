#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void simpleSieve(int limit,vector<int>&prime){
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
            //cout << p << " ";
        }
    }

}
void segmentedsieve(long long int L,long long int R){
  int limit = floor(sqrt(R))+1;
    vector<int> prime;
prime.reserve(limit);
simpleSieve(limit, prime);
long long int low,high;
low=L;
//cout<<low<<endl;
high=L+limit;
//cout<<high<<endl;
while (low < R)
    {
        if (high >= R)
           high = R;

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
                cout << i << " ";

        low = low + limit;
        high = high + limit;
    }
}


int main(){

long long int L,R;
cin>>L>>R;
segmentedsieve(L,R);
return 0;

}
