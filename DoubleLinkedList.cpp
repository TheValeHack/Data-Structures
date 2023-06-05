#include <iostream>
#include <string>

using namespace std;

// Data Structure
struct jkt48 {
	string nama, namaLengkap;
	int umur, gen;

	jkt48* next;
	jkt48* prev;
};

// Double Linked List Class
class LinkedList {
private:
	jkt48* head;
	jkt48* tail;
	int jumlahMember;
public:
	LinkedList(): head(nullptr), tail(nullptr), jumlahMember(0) {}
	~LinkedList() {
		jkt48* temp = head;
		while (temp != nullptr) {
			jkt48* del = temp;
			temp = temp->next;

			delete del;
		}
		head = nullptr;
		tail = nullptr;
	}

	// Add methods
	void addLast(const string &nama, const string &namaLengkap, const int &umur, const int &gen) {
		// Total Member Increment
		this->jumlahMember++;

		jkt48* member = new jkt48{nama, namaLengkap, umur, gen, nullptr, nullptr};

		if (head == nullptr) {
			head = member;
			tail = member;
		}
		else {
			tail->next = member;
			member->prev = tail;
			tail = member;
		}
	}
	void addFirst(const string& nama, const string& namaLengkap, const int& umur, const int& gen) {
		jkt48* member = new jkt48{ nama, namaLengkap, umur, gen, nullptr, nullptr };

		if (head == nullptr) {
			head = member;
			tail = member;
		}
		else {
			// Total Member Increment
			this->jumlahMember++;

			member->next = head;
			head->prev = member;
			head = member;
		}	
	}
	void addMiddle(const string& nama, const string& namaLengkap, const int& umur, const int& gen, const int &posisi) {
		if (posisi == 1) {
			this->addFirst(nama, namaLengkap, umur, gen);
		}
		else if (posisi == (this->jumlahMember + 1)) {
			this->addLast(nama, namaLengkap, umur, gen);
		}
		else if (posisi > this->jumlahMember) {
			cout << "(ERROR) Posisi (" << posisi << ") tidak boleh melebihi jumlah member (" << this->jumlahMember << ")!" << endl << endl;
		}
		else {
			// Total Member Increment
			this->jumlahMember++;

			int i = 1;

			jkt48* member = new jkt48{ nama, namaLengkap, umur, gen, nullptr, nullptr };
			jkt48* temp = head;

			while (i < posisi) {
				temp = temp->next;
				i++;
			}
			jkt48* beforeCur = temp->prev;
			member->next = temp;
			member->prev = beforeCur;
			beforeCur->next = member;
			temp->prev = member;
		}
	}


	// Delete methods
	void delLast() {
		// Total Member Decrement
		this->jumlahMember--;

		jkt48* del = tail;
		tail = tail->prev;
		tail->next = nullptr;

		delete del;
	}
	void delFirst() {
		// Total Member Decrement
		this->jumlahMember--;

		jkt48* del = head;
		head = head->next;
		head->prev = nullptr;

		delete del;
	}
	void delMiddle(const int &posisi) {
		if (posisi == 1) {
			this->delFirst();
		}
		else if (posisi == this->jumlahMember) {
			this->delLast();
		}
		else if (posisi > this->jumlahMember) {
			cout << "(ERROR) Posisi (" << posisi << ") tidak boleh melebihi jumlah member (" << this->jumlahMember << ")!" << endl << endl;
		}
		else {
			// Total Member Decrement
			this->jumlahMember--;

			int i = 1;

			jkt48* temp = head;

			while (i < posisi) {
				temp = temp->next;
				i++;
			}
			jkt48* beforeCur = temp->prev;
			jkt48* afterCur = temp->next;
			beforeCur->next = afterCur;
			afterCur->prev = beforeCur;

			delete temp;
		}
	}

	// Display method
	void display(bool rev) const {
		if (head == nullptr) {
			cout << "JKT48 belum memiliki member" << endl;
		}
		else {
			if (rev == true) {
				cout << "========= JKT48  =========" << endl;
				cout << "Jumlah member saat ini : " << this->jumlahMember << endl;
				cout << "Daftar member (reversee) : " << endl << endl;

				jkt48* temp = tail;
				while (temp != nullptr) {
					cout << "Nama Panggilan : " << temp->nama << endl;
					cout << "Nama Lengkap   : " << temp->namaLengkap << endl;
					cout << "Umur           : " << temp->umur << endl;
					cout << "Generasi       : " << temp->gen << endl;
					cout << endl;

					temp = temp->prev;
				}
			}
			else {
				cout << "========= JKT48  =========" << endl;
				cout << "Jumlah member saat ini : " << this->jumlahMember << endl;
				cout << "Daftar member : " << endl << endl;

				jkt48* temp = head;
				while (temp != nullptr) {
					cout << "Nama Panggilan : " << temp->nama << endl;
					cout << "Nama Lengkap   : " << temp->namaLengkap << endl;
					cout << "Umur           : " << temp->umur << endl;
					cout << "Generasi       : " << temp->gen << endl;
					cout << endl;

					temp = temp->next;
				}
			}	
		}
	}
};

int main() {
	LinkedList* jeketi = new LinkedList();

	// Test addLast Function
	jeketi->addLast("Zee", "Azizi Shafaa Asadel", 19, 7);
	jeketi->addLast("Fiony", "Fiony Alveria Tantri", 21, 8);
	jeketi->addLast("Michie", "Michelle Alexandra", 14, 11);
	jeketi->addLast("Kitty", "Angelina Christy", 18, 7);


	// Test addFirst Function
	jeketi->addFirst("Shani", "Shani Indira Natio", 23, 3);
	jeketi->addFirst("Freya", "Freyanashifa Jayawardhana", 17, 7);
	jeketi->addFirst("Ashel", "Adzana Shalifa", 18, 9);
	jeketi->addFirst("Kathrina", "Kathrina Bokem", 17, 10);

	// Test delLast Function
	jeketi->delLast();

	// Test delFirst Function
	jeketi->delFirst();

	// Test addMiddle
	jeketi->addMiddle("Feni", "Feni Fitriyanti", 23, 3, 3);
	jeketi->addMiddle("Jicel", "Giselle", 18, 10, 5);
	jeketi->addMiddle("Gendis", "Gendis Permatasari", 13, 11, 8);

	// Test delMiddle
	jeketi->delMiddle(8);
	jeketi->delMiddle(1);
	jeketi->delMiddle(3);
	jeketi->delMiddle(2);

	// Test diplay Function
	jeketi->display(false);
	jeketi->display(true);

	return 0;
}