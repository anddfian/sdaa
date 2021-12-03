#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include<bits/stdc++.h>
using namespace std;
const int MAKS_VAKSIN = 100, MAKS_VAKSINASI = 100, MAKS_ACCOUNT = 100, MAKS_DIVAKSIN = 2;

struct Vaksin {
	string nama, produksi;
	int penggunaan;
};

struct Vaksinasi {
	string nama, tanggal_lahir, alamat, tekanan[MAKS_DIVAKSIN], vaksin[MAKS_DIVAKSIN], kipi[MAKS_DIVAKSIN];
	int jumlah, batch[MAKS_DIVAKSIN];
	long long nohp, nik;
	float suhu[MAKS_DIVAKSIN];
};

struct Account {
	string username, password, level, nama, tanggal_lahir, alamat;
	long long nik, nohp;
	int umur;
	bool vaksinasi;
};

struct GudangVaksin {
	string id, nama;
	GudangVaksin *next;
};

struct AntrianVaksinasi {
	int id;
	Account data;
	AntrianVaksinasi *next;
};

GudangVaksin *TOP = NULL;
AntrianVaksinasi *FRONT = NULL, *REAR = NULL;

Vaksin vaksin[MAKS_VAKSIN];
Vaksinasi vaksinasi[MAKS_VAKSINASI];
Account accounts[MAKS_ACCOUNT];
Account session_account;

void final_vaksinasi(int index, int tahap); void proses_vaksinasi_keempat(int index, int tahap); void proses_vaksinasi_ketiga(int index, int tahap); void proses_vaksinasi_kedua(int index, int tahap);
void proses_vaksinasi_pertama(AntrianVaksinasi *front); void show_menu_vaksinasi(); void show_menu_vaksin(); void auth_register(); void auth_login(); void show_menu_user(); void show_menu_dinkes(); void show_menu_admin(); void show_vaksin(Vaksin *vaksin);
void back_to_show_menu(); void add_vaksin(Vaksin *vaksin); void edit_vaksin(Vaksin *vaksin); void delete_vaksin(Vaksin *vaksin); void close_app();
int insert_meja_pertama(long long nik, string nama, string tanggal_lahir, long long no_hp, string alamat); bool insert_meja_keempat(int index, int tahap, string kipi);
bool insert_meja_ketiga(int index, int tahap, int nomor_vaksin, int nomor_batch_vaksin); bool insert_meja_kedua(int index, int tahap, float suhu_tubuh, string tekanan_darah);
void show_statistik_vaksinasi(); void show_vaksinasi(); int check_meja_pertama(long long nik); void sort_vaksin_menu(); void sort_vaksin_method(int category);
void sort_vaksin_order(int category, int method); void sort_vaksin(int category, int method, int order); void search_vaksin_menu(); void search_vaksin_method(int category);
void search_vaksin(int category, int method); int jumpSearch(Vaksin *vaksinp, int n, string x, int category); int jumpSearch(Vaksin *vaksinp, int n, int x, int category);
void show_menu_antrian(); void show_menu_gudang(); void show_menu_pengguna(); void show_pengguna(); void add_pengguna(); void edit_pengguna(); void delete_pengguna();
void display(GudangVaksin *top); void push(GudangVaksin **top, Vaksin *vaksinp); void pop(GudangVaksin **top);
void daftar_vaksinasi(); void riwayat_vaksinasi();
void enqueue(AntrianVaksinasi **front, AntrianVaksinasi **rear, Account account); void dequeue(AntrianVaksinasi **front); void display(AntrianVaksinasi *front);

void show_auth() {
	system("cls");
	int selected_auth;
	cout << "========================================================================" << endl;
    cout << "|                            SELAMAT DATANG                            |" << endl;
    cout << "|                                  DI                                  |" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "|                                 OLEH                                 |" << endl;
    cout << "|                    KELOMPOK 1 - INFORMATIKA A 2020                   |" << endl;
	cout << "========================================================================" << endl;
    cout << "| [1] Daftar Akun                                                      |" << endl;
    cout << "| [2] Masuk Akun                                                       |" << endl;
    cout << "| [0] Keluar Aplikasi                                                  |" << endl;
	cout << "========================================================================" << endl;
    cout << "| Masukkan Pilihan> "; cin >> selected_auth;
	switch(selected_auth) {
		case 1:
			auth_register();
			break;
		case 2:
			auth_login();
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
			cout << "| Error: Pilihan salah!                                                |" << endl;
			cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_auth();			
	}
}

void auth_register() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                              DAFTAR AKUN                             |" << endl;
	cout << "========================================================================" << endl;
	string username, password, nama, tanggal_lahir, alamat;
	long long nik, nohp;
	int umur;
	cin.ignore();
	cout << "| Username      : "; getline(cin, username);
	cout << "| Password      : "; getline(cin, password);
	cout << "| NIK           : "; cin >> nik;
	cin.ignore();
	cout << "| Nama          : "; getline(cin, nama);
	cout << "| Umur          : "; cin >> umur;
	cout << "| No. HP        : "; cin >> nohp;
	cin.ignore();
	cout << "| Alamat        : "; getline(cin, alamat);
	cout << "| Tanggal Lahir : "; getline(cin, tanggal_lahir);
	int status = -1, index;
	for(int i = 0; i < MAKS_ACCOUNT; i++) {
		if(accounts[i].username == username || accounts[i].nik == nik) {
			status = 1;
			break;
		}
	}
	if(status == -1) {
		for(int i = 0; i < MAKS_ACCOUNT; i++) {
			if(accounts[i].username == "") {
				index = i;
				break;
			}
		}
		accounts[index].username = username;
		accounts[index].password = password;
		accounts[index].level = "user";
		accounts[index].nik = nik;
		accounts[index].nama = nama;
		accounts[index].umur = umur;
		accounts[index].nohp = nohp;
		accounts[index].alamat = alamat;
		accounts[index].tanggal_lahir = tanggal_lahir;
		accounts[index].vaksinasi = false;
        cout << "========================================================================" << endl;
        cout << "| Sukses: Akun berhasil dibuat dan disimpan                            |" << endl;
        cout << "========================================================================" << endl;
	} else {		
		cout << "========================================================================" << endl;
        cout << "| Error: Akun tersebut telah didaftarkan!                              |" << endl;
        cout << "========================================================================" << endl;
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_auth();
}

