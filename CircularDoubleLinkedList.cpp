#include <iostream>
#include <string>

class Kampus {
private:
	struct mahasiswa {
		std::string nama, jurusan;
		int nim;

		mahasiswa* prev;
		mahasiswa* next;
	};
	mahasiswa* head;
	mahasiswa* tail;
	int jumlahMahasiswa;
public:
	Kampus(): head(nullptr), tail(nullptr), jumlahMahasiswa(0){}
	~Kampus() {
		if (head == nullptr) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			mahasiswa* temp = head;
			while (temp->next != head) {
				mahasiswa* del = temp;
				temp = temp->next;

				delete del;
			}
			head = nullptr;
			tail = nullptr;

			delete temp;
		}
	}

	void addLast(const std::string &nama, const std::string &jurusan, const int &nim) {
		this->jumlahMahasiswa++;

		mahasiswa* baru = new mahasiswa{nama, jurusan, nim, nullptr, nullptr};
		if (head == nullptr) {
			head = baru;
			tail = head;
			tail->next = head;
			tail->prev = head;
		}
		else {
			tail->next = baru;
			baru->prev = tail;
			tail = baru;
			tail->next = head;
			head->prev = tail;
		}
	}
	void addFirst(const std::string& nama, const std::string& jurusan, const int& nim) {
		this->jumlahMahasiswa++;

		mahasiswa* baru = new mahasiswa{ nama, jurusan, nim, nullptr, nullptr };
		if (head == nullptr) {
			head = baru;
			tail = head;
			tail->next = head;
			tail->prev = head;
		}
		else {
			head->prev = baru;
			baru->next = head;
			head = baru;
			head->prev = tail;
			tail->next = head;
		}
	}
	void addMiddle(const std::string& nama, const std::string& jurusan, const int& nim, const int& posisi) {
		if (posisi == 1) {
			this->addFirst(nama, jurusan, nim);
		}
		else if (posisi == (this->jumlahMahasiswa + 1)) {
			this->addLast(nama, jurusan, nim);
		}
		else if (posisi > (this->jumlahMahasiswa + 1)) {
			std::cout << "(ERROR) POSISI (" << posisi << ") TIDAK BOLEH MELEBIHI JUMLAH MAHASISWA (" << this->jumlahMahasiswa << ")" << std::endl << std::endl;
		}
		else {
			this->jumlahMahasiswa++;

			int i = 1;
			mahasiswa* baru = new mahasiswa{ nama, jurusan, nim };
			mahasiswa* cur = head;

			while (i < posisi) {
				cur = cur->next;
				i++;
			}
			mahasiswa* beforeMid = cur->prev;
			mahasiswa* afterMid = cur;
			baru->next = afterMid;
			baru->prev = beforeMid;
			beforeMid->next = baru;
			afterMid->prev = baru;
		}	
	}

	void delLast() {
		if (head == nullptr) {
			std::cout << "Kampus tutup" << std::endl;
		}
		else if (head == tail) {
			this->jumlahMahasiswa--;

			mahasiswa* del = head;
			head = nullptr;
			tail = nullptr;

			delete del;
		}
		else {
			this->jumlahMahasiswa--;

			mahasiswa* del = tail;
			tail = tail->prev;
			tail->next = head;
			head->prev = tail;

			delete del;
		}
	}
	void delFirst() {
		if (head == nullptr) {
			std::cout << "Kampus tutup" << std::endl;
		}
		else if (head == tail) {
			this->jumlahMahasiswa--;

			mahasiswa* del = head;
			head = nullptr;
			tail = nullptr;

			delete del;
		}
		else {
			this->jumlahMahasiswa--;

			mahasiswa* del = head;
			head = head->next;
			head->prev = tail;
			tail->next = head;

			delete del;
		}
	}
	void delMiddle(const int& posisi) {
		if (posisi == 1) {
			this->delFirst();
		}
		else if (posisi == this->jumlahMahasiswa) {
			this->delLast();
		}
		else if (posisi > this->jumlahMahasiswa) {
			std::cout << "(ERROR) POSISI (" << posisi << ") TIDAK BOLEH MELEBIHI JUMLAH MAHASISWA (" << this->jumlahMahasiswa << ")" << std::endl << std::endl;
		}
		else {
			this->jumlahMahasiswa--;

			int i = 1;
			mahasiswa* cur = head;

			while (i < posisi) {
				cur = cur->next;
				i++;
			}
			mahasiswa* del = cur;
			mahasiswa* beforeMid = cur->prev;
			mahasiswa* afterMid = cur->next;
			beforeMid->next = afterMid;
			afterMid->prev = beforeMid;

			delete del;
		}
	}

	void display(bool rev) const {
		if (head == nullptr) {
			std::cout << "Kampus tutup" << std::endl;
		}
		else {
			std::cout << "JUMLAH MAHASISWA : " << this->jumlahMahasiswa << std::endl << std::endl;
			if (rev == true) {
				mahasiswa* cur = tail;
				while (cur->prev != tail) {
					std::cout << "NAMA      : " << cur->nama << std::endl;
					std::cout << "JURUSAN   : " << cur->jurusan << std::endl;
					std::cout << "NIM       : " << cur->nim << std::endl << std::endl;

					cur = cur->prev;
				}
				std::cout << "NAMA      : " << cur->nama << std::endl;
				std::cout << "JURUSAN   : " << cur->jurusan << std::endl;
				std::cout << "NIM       : " << cur->nim << std::endl << std::endl;
			}
			else {
				mahasiswa* cur = head;
				while (cur->next != head) {
					std::cout << "NAMA      : " << cur->nama << std::endl;
					std::cout << "JURUSAN   : " << cur->jurusan << std::endl;
					std::cout << "NIM       : " << cur->nim << std::endl << std::endl;

					cur = cur->next;
				}
				std::cout << "NAMA      : " << cur->nama << std::endl;
				std::cout << "JURUSAN   : " << cur->jurusan << std::endl;
				std::cout << "NIM       : " << cur->nim << std::endl << std::endl;
			}
		}
	}
};

int main() {
	Kampus* ugm = new Kampus();

	ugm->addLast("Irfan Valerian", "TRPL", 99999999);
	ugm->addLast("Raihan Fadhlurrahman", "TRPL", 99999988);
	ugm->addLast("Muhammad Najwan Fadlilah", "TRPL", 9992999);
	ugm->addLast("Muhammad Najwan Fadlilah", "TRPL", 9992999);

	ugm->addFirst("Abiyyu Dewa Dzamallaqi", "TRM", 99996999);
	ugm->addFirst("Luthfi Aqeela", "TRM", 99996999);
	ugm->addFirst("Luthfi Aqeela", "TRM", 99996999);

	ugm->delLast();

	ugm->delFirst();

	ugm->addMiddle("Freyanashifa Jayawardhana", "Seni", 99999999, 3);

	ugm->delMiddle(1);
	ugm->delMiddle(4);

	ugm->display(false);

	return 0;
}