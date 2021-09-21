# Tentang
- Mata Kuliah: Struktur Data dan Analisis Algoritma
- Kelas: Informatika A 2020
- Dosen Pembimbing: Rosmasari, S.Kom.,MT / Masna Wati, S.Si.,MT
- Bahasa Pemrograman: Python

# Algoritma Sorting dengan metode Exchange Sort
1. Tulis "Masukkan Data: "
2. Masukkan array
3. Tulis "Urutkan Secara: 1. Ascending 2. Descending"
4. Tulis "Pilihan: "
5. Masukkan order
6. Lakukan perulangan i sebanyak panjang array - 1
7. n ← 0
8. Lakukan perulangan j sebanyak awal i + 1 dan akhir panjang array
9. Jika order == 1 maka kerjakan baris 10 jika tidak maka kerjakan baris 13
10. Jika array[i] > array[j] maka kerjakan baris 11
11. array[i], array[j] ← array[j], array[i]
12. n ← n + 1
13. Jika array[i] < array[j] maka kerjakan baris 11
14. Tulis "Iterasi ke i+1 terjadi n pertukaran"
15. Tulis "Data setelah diurutkan: "
16. Lakukan perulangan i sebanyak array
17. Tulis i