void auth_login() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                                 LOGIN                                |" << endl;
	cout << "========================================================================" << endl;
    string username, password;
    cin.ignore();
    cout << "| Username : "; getline(cin, username);
    cout << "| Password : "; getline(cin, password);
	int status;
    for(int i = 0; i < MAKS_ACCOUNT; i++) {
		if(accounts[i].username == username) {
			if(accounts[i].password == password) {
				status = 3;
				session_account.username = accounts[i].username;
				session_account.password = accounts[i].password;
				session_account.level = accounts[i].level;
				session_account.nik = accounts[i].nik;
				session_account.nama = accounts[i].nama;
				session_account.umur = accounts[i].umur;
				session_account.nohp = accounts[i].nohp;
				session_account.alamat = accounts[i].alamat;
				session_account.tanggal_lahir = accounts[i].tanggal_lahir;
				session_account.vaksinasi = accounts[i].vaksinasi;
				break;
			} else {
				status = 2;
				break;
			}
		} else {
			status = 1;
			continue;
		}
	}
	switch(status) {
		case 1:
			cout << "========================================================================" << endl;
            cout << "| Error: Username tidak ditemukan!                                     |" << endl;
            cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_auth();
			break;
		case 2:
            cout << "========================================================================" << endl;
            cout << "| Error: Password salah!                                               |" << endl;
            cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_auth();
			break;
		case 3:
			if(session_account.level == "admin") {				
				show_menu_admin();
			} else if(session_account.level == "dinkes") {
				show_menu_dinkes();
			} else {
				show_menu_user();
			}
			break;
	}
}

void show_menu_user() {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
    cout << "| [1] Lihat Data Vaksin COVID-19                                       |" << endl;
    cout << "| [2] Lihat Data Vaksinasi COVID-19                                    |" << endl;
    cout << "| [3] Daftar Vaksinasi COVID-19                                        |" << endl;
    cout << "| [4] Riwayat Vaksinasi COVID-19                                       |" << endl;
    cout << "| [5] Logout                                                           |" << endl;
    cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	cout << "Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			show_vaksin(&vaksin[0]);
			break;
		case 2:
			show_statistik_vaksinasi();
			break;
		case 3:
			daftar_vaksinasi();
			break;
		case 4:
			riwayat_vaksinasi();
			break;
		case 5:
			show_auth();
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_user();
	}
}

void daftar_vaksinasi() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
	if(session_account.vaksinasi == false) {
		int jumlah = 0;
		for(int i = 0; i < MAKS_VAKSINASI; i++) {
			if(vaksinasi[i].nama == session_account.nama && vaksinasi[i].nik == session_account.nik) {
				jumlah = vaksinasi[i].jumlah;
				break;
			}
		}
		if(jumlah >= 2) {			
	        cout << "| Error: Anda telah di vaksin 2x                                       |" << endl;
	        cout << "========================================================================" << endl;
		} else {			
			session_account.vaksinasi = true;
			for(int i = 0; i < MAKS_ACCOUNT; i++) {
				if((accounts[i].nama == session_account.nama) && (accounts[i].nik == session_account.nik)) {
					accounts[i].vaksinasi = true;
					enqueue(&FRONT, &REAR, session_account);
	                cout << "| Sukses: Data anda berhasil di daftar                                 |" << endl;
	                cout << "========================================================================" << endl;
					break;
				}
			}
		}
	} else {		
        cout << "| Error: Data anda telah terdaftar!                                    |" << endl;
        cout << "========================================================================" << endl;
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_user();
}

void riwayat_vaksinasi() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
	int status = -1;
	for(int i = 0; i < MAKS_VAKSINASI; i++) {
		if(vaksinasi[i].nama == session_account.nama && vaksinasi[i].nik == session_account.nik) {
			cout << "| Nama               : " << vaksinasi[i].nama << endl;
			cout << "| NIK                : " << vaksinasi[i].nik << endl;
			cout << "| Tanggal Lahir      : " << vaksinasi[i].tanggal_lahir << endl;
			cout << "| No HP              : " << vaksinasi[i].nohp << endl;
			cout << "| Alamat             : " << vaksinasi[i].alamat << endl;
			for(int j = 0; j < MAKS_DIVAKSIN; j++) {
				if(vaksinasi[i].vaksin[j] == "") {
					continue;
				} else {
					cout << "| Vaksin ke          : " << j + 1 << endl;
					cout << "| Suhu Tubuh         : " << vaksinasi[i].suhu[j] << endl;
					cout << "| Tekanan Darah      : " << vaksinasi[i].tekanan[j] << endl;
					cout << "| Nama Vaksin        : " << vaksinasi[i].vaksin[j] << endl;
					cout << "| Nomor Batch Vaksin : " << vaksinasi[i].batch[j] << endl;
					cout << "| KIPI               : " << vaksinasi[i].kipi[j] << endl;
				}
			}
		    cout << "========================================================================" << endl;
		    status = 1;
		    break;			
		}
	}
	if(status == -1) {
		cout << "| Error: Anda tidak memiliki riwayat vaksinasi!                        |" << endl;
	    cout << "========================================================================" << endl;
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_user();
}

void enqueue(AntrianVaksinasi **front, AntrianVaksinasi **rear, Account account) {
	AntrianVaksinasi *nodeBaru = new AntrianVaksinasi();
	nodeBaru->data.nama = account.nama;
	nodeBaru->data.nik = account.nik;
	nodeBaru->data.tanggal_lahir = account.tanggal_lahir;
	nodeBaru->data.nohp = account.nohp;
	nodeBaru->data.alamat = account.alamat;
	if(*front == NULL) {
		*front = nodeBaru;
	} else {
		(*rear)->next = nodeBaru;
	}
	*rear = nodeBaru;
}

void dequeue(AntrianVaksinasi **front) {
	if(*front == NULL) {
		cout << "| Error: Queue Kosong!                                                 |" << endl;
	    cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu_antrian();
	}
	AntrianVaksinasi *temp = *front;
	*front = (*front)->next;
}

void display(AntrianVaksinasi *front) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      ANTRIAN VAKSINASI COVID-19                      |" << endl;
    cout << "========================================================================" << endl;
	if(front == NULL) {
		cout << "| Error: Queue Kosong!                                                 |" << endl;
	    cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu_antrian();
	}
	int i = 0;
	while(front != NULL) {
		cout << "| Antrian ke-" << i+1 << endl;
		cout << "| Nama : " << front->data.nama << endl;
	    cout << "========================================================================" << endl;
		front = front->next;
		i++;
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_antrian();		
}

