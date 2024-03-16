#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

void init(Node *&head){
    head = NULL;
}

Node* create_Node(int x){
    Node *p = new Node;
    p -> value = x;
    p -> next = NULL;
    return p;
}


void add_first(Node *&head, int x){
    Node *p = create_Node(x);
    p -> next = head;
    head = p;
}


void add_last(Node *&head, int x){
    Node *p = create_Node(x);
    if (head == NULL){
        head = p;
    }
    else{
        // Xac dinh Node cuoi cung
        Node *last = head;
        while(last->next != NULL){
            last = last->next;
        }

        //Chen vao cuoi cung
        last -> next = p;
    }
}


void add_after(Node *head, int v, int x){
    Node *p = create_Node(x);

    //Tim node co gia tri la v
    Node *q = head;
    while(q != NULL && q -> value != v){
        q = q -> next;
    }
    // q la dai dien cho node co gia tri v 
    if(q != NULL){ //trong danh sach co gia tri v
        p -> next = q -> next;
        q -> next = p;
    }

}

void del_first(Node *&head){
    if(head != NULL){
        Node *p = head;
        head = p -> next;
        p -> next = NULL;
        delete(p);
    }
}

void del_last(Node *&head){
    if(head != NULL){
        Node *last = head;
        Node *prev = NULL;
        while(last ->next != NULL){
            prev = last;
            last = last -> next;
        }
        if(prev == NULL){// danh sach co 1 phan tu
            del_first(head);
        }
        else{
            prev -> next = nullptr;
            delete(last);
        }
    }
}


void del_node(Node *&head, int value){
    if (head != NULL){
        Node *p = head;
        Node *prev = NULL;

        while(p != NULL && p -> value != value){
            prev = p;
            p = p -> next;
        }
        if(p != NULL){// Tim thay phan tu can xoa
            if(prev == NULL){// danh sach co 1 phan tu
                del_first(head);
            }
            else{
                prev -> next = p -> next;
                p -> next = NULL;
                delete(p);
            }
        }
    }
}

void del_all(Node *&head){
    while(head != NULL){
        del_first(head);
    }
}


void output(Node *head){
    Node *p = head;
    int count = 0;
    while(p!= NULL){
        cout << p->value <<"\t";
        p = p->next;
        count++;
    }
    cout<<"count = "<<count<<endl;
}


int main(){
    Node *head;
    init(head);

    add_first(head, 30);
    add_first(head, 5);
    add_first(head, 7);
    add_first(head, 1);
    add_last(head, 40);
    add_after(head, 1, 100);
    cout <<"Danh sach ban dau:\n";
    output(head);
    cout<< endl;

    cout <<"Danh sach luc sau:\n";

    //del_node(head, 5);
    del_last(head);
    output(head);
    if(head == NULL){
        cout <<"Danh sach rong";
    }

    return 0;
}