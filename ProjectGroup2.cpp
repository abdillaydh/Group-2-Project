#include<iostream>
#include<string>
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
//ascending
void urutkanRAM(Data data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j].ram > data[j + 1].ram) {
                Data temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

//ascending
void urutkanStorage(Data data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j].storage > data[j + 1].storage) {
                Data temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int cariID(Data data[], int n, string id) {
    for (int i = 0; i < n; i++) {
        if (data[i].id == id) {
            return i;
        }
    }
    return -1;
}

void cariPemilik(Data data[], int n, string name) {
    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (data[i].name == name) {
            cout << "ID: " << data[i].id << endl;
            cout << "Nama: " << data[i].name << endl;
            cout << "Jenis: " << data[i].type << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}

void cariSoftware(Data dta[], int n, string software) {
    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (data[i].software == software) {
            cout << "ID: " << data[i].id << endl;
            cout << "Nama: " << data[i].name << endl;
            cout << "Software: " << data[i].software << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}