void show_menu_dinkes() {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
    cout << "| [1] Data Vaksin COVID-19                                             |" << endl;
    cout << "| [2] Data Vaksinasi COVID-19                                          |" << endl;
    cout << "| [3] Data Antrian Vaksinasi COVID-19                                  |" << endl;
    cout << "| [4] Data Gudang Vaksin COVID-19                                      |" << endl;
    cout << "| [5] Logout                                                           |" << endl;
    cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	cout << "Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			show_menu_vaksin();
			break;
		case 2:
			show_menu_vaksinasi();
			break;
		case 3:
			show_menu_antrian();
			break;
		case 4:
			show_menu_gudang();
			break;
		case 5:
			show_auth();
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_dinkes();
	}
}

void show_menu_admin() {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
    cout << "| [1] Data Pengguna                                                    |" << endl;
    cout << "| [2] Data Vaksin COVID-19                                             |" << endl;
    cout << "| [3] Data Vaksinasi COVID-19                                          |" << endl;
    cout << "| [4] Data Antrian Vaksin COVID-19                                     |" << endl;
    cout << "| [5] Data Gudang Vaksin COVID-19                                      |" << endl;
    cout << "| [6] Logout                                                           |" << endl;
    cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	cout << "Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			show_menu_pengguna();
			break;
		case 2:
			show_menu_vaksin();
			break;
		case 3:
			show_menu_vaksinasi();
			break;
		case 4:
			show_menu_antrian();
			break;
		case 5:
			show_menu_gudang();
			break;
		case 6:
			show_auth();
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_admin();
	}
}

void show_menu_antrian() {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
    cout << "| [1] Lihat Data Antrian Vaksinasi COVID-19                            |" << endl;
    cout << "| [2] Proses Vaksinasi COVID-19                                        |" << endl;
    cout << "| [3] Kembali                                                          |" << endl;
    cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	cout << "Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			display(FRONT);
			break;
		case 2:
			proses_vaksinasi_pertama(FRONT);
			break;
		case 3:
			if(session_account.level == "admin") {
				show_menu_admin();				
			} else {
				show_menu_dinkes();
			}
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_antrian();
	}
}

void show_menu_gudang() {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
    cout << "| [1] Lihat Data Gudang Vaksin COVID-19                                |" << endl;
    cout << "| [2] Tambah Data Gudang Vaksin COVID-19                               |" << endl;
    cout << "| [3] Hapus Data Gudang Vaksin COVID-19                                |" << endl;
    cout << "| [4] Kembali                                                          |" << endl;
    cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	cout << "Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			display(TOP);
			break;
		case 2:
			push(&TOP, &vaksin[0]);
			break;
		case 3:
			pop(&TOP);
			break;
		case 4:
			if(session_account.level == "admin") {
				show_menu_admin();				
			} else {
				show_menu_dinkes();
			}
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_gudang();
	}
}

void push(GudangVaksin **top, Vaksin *vaksinp) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      DATA GUDANG VAKSIN COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
	GudangVaksin *nodeBaru = new GudangVaksin();
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(vaksinp->nama == "") {
			continue;
		} else {
			cout << "| Vaksin ke-" << i+1 << endl;
			cout << "| Nama Vaksin : " << vaksinp->nama << endl;
			cout << "| Produksi    : " << vaksinp->produksi << endl;
			cout << "| Penggunaan  : " << vaksinp->penggunaan << endl;
		    cout << "========================================================================" << endl;
		}
		vaksinp++;
	}
	int nomor;
	cout << "| Masukkan ID Box Vaksin : "; cin >> nodeBaru->id;
	cout << "| Masukkan Nomor Vaksin  : "; cin >> nomor;
	nodeBaru->nama = vaksin[nomor-1].nama;
	if(*top == NULL) {
		*top = nodeBaru;
	    cout << "========================================================================" << endl;
		cout << "| Sukses: Data Gudang Vaksin COVID-19 berhasil ditambahkan             |" << endl;
	    cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu_gudang();
		return;
	}
	nodeBaru->next = *top;
	*top = nodeBaru;
    cout << "========================================================================" << endl;
	cout << "| Sukses: Data Gudang Vaksin COVID-19 berhasil ditambahkan             |" << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_gudang();
}

void pop(GudangVaksin **top) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      DATA GUDANG VAKSIN COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
	if(*top == NULL) {
		cout << "| Error: LinkedList Underflow!                                         |" << endl;
	    cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu_gudang();
	}
	GudangVaksin *temp = *top;
	*top = (*top)->next;
	delete temp;
	cout << "| Sukses: Data Gudang Vaksin COVID-19 berhasil dihapus                 |" << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_gudang();
}

void display(GudangVaksin *top) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      DATA GUDANG VAKSIN COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
	if(top == NULL) {
		cout << "| Error: LinkedList Underflow!                                         |" << endl;
	    cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu_gudang();
	}
	while(top != NULL) {
		cout << "| ID Box Vaksin : " << top->id << endl;
		cout << "| Nama Vaksin   : " << top->nama << endl;
	    cout << "========================================================================" << endl;
		top = top->next;
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_gudang();
}

void show_menu_pengguna() {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
    cout << "| [1] Lihat Data Pengguna                                              |" << endl;
    cout << "| [2] Tambah Data Pengguna                                             |" << endl;
    cout << "| [3] Ubah Data Pengguna                                               |" << endl;
    cout << "| [4] Hapus Data Pengguna                                              |" << endl;
    cout << "| [5] Urut Data Pengguna                                               |" << endl;
    cout << "| [6] Cari Data Pengguna                                               |" << endl;
    cout << "| [7] Kembali                                                          |" << endl;
    cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	cout << "Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			show_pengguna();
			break;
		case 2:
			add_pengguna();
			break;
		case 3:
			edit_pengguna();
			break;
		case 4:
			delete_pengguna();
			break;
		case 5:
			// Urut
			break;
		case 6:
			// Cari
			break;
		case 7:
			show_menu_admin();				
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_pengguna();
	}
}

