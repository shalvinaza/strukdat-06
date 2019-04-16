/*
Author   : Shalvina Zahwa Aulia
NPM      : 140810180052
Deskripsi: Program doubly linked list
Tahun    : 2019
*/
#include <iostream>
#include <windows.h>
using namespace std;
#include<iostream>
using namespace std;

struct data{
	char huruf;
	data* next;
	data* prev;
};
typedef data* pointer;
typedef pointer List;

void createList (List& First){
	First = NULL;
}
void createData(pointer& pBaru) {
	pBaru = new data;
	cout << "Masukkan huruf : ";cin >> pBaru->huruf;
	pBaru->next = NULL;
	pBaru->prev = NULL;
}
void insertFirstDoubly(List& First, pointer pBaru){
	if (First==NULL)
		First=pBaru;
	else {
		pBaru->next=First;
		First->prev = pBaru;
		First=pBaru;
	}
}

void insertLastDoubly(List& First, pointer pBaru){
    pointer last;
	if (First==NULL){
		First=pBaru;
	}
	else {
		last=First;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
		pBaru->prev = last;
	}
}

void deleteFirstDoubly (List& First, pointer& pHapus){
	if (First == NULL){
		pHapus = NULL;
		cout << "\nKOSONG\n";
	}
	else if (First->next == NULL){
		pHapus = First;
		First = NULL;
	}
	else {
		pHapus = First;
		First = First->next;
		pHapus->next = NULL;
		First->prev = NULL;
	}
}

void deleteLastDoubly (List& First, pointer& pHapus){
	pointer last;
	if (First == NULL){
		pHapus = NULL;
		cout << "\nKOSONG\n";
	}
	else if (First->next == NULL){
		pHapus = First;
		First = NULL;
	}
	else {
		last = First;
		while (last->next != NULL){
			last = last->next;
		}
		pHapus = last;
		last->prev->next = NULL;
		pHapus->prev = NULL;
	}
}

void traversal (List First){
	pointer pBantu;
	if (First == NULL){
		cout << "\nKOSONG\n";
	}
	else {
		pBantu = First;
		do {
			cout << pBantu->huruf << " ";
			if (pBantu->next!=NULL)
                cout << "<--> ";
			pBantu = pBantu->next;
		} while (pBantu != NULL);
		cout << endl;
	}
}

int main (){
	pointer p;
	List data;
	int menu;

    while (1){
    system("cls");
    cout << "1. Insert First Doubly\n";
    cout << "2. Delete First Doubly\n";
    cout << "3. Insert Last Doubly\n";
    cout << "4. Delete Last Doubly\n";
    cout << "5. Traversal\n";
    cout << "6. Keluar\n";
    cout << "Pilih menu (1/2/3/4/5/6) : "; cin >> menu;
    if (menu<1 || menu>6){
        cout << "\nAnda salah memasukkan angka!\n";
        exit(0);
    }

    switch (menu) {
        case 1:
            createData(p);
            insertFirstDoubly(data,p);
            break;
        case 2 :
            deleteFirstDoubly(data,p);
            break;
        case 3 :
            createData(p);
            insertLastDoubly(data,p);
            break;
        case 4 :
            deleteLastDoubly(data,p);
            break;
        case 5 :
            traversal(data);
            break;
        case 6 :
            cout << "\nAnda telah selesai\n";
            exit(0);
            break;
        }
        system("pause");
    }



}

