/*
Author   : Shalvina Zahwa Aulia
NPM      : 140810180052
Deskripsi: Program circular doubly linked list
Tahun    : 2019
*/
#include<iostream>
#include<windows.h>
using namespace std;

struct Node{
    char info;
    Node* next;
    Node* prev;
};
typedef Node* pointer;
typedef pointer List;

void CreateList(List& First){
    First = NULL;
}

void CreateElement(pointer& pBaru){
    pBaru = new Node;
    cout << "Masukkan data : ";
    cin >> pBaru->info;
    pBaru->next = NULL;
    pBaru->prev = NULL;
}

void insertFirst(List& First, pointer pBaru){
    if(First != NULL){
        First->prev = pBaru;
    }
    First = pBaru;
}

void insertLast(List& First, pointer pBaru)
{
    pointer last;
    if (First == NULL){
        First = pBaru;
        last = First;
    }
    else{
        last = First;
        while(last->next != First){
            last = last->next;
        }
        last->next = pBaru;
        pBaru->prev = last;
        pBaru->next = First;
        First->prev = pBaru;
    }
}

void deleteFirst(List& First, pointer& pHapus){
    pointer last;
    if (First == NULL){
        cout << "List kosong, tidak ada yang bisa dihapus" << endl;
    }
    else if (First->next == First){
        pHapus = First;
        pHapus->next = NULL;
        pHapus->prev = NULL;
        First = NULL;
    }
    else{
        last = First;
        while(last->next != First){
            last = last->next;
        }
        pHapus = First;
        First = pHapus->next;
        last->next = First;
        First->prev = last;
        pHapus->next = NULL;
        pHapus->prev = NULL;
    }
}

void deleteLast(List& First, pointer& pHapus)
{
    pointer last;
    if (First == NULL){
        cout << "List kosong, tidak ada yang bisa dihapus" << endl;
    }
    else if (First->next == First){
        pHapus = First;
        pHapus->next = NULL;
        pHapus->prev = NULL;
        First = NULL;
    }
    else{
        last = First;
        while(last->next != First){
            last = last->next;
        }
        pHapus = last;
        First->prev = last->prev;
        last->prev->next = First;
        pHapus->next = NULL;
        pHapus->prev = NULL;
    }
}

void traversal(List First){
    cout << "LIST : ";
    pointer pBantu;
    if(First==NULL){
        cout << "List Kosong";
    }
    else{
        pBantu=First;
        do{
            cout << pBantu->info << " " << endl;
            pBantu = pBantu->next;
        } while(pBantu != NULL);
    }
    cout << endl;
}

int main()
{
    pointer p;
    List circ;
    int menu;

    CreateList(circ);

    do{
        system("cls");
        cout<<"1. Insert First Ciecular"<<endl;
        cout<<"2. Insert Last Circular"<<endl;
        cout<<"3. Delete First Circular"<<endl;
        cout<<"4. Delete Last Circular"<<endl;
        cout<<"5. Traversal"<<endl;
        cout<<"6. Keluar"<<endl;
        cout << "Pilih Menu (1/2/3/4/5/6): "; cin >> menu;
        switch(menu){
        case 1:
            CreateElement(p);
            insertFirst(circ, p);
            break;

        case 2:
            CreateElement(p);
            insertLast(circ,p);
            break;

        case 3:
            deleteFirst(circ,p);
            break;

        case 4:
            deleteLast(circ,p);
            break;

        case 5:
            traversal(circ);
            break;
        default :
            exit(0);
            break;
        }
        system("pause");
    }while(1);
}