void show_menu_vaksin() {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
    cout << "| [1] Lihat Data Vaksin COVID-19                                       |" << endl;
    cout << "| [2] Tambah Data Vaksin COVID-19                                      |" << endl;
    cout << "| [3] Ubah Data Vaksin COVID-19                                        |" << endl;
    cout << "| [4] Hapus Data Vaksin COVID-19                                       |" << endl;
    cout << "| [5] Urut Data Vaksin COVID-19                                        |" << endl;
    cout << "| [6] Cari Data Vaksin COVID-19                                        |" << endl;
    cout << "| [7] Kembali                                                          |" << endl;
    cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	cout << "Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			show_vaksin(&vaksin[0]);
			break;
		case 2:
			add_vaksin(&vaksin[0]);
			break;
		case 3:
			edit_vaksin(&vaksin[0]);
			break;
		case 4:
			delete_vaksin(&vaksin[0]);
			break;
		case 5:
			sort_vaksin_menu();
			break;
		case 6:
			search_vaksin_menu();
			break;
		case 7:
			if(session_account.level == "admin") {
				show_menu_admin();				
			} else {
				show_menu_dinkes();
			}
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_vaksin();
	}
}

void show_menu_vaksinasi() {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
    cout << "| [1] Lihat Statistik Vaksinasi COVID-19                               |" << endl;
    cout << "| [2] Lihat Data Vaksinasi COVID-19                                    |" << endl;
    cout << "| [3] Kembali                                                          |" << endl;
    cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	cout << "Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			show_statistik_vaksinasi();
			break;
		case 2:
			show_vaksinasi();
			break;
		case 3:
			if(session_account.level == "admin") {				
				show_menu_admin();
			} else {
				show_menu_dinkes();
			}
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_vaksinasi();
	}
}

string get_time() {
	time_t now = time(0);
	char* dt = ctime(&now);
	return dt;
}

void show_statistik_vaksinasi() {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                        DATA VAKSINASI COVID-19                       |" << endl;
    cout << "========================================================================" << endl;
	cout << "| Tanggal          : " << get_time();
	int count_vaksinasi = 0;
	for(int i = 0; i < MAKS_VAKSINASI; i++) {
		if(vaksinasi[i].nama != "" && vaksinasi[i].jumlah > 0) {
			count_vaksinasi += vaksinasi[i].jumlah;
		}
	}
    cout << "| Jumlah Vaksinasi : " << count_vaksinasi << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	if(session_account.level == "admin" ||  session_account.level == "dinkes") {		
		show_menu_vaksinasi();
	} else {
		show_menu_user();
	}
}

void show_vaksinasi() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                        DATA VAKSINASI COVID-19                       |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_VAKSINASI; i++) {
		if(vaksinasi[i].nama == "") {
			continue;
		} else {
			cout << "| Vaksinasi ke-" << i + 1 << endl;
			cout << "| Nama               : " << vaksinasi[i].nama << endl;
			cout << "| NIK                : " << vaksinasi[i].nik << endl;
			cout << "| Tanggal Lahir      : " << vaksinasi[i].tanggal_lahir << endl;
			cout << "| No HP              : " << vaksinasi[i].nohp << endl;
			cout << "| Alamat             : " << vaksinasi[i].alamat << endl;
			for(int j = 0; j < MAKS_DIVAKSIN; j++) {
				if(vaksinasi[i].vaksin[j] == "") {
					continue;
				} else {
					cout << "| Vaksin ke          : " << j + 1 << endl;
					cout << "| Suhu Tubuh         : " << vaksinasi[i].suhu[j] << endl;
					cout << "| Tekanan Darah      : " << vaksinasi[i].tekanan[j] << endl;
					cout << "| Nama Vaksin        : " << vaksinasi[i].vaksin[j] << endl;
					cout << "| Nomor Batch Vaksin : " << vaksinasi[i].batch[j] << endl;
					cout << "| KIPI               : " << vaksinasi[i].kipi[j] << endl;
				}
			}
		    cout << "========================================================================" << endl;
		}
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_vaksinasi();
}

void show_pengguna() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                             DATA PENGGUNA                            |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_ACCOUNT; i++) {
		if(accounts[i].username == "") {
			continue;
		} else {
			cout << "| Pengguna ke-" << i + 1 << endl;
			cout << "| Username  : " << accounts[i].username << endl;
			cout << "| Password  : " << accounts[i].password << endl;
			cout << "| Level     : " << accounts[i].level << endl;
			cout << "| NIK       : " << accounts[i].nik << endl;
			cout << "| Nama      : " << accounts[i].nama << endl;
			cout << "| Umur      : " << accounts[i].umur << endl;
			cout << "| No HP     : " << accounts[i].nohp << endl;
			cout << "| Alamat    : " << accounts[i].alamat << endl;
			cout << "| Vaksinasi : " << accounts[i].vaksinasi << endl;
		    cout << "========================================================================" << endl;
		}
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_pengguna();
}

void add_pengguna() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                             DATA PENGGUNA                            |" << endl;
    cout << "========================================================================" << endl;
	int index = -1;
	for(int i = 0; i < MAKS_ACCOUNT; i++) {
		if(accounts[i].username == "") {
			index = i;
			break;
		}
	}
	if(index != -1) {
		string username, password, nama, alamat, level;
		long long nik, nohp;
		int umur;
		cin.ignore();
		cout << "| Username : "; getline(cin, username);
		cout << "| Password : "; getline(cin, password);
		cout << "| Level    : "; cin >> level;
		cout << "| NIK      : "; cin >> nik;
		cin.ignore();
		cout << "| Nama     : "; getline(cin, nama);
		cout << "| Umur     : "; cin >> umur;
		cout << "| No. HP   : "; cin >> nohp;
		cin.ignore();
		cout << "| Alamat   : "; getline(cin, alamat);
		int status = -1;
		for(int i = 0; i < MAKS_ACCOUNT; i++) {
			if(accounts[i].username == username) {
				status = 1;
				break;
			}
		}
		if(status == -1) {
			accounts[index].username = username;
			accounts[index].password = password;
			accounts[index].level = level;
			accounts[index].nik = nik;
			accounts[index].nama = nama;
			accounts[index].umur = umur;
			accounts[index].nohp = nohp;
			accounts[index].alamat = alamat;
			accounts[index].vaksinasi = false;
	        cout << "========================================================================" << endl;
	        cout << "| Sukses: Akun berhasil dibuat dan disimpan                            |" << endl;
	        cout << "========================================================================" << endl;
		} else {		
			cout << "========================================================================" << endl;
	        cout << "| Error: Akun tersebut telah didaftarkan!                              |" << endl;
	        cout << "========================================================================" << endl;
		}
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_pengguna();
}

