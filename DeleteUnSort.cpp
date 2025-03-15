#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void del(Node* &head){
    Node* cur=head;
    for(int i=0;cur!=NULL;i++){
        Node* val=cur->next;
       while(cur !=NULL && cur->next != NULL){
        if(cur == val){
          Node*next_next=cur->next->next;
          Node* nodetodelete=cur->next;
          delete(nodetodelete);
          cur->next=next_next;
          cur=cur->next;
        }else{
            cur=cur->next;
        }
    }  
    }
}
void insertAthead(Node* &head,int d)
{
    //New node creation
    Node *temp= new Node(d);
    temp->next=head;
    head=temp;
}
void print(Node* &tail){
    Node *temp=tail;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    Node* node1=new Node(4);
    Node *head=node1;
   insertAthead(head,2);
   insertAthead(head,5);
   insertAthead(head,3);
   insertAthead(head,2);
   insertAthead(head,4);
   insertAthead(head,1);
   print(head);
   cout<<endl;
   del(head);
   print(head);
}