#include <iostream>
#define MAX 100
using namespace std;


struct DSDac{
    int a[MAX];
    int n;
};

void nhapDsDac(DSDac &ds){
    cout << "Nhap n = ";
    cin >> ds.n;

    for(int i = 0; i < ds.n; i++){
        cout <<"A["<<i<<"] = ";
        cin >> ds.a[i];
    }
}

void xuatDsDac(DSDac ds){
    for(int i = 0; i < ds.n; i++){
        cout << "A["<<i<<"] = "<<ds.a[i]<<"\t";
    }
    cout << endl;
}

int timDauTien(DSDac ds, int x){
    int vt = -1;
    for(int i = 0; i < ds.n && vt == -1; i++){
        if(ds.a[i] == x){
            vt = i;
        }
    }
    return vt;
}       


int main(){
    DSDac ds;
    nhapDsDac(ds);
    xuatDsDac(ds);

    int x;
    cout << "Nhap x = ";
    cin >> x;

    int vt = timDauTien(ds,x);
    if(vt == -1){
        cout <<"Khong co so can tim trong danh sach!!";
    }
    else {
        cout << "So can tim o vi tri "<<vt;
    }

    return 0;
}