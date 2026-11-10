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
	while (!(cin >> dt[n].ram) || (dt[n].ram < 0)){
	    cout<<"Input tidak valid. Pastikan input merupakan bilangan bulat positif.\n";
	    cin.clear();
	    cin.ignore(100,'\n');
	    cout<<"Masukkan RAM \t: ";
	}
	
	
	cout << "Masukkan Storage \t: ";
	while (!(cin >> dt[n].storage) || (dt[n].storage < 0)){
	    cout<<"Input tidak valid. Pastikan input merupakan bilangan bulat positif.\n";
	    cin.clear();
	    cin.ignore(100,'\n');
	    cout<<"Masukkan Storage \t: ";
	}
	klasifikasiSpek(dt,n+1);
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

void menuStatistik(Data dt[], int n) {
    if (n == 0) {
        cout << "Data kosong. Tidak ada statistik.\n";
        return;
    }
    klasifikasiSpek(dt, n);

    int high = 0, medium = 0, low = 0;
    for (int i = 0; i < n; i++) {
        if (dt[i].spek == "High") high++;
        else if (dt[i].spek == "Medium") medium++;
        else low++;
    }

    cout << "\n=== STATISTIK INVENTORY ===\n";
    cout << fixed << setprecision(2);
    cout << "Jumlah data          : " << n << endl;
    cout << "Rata-rata RAM        : " << avgRAM(dt, n) << " GB\n";
    cout << "Rata-rata Storage    : " << avgStorage(dt, n) << " GB\n";
    cout << "RAM minimum          : " << cariMinRam(dt, n) << " GB\n";
    cout << "RAM maksimum         : " << cariMaxRam(dt, n) << " GB\n";
    cout << "Total storage        : " << totalStorage(dt, n) << " GB\n";
    cout << "\nDistribusi spesifikasi:\n";
    cout << "  High   : " << high << " perangkat\n";
    cout << "  Medium : " << medium << " perangkat\n";
    cout << "  Low    : " << low << " perangkat\n";
}

void menuCari(Data dt[], int n) {
    if (n == 0) {
        cout << "Data kosong. Tidak ada yang dicari.\n";
        return;
    }

    int pilih;
    cout << "\n=== CARI DATA ===\n";
    cout << "1. Berdasarkan ID\n";
    cout << "2. Berdasarkan Nama (substring)\n";
    cout << "3. Berdasarkan Jenis\n";
    cout << "Pilih: ";
    cin >> pilih;
    cin.ignore();

    string keyword;
    cout << "Masukkan kata kunci: ";
    getline(cin, keyword);

    bool ketemu = false;
    int jumlah = 0;

    cout << "\n--- Hasil Pencarian ---\n";
    for (int i = 0; i < n; i++) {
        bool cocok = false;
        switch (pilih) {
            case 1: cocok = (dt[i].id == keyword); break;
            case 2: cocok = (dt[i].name.find(keyword) != string::npos); break;
            case 3: cocok = (dt[i].type == keyword); break;
            default:
                cout << "Pilihan tidak valid.\n";
                return;
        }
        if (cocok) {
            if (!ketemu) {
                // cetak header sekali
                cout << left;
                cout << setw(10) << "ID" << setw(14) << "Pemilik"
                     << setw(14) << "Jenis" << setw(6) << "RAM"
                     << setw(10) << "Storage" << setw(14) << "Software"
                     << setw(10) << "Status" << setw(10) << "Spek" << endl;
                cout << string(88, '-') << endl;
                ketemu = true;
            }
            cout << left;
            cout << setw(10) << dt[i].id;
            cout << setw(14) << dt[i].name;
            cout << setw(14) << dt[i].type;
            cout << setw(6)  << dt[i].ram;
            cout << setw(10) << dt[i].storage;
            cout << setw(14) << dt[i].software;
            cout << setw(10) << dt[i].status;
            cout << setw(10) << dt[i].spek;
            cout << endl;
            jumlah++;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan.\n";
    } else {
        cout << "\nTotal ditemukan: " << jumlah << " data.\n";
    }
}

void menuUrut(Data dt[], int n) {
    if (n == 0) {
        cout << "Data kosong. Tidak ada yang diurutkan.\n";
        return;
    }

    int pilih;
    cout << "\n=== URUTKAN DATA ===\n";
    cout << "1. Berdasarkan RAM (ascending)\n";
    cout << "2. Berdasarkan RAM (descending)\n";
    cout << "3. Berdasarkan Storage (ascending)\n";
    cout << "4. Berdasarkan Storage (descending)\n";
    cout << "5. Berdasarkan Nama (A-Z)\n";
    cout << "Pilih: ";
    cin >> pilih;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool tukar = false;
            switch (pilih) {
                case 1: tukar = dt[j].ram > dt[j+1].ram; break;
                case 2: tukar = dt[j].ram < dt[j+1].ram; break;
                case 3: tukar = dt[j].storage > dt[j+1].storage; break;
                case 4: tukar = dt[j].storage < dt[j+1].storage; break;
                case 5: tukar = dt[j].name > dt[j+1].name; break;
                default:
                    cout << "Pilihan tidak valid.\n";
                    return;
            }
            if (tukar) {
                Data temp = dt[j];
                dt[j] = dt[j+1];
                dt[j+1] = temp;
            }
        }
    }

    cout << "Data berhasil diurutkan.\n";
    tampilData(dt, n);
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
            case 3: menuStatistik(data, n); break;
            case 4: menuUrut(data, n); break;
            case 5: menuCari(data, n); break;
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
