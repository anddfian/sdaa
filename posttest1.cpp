#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

const int MAKS_VAKSIN = 10, MAKS_VAKSINASI = 25, MAKS_PENGGUNA = 25;

string nama_vaksin[MAKS_VAKSIN] = {"Sinovac", "Moderna", "AstraZeneca", "Pfizer"}, produksi_vaksin[MAKS_VAKSIN] = {"Sinovac Biotech", "The National Institutes of Health (NIH)", "AstraZeneca", "Pfizer"};
int penggunaan_vaksin[MAKS_VAKSIN] = {0, 0, 0, 0};

string nama_vaksinasi[MAKS_VAKSINASI], tanggal_vaksinasi[MAKS_VAKSINASI], alamat_vaksinasi[MAKS_VAKSINASI], tekanan_vaksinasi[MAKS_VAKSINASI], vaksin_vaksinasi[MAKS_VAKSINASI], kipi_vaksinasi[MAKS_VAKSINASI];
int jumlah_vaksinasi[MAKS_VAKSINASI], batch_vaksinasi[MAKS_VAKSINASI];
long long nik_vaksinasi[MAKS_VAKSINASI], no_hp_vaksinasi[MAKS_VAKSINASI];
float suhu_vaksinasi[MAKS_VAKSINASI];

string username_pengguna[MAKS_PENGGUNA] = {"anddfian"}, password_pengguna[MAKS_PENGGUNA] = {"anddfian"};

