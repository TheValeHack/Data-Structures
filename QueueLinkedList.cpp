#include <iostream>

// Class
class antrian {
private:
	struct orang {
		std::string nama, pekerjaan;
		int umur;

		orang* next;
	};
	orang* head;
	orang* tail;
	int jumlahOrang;
	int maks;
public:
	antrian(const int& maksimal) : maks(maksimal), head(nullptr), tail(nullptr) {}
	~antrian() {
		orang* temp = head;
		while (temp != nullptr) {
			orang* del = temp;
			temp = temp->next;

			delete del;
		}
		head = nullptr;
		tail = nullptr;
	}
	bool isFull() const {
		return jumlahOrang >= maks;
	}
	bool isEmpty() const {
		return jumlahOrang == 0;
	}
	void enqueue(const std::string& nama, const std::string& pekerjaan, const int& umur) {
		if (isFull()) {
			std::cout << "Antrian sudah penuh!" << std::endl << std::endl;
		}
		else {
			orang* baru = new orang{nama, pekerjaan, umur, nullptr};
			if (isEmpty()) {
				head = baru;
				tail = baru;
			}
			else {
				tail->next = baru;
				tail = baru;
			}
			jumlahOrang++;
		}
	}
	void dequeue() {
		if (isEmpty()) {
			std::cout << "Antrian kosong!" << std::endl;
		}
		else {
			jumlahOrang--;
			if (head == tail) {
				orang* del = head;
				head = nullptr;
				tail = nullptr;

				delete del;
			}
			else {
				orang* del = head;
				head = head->next;

				delete del;
			}
		}
	}
	void destroy() {
		if (isEmpty()) {
			std::cout << "Antrian kosong!" << std::endl;
		}
		else {
			orang* temp = head;
			while (temp != nullptr) {
				orang* del = temp;
				temp = temp->next;

				delete del;
			}
			head = nullptr;
			tail = nullptr;
			jumlahOrang = 0;
		}
	}

	void display() const {
		if (isEmpty()) {
			std::cout << "Antrian kosong!" << std::endl;
		}
		else {
			orang* cur = head;
			int i = 1;
			while (i <= maks) {
				std::cout << "NO. ANTRIAN  : " << i << std::endl;

				if (cur != nullptr) {
					std::cout << "NAMA         : " << cur->nama << std::endl;
					std::cout << "PEKERJAAN    : " << cur->pekerjaan << std::endl;
					std::cout << "UMUR         : " << cur->umur << std::endl;
					cur = cur->next;
				}
				else {
					std::cout << "(Antrian belum diisi)" << std::endl;
				}
				std::cout << std::endl;
				i++;
			}
		}
	}
};


// Main Function
int main() {
	antrian* sembako = new antrian(5);

	sembako->enqueue("Rosidah", "Ibu Rumah Tangga", 49);
	sembako->enqueue("Sumanto", "Food Vlogger", 41);
	sembako->enqueue("Cristiano Ronaldo", "Pemain Bola", 38);
	sembako->enqueue("Marcus Rashford", "Penjual Sate", 25);

	sembako->dequeue();

	sembako->display();

	delete sembako;

	return 0;
}
