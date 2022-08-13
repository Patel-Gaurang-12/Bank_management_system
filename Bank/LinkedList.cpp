#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node(int n) {
        data = n;
        next = NULL;
    }
}*head=NULL;

void insertNode(int num,node* &head) {

    node* tmp = new node(num);
    if(head == NULL) {
        head = tmp;
        return;
    }
    node *p;
    p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = tmp;
}

void display(node *head) {
    node *tmp;
    tmp = head;
    while(tmp != NULL) {
        cout<<tmp->data<<" ~> ";
        tmp = tmp->next;
    }
}

int main() {

    int ch,num;
    while(1) {
        cout<<"\n1. Insert";
        cout<<"\n2. Display";
        cout<<"\nEnter choice: ";
        cin>>ch;
        switch(ch) {

            case 1: cout<<"\nEnter number: ";
                    cin>>num;
                    insertNode(num,head);
                    break;

            case 2: display(head);
                    break;

            case 0: exit(0);

            default : cout<<"\nInvalid choice!!";
        }
    }
}
