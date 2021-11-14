#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

struct Vaksin {
	string id, nama, produksi;
	int penggunaan;
};

struct Node {
	Vaksin data;
	struct Node* next;
	struct Node* prev;
};

Node *HEAD = NULL, *TAIL = NULL, *DEL;

void show_vaksin(Node *head, Node *tail) {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	if(head == NULL) {
	    cout << "| Error: Data Vaksin kosong                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		return;
	}
	cout << "| [1] Lihat diawal                                                    |" << endl;
	cout << "| [2] Lihat diakhir                                                   |" << endl;
    cout << "========================================================================" << endl;
	cout << "| Pilih Menu> "; cin >> selected_menu;
	system("cls");
	switch(selected_menu) {
		case 1:
			cout << "========================================================================" << endl;
		    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
		    cout << "========================================================================" << endl;
			while(head != NULL) {
				cout << "| ID Vaksin   : " << head->data.id << endl;
				cout << "| Nama Vaksin : " << head->data.nama << endl;
				cout << "| Produksi    : " << head->data.produksi << endl;
				cout << "| Penggunaan  : " << head->data.penggunaan << endl;
			    cout << "========================================================================" << endl;
			    head = head->next;
			}
			break;
		case 2:
			cout << "========================================================================" << endl;
		    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
		    cout << "========================================================================" << endl;
			while(tail != NULL) {
				cout << "| ID Vaksin   : " << tail->data.id << endl;
				cout << "| Nama Vaksin : " << tail->data.nama << endl;
				cout << "| Produksi    : " << tail->data.produksi << endl;
				cout << "| Penggunaan  : " << tail->data.penggunaan << endl;
			    cout << "========================================================================" << endl;
			    tail = tail->prev;
			}
			break;
		default:
			cout << "========================================================================" << endl;
			cout << "| Error: Pilihan Salah!                                                |" << endl;
			cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			return;
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
}

void add_vaksin(Node **head, Node **tail) {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	cout << "| [1] Tambah diawal                                                    |" << endl;
	cout << "| [2] Tambah diakhir                                                   |" << endl;
    cout << "========================================================================" << endl;
	cout << "| Pilih Menu> "; cin >> selected_menu;
	Node *nodeBaru = new Node();
	Node *temp = *head;
	switch(selected_menu) {
		case 1:
			system("cls");
			cout << "========================================================================" << endl;
		    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
		    cout << "========================================================================" << endl;
			cout << "| Masukkan ID Vaksin         : "; cin >> nodeBaru->data.id;
			cin.ignore();
			cout << "| Masukkan Nama Vaksin       : "; getline(cin, nodeBaru->data.nama);
			cout << "| Masukkan Produksi Vaksin   : "; getline(cin, nodeBaru->data.produksi);
			cout << "| Masukkan Penggunaan Vaksin : "; cin >> nodeBaru->data.penggunaan;
			nodeBaru->next = *head;
			if(*head == NULL) {
				*head = nodeBaru;
				*tail = nodeBaru;
			    cout << "========================================================================" << endl;
			    cout << "| Sukses: Data Vaksin berhasil ditambahkan                             |" << endl;
			    cout << "========================================================================" << endl;
				cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
				return;
			} else {
				nodeBaru->prev = NULL;
				nodeBaru->next = *head;
				(*head)->prev = nodeBaru;
				(*head) = nodeBaru;
			}
			break;
		case 2:
			system("cls");
			cout << "========================================================================" << endl;
		    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
		    cout << "========================================================================" << endl;
			cout << "| Masukkan ID Vaksin         : "; cin >> nodeBaru->data.id;
			cin.ignore();
			cout << "| Masukkan Nama Vaksin       : "; getline(cin, nodeBaru->data.nama);
			cout << "| Masukkan Produksi Vaksin   : "; getline(cin, nodeBaru->data.produksi);
			cout << "| Masukkan Penggunaan Vaksin : "; cin >> nodeBaru->data.penggunaan;
			nodeBaru->next = NULL;
			if(*head == NULL) {
				*head = nodeBaru;
				*tail = nodeBaru;
			    cout << "========================================================================" << endl;
			    cout << "| Sukses: Data Vaksin berhasil ditambahkan                             |" << endl;
			    cout << "========================================================================" << endl;
				cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
				return;
			} else {
				nodeBaru->prev = *tail;
				nodeBaru->next = NULL;
				(*tail)->next = nodeBaru;
				*tail = nodeBaru; 
			}
			break;
		default:
			cout << "========================================================================" << endl;
			cout << "| Error: Pilihan Salah!                                                |" << endl;
			cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			return;
	}
    cout << "========================================================================" << endl;
    cout << "| Sukses: Data Vaksin berhasil ditambahkan                             |" << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
}

void edit_vaksin(Node *head) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	Node *newdata = head;
	if(head == NULL) {
	    cout << "| Error: Data Vaksin kosong                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		return;
	}
	while(head != NULL) {
		cout << "| ID Vaksin   : " << head->data.id << endl;
		cout << "| Nama Vaksin : " << head->data.nama << endl;
		cout << "| Produksi    : " << head->data.produksi << endl;
		cout << "| Penggunaan  : " << head->data.penggunaan << endl;
	    cout << "========================================================================" << endl;
	    head = head->next;
	}
	string id, nama, produksi;
	int penggunaan;
	cout << "| Masukkan ID Vaksin         : "; cin >> id;
	cin.ignore();
	cout << "| Masukkan Nama Vaksin       : "; getline(cin, nama);
	cout << "| Masukkan Produksi Vaksin   : "; getline(cin, produksi);
	cout << "| Masukkan Penggunaan Vaksin : "; cin >> penggunaan;
	while(newdata != NULL) {
		if(newdata->data.id == id) {
			newdata->data.nama = nama;
			newdata->data.produksi = produksi;
			newdata->data.penggunaan = penggunaan;
		    cout << "========================================================================" << endl;
		    cout << "| Sukses: Data Vaksin berhasil diperbaharui                            |" << endl;
		    cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			return;
		}
		newdata = newdata->next;
	}
    cout << "========================================================================" << endl;
    cout << "| Error: Data Vaksin gagal diperbaharui                                |" << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
}

