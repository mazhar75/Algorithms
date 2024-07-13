#include<iostream>
using namespace std;
struct node{
   int val;
   node *next;
   node(){
     val = 0;
     next = NULL;
   }
   node(int k){
    val = k;
    next = NULL;
   }
};
struct SinglyLinkedList{
     node *head,*tail;
     SinglyLinkedList();
     void InsertIntoHead(int);
     void InsertIntoTail(int);
     int DeleteFromHead();
     void PrintList();
     void ReverseList();


};
SinglyLinkedList::SinglyLinkedList(){
  head = NULL;
  tail = NULL;
}
void SinglyLinkedList::InsertIntoHead(int x){
   node *cur = new node(x);
   if(head==NULL){
     head = tail = cur;
     return;
   }
   cur->next=head;
   head=cur;
}
void SinglyLinkedList::InsertIntoTail(int x){
   node *cur = new node(x);
   if(head==NULL){
     head = tail = cur;
     return;
   }
   tail->next=cur;
   tail = tail->next;

}
int SinglyLinkedList::DeleteFromHead(){
     if(head==NULL){
        cout<<"Underflow"<<endl;
        return -1;
     }
     node *temp;
     temp = head;
     int ret=temp->val;
     if(head->next==NULL){
       
        head=tail=NULL;
        delete temp;
        return ret;

     }
     head = head->next;
     delete temp;
     return ret;

}

void SinglyLinkedList:: PrintList(){
  cout<<"Start List -------------------------"<<endl;
   cout<<endl;
  if(head==NULL){
   
    cout<<"EmptyList"<<endl;
    cout<<endl;
    cout<<"End List----------------------------"<<endl;
    return;
    
  }
  node *temp=head;
  while(temp!=NULL){
    cout<<temp->val<<" ";
    temp=temp->next;
  }
  cout<<endl;
  cout<<endl;
  cout<<"End List----------------------------"<<endl;

}
void SinglyLinkedList::ReverseList() {
    if (head == NULL) {
        cout << "Reversed List-------------------" << endl;
        cout << endl;
        cout << "List is empty" << endl;
        cout << "End list----------------------" << endl;
        return;
    }

    node *prev = NULL;
    node *current = head;
    node *next = NULL;
    tail = head;  

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;
    }

    head = prev; 

    cout << "Reversed List-------------------" << endl;
    cout << endl;
    PrintList();
    cout << "End list----------------------" << endl;
}


int main(){
    SinglyLinkedList sl;
    int n;
    cin>>n;
    int x;
    while(n--){
        cout<<"1 -> insert into head"<<endl;
        cout<<"2 -> insert into tail"<<endl;
        cout<<"3 -> delete from head"<<endl;
        cout<<"4 -> reverse list"<<endl;
        cout<<"5 ->PrintList"<<endl;
        int op;
        cin>>op;
        
        if(op==1){
        cin>>x;    
        sl.InsertIntoHead(x);
        }
        else if(op==2){
            cin>>x;
            sl.InsertIntoTail(x);
        }
        else if(op==3){
            int d=sl.DeleteFromHead();
            cout<<d<<endl;
        }
        else if(op==4){
            sl.ReverseList();
        }    
        else{
            sl.PrintList();
        }
    }

 return 0;

    }