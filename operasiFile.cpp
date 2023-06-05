#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Files {
public: 
	string namaFile;

	Files(string namaFileNya) : namaFile(namaFileNya) { }

	void tulisFile() {
		string baris;
		ofstream tulis;
		tulis.open(namaFile);

		cout << "==== Tulis perasaanmu disini ====" << endl;

		while (true) {
			cout << "> ";
			getline(cin, baris);
			if (baris == "q") break;
			tulis << baris << endl;
		}

		tulis.close();

		cout << endl << "Terimakasih, Perasaanmu telah ditulis ke " << namaFile << "!" << endl;

	}
	void bacaFile() {
		string baris;
		ifstream baca;
		baca.open(namaFile);
		
		while (getline(baca, baris)) {
			cout << baris << endl;
		}

		baca.close();
	}
};

int main() {

	while (true) {
		string tanya;
		cout << "Pilih baca [b] atau tulis [t]? : ";
		getline(cin, tanya);


		if (tanya == "b") {
			string namaFile;
			cout << "Nama file : ";
			getline(cin, namaFile);

			Files* operasi = new Files(namaFile);
			cout << endl;
			operasi->bacaFile();
			cout << endl;
			delete operasi;
		}
		else if (tanya == "t") {
			string namaFile;
			cout << "Nama file : ";
			getline(cin, namaFile);
			Files* operasi = new Files(namaFile);
			operasi->tulisFile();
			delete operasi;
		}
		else {
			if (tanya == "q") break;
			if ((tanya != "b") || (tanya != "t")) continue;
		}
	}

}