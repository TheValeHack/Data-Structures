#include <iostream>

class gym {
private:
	struct machine {
		std::string name, muscleTargeted;
		int quantity;

		machine* prev;
		machine* next;
	};
	
	machine* head;
	machine* tail;
	int machineCount;
	int totalMachine;
public:
	gym(const int &maks) : head(nullptr), tail(nullptr), machineCount(0), totalMachine(maks){}

	bool isFull() const {
		if (machineCount == totalMachine) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isEmpty() const {
		if ((machineCount == 0) || (head == nullptr)) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isPositionCorrect(const int& position) const {
		if ((position > totalMachine) || (position < 1)) {
			return false;
		}
		else {
			return true;
		}
	}
	void push(const std::string& name, const std::string& muscleTargeted, const int& quantity) {
		if (isFull()) {
			std::cout << "GYM PENUH!" << std::endl << std::endl;
		}
		else {
			machineCount++;

			machine* newMachine = new machine{ name, muscleTargeted, quantity, nullptr, nullptr };
			if (isEmpty()) {
				head = newMachine;
				tail = newMachine;
			}
			else {
				newMachine->prev = tail;
				tail->next = newMachine;
				tail = newMachine;
			}
		}	
	}
	void pop() {
		if (isEmpty()) {
			std::cout << "DATA MASIH KOSONG" << std::endl << std::endl;
		}
		else {
			machineCount--;

			if (head == tail) {
				delete head;

				head = nullptr;
				tail = nullptr;
			}
			else {
				machine* del = tail;
				tail = tail->prev;
				tail->next = nullptr;

				delete del;
			}
		}
	}
	void change(const std::string& name, const std::string& muscleTargeted, const int& quantity, const int& position) {
		if (!isPositionCorrect(position)) {
			std::cout << "POSISI () TIDAK BOLEH MELEBIHI TOTAL ALAT ()" << std::endl << std::endl;
		}
		else if (isEmpty()) {
			std::cout << "DATA MASIH KOSONG" << std::endl << std::endl;
		}
		else {
			machine* cur = tail;
			int i = 1;
			while (i < position) {
				cur = cur->prev;
				i++;
			}
			cur->name = name;
			cur->muscleTargeted = muscleTargeted;
			cur->quantity = quantity;
		}
	}
	void destroy() {
		machineCount = 0;
		machine* cur = head;

		while (cur != nullptr) {
			machine* del = cur;
			cur = cur->next;

			delete del;
		}
		head = nullptr;
		tail = nullptr;
	}
	void peek(const int& position) const {
		if (!isPositionCorrect(position)) {
			std::cout << "POSISI () TIDAK BOLEH MELEBIHI TOTAL ALAT ()" << std::endl << std::endl;
		}
		else if (isEmpty()) {
			std::cout << "DATA MASIH KOSONG" << std::endl << std::endl;
		}
		else {
			machine* cur = tail;
			int i = 1;
			while (i < position) {
				cur = cur->prev;
				i++;
			}
			std::cout << "=======================(PEEK NO." << position << ")=======================" << std::endl;
			std::cout << "MACHINE NAME      : " << cur->name << std::endl;
			std::cout << "MUSCLE TARGETED   : " << cur->muscleTargeted << std::endl;
			std::cout << "MACHINE QUANTITY  : " << cur->quantity << std::endl;
			std::cout << "=========================================================" << std::endl;
			std::cout << std::endl;
		}
	}
	void display() const {
		if (isEmpty()) {
			std::cout << "DATA MASIH KOSONG" << std::endl << std::endl;
		}
		else {
			machine* cur = tail;
			while (cur != nullptr) {
				std::cout << "MACHINE NAME      : " << cur->name << std::endl;
				std::cout << "MUSCLE TARGETED   : " << cur->muscleTargeted << std::endl;
				std::cout << "MACHINE QUANTITY  : " << cur->quantity << std::endl;
				std::cout << std::endl;

				cur = cur->prev;
			}
		}	
	}

	~gym() {
		destroy();
	}
};

int main() {
	gym* roni = new gym(6);

	roni->push("Dumbell 5kg", "Biceps", 8);
	roni->push("Lat PullDown", "Back", 3);
	roni->push("Barbell 50Kg", "Biceps", 5);
	roni->push("Leg Press", "Leg", 4);
	roni->push("Dumbell 10kg", "Biceps", 8);
	roni->push("Dumbell 15kg", "Biceps", 8);
	roni->push("Dumbell 20kg", "Biceps", 8);


	roni->change("Lateral PullDown", "Back & Shoulder", 4, 2);
	roni->change("Leg Press", "Calves & Thigh", 4, 3);

	roni->peek(4);

	roni->display();

	delete roni;

	return 0;
}