void edit_pengguna() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                             DATA PENGGUNA                            |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_ACCOUNT; i++) {
		if(accounts[i].username == "") {
			continue;
		} else {
			cout << "| Pengguna ke-" << i + 1 << endl;
			cout << "| Username  : " << accounts[i].username << endl;
			cout << "| Password  : " << accounts[i].password << endl;
			cout << "| Level     : " << accounts[i].level << endl;
			cout << "| NIK       : " << accounts[i].nik << endl;
			cout << "| Nama      : " << accounts[i].nama << endl;
			cout << "| Umur      : " << accounts[i].umur << endl;
			cout << "| No HP     : " << accounts[i].nohp << endl;
			cout << "| Alamat    : " << accounts[i].alamat << endl;
			cout << "| Vaksinasi : " << accounts[i].vaksinasi << endl;
		    cout << "========================================================================" << endl;
		}
	}
	int nomor;
	string username, password, nama, alamat, level;
	long long nik, nohp;
	int umur;
	bool vaksinasi;
	cout << "| Masukkan Nomor Pengguna : "; cin >> nomor;
	cin.ignore();
	cout << "| Masukkan Username       : "; getline(cin, username);
	cout << "| Masukkan Password       : "; getline(cin, password);
	cout << "| Masukkan Level          : "; cin >> level;
	cout << "| Masukkan NIK            : "; cin >> nik;
	cin.ignore();
	cout << "| Masukkan Nama           : "; getline(cin, nama);
	cout << "| Masukkan Umur           : "; cin >> umur;
	cout << "| Masukkan No. HP         : "; cin >> nohp;
	cin.ignore();
	cout << "| Masukkan Alamat         : "; getline(cin, alamat);
	cout << "| Masukkan Vaksinasi      : "; cin >> vaksinasi;
	accounts[nomor-1].username = username;
	accounts[nomor-1].password = password;
	accounts[nomor-1].level = level;
	accounts[nomor-1].nik = nik;
	accounts[nomor-1].nama = nama;
	accounts[nomor-1].umur = umur;
	accounts[nomor-1].nohp = nohp;
	accounts[nomor-1].alamat = alamat;
	accounts[nomor-1].vaksinasi = vaksinasi;
    cout << "========================================================================" << endl;
    cout << "| Sukses: Akun berhasil diperbaharui                                   |" << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_pengguna();
}

void delete_pengguna() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                             DATA PENGGUNA                            |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_ACCOUNT; i++) {
		if(accounts[i].username == "") {
			continue;
		} else {
			cout << "| Pengguna ke-" << i + 1 << endl;
			cout << "| Username  : " << accounts[i].username << endl;
			cout << "| Password  : " << accounts[i].password << endl;
			cout << "| Level     : " << accounts[i].level << endl;
			cout << "| NIK       : " << accounts[i].nik << endl;
			cout << "| Nama      : " << accounts[i].nama << endl;
			cout << "| Umur      : " << accounts[i].umur << endl;
			cout << "| No HP     : " << accounts[i].nohp << endl;
			cout << "| Alamat    : " << accounts[i].alamat << endl;
			cout << "| Vaksinasi : " << accounts[i].vaksinasi << endl;
		    cout << "========================================================================" << endl;
		}
	}
	int nomor;
	cout << "| Masukkan Nomor Pengguna : "; cin >> nomor;
	accounts[nomor-1].username = "";
	accounts[nomor-1].password = "";
	accounts[nomor-1].level = "";
	accounts[nomor-1].nik = 0;
	accounts[nomor-1].nama = "";
	accounts[nomor-1].umur = 0;
	accounts[nomor-1].nohp = 0;
	accounts[nomor-1].alamat = "";
	accounts[nomor-1].vaksinasi = false;
	cout << "========================================================================" << endl;
    cout << "| Sukses: Akun berhasil dihapus                                        |" << endl;
	cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_pengguna();
}

void show_vaksin(Vaksin *vaksinp) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(vaksinp->nama == "") {
			continue;
		} else {
			cout << "| Vaksin ke-" << i + 1 << endl;
			cout << "| Nama Vaksin : " << vaksinp->nama << endl;
			cout << "| Produksi    : " << vaksinp->produksi << endl;
			cout << "| Penggunaan  : " << vaksinp->penggunaan << endl;
		    cout << "========================================================================" << endl;
		}
		vaksinp++;
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	if(session_account.level == "admin" || session_account.level == "dinkes") {
		show_menu_vaksin();
	} else {
		show_menu_user();
	}
}

void add_vaksin(Vaksin *vaksinp) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	int index = -1;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(vaksinp->nama == "") {
			index = i;
			break;
		}
		vaksinp++;
	}
	if(index != -1) {
		cin.ignore();
		cout << "| Masukkan Nama Vaksin     : "; getline(cin, vaksinp->nama);
		cout << "| Masukkan Produksi Vaksin : "; getline(cin, vaksinp->produksi);
		vaksin[index].penggunaan = 0;
	    cout << "========================================================================" << endl;
        cout << "| Sukses: Data Vaksin berhasil ditambahkan                             |" << endl;
	    cout << "========================================================================" << endl;
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_vaksin();
}

void edit_vaksin(Vaksin *vaksinp) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(vaksinp->nama == "") {
			continue;
		} else {
			cout << "| Vaksin ke-" << i+1 << endl;
			cout << "| Nama Vaksin : " << vaksinp->nama << endl;
			cout << "| Produksi    : " << vaksinp->produksi << endl;
			cout << "| Penggunaan  : " << vaksinp->penggunaan << endl;
		    cout << "========================================================================" << endl;
		}
		vaksinp++;
	}
	int nomor;
	string nama, produksi;
	cout << "| Masukkan Nomor Vaksin    : "; cin >> nomor;
	cin.ignore();
	cout << "| Masukkan Nama Vaksin     : "; getline(cin, nama);
	cout << "| Masukkan Produksi Vaksin : "; getline(cin, produksi);
	vaksin[nomor-1].nama = nama;
	vaksin[nomor-1].produksi = produksi;
    cout << "========================================================================" << endl;
    cout << "| Sukses: Data Vaksin berhasil diperbaharui                            |" << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_vaksin();
}

