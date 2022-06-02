#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
long long int n;
vector<long int>vec;
cin>>n;
long int l=floor(sqrt(n));
for(int i=1;i*i<=n;i++){
    if(n%i==0)
    {
    if(i*i<n)
    {vec.push_back(i);
    vec.push_back(n/i);}
    else
    vec.push_back(i);}
    }

 sort(vec.begin(),vec.end());

for(auto it=vec.begin();it!=vec.end();it++)
   cout<<*it<<" ";

return 0;
}
