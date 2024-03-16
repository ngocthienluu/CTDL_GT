#include <iostream>
using namespace std;


struct HocVien {
    int id;
    string name;
    int year;
    HocVien *next;
};


void init(HocVien *&head){
    head = NULL;
}

HocVien *creat_hoc_vien(int x, string y, int z){
    HocVien *h = new HocVien;
    h -> id = x;
    h -> name = y;
    h -> year = z;
    h -> next = nullptr;
    return h;
}

void add_first(HocVien *&head, int x, string y, int z){
    HocVien *h = creat_hoc_vien(x, y, z);
    h -> next = head;
    head = h;
}

void add_last(HocVien *&head, int x, string y, int z){
    HocVien *h = creat_hoc_vien(x, y, z);
    if(head == nullptr){
        head = h;
    }
    else{
        HocVien *last = head;
        while(last -> next != nullptr){
            last = last -> next;
        }

        last -> next = h;
    }

}

void add_after(HocVien *&head, int x, string y, int z, int value){
    HocVien *h = creat_hoc_vien(x, y, z);
    
    //Tim Hoc Vien co id la value
    HocVien *q = head;
    while(q != nullptr && q -> id != value){
        q = q -> next;
    }
    // q la dai dien cho Hoc Vien co id la value

    if (q != nullptr){
        h -> next = q -> next;
        q -> next = h;
    }

}

void delete_first(HocVien *&head){
    if(head != nullptr){
        HocVien *p = head;
        head = p -> next;
        p -> next = nullptr;
        delete(p);
    }

}

void delete_last(HocVien *&head){
    if(head != NULL){
        HocVien *last = head;
        HocVien *prev = head;
        while(last -> next != NULL){
            prev = last;
            last = last -> next;
        }
        prev -> next = nullptr;
        delete(last);
    }
}

bool search_by_id(HocVien *head, int value){
    HocVien *hv = head;
    while(hv != NULL){
        if (hv -> id == value){
            return true;
        }
        hv = hv -> next;
    }
    return false;
}



void display_all(HocVien *head){
    HocVien *p = head;
    int count = 0;
    while(p!= NULL){
        cout <<"Id: "<< p->id <<"\n";
        cout <<"Name: "<< p->name <<"\n";
        cout <<"Year: "<< p->year <<"\n";
        cout <<"------------------------" << endl;
        count++;
        p = p->next;
    }
    cout<<"Count = "<< count<<endl;
}

void display_by_id(HocVien *head, int id){
    HocVien *p = head;
    while(p != NULL){
        if(p->id == id){
            cout<<"Id: "<< p->id<<endl;
            cout<<"Name: "<< p->name<<endl;
            cout<<"Year: "<< p->year<<endl;
            break;
        }
        else{
            p = p -> next;
        }
    }
    
}

int main(){
    HocVien *head;
    init(head);

    add_first(head, 1001, "Ngoc Thien", 2004);
    add_first(head, 1002, "Loc Nguyen", 2004);
    add_last(head, 1003, "Ngoc Hoa", 2004);
    add_after(head, 1005, "Thanh Ngan", 2004, 1002);
    cout <<"Danh sach hoc vien truoc khi thay doi:\n";
    display_all(head);
    cout<<"----------------------------------------------\n";

    
    
    cout <<"Danh sach hoc vien sau khi thay doi:\n";
    // display_all(head);
        cout<<"co hoc vien"<<endl;
    
    if(search_by_id(head, 1003)){
        display_by_id(head, 1003);
        
    };

    return 0;
}