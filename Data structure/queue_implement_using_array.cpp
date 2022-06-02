#include<iostream>
#include<cstdio>
#define sz 10000
using namespace std;
class queue{
public:
int a[sz],front,end;
queue(){
front=0;
end=-1;
}
void push(int x){
end++;
if(end==sz-1)
{cout<<"queue overflow!"<<endl;
return ;
}
a[end]=x;
}
int pop(){
if(end==-1){
cout<<"UnderFlow!"<<endl;
return -1;
}
return a[front++];

}
bool empty(){
if(end<front)
return true;
else
return false;
}
void printQueue(){
int k=front;
if(k>end){
cout<<"The queue is Empty!"<<endl;
return ;
}
while(k<=end){
cout<<a[k++]<<" ";
}
cout<<endl;

}
};
int main(){
queue dp;
dp.push(9);
dp.push(11);
dp.push(0);
dp.printQueue();
dp.push(0);
dp.printQueue();
dp.pop();
dp.printQueue();
dp.empty()?cout<<"YES"<<endl:cout<<"NO"<<endl;
dp.pop();
dp.pop();
dp.pop();
dp.printQueue();
return 0;
}
