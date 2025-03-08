#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LinkedList{
    private:
        struct node{
            int data;
            node *next;
        };
    
        node *head;
        node *tail;
    
    public:
            LinkedList(){
                head=NULL;
                tail=NULL;
            }
    
            void insertFront(int data){
                node*n= new node;
                n->data=data;
                n-> next=NULL;
                if(head==NULL){
                    head=tail=n;
                }
                else {
                    n->next=head;
                    head=n;
                }
    
            }
    
    
            void insertLast(int data){
                node* n=new node;
                n->data=data;
                n->next=NULL;
                if(head==NULL){
                    head=n;
                }
                tail->next=n;
                tail=n;
            }
    
            void print(){
                node *temp=head;
                while(temp!=NULL){
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
                cout<<endl;
            }
    
            int size(){
                node *temp=head;
                int count=0;
                while(temp!=NULL){
                    count++;
                    temp=temp->next;
                }
                return count;
            }
    
            void insertAt(int data,int pos){
                node *n = new node;
                n->data=data;
                n->next=NULL;
                if(pos==0){
                    n->next=head;
                    head=n;
                }
                else if(pos>=size()){
                    tail->next=n;
                    tail=n;
                }
                else{
                    node *temp=head;
                    for(int i=0;i<pos-1;i++){
                        temp=temp->next;
                    }
                    n->next=temp->next;
                    temp->next=n;
                }
            }
    
            void deleteAt(int pos){
                node *temp=head;
                if(pos==0){
                    head=head->next;
                    delete temp;
                }
                else{
                    for(int i=0;i<pos-1;i++){
                        temp=temp->next;
                    }
                    node *t=temp->next;
                    temp->next=t->next;
                    delete t;
                }
            }
    
            void deleteFront(){
                node *temp=head;
                head=head->next;
                delete temp;
            }
    
            void deleteLast(){
                node *temp=head;
                while(temp->next!=tail){
                    temp=temp->next;
                }
                node *t=tail;
                tail=temp;
                delete t;
            }
    
            void reverse(){
                node *prev=NULL;
                node *current=head;
                node *next=NULL;
                while(current!=NULL){
                    next=current->next;
                    current->next=prev;
                    prev=current;
                    current=next;
                }
                head=prev;
            }
    
            void search(int data){
                node *temp=head;
                int pos=0;
                while(temp!=NULL){
                    if(temp->data==data){
                        cout<<"Element found at position: "<<pos<<endl;
                        return;
                    }
                    pos++;
                    temp=temp->next;
                }
                cout<<"Element not found"<<endl;
            }
    
            bool isempty(){
                return head==NULL;
            }
            
            ~LinkedList(){
                node *temp=head;
                while(temp!=NULL){
                    node *t=temp;
                    temp=temp->next;
                    delete t;
                }
            }
    };
    
int main(){
    LinkedList l;
    l.insertFront(10);
    l.insertFront(20);
    l.insertFront(30);
    l.insertFront(40);
    l.insertFront(50);
    l.insertFront(60);
    l.insertFront(70);
    l.insertFront(80);
    l.insertFront(90);
    l.insertFront(100);
    l.print();
    l.insertLast(110);
    l.print();
    l.insertAt(120,5);
    l.print();
    l.deleteAt(5);
    l.print();
    l.deleteFront();
    l.print();
    l.deleteLast();
    l.print();
    l.reverse();
    l.print();
    l.search(40);
    l.search(100);
    l.search(120);
    l.search(110);
    l.search(10);
    l.isempty()?cout<<"Empty"<<endl:cout<<"Not Empty"<<endl;
    return 0;
}