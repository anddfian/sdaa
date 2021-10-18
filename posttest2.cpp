#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include<fstream>
using namespace std;

const int MAKS_VAKSIN = 10, MAKS_VAKSINASI = 25, MAKS_ACCOUNT = 25, MAKS_DIVAKSIN = 2;

struct Vaksin {
	string nama, produksi;
	int penggunaan;
};

Vaksin vaksin[MAKS_VAKSIN];

struct Vaksinasi {
	string nama, tanggal, alamat, tekanan[MAKS_DIVAKSIN], vaksin[MAKS_DIVAKSIN], kipi[MAKS_DIVAKSIN];
	int jumlah, batch[MAKS_DIVAKSIN];
	long long nik, hp;
	float suhu[MAKS_DIVAKSIN];
};

Vaksinasi vaksinasi[MAKS_VAKSINASI];

struct Account {
	string username;
	string password;
};

string username_pengguna[MAKS_PENGGUNA] = {"anddfian"}, password_pengguna[MAKS_PENGGUNA] = {"anddfian"};

Account account[MAKS_ACCOUNT];

void final_vaksinasi(int index, int tahap); void proses_vaksinasi_keempat(int index, int tahap); void proses_vaksinasi_ketiga(int index, int tahap); void proses_vaksinasi_kedua(int index, int tahap);
void proses_vaksinasi_pertama(); void show_menu_vaksinasi(); void show_menu_vaksin(); void auth_register(); void auth_login(); void show_menu(); void show_vaksin();
void back_to_show_menu(); void add_vaksin(); void edit_vaksin(); void delete_vaksin(); void close_app(); void about_app();
int insert_meja_pertama(long long nik, string nama, string tanggal_lahir, long long no_hp, string alamat); bool insert_meja_keempat(int index, int tahap, string kipi);
bool insert_meja_ketiga(int index, int tahap, int nomor_vaksin, int nomor_batch_vaksin); bool insert_meja_kedua(int index, int tahap, float suhu_tubuh, string tekanan_darah);
void show_statistik_vaksinasi(); void show_vaksinasi(); int check_meja_pertama(long long nik);

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
	string username, password;
	cin.ignore();
	cout << "| Username : "; getline(cin, username); 
	cout << "| Password : "; getline(cin, password);
	int status = -1, index;
	for(int i = 0; i < MAKS_ACCOUNT; i++) {
		if(account[i].username == username) {
			status = 1;
			break;
		}
	}
	if(status == -1) {
		for(int i = 0; i < MAKS_ACCOUNT; i++) {
			if(account[i].username == "") {
				index = i;
				break;
			}
		}
		account[index].username = username;
		account[index].password = password;
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
	cout << "========================================================================" << endl;
    cout << "|                                 LOGIN                                |" << endl;
	cout << "========================================================================" << endl;
    string username, password;
    cin.ignore();
    cout << "| Username : "; getline(cin, username);
    cout << "| Password : "; getline(cin, password);
	int status;
    for(int i = 0; i < MAKS_ACCOUNT; i++) {
		if(account[i].username == username) {
			if(account[i].password == password) {
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
    cout << "| [1] Data Vaksin COVID-19                                             |" << endl;
    cout << "| [2] Data Vaksinasi COVID-19                                          |" << endl;
    cout << "| [3] Proses Vaksin COVID-19                                           |" << endl;
    cout << "| [4] Tentang Aplikasi                                                 |" << endl;
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
			proses_vaksinasi_pertama();
			break;
		case 4:
			about_app();
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
			show_menu();
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
    cout << "| [5] Kembali                                                          |" << endl;
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
			show_menu();
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
			show_menu();
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
	show_menu_vaksinasi();
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
			cout << "| Tanggal Lahir      : " << vaksinasi[i].tanggal << endl;
			cout << "| No HP              : " << vaksinasi[i].hp << endl;
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


void show_vaksin() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(vaksin[i].nama == "") {
			continue;
		} else {
			cout << "| Vaksin ke-" << i + 1 << endl;
			cout << "| Nama Vaksin : " << vaksin[i].nama << endl;
			cout << "| Produksi    : " << vaksin[i].produksi << endl;
			cout << "| Penggunaan  : " << vaksin[i].penggunaan << endl;
		    cout << "========================================================================" << endl;
		}
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_vaksin();
}

void add_vaksin() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	int index = -1;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(vaksin[i].nama == "") {
			index = i;
			break;
		}
	}
	if(index != -1) {
		string nama, produksi;
		cin.ignore();
		cout << "| Masukkan Nama Vaksin     : "; getline(cin, nama);
		cout << "| Masukkan Produksi Vaksin : "; getline(cin, produksi);
		vaksin[index].nama = nama;
		vaksin[index].produksi = produksi;
		vaksin[index].penggunaan = 0;
	    cout << "========================================================================" << endl;
        cout << "| Sukses: Data Vaksin berhasil ditambahkan                             |" << endl;
	    cout << "========================================================================" << endl;
	}
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu_vaksin();
}

void edit_vaksin() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
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

void delete_vaksin() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                         DATA VAKSIN COVID-19                         |" << endl;
    cout << "========================================================================" << endl;
	for(int i = 0; i < MAKS_VAKSIN; i++) {
		if(vaksin[i].nama == "") {
			continue;
		} else {
			cout << "| Vaksin ke-" << i + 1 << endl;
			cout << "| Nama Vaksin : " << vaksin[i].nama << endl;
			cout << "| Produksi    : " << vaksin[i].produksi << endl;
			cout << "| Penggunaan  : " << vaksin[i].penggunaan << endl;
			cout << "========================================================================" << endl;
		}
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

void proses_vaksinasi_pertama() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
	cout << "========================================================================" << endl;
    cout << "|                             MEJA PERTAMA                             |" << endl;
	cout << "========================================================================" << endl;
	string nama, tanggal_lahir, alamat;
	long long nik, no_hp;
	cout << "| Masukkan NIK           : "; cin >> nik;
	int status_nik = check_meja_pertama(nik);
	if(status_nik == -1) {
		cin.ignore();
		cout << "| Masukkan Nama          : "; getline(cin, nama);
		cout << "| Masukkan Tanggal Lahir : "; getline(cin, tanggal_lahir);
		cout << "| Masukkan No. HP        : "; cin >> no_hp;
		cin.ignore();
		cout << "| Masukkan Alamat        : "; getline(cin, alamat);
		status_nik = insert_meja_pertama(nik, nama, tanggal_lahir, no_hp, alamat);
	}
	switch(vaksinasi[status_nik].jumlah) {
		case 0: 1;
			cout << "========================================================================" << endl;
		    cout << "| Sukses: Meja pertama selesai                                         |" << endl;
			cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk melanjutkan..."; getch(); cout << endl;
			proses_vaksinasi_kedua(status_nik, vaksinasi[status_nik].jumlah);
			break;
		case 2:
			cout << "========================================================================" << endl;
		    cout << "| Error: Telah 2x mengikuti vaksinasi                                  |" << endl;
			cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu();
			break;
		default:
			cout << "========================================================================" << endl;
		    cout << "| Error: Mungkin terjadi kesalahan!                                    |" << endl;
			cout << "========================================================================" << endl;
			cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
			show_menu();
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

int insert_meja_pertama(long long nik, string nama, string tanggal_lahir, long long no_hp, string alamat) {
	int index;
	for(int i = 0; i < MAKS_VAKSINASI; i++) {
		if(vaksinasi[i].nik == 0) {
			index = i;
			break;
		}
	}
	vaksinasi[index].nik = nik;
	vaksinasi[index].nama = nama;
	vaksinasi[index].tanggal = tanggal_lahir;
	vaksinasi[index].hp = no_hp;
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
		show_menu();
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
		show_menu();
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
		show_menu();
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
	cout << "| Tanggal Lahir      : " << vaksinasi[index].tanggal << endl;
	cout << "| No HP              : " << vaksinasi[index].hp << endl;
	cout << "| Alamat             : " << vaksinasi[index].alamat << endl;
	cout << "| Vaksinasi Ke       : " << vaksinasi[index].jumlah << endl;
	cout << "| Suhu Tubuh         : " << vaksinasi[index].suhu[tahap] << endl;
	cout << "| Tekanan Darah      : " << vaksinasi[index].tekanan[tahap] << endl;
	cout << "| Nama Vaksin        : " << vaksinasi[index].vaksin[tahap] << endl;
	cout << "| Nomor Batch Vaksin : " << vaksinasi[index].batch[tahap] << endl;
	cout << "| KIPI               : " << vaksinasi[index].kipi[tahap] << endl;
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
    cout << "| Pengembang           : Andi Alfian Bahtiar (2009106002)              |" << endl;
    cout << "| Donasi Pengembangan  : 056301058860507     (BRI)                     |" << endl;
    cout << "|                      : 7995048523          (BCA)                     |" << endl;
    cout << "|                      : 4132282159          (Permata)                 |" << endl;
    cout << "|                      : 1480016496716       (Mandiri)                 |" << endl;
    cout << "|                      : 90020219079         (Jenius)                  |" << endl;
    cout << "|                      : 085346816962        (Dana/OVO/Gopay/LinkAja)  |" << endl;
    cout << "|                                                                      |" << endl;
    cout << "|                  Hak Cipta 2021 Vaksinasi COVID-19                   |" << endl;
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
