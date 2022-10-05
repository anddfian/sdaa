#include <iostream>
using namespace std;

struct dataMahasiswa {
	string nama;
	string prodi;
	float ipk;
};

struct Node {
	dataMahasiswa data;
	struct Node* next;
};

int isEmpty(Node **head) {
	if(*head == NULL) {
		cout << "LinkedList kosong" << endl;
		return 1;
	}
	else return 0;
}

void printData(Node *head) {
	isEmpty(&head);
	while (head != NULL) {
		cout << "Nama Mahasiswa : " << head->data.nama << " ";
		cout << "Nama Prodi : " << head->data.prodi << " ";
		cout << "IPK : " << head->data.ipk << " " << endl;
		head = head->next;
	}
}

void addFirst(Node **head) {
	Node *nodeBaru = new Node;
	cout << "Masukan Nama : "; 
	fflush(stdin);
	getline(cin, nodeBaru->data.nama);
	cout << "Masukan Prodi : ";
	fflush(stdin);
	getline(cin, nodeBaru->data.prodi);
	cout << "Masukan IPK : "; cin >> nodeBaru->data.ipk;
	nodeBaru->next = *head;
	*head = nodeBaru;
}

void addLast(Node **head) {
	Node *nodeBaru = new Node();
	cout << "Masukan Nama : "; 
	fflush(stdin);
	getline(cin, nodeBaru->data.nama);
	cout << "Masukan Prodi : ";
	fflush(stdin);
	getline(cin, nodeBaru->data.prodi);
	cout << "Masukan IPK : "; cin >> nodeBaru->data.ipk;
	nodeBaru->next = NULL;
	
	if(*head == NULL) {
		*head = nodeBaru;
		return;
	}
	Node *temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = nodeBaru;
}

void deleteFirst(Node **head) {
	if(*head == NULL) {
		cout << "LinkedList kosong" << endl;
		return;
	}
	*head = (*head)->next;
}

void deleteLast(Node **head) {
	if(*head == NULL) {
		cout << "LinkedList kosong" << endl;
		return;
	}
	if((*head)->next == NULL) {
		*head = NULL;
		return;
	}
	Node *temp = *head;
	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	temp->next = NULL;
}

void updateData(Node **head){
	if(*head == NULL) {
		cout << "LinkedList kosong" << endl;
		return;
	}
	string nama;
	cout << "Masukan data nama yang akan diubah : ";
	fflush(stdin);
	getline(cin, nama);
	Node *temp = (*head);
	while (temp != NULL){
		if (temp->data.nama == nama){
			cout << "Masukan data nama yang baru : ";
			cin >> temp->data.nama;
			cout << "Masukan data prodi yang baru : ";
			cin >> temp->data.prodi;
			cout << "Masukan data ipk yang baru : ";
			cin >> temp->data.ipk;
			cout << "Data berhasil diubah" << endl;
			return;
		}
		temp = temp->next;
	}
	cout << "Data tidak ditemukan" << endl;
}

int main()
{
	struct Node* HEAD = NULL;
	int menu;
	while(menu != 9) {
		cout << "==== MENU ====" << endl;
		cout << "1. Tambah Data Pertama" << endl;
		cout << "2. Tambah Data Terakhir" << endl;
		cout << "3. Hapus Data Pertama" << endl;
		cout << "4. Hapus Data Terakhir" << endl;
		cout << "5. Update Data" << endl;
		cout << "6. Tampilkan Data" << endl;
		cout << "9. Exit Program" << endl;
		cout << "Masukkan Pilihan: "; cin >> menu;
		switch(menu) {
			case 1:
				addFirst(&HEAD);
				break;
			case 2:
				addLast(&HEAD);
				break;
			case 3:
				deleteFirst(&HEAD);
				break;
			case 4:
				deleteLast(&HEAD);
				break;
			case 5:
				updateData(&HEAD);
				break;
			case 6:
				printData(HEAD);
				break;
			case 9:
				continue;
			default:
				cout << "Pilihan Tidak Ada" << endl;
		}
	}	
	return 0;
}