void delete_vaksin(Vaksin *vaksinp) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(vaksinp->nama == "") {
			continue;
		} else {
			cout << "| Vaksin ke-" << i+1 << endl;
			cout << "| Nama Vaksin : " << vaksinp->nama << endl;
			cout << "| Produksi    : " << vaksinp->produksi << endl;
			cout << "| Penggunaan  : " << vaksinp->penggunaan << endl;
		    cout << "========================================================================" << endl;
		}
		vaksinp++;
	}
	int nomor;
	cout << "| Masukkan Nomor Vaksin : "; cin >> nomor;
	vaksin[nomor - 1].nama = "";
	vaksin[nomor - 1].produksi = "";
	vaksin[nomor - 1].penggunaan = 0;
	cout << "========================================================================" << endl;
    cout << "| Sukses: Data Vaksin berhasil dihapus                                 |" << endl;
	cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_vaksin();
}

void sort_vaksin_menu() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	cout << "| [1] Nama Vaksin                                                      |" << endl;
	cout << "| [2] Produksi                                                         |" << endl;
	cout << "| [3] Penggunaan                                                       |" << endl;
	cout << "| [4] Kembali                                                          |" << endl;
	cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	int selected_menu;
	cout << "| Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			sort_vaksin_method(selected_menu);
			break;
		case 2:
			sort_vaksin_method(selected_menu);
			break;
		case 3:
			sort_vaksin_method(selected_menu);
			break;
		case 4:
			show_menu_vaksin();
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			sort_vaksin_menu();
	}
}

void sort_vaksin_method(int category) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	cout << "| [1] Shell Sort                                                       |" << endl;
	cout << "| [2] Kembali                                                          |" << endl;
	cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	int selected_menu;
	cout << "| Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			sort_vaksin_order(category, selected_menu);
			break;
		case 2:
			sort_vaksin_menu();
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			sort_vaksin_method(category);
	}
}

void sort_vaksin_order(int category, int method) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	cout << "| [1] Ascending                                                        |" << endl;
	cout << "| [2] Descending                                                       |" << endl;
	cout << "| [3] Kembali                                                          |" << endl;
	cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	int selected_menu;
	cout << "| Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			sort_vaksin(category, method, selected_menu);
			cout << "========================================================================" << endl;
	        cout << "| Sukses: Data Vaksin berhasil diurutkan                               |" << endl;
		    cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_vaksin();
			break;
		case 2:
			sort_vaksin(category, method, selected_menu);
			cout << "========================================================================" << endl;
	        cout << "| Sukses: Data Vaksin berhasil diurutkan                               |" << endl;
		    cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_vaksin();
			break;
		case 3:
			sort_vaksin_method(category);
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			sort_vaksin_order(category, method);
	}
}