void delete_vaksin(Node **head, Node **tail) {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	if(*head == NULL) {
	    cout << "| Error: Data Vaksin kosong                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		return;
	}
	cout << "| [1] Hapus diawal                                                     |" << endl;
	cout << "| [2] Hapus diakhir                                                    |" << endl;
    cout << "========================================================================" << endl;
	cout << "| Pilih Menu> "; cin >> selected_menu;
	Node *temp = *head;
	switch(selected_menu) {
		case 1:
			if((*head)->next == NULL) {
				*head = NULL;
				*tail = NULL;
				cout << "========================================================================" << endl;
				cout << "| Sukses: Data Vaksin berhasil dihapus                                 |" << endl;
				cout << "========================================================================" << endl;
				cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
				return;
			}
			DEL = *head;
			*head = temp->next;
			(*head)->prev = NULL;
			delete DEL;
			break;
		case 2:
			if((*head)->next == NULL) {
				*head = NULL;
				*tail = NULL;
				cout << "========================================================================" << endl;
				cout << "| Sukses: Data Vaksin berhasil dihapus                                 |" << endl;
				cout << "========================================================================" << endl;
				cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
				return;
			}
			DEL = *tail;
			*tail = (*tail)->prev;
			(*tail)->next = NULL;
			delete DEL;
			break;
		default:
			cout << "========================================================================" << endl;
			cout << "| Error: Pilihan Salah!                                                |" << endl;
			cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			return;
	}
	cout << "========================================================================" << endl;
    cout << "| Sukses: Data Vaksin berhasil dihapus                                 |" << endl;
	cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
}

