#include <iostream>
#include <string>


class LinkedList {
private:
	struct jkt48 {
		std::string nama, namaLengkap;
		int gen;

		jkt48* next;
	};
	jkt48* head;
	jkt48* tail;
	int jumlahMember;
public:
	LinkedList(): head(nullptr), tail(nullptr), jumlahMember(0) {}
	~LinkedList() {
		jkt48* temp = head;
		while (temp->next != head) {
			jkt48* del = temp;
			temp = temp->next;

			delete del;
		}
		head = nullptr;
		tail = nullptr;

		delete temp;
	}
	void addLast(const std::string& nama, const std::string& namaLengkap, const int& gen) {
		this->jumlahMember++;

		jkt48* member = new jkt48{ nama, namaLengkap, gen, nullptr };

		if (head == nullptr) {
			head = member;
			tail = head;
			head->next = tail;
		}
		else {
			member->next = head;
			tail->next = member;
			tail = member;
		}
	}
	void addFirst(const std::string& nama, const std::string& namaLengkap, const int& gen) {
		this->jumlahMember++;

		jkt48* member = new jkt48{ nama, namaLengkap, gen, nullptr };
		member->next = head;
		tail->next = member;
		head = member;
	}
	void addMiddle(const std::string& nama, const std::string& namaLengkap, const int& gen, const int &posisi) {
		if (posisi == 1) {
			this->addFirst(nama, namaLengkap, gen);
		} 
		else if(posisi == (this->jumlahMember + 1)){
			this->addLast(nama, namaLengkap, gen);
		}
		else if (posisi > (this->jumlahMember + 1)) {
			std::cout << "(ERROR) Posisi (" << posisi << ") tidak boleh melebih jumlah member (" << this->jumlahMember << ")" << std::endl << std::endl;
		}
		else {
			this->jumlahMember++;

			jkt48* member = new jkt48{ nama, namaLengkap, gen, nullptr };
			jkt48* cur = head;
			int i = 1;
			while (i < (posisi-1)) {
				cur = cur->next;
				i++;
			}
			jkt48* beforeMid = cur;
			jkt48* afterMid = cur->next;
			beforeMid->next = member;
			member->next = afterMid;
		}
	}

	void delFirst() {
		if (head == nullptr) {
			std::cout << "Member belum ada" << std::endl;
		}
		else if (head == tail) {
			this->jumlahMember--;

			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {
			this->jumlahMember--;

			jkt48* del = head;
			head = head->next;
			tail->next = head;

			delete del;
		}
	}
	void delLast() {
		if (head == nullptr) {
			std::cout << "Member belum ada" << std::endl;
		}
		else if (head == tail) {
			this->jumlahMember--;

			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {
			this->jumlahMember--;

			jkt48* cur = head;
			while (cur->next != tail) {
				cur = cur->next;
			}
			jkt48* del = tail;
			tail = cur;
			tail->next = head;

			delete del;
		}
	}
	void delMiddle(const int& posisi) {
		if (posisi == 1) {
			this->delFirst();
		}
		else if (posisi == this->jumlahMember) {
			this->delLast();
		}
		else if (posisi > this->jumlahMember) {
			std::cout << "(ERROR) Posisi (" << posisi << ") tidak boleh melebih jumlah member (" << this->jumlahMember << ")" << std::endl << std::endl;
		}
		else {
			this->jumlahMember--;

			jkt48* cur = head;
			int i = 1;
			while (i < (posisi - 1)) {
				cur = cur->next;
				i++;
			}
			jkt48* del = cur->next;
			cur->next = cur->next->next;

			delete del;
		}
	}

	void display() const {
		if (head == nullptr) {
			std::cout << "Member belum ada" << std::endl;
		}
		else {
			std::cout << "Jumlah member : " << this->jumlahMember << std::endl << std::endl;

			jkt48* cur = head;
			
			while (cur->next != head) {
				std::cout << "Nama Panggilan : " << cur->nama << std::endl;
				std::cout << "Nama Lengkap   : " << cur->namaLengkap << std::endl;
				std::cout << "Generasi       : " << cur->gen << std::endl;
				std::cout << std::endl;

				cur = cur->next;
			}
			std::cout << "Nama Panggilan : " << cur->nama << std::endl;
			std::cout << "Nama Lengkap   : " << cur->namaLengkap << std::endl;
			std::cout << "Generasi       : " << cur->gen << std::endl;
			std::cout << std::endl;
		}
	}
};

int main() {
	LinkedList* jeketi = new LinkedList();
	
	jeketi->addLast("Fiony", "Fiony Alveria Tantri", 8);
	jeketi->addLast("Zee", "Azizi Shafaa Asadel", 7);


	jeketi->delFirst();

	jeketi->addFirst("Freya", "Freyanashifa Jayawardhana", 7);
	jeketi->addFirst("Freyanaa", "Raden Roro Freyanashifa Jayawardhana", 7);
	jeketi->addFirst("Freyanashifa", "Raden Roro Freyanashifa Jayawardhana", 7);

	jeketi->delLast();

	jeketi->addFirst("Istriku, Freyanashifa Jayawardhana", "Istri", 7);

	jeketi->addMiddle("Zee", "Azizi Shafaa Asadel", 7, 2);
	jeketi->addMiddle("Zee6", "Azizi Shafaa Asadel", 7, 4);

	jeketi->delMiddle(2);
	jeketi->delMiddle(3);

	jeketi->display();

	return 0;
}