int shellSort(Vaksin *vaksinp, int n, int category, int order) {
	for(int gap = n / 2; gap > 0; gap /= 2) {
		for(int i = gap; i < n; i += 1) {
			Vaksin temp = vaksinp[i];
			int j;
			if(category == 1 and order == 1) {
				for (j = i; j >= gap && vaksinp[j - gap].nama > temp.nama; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 1 and order == 2) {
				for (j = i; j >= gap && vaksinp[j - gap].nama < temp.nama; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 2 and order == 1) {
				for (j = i; j >= gap && vaksinp[j - gap].produksi > temp.produksi; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 2 and order == 2) {
				for (j = i; j >= gap && vaksinp[j - gap].produksi < temp.produksi; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 3 and order == 1) {
				for (j = i; j >= gap && vaksinp[j - gap].penggunaan > temp.penggunaan; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			else if(category == 3 and order == 2) {
				for (j = i; j >= gap && vaksinp[j - gap].penggunaan < temp.penggunaan; j -= gap)
					vaksinp[j] = vaksinp[j - gap];				
			}
			vaksinp[j] = temp;
		}
	}
	return 0;
}

void sort_vaksin(int category, int method, int order) {
	int count_vaksin_valid;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(vaksin[i].nama == "") {
			continue;
		} else {
			count_vaksin_valid++;
		}
	}
	switch(method) {
		case 1:
			shellSort(&vaksin[0], count_vaksin_valid, category, order);
			break;
	}
}

void search_vaksin_menu() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	cout << "| [1] Nama Vaksin                                                      |" << endl;
	cout << "| [2] Produksi                                                         |" << endl;
	cout << "| [3] Penggunaan                                                       |" << endl;
	cout << "| [4] Kembali                                                          |" << endl;
	cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	int selected_menu;
	cout << "| Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			search_vaksin_method(selected_menu);
			break;
		case 2:
			search_vaksin_method(selected_menu);
			break;
		case 3:
			search_vaksin_method(selected_menu);
			break;
		case 4:
			show_menu_vaksin();
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			search_vaksin_menu();
	}
}

void search_vaksin_method(int category) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	if(category == 1 or category == 2) {
		cout << "| [1] Jump Search                                                      |" << endl;
		cout << "| [2] Kembali                                                          |" << endl;
		cout << "| [0] Keluar Aplikasi                                                  |" << endl;		
	} else {
		cout << "| [1] Jump Search                                                      |" << endl;
		cout << "| [2] Fibonacci Search                                                 |" << endl;
		cout << "| [3] Kembali                                                          |" << endl;
		cout << "| [0] Keluar Aplikasi                                                  |" << endl;
	}
    cout << "========================================================================" << endl;
	int selected_menu;
	cout << "| Pilih Menu> "; cin >> selected_menu;
	if(category == 1 or category == 2) {
		switch(selected_menu) {
			case 1:
				search_vaksin(category, selected_menu);
				break;
			case 2:
				search_vaksin_menu();
				break;
			case 0:
				close_app();
				break;
			default:
				cout << "========================================================================" << endl;
		    	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
		    	cout << "========================================================================" << endl;
				cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
				search_vaksin_method(category);
		}
	} else {
		switch(selected_menu) {
			case 1:
				search_vaksin(category, selected_menu);
				break;
			case 2:
				search_vaksin(category, selected_menu);
				break;
			case 3:
				search_vaksin_menu();
				break;
			case 0:
				close_app();
				break;
			default:
				cout << "========================================================================" << endl;
	        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
	        	cout << "========================================================================" << endl;
				cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
				search_vaksin_method(category);
		}
	}
}

int jumpSearch(Vaksin *vaksinp, int n, string x, int category) {
	int step = sqrt(n);
	int prev = 0;
	if(category == 1) {
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
	} else if(category == 2) {
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

int min(int x, int y) { return (x <= y) ? x : y; }

int fibMonaccianSearch(Vaksin *vaksinp, int n, int x) {
	int fibMMm2 = 0;
	int fibMMm1 = 1;
	int fibM = fibMMm2 + fibMMm1;

	while(fibM < n) {
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	int offset = -1;

	while(fibM > 1) {
		int i = min(offset + fibMMm2, n - 1);

		if(vaksinp[i].penggunaan < x) {
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		} else if(vaksinp[i].penggunaan > x) {
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		} else
			return i;
	}

	if(fibMMm1 && vaksinp[offset + 1].penggunaan == x)
		return offset + 1;

	return -1;
}

int jumpSearch(Vaksin *vaksinp, int n, int x, int category) {
	int step = sqrt(n);
	int prev = 0;
	if(category == 3) {
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

void search_vaksin(int category, int method) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	int count_vaksin_valid;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(vaksin[i].nama == "") {
			continue;
		} else {
			count_vaksin_valid++;
		}
	}
	int search_int;
	string search_str;
	int index;
	switch(method) {
		case 1:
			switch(category) {
				case 1:
					cout << "| Data yang ingin dicari> "; cin >> search_str;
					sort_vaksin(category, 1, 1);
					index = jumpSearch(&vaksin[0], count_vaksin_valid, search_str, category);
					break;
				case 2:
					cout << "| Data yang ingin dicari> "; cin >> search_str;
					sort_vaksin(category, 2, 1);
					index = jumpSearch(&vaksin[0], count_vaksin_valid, search_str, category);
					break;
				case 3:
					cout << "| Data yang ingin dicari> "; cin >> search_int;
					sort_vaksin(category, 3, 1);
					index = jumpSearch(&vaksin[0], count_vaksin_valid, search_int, category);
					break;
			}
			break;
		case 2:
			cout << "| Data yang ingin dicari> "; cin >> search_int;
			sort_vaksin(category, 3, 1);
			index = fibMonaccianSearch(&vaksin[0], count_vaksin_valid, search_int);
			break;
	}
	if(index != -1) {		
		cout << "========================================================================" << endl;
        cout << "| Sukses: Data Vaksin ditemukan                                        |" << endl;
		cout << "========================================================================" << endl;
        cout << "| Vaksin ke-" << index + 1 << endl;
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
	show_menu_vaksin();
}

void proses_vaksinasi_pertama(AntrianVaksinasi *front) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
	cout << "========================================================================" << endl;
    cout << "|                             MEJA PERTAMA                             |" << endl;
	cout << "========================================================================" << endl;
	if(front == NULL) {
		cout << "| Error: Queue Kosong!                                                 |" << endl;
	    cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu_antrian();
	}
	int status_nik = check_meja_pertama(FRONT->data.nik);
	if(status_nik == -1) {
		status_nik = insert_meja_pertama(FRONT->data.nik, FRONT->data.nama, FRONT->data.tanggal_lahir, FRONT->data.nohp, FRONT->data.alamat);
	}
	cout << "[DEBUG-1] " << status_nik << endl;
	switch(vaksinasi[status_nik].jumlah) {
		case 0:
			cout << "========================================================================" << endl;
		    cout << "| Sukses: Meja pertama selesai                                         |" << endl;
			cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk melanjutkan..."; getch(); cout << endl;
			proses_vaksinasi_kedua(status_nik, vaksinasi[status_nik].jumlah);
			break;
		case 1:
			cout << "========================================================================" << endl;
		    cout << "| Sukses: Meja pertama selesai                                         |" << endl;
			cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk melanjutkan..."; getch(); cout << endl;
			proses_vaksinasi_kedua(status_nik, vaksinasi[status_nik].jumlah);
			break;
		case 2:
			cout << "========================================================================" << endl;
		    cout << "| Error: Telah 2x mengikuti vaksinasi!                                 |" << endl;
			cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_antrian();
			break;
		default:
			cout << "========================================================================" << endl;
		    cout << "| Error: Mungkin terjadi kesalahan!                                    |" << endl;
			cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu_antrian();
	}
}

int check_meja_pertama(long long nik) {
	int index = -1;
	for(int i = 0; i < MAKS_VAKSINASI; i++) {
		if(vaksinasi[i].nik == nik) {
			index = i;
		}
	}
	return index;
}

int insert_meja_pertama(long long nik, string nama, string tanggal_lahir, long long nohp, string alamat) {
	int index;
	for(int i = 0; i < MAKS_VAKSINASI; i++) {
		if(vaksinasi[i].nik == 0 && vaksinasi[i].nama == "") {
			index = i;
			cout << "[DEBUG-2] " << index << endl;
			break;
		}
	}
	vaksinasi[index].nik = nik;
	vaksinasi[index].nama = nama;
	vaksinasi[index].tanggal_lahir = tanggal_lahir;
	vaksinasi[index].nohp = nohp;
	vaksinasi[index].alamat = alamat;
	return index;
}

int check_tahap(int nik) {
	for(int i = 0; i < MAKS_VAKSINASI; i++) {
		if(vaksinasi[i].nik == nik) {
			return vaksinasi[i].jumlah;
		}
	}
}

void proses_vaksinasi_kedua(int index, int tahap) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
	cout << "========================================================================" << endl;
    cout << "|                              MEJA KEDUA                              |" << endl;
	cout << "========================================================================" << endl;
	float suhu_tubuh;
	string tekanan_darah;
	cout << "| Masukkan Suhu Tubuh    : "; cin >> suhu_tubuh;
	cout << "| Masukkan Tekanan Darah : "; cin >> tekanan_darah;
	bool status = insert_meja_kedua(index, tahap, suhu_tubuh, tekanan_darah);
	if(status == true) {
		cout << "========================================================================" << endl;
	    cout << "| Sukses: Meja kedua selesai                                           |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk melanjutkan..."; getch(); cout << endl;
		proses_vaksinasi_ketiga(index, tahap);
	} else {
		cout << "========================================================================" << endl;
	    cout << "| Error: Terjadi kesalahan!                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu_antrian();
	}
}

bool insert_meja_kedua(int index, int tahap, float suhu_tubuh, string tekanan_darah) {
	vaksinasi[index].suhu[tahap] = suhu_tubuh;
	vaksinasi[index].tekanan[tahap] = tekanan_darah;
	return true;
}

void proses_vaksinasi_ketiga(int index, int tahap) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
	cout << "========================================================================" << endl;
    cout << "|                              MEJA KETIGA                             |" << endl;
	cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(vaksin[i].nama == "") {
			continue;
		} else {
			cout << "| Vaksin ke-" << i+1 << endl;
			cout << "| Nama Vaksin : " << vaksin[i].nama << endl;
			cout << "| Produksi    : " << vaksin[i].produksi << endl;
			cout << "| Penggunaan  : " << vaksin[i].penggunaan << endl;
		    cout << "========================================================================" << endl;
		}
	}
	int nomor_vaksin, nomor_batch_vaksin;
	cout << "| Masukkan Nomor Vaksin       : "; cin >> nomor_vaksin;
	cout << "| Masukkan Nomor Batch Vaksin : "; cin >> nomor_batch_vaksin;
	bool status = insert_meja_ketiga(index, tahap, nomor_vaksin, nomor_batch_vaksin);
	if(status == true) {
		cout << "========================================================================" << endl;
	    cout << "| Sukses: Meja ketiga selesai                                          |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk melanjutkan..."; getch(); cout << endl;
		proses_vaksinasi_keempat(index, tahap);
	} else {
		cout << "========================================================================" << endl;
	    cout << "| Error: Terjadi kesalahan!                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu_antrian();
	}
}

bool insert_meja_ketiga(int index, int tahap, int nomor_vaksin, int nomor_batch_vaksin) {
	vaksinasi[index].vaksin[tahap] = vaksin[nomor_vaksin-1].nama;
	vaksinasi[index].batch[tahap] = nomor_batch_vaksin;
	vaksinasi[index].jumlah++;
	vaksin[nomor_vaksin-1].penggunaan++;
	return true;
}

void proses_vaksinasi_keempat(int index, int tahap) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
	cout << "========================================================================" << endl;
    cout << "|                              MEJA KEEMPAT                            |" << endl;
	cout << "========================================================================" << endl;
	string kipi;
	cin.ignore();
	cout << "| Masukkan KIPI : "; getline(cin, kipi);
	bool status = insert_meja_keempat(index, tahap, kipi);
	if(status == true) {
		cout << "========================================================================" << endl;
	    cout << "| Sukses: Meja keempat selesai                                         |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk melanjutkan..."; getch(); cout << endl;
		final_vaksinasi(index, tahap);
	} else {
		cout << "========================================================================" << endl;
	    cout << "| Error: Terjadi kesalahan!                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu_antrian();
	}
}

bool insert_meja_keempat(int index, int tahap, string kipi) {
	vaksinasi[index].kipi[tahap] = kipi;
	return true;
}

void final_vaksinasi(int index, int tahap) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
	cout << "========================================================================" << endl;
    cout << "|                           DATA VAKSINASI                             |" << endl;
	cout << "========================================================================" << endl;
	cout << "| Nama               : " << vaksinasi[index].nama << endl;
	cout << "| NIK                : " << vaksinasi[index].nik << endl;
	cout << "| Tanggal Lahir      : " << vaksinasi[index].tanggal_lahir << endl;
	cout << "| No HP              : " << vaksinasi[index].nohp << endl;
	cout << "| Alamat             : " << vaksinasi[index].alamat << endl;
	cout << "| Vaksinasi Ke       : " << vaksinasi[index].jumlah << endl;
	cout << "| Suhu Tubuh         : " << vaksinasi[index].suhu[tahap] << endl;
	cout << "| Tekanan Darah      : " << vaksinasi[index].tekanan[tahap] << endl;
	cout << "| Nama Vaksin        : " << vaksinasi[index].vaksin[tahap] << endl;
	cout << "| Nomor Batch Vaksin : " << vaksinasi[index].batch[tahap] << endl;
	cout << "| KIPI               : " << vaksinasi[index].kipi[tahap] << endl;
	cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_ACCOUNT; i++) {
		if((accounts[i].nama == vaksinasi[index].nama) && (accounts[i].nik == vaksinasi[index].nik)) {
			accounts[i].vaksinasi = false;
			break;
		}
	}
	dequeue(&FRONT);
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_antrian();
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
	// Data Admin
	accounts[0].username = "admin";
	accounts[0].password = "admin";
	accounts[0].level = "user";
	accounts[0].nik = 6408120804020002;
	accounts[0].nama = "Andi Alfian Bahtiar";
	accounts[0].umur = 19;
	accounts[0].nohp = 6285346816962;
	accounts[0].alamat = "Jl. Perjuangan 7";

	accounts[1].username = "dinkes";
	accounts[1].password = "dinkes";
	accounts[1].level = "dinkes";
	accounts[1].nik = 6408120804020002;
	accounts[1].nama = "Fathan Ghoji Adzikra";
	accounts[1].umur = 19;
	accounts[1].nohp = 6285346816962;
	accounts[1].alamat = "Jl. Perjuangan 7";

	accounts[2].username = "user";
	accounts[2].password = "user";
	accounts[2].level = "user";
	accounts[2].nik = 6408120804020001;
	accounts[2].nama = "Muh. Fathir Fahreza";
	accounts[2].umur = 19;
	accounts[2].nohp = 6285346816962;
	accounts[2].alamat = "Jl. Perjuangan 7";

	// Data Vaksin
	vaksin[0].nama = "SinoVac";
	vaksin[0].produksi = "SinoVac BioTech";
	vaksin[0].penggunaan = 0;

	vaksin[1].nama = "AstraZeneca";
	vaksin[1].produksi = "AstraZeneca";
	vaksin[1].penggunaan = 0;

	vaksin[2].nama = "Pfizer";
	vaksin[2].produksi = "Pfizer";
	vaksin[2].penggunaan = 0;

	vaksin[3].nama = "Moderna";
	vaksin[3].produksi = "The National Institutes of Health (NIH)";
	vaksin[3].penggunaan = 0;

	while(true) {
		try {
			show_auth();
		} catch(...) {
			close_app();
		}
	}
	return 0;
}
