#include<iostream>
#include<vector>
using namespace std;
int NumberOfDivisor(long long int n){
vector<bool>primes;
primes.assign(n+1,true);

vector<bool>primesSquare;
vector<int>vec;//For all primes number sorted order
primesSquare.assign(n*n+1,false);
for(long long p=2;p*p<=n;p++){
  if(primes[p]){
  for(long long i=p*p;i<=n;i+=p)
     primes[i]=false;


  }

}

for(long long p=2;p<=n;p++){
   if(primes[p]){
   vec.push_back(p);
   primesSquare[p*p]=true;}
}
int ans=1;
for(int i=0;;i++){
int cnt=1;
if(vec[i]*vec[i]*vec[i]>n)
break;
while(n%vec[i]==0){
     n=n/vec[i];
     cnt++;
}
ans=ans*cnt;}
if(primes[n])
return ans*2;
else if(primesSquare[n])
return ans*3;
else if(n!=1)
return ans*4;



}
int main(){
long int t,i=1;
cin>>t;
while(i<=t){
long long int n;
cin>>n;
cout<<"Case "<<i<<": "<<NumberOfDivisor(n)-1<<endl;
i++;}

return 0;
}