void final_vaksinasi(int index); void proses_vaksinasi_keempat(int index); void proses_vaksinasi_ketiga(int index); void proses_vaksinasi_kedua(int index);
void proses_vaksinasi_pertama(); void show_menu_vaksinasi(); void show_menu_vaksin(); void auth_register(); void auth_login(); void show_menu(); void show_vaksin();
void back_to_show_menu(); void add_vaksin(); void edit_vaksin(); void delete_vaksin(); void close_app(); void about_app();
int insert_meja_pertama(string nama, long long nik, string tanggal_lahir, long long no_hp, string alamat); bool insert_meja_keempat(int index, string kipi);
bool insert_meja_ketiga(int index, int nomor_vaksin, int nomor_batch_vaksin); bool insert_meja_kedua(int index, float suhu_tubuh, string tekanan_darah);

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
	int status = -1, index;
	for(int i = 0; i < MAKS_PENGGUNA; i++) {
		if(username_pengguna[i] == username) {
			status = 1;
			break;
		}
	}
	if(status == -1) {
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
	cout << "========================================================================" << endl;
    cout << "|                                 LOGIN                                |" << endl;
	cout << "========================================================================" << endl;
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

string get_time() {
	time_t now = time(0);
	char* dt = ctime(&now);
	return dt;
}

void show_menu_vaksinasi() {
	system("cls");
	int selected_menu;
	cout << "========================================================================" << endl;
    cout << "|                        DATA VAKSINASI COVID-19                       |" << endl;
    cout << "========================================================================" << endl;
	cout << "| Tanggal          : " << get_time();
	int count_vaksinasi = 0;
	for(int i = 0; i < MAKS_VAKSINASI; i++) {
		if(nama_vaksinasi[i] != "" && jumlah_vaksinasi[i] > 0) {
			count_vaksinasi += jumlah_vaksinasi[i];
		}
	}
    cout << "| Jumlah Vaksinasi : " << count_vaksinasi << endl;
    cout << "========================================================================" << endl;
	cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
	show_menu();
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
		string nama, produksi;
		cin.ignore();
		cout << "| Masukkan Nama Vaksin     : "; getline(cin, nama);
		cout << "| Masukkan Produksi Vaksin : "; getline(cin, produksi);
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

void proses_vaksinasi_pertama() {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
	cout << "========================================================================" << endl;
    cout << "|                             MEJA PERTAMA                             |" << endl;
	cout << "========================================================================" << endl;
	string nama, tanggal_lahir, alamat;
	long long nik, no_hp;
	cin.ignore();
	cout << "| Masukkan Nama          : "; getline(cin, nama);
	cout << "| Masukkan NIK           : "; cin >> nik;
	cin.ignore();
	cout << "| Masukkan Tanggal Lahir : "; getline(cin, tanggal_lahir);
	cout << "| Masukkan No. HP        : "; cin >> no_hp;
	cin.ignore();
	cout << "| Masukkan Alamat        : "; getline(cin, alamat);
	int status = insert_meja_pertama(nama, nik, tanggal_lahir, no_hp, alamat);
	if(status != -1) {
		cout << "========================================================================" << endl;
	    cout << "| Sukses: Meja pertama selesai                                         |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk melanjutkan..."; getch(); cout << endl;
		proses_vaksinasi_kedua(status);
	} else if(status == MAKS_VAKSINASI + 1) {
		cout << "========================================================================" << endl;
	    cout << "| Error: Telah 2x mengikuti vaksinasi                                  |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu();		
	} else {
		cout << "========================================================================" << endl;
	    cout << "| Error: Mungkin terjadi kesalahan!                                    |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu();
	}
}

int insert_meja_pertama(string nama, long long nik, string tanggal_lahir, long long no_hp, string alamat) {
	int status = -1, index = -1;
	for(int i = 0; i < MAKS_VAKSINASI; i++) {
		if(nik_vaksinasi[i] == nik) {
			status = 1;
			if(jumlah_vaksinasi[i] > 1) {
				index = MAKS_VAKSINASI + 1;
			} else {
				index = i;
			}
			break;
		}
	}
	if(status == -1) {
		for(int i = 0; i < MAKS_VAKSINASI; i++) {
			if(nik_vaksinasi[i] == 0) {
				index = i;
				break;
			}
		}
		nama_vaksinasi[index] = nama;
		nik_vaksinasi[index] = nik;
		tanggal_vaksinasi[index] = tanggal_lahir;
		no_hp_vaksinasi[index] = no_hp;
		alamat_vaksinasi[index] = alamat;
	}
	return index;
}

void proses_vaksinasi_kedua(int index) {
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
	bool status = insert_meja_kedua(index, suhu_tubuh, tekanan_darah);
	if(status == true) {
		cout << "========================================================================" << endl;
	    cout << "| Sukses: Meja kedua selesai                                           |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk melanjutkan..."; getch(); cout << endl;
		proses_vaksinasi_ketiga(index);
	} else {
		cout << "========================================================================" << endl;
	    cout << "| Error: Terjadi kesalahan!                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu();
	}
}

bool insert_meja_kedua(int index, float suhu_tubuh, string tekanan_darah) {
	suhu_vaksinasi[index] = suhu_tubuh;
	tekanan_vaksinasi[index] = tekanan_darah;
	return true;
}

void proses_vaksinasi_ketiga(int index) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
	cout << "========================================================================" << endl;
    cout << "|                              MEJA KETIGA                             |" << endl;
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
	int nomor_vaksin, nomor_batch_vaksin;
	cout << "| Masukkan Nomor Vaksin       : "; cin >> nomor_vaksin;
	cout << "| Masukkan Nomor Batch Vaksin : "; cin >> nomor_batch_vaksin;
	bool status = insert_meja_ketiga(index, nomor_vaksin, nomor_batch_vaksin);
	if(status == true) {
		cout << "========================================================================" << endl;
	    cout << "| Sukses: Meja ketiga selesai                                          |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk melanjutkan..."; getch(); cout << endl;
		proses_vaksinasi_keempat(index);
	} else {
		cout << "========================================================================" << endl;
	    cout << "| Error: Terjadi kesalahan!                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu();
	}
}

bool insert_meja_ketiga(int index, int nomor_vaksin, int nomor_batch_vaksin) {
	vaksin_vaksinasi[index] = nama_vaksin[nomor_vaksin-1];
	batch_vaksinasi[index] = nomor_batch_vaksin;
	jumlah_vaksinasi[index]++;
	penggunaan_vaksin[nomor_vaksin-1]++;
	return true;
}

void proses_vaksinasi_keempat(int index) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
	cout << "========================================================================" << endl;
    cout << "|                              MEJA KEEMPAT                            |" << endl;
	cout << "========================================================================" << endl;
	string kipi;
	cin.ignore();
	cout << "| Masukkan KIPI : "; getline(cin, kipi);
	bool status = insert_meja_keempat(index, kipi);
	if(status == true) {
		cout << "========================================================================" << endl;
	    cout << "| Sukses: Meja keempat selesai                                         |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk melanjutkan..."; getch(); cout << endl;
		final_vaksinasi(index);
	} else {
		cout << "========================================================================" << endl;
	    cout << "| Error: Terjadi kesalahan!                                            |" << endl;
		cout << "========================================================================" << endl;
		cout << "Tekan 'Enter' untuk kembali..."; getch(); cout << endl;
		show_menu();
	}
}

bool insert_meja_keempat(int index, string kipi) {
	kipi_vaksinasi[index] = kipi;
	return true;
}

void final_vaksinasi(int index) {
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                      APLIKASI VAKSINASI COVID-19                     |" << endl;
	cout << "========================================================================" << endl;
    cout << "|                           DATA VAKSINASI                             |" << endl;
	cout << "========================================================================" << endl;
	cout << "| Nama               : " << nama_vaksinasi[index] << endl;
	cout << "| NIK                : " << nik_vaksinasi[index] << endl;
	cout << "| Tanggal Lahir      : " << tanggal_vaksinasi[index] << endl;
	cout << "| No HP              : " << no_hp_vaksinasi[index] << endl;
	cout << "| Alamat             : " << alamat_vaksinasi[index] << endl;
	cout << "| Vaksinasi Ke       : " << jumlah_vaksinasi[index] << endl;
	cout << "| Suhu Tubuh         : " << suhu_vaksinasi[index] << endl;
	cout << "| Tekanan Darah      : " << tekanan_vaksinasi[index] << endl;
	cout << "| Nama Vaksin        : " << vaksin_vaksinasi[index] << endl;
	cout << "| Nomor Batch Vaksin : " << batch_vaksinasi[index] << endl;
	cout << "| KIPI               : " << kipi_vaksinasi[index] << endl;
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
