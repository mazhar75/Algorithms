#include<iostream>
#include<vector>
#define sz 10000
using namespace std;
vector<int>heap(sz);
vector<int>a;

void heapify(int i)
{
    int par=(i-1)/2;
    bool check =false;
    while(true)
    {   //if(par==0)break;
        if(heap[par]<heap[i])
        swap(heap[par],heap[i]);
        else
        break;
        i=par;
        par=(i-1)/2;
        if(check)break;
        if(par==0)check = true;

    }


}

void inputHeap(int n)
{
    heap[0]=a[0];
    for(int i=1; i<n; i++)
    {

        heap[i]=a[i];// 1 3 2
        heapify(i);



    }
    for(int i=0; i<n; i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;


}
void againheapify()
{
    int x=max(heap[1],heap[2]),val=heap[0],j=0;
    while(val<x)
    {

        if(x==heap[j*2+1])
        {
            swap(heap[j],heap[2*j+1]);
            j=2*j+1;
            x=max(heap[2*j+1],heap[2*j+2]);
        }
        else
        {
            swap(heap[j],heap[2*j+2]);
            j=2*j+2;
            x=max(heap[2*j+1],heap[2*j+2]);
        }



    }



}
int deleteHeap(int n)
{
    int k=heap[0];
    heap[0]=heap[n-1];
    heap[n-1]=-1;
    againheapify();
    return k;

}

void init(int n)
{
    for(int i=0; i<n; i++)
    {
        heap[i]=-1;
    }

}
int main()
{
    int n;
    cin>>n;
    for(int i=0,val; i<n; i++)
    {
        cin>>val;
        a.push_back(val);

    }
    init(n);
    inputHeap(n);
    int val=deleteHeap(n);
    cout<<val<<endl;



    return 0;
}
