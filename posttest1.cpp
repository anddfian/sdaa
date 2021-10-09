#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

const int MAKS_VAKSIN = 10;
//const int MAKS_VAKSINASI = 25;
const int MAKS_PENGGUNA = 25;

string nama_vaksin[MAKS_VAKSIN] = {"Sinovac", "Moderna", "AstraZeneca", "Pfizer"};
string produksi_vaksin[MAKS_VAKSIN] = {"Sinovac Biotech", "The National Institutes of Health (NIH)", "AstraZeneca", "Pfizer"};
int penggunaan_vaksin[MAKS_VAKSIN] = {0, 0, 0, 0};

//int nik_vaksinasi[MAKS_VAKSINASI];
//string nama_vaksinasi[MAKS_VAKSINASI];
//int jumlah_vaksinasi[MAKS_VAKSINASI];
//char darah_vaksinasi[MAKS_VAKSINASI];
//float suhu_vaksinasi[MAKS_VAKSINASI];
//string tekanan_vaksinasi[MAKS_VAKSINASI];
//string vaksin_vaksinasi[MAKS_VAKSINASI];
//int batch_vaksinasi[MAKS_VAKSINASI];
//string kipi_vaksinasi[MAKS_VAKSINASI];

string username_pengguna[MAKS_PENGGUNA] = {"anddfian"};
string password_pengguna[MAKS_PENGGUNA] = {"anddfian"};

void auth_register();
void auth_login();
void show_menu();
void show_vaksin();
void back_to_show_menu();
void add_vaksin();
void edit_vaksin();
void delete_vaksin();
void close_app();
void about_app();

void show_auth() {
	system("cls");
	int selected_auth;
	cout << "========================================================================" << endl;
    cout << "|                            SELAMAT DATANG                            |" << endl;
    cout << "|                                  DI                                  |" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "|                                 OLEH                                 |" << endl;
    cout << "|         ANDI ALFIAN BAHTIAR - 2009106002 - INFORMATIKA A 2020        |" << endl;
	cout << "========================================================================" << endl;
    cout << "| [1] Daftar Akun                                                      |" << endl;
    cout << "| [2] Masuk Akun                                                       |" << endl;
    cout << "| [0] Keluar Aplikasi                                                  |" << endl;
	cout << "========================================================================" << endl;
    cout << "Masukkan Pilihan> "; cin >> selected_auth;
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
	string username, password;
	cin.ignore();
	cout << "| Username : "; getline(cin, username); 
	cout << "| Password : "; getline(cin, password);
	int status, index;
	for(int i = 0; i < MAKS_PENGGUNA; i++) {
		if(username_pengguna[i] == username) {
			status = 1;
			break;
		}
	}
	if(status != 1) {
		for(int i = 0; i < MAKS_PENGGUNA; i++) {
			if(username_pengguna[i] == "") {
				index = i;
				break;
			}
		}
		username_pengguna[index] = username;
		password_pengguna[index] = password;
        cout << "========================================================================" << endl;
        cout << "| Sukses: Akun berhasil dibuat dan disimpan!                           |" << endl;
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
	cout << "======================================================================" << endl;
    cout << "|                                LOGIN                               |" << endl;
    cout << "======================================================================" << endl;
    string username, password;
    cin.ignore();
    cout << "| Username : "; getline(cin, username);
    cout << "| Password : "; getline(cin, password);
	int status;
    for(int i = 0; i < MAKS_PENGGUNA; i++) {
		if(username_pengguna[i] == username) {
			if(password_pengguna[i] == password) {
				status = 3;
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
			cout << "======================================================================" << endl;
            cout << "| Error: Username tidak ditemukan!                                   |" << endl;
            cout << "======================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_auth();
			break;
		case 2:
			cout << "======================================================================" << endl;
            cout << "| Error: Password salah!                                             |" << endl;
            cout << "======================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_auth();
			break;
		case 3:
			show_menu();
			break;
	}
}

void show_menu() {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
    cout << "========================================================================" << endl;
    cout << "| [1] Lihat Data Vaksin COVID-19                                       |" << endl;
    cout << "| [2] Tambah Data Vaksin COVID-19                                      |" << endl;
    cout << "| [3] Ubah Data Vaksin COVID-19                                        |" << endl;
    cout << "| [4] Hapus Data Vaksin COVID-19                                       |" << endl;
    cout << "| [5] Tentang Aplikasi                                                 |" << endl;
    cout << "| [0] Keluar Aplikasi                                                  |" << endl;
    cout << "========================================================================" << endl;
	cout << "Pilih Menu> "; cin >> selected_menu;
	switch(selected_menu) {
		case 1:
			show_vaksin();
			break;
		case 2:
			add_vaksin();
			break;
		case 3:
			edit_vaksin();
			break;
		case 4:
			delete_vaksin();
			break;
		case 5:
			about_app();
			break;
		case 0:
			close_app();
			break;
		default:
			cout << "========================================================================" << endl;
        	cout << "| Error: Anda memilih menu yang salah!                                 |" << endl;
        	cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu();
	}
}

void show_vaksin() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(nama_vaksin[i] == "") {
			continue;
		} else {
			cout << "| Vaksin ke-" << i+1 << endl;
			cout << "| Nama Vaksin : " << nama_vaksin[i] << endl;
			cout << "| Produksi    : " << produksi_vaksin[i] << endl;
			cout << "| Penggunaan  : " << penggunaan_vaksin[i] << endl;
		    cout << "========================================================================" << endl;
		}
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu();
}

void add_vaksin() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	int index = -1;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(nama_vaksin[i] == "") {
			index = i;
			break;
		}
	}
	if(index != -1) {
		char nama[128], produksi[128];
		cin.ignore();
		cout << "| Masukkan Nama Vaksin 	: "; cin.getline(nama, 128);
		cout << "| Masukkan Produksi Vaksin : "; cin.getline(produksi, 128);
		nama_vaksin[index] = nama;
		produksi_vaksin[index] = produksi;
		penggunaan_vaksin[index] = 0;
	    cout << "========================================================================" << endl;
        cout << "| Sukses: Data Vaksin berhasil ditambahkan                             |" << endl;
	    cout << "========================================================================" << endl;
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu();
}

void edit_vaksin() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(nama_vaksin[i] == "") {
			continue;
		} else {
			cout << "| Vaksin ke-" << i+1 << endl;
			cout << "| Nama Vaksin : " << nama_vaksin[i] << endl;
			cout << "| Produksi    : " << produksi_vaksin[i] << endl;
			cout << "| Penggunaan  : " << penggunaan_vaksin[i] << endl;
		    cout << "========================================================================" << endl;
		}
	}
	int nomor;
	string nama, produksi;
	cout << "| Masukkan Nomor Vaksin    : "; cin >> nomor;
	cin.ignore();
	cout << "| Masukkan Nama Vaksin     : "; getline(cin, nama);
	cout << "| Masukkan Produksi Vaksin : "; getline(cin, produksi);
	nama_vaksin[nomor-1] = nama;
	produksi_vaksin[nomor-1] = produksi;
    cout << "========================================================================" << endl;
    cout << "| Sukses: Data Vaksin berhasil diperbaharui                            |" << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu();
}

