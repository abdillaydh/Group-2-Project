#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Data {
	string id;
	string name;
	string type;
	int ram;
	int storage;
	string software;
	string status;
	string spek;
};

const int MAX = 100;

double avgRAM(Data dt[], int n) {
    if (n == 0) return 0;

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += dt[i].ram;
    }

    return (double) total/n;
}

double avgStorage(Data dt[], int n) {
    if (n == 0) return 0;

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += dt[i].storage;
    }

    return (double) total/n;
}

int totalStorage(Data dt[], int n) {
    if (n == 0) return 0;

    return dt[n-1].storage + totalStorage(dt, n-1);
}

int cariMinRam(Data dt[], int n) {
    if (n == 0) return 0;

    int minRAM = dt[0].ram;
    for (int i = 1; i < n; i++) {
        if (dt[i].ram < minRAM) minRAM = dt[i].ram;
    }

    return minRAM;
}

int cariMaxRam(Data dt[], int n) {
    if (n == 0) return 0;

    int maxRAM = dt[0].ram;
    for (int i = 1; i < n; i++) {
        if (dt[i].ram > maxRAM) maxRAM = dt[i].ram;
    }

    return maxRAM;
}

void tambahData(Data dt[], int &n){
	if(n >= MAX){
		cout << "Data penuh. Kembali ke menu" << endl;
		return;
	}
	
	cout << "Masukkan ID \t\t: ";
	cin >> dt[n].id;
	
	cin.ignore();
	cout << "Masukkan nama \t\t: ";
	getline(cin, dt[n].name);
	
	cout << "Masukkan jenis \t\t: ";
	getline(cin, dt[n].type);
	
	cout << "Masukkan RAM \t\t: ";
	cin >> dt[n].ram;
	
	cout << "Masukkan Storage \t: ";
	cin >> dt[n].storage;
	
	if(dt[n].ram > 0 && dt[n].storage > 0){
		cout << "Masukkan jenis software : ";
		cin >> dt[n].software;
		
		cout << "Masukkan status \t: ";
		cin >> dt[n].status;
	} else{
		return;
	}
	
	cout << endl;
	n++;
}

void klasifikasiSpek(Data dt[], int n){
	for(int i = 0; i < n; i++){
		if(dt[i].ram >= 16 && dt[i].storage >= 512){
			dt[i].spek = "High";
		} else if(dt[i].ram >= 8 && dt[i].storage >= 256){
			dt[i].spek = "Medium";
		} else{
			dt[i].spek = "Low";
		}
	}
}

void tampilData(Data dt[], int n){
	if(n == 0){
		cout << "Data kosong";
		return;
	} 
	
	cout << left;
	cout << setw(10) << "ID";
	cout << setw(14) << "Pemilik"; 
	cout << setw(14) << "Jenis";
	cout << setw(6) << "RAM";
	cout << setw(10) << "Storage";
	cout << setw(14) << "Software";
	cout << setw(10) << "Status";
	cout << setw(10) << "Spek";
	cout << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	for(int i =0; i < n; i++){
		cout << left; 
		cout << setw(10) << dt[i].id ;
		cout << setw(14) << dt[i].name;
		cout << setw(14) << dt[i].type; 
		cout << setw(6) << dt[i].ram;
		cout << setw(10) << dt[i].storage;
		cout << setw(14) << dt[i].software;
		cout << setw(10) << dt[i].status;
		cout << setw(10) << dt[i].spek;
		cout << endl;
	}
}

void tampilMenu() {
	cout << "\n=== INVENTORY MANAGER ===\n"
         << "1. Tambah data\n"
         << "2. Tampil data\n"
         << "3. Statistik (rata-rata, min, maks)\n"
         << "4. Urutkan data\n"
         << "5. Cari data\n"
         << "6. Total storage (rekursif)\n"
         << "7. Filter syarat (tantangan)\n"
         << "0. Keluar\n"
         << "Pilih: ";
}

int main () {
	Data data[MAX];
	int n=0;
	int pilih;

	do {
        tampilMenu();
        cin >> pilih;

        switch (pilih) {
            case 1: tambahData(data, n); break;
            case 2: tampilData(data, n); break;
            //case 3: menuStatistik(data, n); break;
            //case 4: menuUrut(data, n); break;
            //case 5: menuCari(data, n); break;
            case 6:
                cout << "Total storage semua perangkat: "
                     << totalStorage(data, n) << " GB\n";
                break;
            case 7: {
                int r, s;
                cout << "Minimal RAM (GB)     : "; cin >> r;
                cout << "Minimal storage (GB) : "; cin >> s;
                //filterSyarat(data, n, r, s);
                break;
            }
            case 0: cout << "Terima kasih. Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 0);

    return 0;
}