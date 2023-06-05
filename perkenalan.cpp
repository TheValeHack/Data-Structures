#include <iostream>

using namespace std;

// Classes
class orang {
public:
	string nama;

	orang(string namaNya) : nama(namaNya) {
		cout << "Orang dibuat" << endl;
	}
	~orang() {
		cout << "Orang dihancurkan" << endl;
	}
};

class pekerja : virtual public orang {
public:
	string pekerjaan;

	pekerja(string pekerjaanNya, string namaNya) : pekerjaan(pekerjaanNya), orang(namaNya) {
		cout << "Pekerja dibuat" << endl;
	}
	~pekerja() {
		cout << "Pekerja dihancurkan" << endl;
	}
};

class pelajar : virtual public orang {
public:
	string sekolah;

	pelajar(string sekolahNya, string namaNya) : sekolah(sekolahNya), orang(namaNya) {
		cout << "Pelajar dibuat" << endl;
	}
	~pelajar() {
		cout << "Pelajar dihancurkan" << endl;
	}
	void perkenalan() {
		cout << endl << "Halo, aku " << nama << " dari " << sekolah << endl << endl;
	}
};

class orangKeren : public pelajar, public pekerja {
public:
	int umur;

	orangKeren(string namaNya, string pekerjaanNya, string sekolahNya, int umurNya) :
		umur(umurNya),
		pekerja(pekerjaanNya, namaNya),
		pelajar(sekolahNya, namaNya),
		orang(namaNya)
	{
		cout << "OrangKeren dibuat" << endl;
	}
	~orangKeren() {
		cout << "OrangKeren dihancurkan" << endl;
	}
	void perkenalan() {
		printf("\nHalo, aku %s. Saat ini aku berusia %i tahun, aku bersekolah di %s sembari bekerja sebagai %s\n\n", nama.c_str(), umur, sekolah.c_str(), pekerjaan.c_str());
	}
};

// Main Function
int main() {
	orangKeren* freya = new orangKeren("Freya", "Idol JKT48", "SMAN", 17);

	freya->pelajar::perkenalan();

	delete freya;

	return 0;
}