void shellSort(Vaksin *vaksinp, int n, int category, int order) {
	for(int gap = n / 2; gap > 0; gap /= 2) {
		for(int i = gap; i < n; i += 1) {
			Vaksin temp = vaksinp[i];
			int j;
			if(category == 1 and order == 1) {
				for (j = i; j >= gap && vaksinp[j - gap].id > temp.id; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 1 and order == 2) {
				for (j = i; j >= gap && vaksinp[j - gap].id < temp.id; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 2 and order == 1) {
				for (j = i; j >= gap && vaksinp[j - gap].nama > temp.nama; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 2 and order == 2) {
				for (j = i; j >= gap && vaksinp[j - gap].nama < temp.nama; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 3 and order == 1) {
				for (j = i; j >= gap && vaksinp[j - gap].produksi > temp.produksi; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 3 and order == 2) {
				for (j = i; j >= gap && vaksinp[j - gap].produksi < temp.produksi; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 4 and order == 1) {
				for (j = i; j >= gap && vaksinp[j - gap].penggunaan > temp.penggunaan; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 4 and order == 2) {
				for (j = i; j >= gap && vaksinp[j - gap].penggunaan < temp.penggunaan; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			vaksinp[j] = temp;
		}
	}
}

void sort_vaksin(Node *head, Node *tail) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	Node *newdata = head;
	Vaksin vaksin[100];
	if(head == NULL) {
	    cout << "| Error: Data Vaksin kosong                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		return;
	}
	int i;
	while(head != NULL) {
	    vaksin[i].id = head->data.id;
	    vaksin[i].nama = head->data.nama;
	    vaksin[i].produksi = head->data.produksi;
	    vaksin[i].penggunaan = head->data.penggunaan;
	    head = head->next;
	    i++;
	}
	int selected_menu;
	cout << "| [1] ID Vaksin                                                        |" << endl;
	cout << "| [2] Nama Vaksin                                                      |" << endl;
	cout << "| [3] Produksi Vaksin                                                  |" << endl;
	cout << "| [4] Penggunaan Vaksin                                                |" << endl;
	cout << "========================================================================" << endl;
	cout << "| Pilih Menu> "; cin >> selected_menu;
	int selected_order;
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	cout << "| [1] Ascending                                                        |" << endl;
	cout << "| [2] Descending                                                       |" << endl;
	cout << "========================================================================" << endl;
	cout << "| Pilih Menu> "; cin >> selected_order;	
	shellSort(&vaksin[0], i, selected_menu, selected_order);
	i = 0;
	while(newdata != NULL) {
		newdata->data.id = vaksin[i].id;
		newdata->data.nama = vaksin[i].nama;
		newdata->data.produksi = vaksin[i].produksi;
		newdata->data.penggunaan = vaksin[i].penggunaan;
//		newdata->prev = NULL;
		newdata = newdata->next;
		i++;
	}
	cout << "========================================================================" << endl;
    cout << "| Sukses: Data Vaksin berhasil diurutkan                               |" << endl;
	cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
}

int jumpSearch(Vaksin *vaksinp, int n, string x, int category) {
	int step = sqrt(n);
	int prev = 0;
	if(category == 1) {
		while(vaksinp[min(step, n)-1].id < x) {
			prev = step;
			step += sqrt(n);
			if(prev >= n)
				return -1;
		}
		while(vaksinp[prev].id < x) {
			prev++;
			if(prev == min(step, n))
				return -1;
		}
		if(vaksinp[prev].id == x)
			return prev;
	} else if(category == 2) {
		while(vaksinp[min(step, n)-1].nama < x) {
			prev = step;
			step += sqrt(n);
			if(prev >= n)
				return -1;
		}
		while(vaksinp[prev].nama < x) {
			prev++;
			if(prev == min(step, n))
				return -1;
		}
		if(vaksinp[prev].nama == x)
			return prev;
	} else if(category == 3) {
		while(vaksinp[min(step, n)-1].produksi < x) {
			prev = step;
			step += sqrt(n);
			if(prev >= n)
				return -1;
		}
		while(vaksinp[prev].produksi < x) {
			prev++;
			if(prev == min(step, n))
				return -1;
		}
		if(vaksinp[prev].produksi == x)
			return prev;
	}
	return -1;
}

int jumpSearch(Vaksin *vaksinp, int n, int x, int category) {
	int step = sqrt(n);
	int prev = 0;
	if(category == 4) {
		while(vaksinp[min(step, n)-1].penggunaan < x) {
			prev = step;
			step += sqrt(n);
			if(prev >= n)
				return -1;
		}
		while(vaksinp[prev].penggunaan < x) {
			prev++;
			if(prev == min(step, n))
				return -1;
		}
		if(vaksinp[prev].penggunaan == x)
			return prev;
	}
	return -1;
}

void search_vaksin(Node *head) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	Node *newdata = head;
	Vaksin vaksin[100];
	if(head == NULL) {
	    cout << "| Error: Data Vaksin kosong                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		return;
	}
	int i;
	while(head != NULL) {
	    vaksin[i].id = head->data.id;
	    vaksin[i].nama = head->data.nama;
	    vaksin[i].produksi = head->data.produksi;
	    vaksin[i].penggunaan = head->data.penggunaan;
	    head = head->next;
	    i++;
	}
	int selected_menu;
	cout << "| [1] ID Vaksin                                                        |" << endl;
	cout << "| [2] Nama Vaksin                                                      |" << endl;
	cout << "| [3] Produksi Vaksin                                                  |" << endl;
	cout << "| [4] Penggunaan Vaksin                                                |" << endl;
	cout << "========================================================================" << endl;
	cout << "| Pilih Menu> "; cin >> selected_menu;
	shellSort(&vaksin[0], i, selected_menu, 1);
	i = 0;
	while(newdata != NULL) {
		newdata->data.id = vaksin[i].id;
		newdata->data.nama = vaksin[i].nama;
		newdata->data.produksi = vaksin[i].produksi;
		newdata->data.penggunaan = vaksin[i].penggunaan;
		newdata = newdata->next;
		i++;
	}
	string search_str;
	int search_int;
	int index;
	if(selected_menu == 1 or selected_menu == 2 or selected_menu == 3) {
		cout << "========================================================================" << endl;
		cout << "| Data yang ingin dicari> "; cin >> search_str;
		index = jumpSearch(&vaksin[0], i, search_str, selected_menu);
	} else {
		cout << "========================================================================" << endl;
		cout << "| Data yang ingin dicari> "; cin >> search_int;
		index = jumpSearch(&vaksin[0], i, search_int, selected_menu);		
	}
	if(index != -1) {
		cout << "========================================================================" << endl;
	    cout << "| Sukses: Data Vaksin ditemukan!                                       |" << endl;
		cout << "========================================================================" << endl;
	    cout << "| ID Vaksin   : " << vaksin[index].id << endl;
	    cout << "| Nama Vaksin : " << vaksin[index].nama << endl;
	    cout << "| Produksi    : " << vaksin[index].produksi << endl;
	    cout << "| Penggunaan  : " << vaksin[index].penggunaan << endl;
		cout << "========================================================================" << endl;		
	} else {
		cout << "========================================================================" << endl;		
		cout << "| Error: Data tidak ditemukan!                                         |" << endl;
		cout << "========================================================================" << endl;
	}
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
				show_vaksin(HEAD, TAIL);
				break;
			case 2:
				add_vaksin(&HEAD, &TAIL);
				break;
			case 3:
				edit_vaksin(HEAD);
				break;
			case 4:
				delete_vaksin(&HEAD, &TAIL);
				break;
			case 5:
				sort_vaksin(HEAD, TAIL);
				break;
			case 6:
				search_vaksin(HEAD);
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
