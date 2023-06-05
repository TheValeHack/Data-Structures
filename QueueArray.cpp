#include <iostream>

// Enqueue
// Dequeue
// isFull
// isEmpty
// Count
// Destroy
// Display

class antrian {
private:
	std::string* antri;
	int maks;
	int depan;
	int belakang;
public:
	antrian(const int& maksimal) : maks(maksimal), depan(0), belakang(0) {
		antri = new std::string[maksimal];
	}
	~antrian() {
		maks = 0;
		depan = 0;
		belakang = 0;

		delete[] antri;
	}
	bool isFull() {
		return belakang >= maks;
	}
	bool isEmpty() {
		return belakang == 0;
	}
	int count() const {
		return belakang;
	}
	void enqueue(const std::string &nama) {
		if (isFull()) {
			std::cout << "Antrian sudah penuh!" << std::endl << std::endl;
		}
		else {
			if (isEmpty()) depan++;
			antri[belakang] = nama;

			belakang++;
		}
	}
	void dequeue() {
		if (isEmpty()) {
			std::cout << "Antrian masih kosong!" << std::endl;
		}
		else {
			if (count() == 1) depan--;
			belakang--;

			for (int i = 0; i < belakang; i++) {
				std::string antrianBaru = antri[i + 1];
				antri[i] = antrianBaru;
			}
		}
	}
	void destroy() {
		if (isEmpty()) {
			std::cout << "Antrian masih kosong!" << std::endl;
		}
		else {
			for (int i = 0; i < belakang; i++) {
				antri[i] = "";
			}
			belakang = 0;
			depan = 0;
		}
	}
	void display() {
		if (isEmpty()) {
			std::cout << "Antrian masih kosong!" << std::endl;
		}
		else {
			std::cout << "Jumlah Antrian : " << count() << std::endl;
			std::cout << "Depan          : " << depan << ". " << antri[depan-1] << std::endl;
			std::cout << "Belakang       : " << belakang << ". " << antri[belakang-1] << std::endl << std::endl;
			for (int i = 0; i < count();i++) {
				if (i != 0) std::cout << " - ";
				std::cout << antri[i];
			}
			std::cout << std::endl;
		}
	}
};

int main() {
	antrian* mall = new antrian(5);

	mall->enqueue("Brizan");
	mall->enqueue("Irfan");
	mall->enqueue("Raihan");
	mall->enqueue("Freya");
	mall->enqueue("Dewa");

	mall->dequeue();

	mall->display();

	delete mall;

	return 0;
}
