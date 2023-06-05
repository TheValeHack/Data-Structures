#include <iostream>
#include <string>

class hashing {
private:
	struct hashTable {
		std::string username, password;
	};
	hashTable* accounts;
public:
	hashing(const int& total) {
		accounts = new hashTable[total];
		welcome();
	}
	~hashing() {
		//printHashTable();
	}
	int hash(const std::string &password) const {
		return tolower(password[0]) - 97;
	}
	bool cekDaftar(const std::string &username, const std::string &password) {
		int index = hash(password);
		std::cout << std::endl;
		if ((accounts[index].username != "") && (accounts[index].password != "")) {
			std::cout << "Akun sudah ada" << std::endl;
			return false;
		}
		else {
			accounts[index].username = username;
			accounts[index].password = password;
			std::cout << "Akun berhasil terdaftar" << std::endl;
			return true;
		}
	}
	bool cekLogin(const std::string& username, const std::string& password) {
		int index = hash(password);
		std::cout << std::endl;
		if ((accounts[index].username == username) && (accounts[index].password == password)) {
			std::cout << "Login berhasil" << std::endl;
			return true;
		}
		else {
			return false;
		}
	}
	bool cekHapus(const int &index) {
		std::cout << std::endl;
		if ((accounts[index].username != "") && (accounts[index].password != "")) {
			accounts[index].username = "";
			accounts[index].password = "";
			std::cout << "Akun ditemukan" << std::endl;
			return true;
		}
		else {
			std::cout << "Akun tidak ditemukan" << std::endl;
			return false;
		}
	}
	void viewDaftar() {
		std::string username, password;
		std::cout << "\n==== MENU DAFTAR ====" << std::endl;
		
		std::cout << "Username : ";
		std::cin.ignore();
		getline(std::cin, username);

		std::cout << "Password : ";
		getline(std::cin, password);

		if (cekDaftar(username, password)) {
			std::cout << "Daftar berhasil" << std::endl;
		}
		else {
			std::cout << "Daftar gagal" << std::endl;
		}
	}
	void viewTambahAkun() {
		std::string username, password;
		std::cout << "\n==== MENU TAMBAH AKUN ====" << std::endl;

		std::cout << "Username : ";
		std::cin.ignore();
		getline(std::cin, username);

		std::cout << "Password : ";
		getline(std::cin, password);

		if (cekDaftar(username, password)) {
			std::cout << "Akun berhasil ditambahkan" << std::endl;
		}
		else {
			std::cout << "Akun gagal ditambahkan" << std::endl;
		}
	}
	void viewHapusAkun() {
		int index;
		std::cout << "\n==== MENU HAPUS AKUN ====" << std::endl;

		std::cout << "index: ";
		std::cin >> index;

		if (cekHapus(index)) {
			std::cout << "Akun berhasil dihapus" << std::endl;
		}
		else {
			std::cout << "Akun gagal dihapus" << std::endl;
		}
	}
	void loginPage() {
		while (true) {
			std::string pilihan;

			std::cout << "\n==== MENU ADMIN ====" << std::endl;
			std::cout << "1. Tambah akun" << std::endl;
			std::cout << "2. Hapus akun" << std::endl;
			std::cout << "3. Lihat data akun" << std::endl;
			std::cout << "4. Keluar" << std::endl << std::endl;
			std::cout << "Pilih [1/2/3/4] : ";
			std::cin >> pilihan;

			std::cout << std::endl;
			if (pilihan == "1") {
				viewTambahAkun();
			}
			else if (pilihan == "2") {
				viewHapusAkun();
			}
			else if (pilihan == "3") {
				printHashTable();
			}
			else if (pilihan == "4") {
				std::cout << "Terimakasih sudah menggunakan program ini!" << std::endl;
				break;
			}
			else {
				std::cout << "Pilihan tidak ditemukan" << std::endl;
			}
		}
	}
	void viewLogin() {
		std::string username, password;
		std::cout << "\n==== MENU LOGIN ====" << std::endl;

		std::cout << "Username : ";
		std::cin.ignore();
		getline(std::cin, username);

		std::cout << "Password : ";
		getline(std::cin, password);

		if (cekLogin(username, password)) {
			loginPage();
		}
		else {
			std::cout << "Login gagal" << std::endl;
		}
	}
	void printHashTable() {
		std::cout << std::endl << "Data Akun : " << std::endl << std::endl;
		std::cout << "|Index\t | Username\t | Password\t\t|" << std::endl << std::endl;
		for (int i = 0; i < 26; i++) {
			std::cout << "|" << i << "\t | " << (accounts[i].username == "" ? "kosong" : accounts[i].username) << "\t | " << (accounts[i].password == "" ? "kosong" : accounts[i].password) << "\t\t|" << std::endl;
		}
	}
	void welcome() {
		while (true) {
			std::string pilihan;

			std::cout << "\n==== SELAMAT DATANG ====" << std::endl;
			std::cout << "1. Daftar" << std::endl;
			std::cout << "2. Login" << std::endl;
			std::cout << "3. Keluar" << std::endl << std::endl;
			std::cout << "Pilih [1/2/3] : ";
			std::cin >> pilihan;

			std::cout << std::endl;
			if (pilihan == "1") {
				viewDaftar();
			}
			else if (pilihan == "2") {
				viewLogin();
			}
			else if (pilihan == "3") {
				std::cout << "Terimakasih sudah menggunakan program ini!" << std::endl;
				break;
			}
			else {
				std::cout << "Pilihan tidak ditemukan" << std::endl;
			}
		}
	}
};

int main() {
	hashing* login = new hashing(26);

	delete login;

	return 0;
}
