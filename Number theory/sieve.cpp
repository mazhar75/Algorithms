#include<iostream>
#include<vector>
using namespace std;
int main(){
int n;
cin>>n;
vector<bool>vec;
vec.assign(n+1,true);

for(int p=2;p*p<=n;p++){
  //vec[p]=false;
  if(vec[p]==true){
  for(int i=p*p;i<=n;i+=p)
      vec[i]=false;

  }

}
for(int i=2;i<=n;i++)
 if(vec[i]==true)
 cout<<i<<" ";

return 0;
}