void delete_vaksin() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(nama_vaksin[i] == "") {
			continue;
		} else {
			cout << "| Vaksin ke-" << i+1 << endl;
			cout << "| Nama Vaksin : " << nama_vaksin[i] << endl;
			cout << "| Produksi    : " << produksi_vaksin[i] << endl;
			cout << "| Penggunaan  : " << penggunaan_vaksin[i] << endl;
			cout << "========================================================================" << endl;
		}
	}
	int nomor;
	cout << "| Masukkan Nomor Vaksin : "; cin >> nomor;
	nama_vaksin[nomor-1] = "";
	produksi_vaksin[nomor-1] = "";
	penggunaan_vaksin[nomor-1] = 0;
	cout << "========================================================================" << endl;
    cout << "| Sukses: Data Vaksin berhasil dihapus                                 |" << endl;
	cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu();
}

void about_app() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                           TENTANG APLIKASI                           |" << endl;
    cout << "========================================================================" << endl;
    cout << "| Nama Aplikasi        : Vaksinasi COVID-19                            |" << endl;
    cout << "| Versi                : 1.0                                           |" << endl;
    cout << "| Pengembang           : Andi Alfian Bahtiar  (2009106002)             |" << endl;
    cout << "| Donasi Pengembangan  : 056301058860507 (BRI)                         |" << endl;
    cout << "|                      : 7995048523 (BCA)                              |" << endl;
    cout << "|                      : 4132282159 (Permata)                          |" << endl;
    cout << "|                      : 1480016496716 (Mandiri)                       |" << endl;
    cout << "|                      : 90020219079 (Jenius)                          |" << endl;
    cout << "|                      : 085346816962 (Dana/OVO/Gopay)                 |" << endl;
    cout << "|                                                                      |" << endl;
    cout << "|                  Hak Cipta © 2021 Vaksinasi COVID-19                 |" << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu();
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
	while(true) {
		try {
			show_auth();
		} catch(...) {
			close_app();
		}
	}
	return 0;
}
