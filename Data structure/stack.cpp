#include<iostream>
#include<vector>
#include<cstdio>
#define sz 10010
using namespace std;
class stack{
public:
int a[sz],top;
stack(){
top=-1;
}
void push(int x){
  ++top;
  if(top==10009)
  {
  cout<<"Stack overflow!"<<endl;
  return;
  }
  a[top]=x;


}
int Top(){
if(top==-1){
cout<<"Stack Empty!"<<endl;
return -1;
}
return a[top];
}
int pop(){
if(top==-1){
cout<<"Underflow!"<<endl;
return -1;
}
return a[top--];
}
bool empty(){
return !(~top);
}
void printStack(){
int k=top;
while(k!=-1){
cout<<a[k--]<<" ";
}
}

};
int main(){
stack dp;
dp.push(2);
dp.push(0);
dp.push(34);
dp.push(45);
dp.push(56);
dp.printStack();
dp.pop();
dp.printStack();
dp.pop();
dp.printStack();
dp.empty()?cout<<"YES"<<endl:cout<<"NO"<<endl;
cout<<dp.Top();


return 0;
}
