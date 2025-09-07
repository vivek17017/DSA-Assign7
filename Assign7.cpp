#include<iostream>
using namespace std;
struct node{
    node* prev;
    int item;
    node* next;
};
class CDLL{
    private:
        node* start;
    public:
        CDLL();
        void insertDataAtBeginning(int);
        void insertDataAtEnd(int);
        node* searchNode(int);
        void insertDataAfter(int,node*);
        void deleteFirstNode();
        void deleteLastNode();
        void deleteSpecificNode(node*);
        ~CDLL();
};
CDLL::CDLL(){
    start=nullptr;
}
void CDLL::insertDataAtBeginning(int data){
    node *temp=new node;
    temp->item=data;
    if(start!=nullptr)
    {
    temp->next=start;
    start->prev->next=temp;
    temp->prev=start->prev;
    start->prev=temp;
    }
    else{
        temp->prev=temp;
        temp->next=temp;
    }
    start=temp;

}
void CDLL:: insertDataAtEnd(int data){
    if(start==nullptr)
        insertDataAtBeginning(data);
    node* temp=new node;
    temp->item=data;
    temp->prev=start->prev;
    temp->next=start;
    start->prev->next=temp;
    start->prev=temp;
}
node* CDLL::searchNode(int data){
    if(start==nullptr)
        return nullptr;
    node* temp=start;
    while (start!=temp->next->prev) 
    {
        if(temp->item==data)
        return temp;
        temp=temp->next;
    }
    return nullptr;
    
}
void CDLL::insertDataAfter(int data,node* t){
    if(start!=nullptr)
    {
    if(searchNode(t->item)==t){
        node* temp=new node;
        temp->item=data;
        temp->prev=t;
        temp->next=t->next;
        t->next->prev=temp;
        t->next=temp;
    }
    else
    {
        cout<<"invalid node";
    }
}

}
void CDLL::deleteFirstNode(){
    if(start!=nullptr)
    {
        node* temp=start;
        if(start==temp->next)
            {
                start=nullptr;
                delete temp;
            }
        else{
        temp->prev->next=start->next;
        temp->next->prev=temp->prev;
        start=temp->next;
        delete temp;
        }
    }
}
void CDLL::deleteLastNode(){
    if(start!=nullptr)
    {
    node* temp=start->prev;
    if(start==temp->next)
            {
                start=nullptr;
                delete temp;
            }
    else{
    temp->prev->next=start;
    start->prev=temp->prev;
    delete temp;
    }
}
}
void CDLL::deleteSpecificNode(node* t){
    if(start==t->next)
            {
                start=nullptr;
                delete t;
            }
    t->prev->next=t->next;
    t->next->prev=t->prev;
    delete t;
}
CDLL::~CDLL(){
    while (start!=nullptr)
    {
        deleteFirstNode();
    }
    
}
int main(){

}