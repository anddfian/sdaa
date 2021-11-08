#include<iostream>
#include<conio.h>
using namespace std;

struct Vaksin {
	string id, nama, produksi;
	int penggunaan;
};

struct Node {
	Vaksin data;
	struct Node* next;
};

void show_vaksin(struct Node* n) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	if(n == NULL) {
	    cout << "| Error: Data Vaksin kosong                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		return;
	}
	while(n != NULL) {
		cout << "| ID Vaksin   : " << n->data.id << endl;
		cout << "| Nama Vaksin : " << n->data.nama << endl;
		cout << "| Produksi    : " << n->data.produksi << endl;
		cout << "| Penggunaan  : " << n->data.penggunaan << endl;
	    cout << "========================================================================" << endl;
	    n = n->next;
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
}

void add_vaksin(Node **head) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	Node *nodeBaru = new Node();
	cout << "| Masukkan ID Vaksin         : "; cin >> nodeBaru->data.id;	
	cin.ignore();
	cout << "| Masukkan Nama Vaksin       : "; getline(cin, nodeBaru->data.nama);
	cout << "| Masukkan Produksi Vaksin   : "; getline(cin, nodeBaru->data.produksi);
	cout << "| Masukkan Penggunaan Vaksin : "; cin >> nodeBaru->data.penggunaan;
	nodeBaru->next = NULL;
	if(*head == NULL) {
		*head = nodeBaru;
	    cout << "========================================================================" << endl;
	    cout << "| Sukses: Data Vaksin berhasil ditambahkan                             |" << endl;
	    cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;	
		return;
	}
	Node *temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = nodeBaru;
    cout << "========================================================================" << endl;
    cout << "| Sukses: Data Vaksin berhasil ditambahkan                             |" << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;	
}

void edit_vaksin(struct Node* n) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	Node *temp = n;
	if(n == NULL) {
	    cout << "| Error: Data Vaksin kosong                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		return;
	}
	while(n != NULL) {
		cout << "| ID Vaksin   : " << n->data.id << endl;
		cout << "| Nama Vaksin : " << n->data.nama << endl;
		cout << "| Produksi    : " << n->data.produksi << endl;
		cout << "| Penggunaan  : " << n->data.penggunaan << endl;
	    cout << "========================================================================" << endl;
	    n = n->next;
	}
	string id, nama, produksi;
	int penggunaan;
	cout << "| Masukkan ID Vaksin         : "; cin >> id;
	cin.ignore();
	cout << "| Masukkan Nama Vaksin       : "; getline(cin, nama);
	cout << "| Masukkan Produksi Vaksin   : "; getline(cin, produksi);
	cout << "| Masukkan Penggunaan Vaksin : "; cin >> penggunaan;
	while(temp != NULL) {
		if(temp->data.id == id) {
			temp->data.nama = nama;
			temp->data.produksi = produksi;
			temp->data.penggunaan = penggunaan;
		    cout << "========================================================================" << endl;
		    cout << "| Sukses: Data Vaksin berhasil diperbaharui                            |" << endl;
		    cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			return;
		}
		temp = temp->next;
	}
    cout << "========================================================================" << endl;
    cout << "| Error: Data Vaksin gagal diperbaharui                                |" << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
}

void delete_vaksin(Node **head) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	if(*head == NULL) {
	    cout << "| Error: Data Vaksin kosong                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		return;
	}
	if((*head)->next == NULL) {
		*head = NULL;
		cout << "========================================================================" << endl;
		cout << "| Sukses: Data Vaksin berhasil dihapus                                 |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		return;
	}
	Node *temp = *head;
	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	temp->next = NULL;
	cout << "========================================================================" << endl;
    cout << "| Sukses: Data Vaksin berhasil dihapus                                 |" << endl;
	cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;

}

void close_app() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                            KELUAR APLIKASI                           |" << endl;
    cout << "========================================================================" << endl;
    cout << "| Info: Terima kasih telah menggunakan Aplikasi Vaksinasi COVID-19     |" << endl;
    cout << "========================================================================" << endl;
    exit(0);
}

int main() {
	struct Node* HEAD = NULL;
	int selected_menu;
	while(selected_menu != 9) {
		system("cls");
		cout << "========================================================================" << endl;
	    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
	    cout << "========================================================================" << endl;
	    cout << "| [1] Lihat Data Vaksin COVID-19                                       |" << endl;
	    cout << "| [2] Tambah Data Vaksin COVID-19                                      |" << endl;
	    cout << "| [3] Ubah Data Vaksin COVID-19                                        |" << endl;
	    cout << "| [4] Hapus Data Vaksin COVID-19                                       |" << endl;
	    cout << "| [5] Urut Data Vaksin COVID-19                                        |" << endl;
	    cout << "| [6] Cari Data Vaksin COVID-19                                        |" << endl;
	    cout << "| [9] Keluar Aplikasi                                                  |" << endl;
	    cout << "========================================================================" << endl;
		cout << "Pilih Menu> "; cin >> selected_menu;
		switch(selected_menu) {
			case 1:
				show_vaksin(HEAD);
				break;
			case 2:
				add_vaksin(&HEAD);
				break;
			case 3:
				edit_vaksin(HEAD);
				break;
			case 4:
				delete_vaksin(&HEAD);
				break;
			case 5:
	//			sort_vaksin_menu();
				break;
			case 6:
	//			search_vaksin_menu();
				break;
			case 9:
				close_app();
				break;
			default:
				cout << "========================================================================" << endl;
	        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
	        	cout << "========================================================================" << endl;
				cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		}
	}
	return 0;
}
