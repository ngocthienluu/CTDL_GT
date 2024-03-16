#include <iostream>
using namespace std;


struct Node {
    int value;
    Node *next;
    Node *prev;
};

void init(Node *&head){
    head = NULL;
}

Node* create_node(Node *head, int x){
    Node *node = new Node;
    node -> value = x;
    node -> next = NULL;
    node -> prev = NULL;
    return node;
}

void add_first(Node *&head, int x){
    Node *node = create_node(head, x);
    if(head == NULL){
        head = node;
        return;
    }
    node -> next = head;
    head -> prev = node;
    head = node;
}


void add_last(Node *&head , int x){
    Node *node = create_node(head, x);
    if(head == NULL){
        head = node;
    }
    else{
        //xac dinh node cuoi cung
        Node *last = head;
        while(last->next != NULL){
            last = last -> next;
        }

        last -> next = node;
        node -> prev = last;

    }

}


void display(Node *head) {
    Node *node = head;
    while(node != NULL){
        cout << node->value <<" <--> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node *head;
    init(head);

    add_first(head, 7);
    add_first(head, 9);
    add_first(head,10);
    add_first(head,11);
    add_last(head,20);
    add_last(head,21);

    display(head);
    return 0;
}