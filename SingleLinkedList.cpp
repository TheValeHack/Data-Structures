#include <iostream>
#include <string>

using namespace std;

// Data Struct
struct Hero {
	string nama, role, damage;

	int skill, tahunRilis;

	Hero* next;
};

// Linked List Class
class LinkedList {
private:
	Hero* head;
	Hero* tail;

	int dataCount;
public:
	LinkedList():head(nullptr), tail(nullptr), dataCount(0){}
	~LinkedList() {
		Hero* temp = head;
		while (temp != nullptr) {
			Hero* del = temp;
			temp = temp->next;

			delete del;
		}
	}

	// Add Methods
	void addLast(const string &nama, const string &role, const string &damage, const int &skill, const int &tahunRilis) {
		// Increase Data Count
		this->dataCount++;

		Hero* hero = new Hero{nama, role, damage, skill, tahunRilis, nullptr};
		if (head == nullptr) {
			head = hero;
			tail = hero;
		}
		else {
			tail->next = hero;
			tail = hero;
		}
	}
	void addFirst(const string &nama, const string &role, const string &damage, const int &skill, const int &tahunRilis) {
		// Increase Data Count
		this->dataCount++;

		Hero* hero = new Hero{ nama, role, damage, skill, tahunRilis, head };
		head = hero;
	}
	void addMiddle(const string &nama, const string &role, const string &damage, const int &skill, const int &tahunRilis, int posisi) {
		if (posisi == 1) {
			this->addFirst(nama, role, damage, skill, tahunRilis);
		}
		else if (posisi > this->dataCount) {
			printf("(error) Position (%i) cant be above the amount of the data (%i)\n", posisi, this->dataCount);
		}
		else {
			// Increase Data Count
			this->dataCount++;

			Hero* hero = new Hero{ nama, role, damage, skill, tahunRilis, nullptr };
			Hero* temp = head;
			int i = 1;

			while (i < (posisi - 1)) {
				temp = temp->next;
				i++;
			}
			hero->next = temp->next;
			temp->next = hero;
		}
	}


	// Delete methods
	void delLast() {
		// Decrease Data Count
		this->dataCount--;

		Hero* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		Hero* del = tail;
		tail = temp;
		tail->next = nullptr;

		delete del;
	}
	void delFirst() {
		// Decrease Data Count
		this->dataCount--;

		Hero* del = head;
		head = head->next;

		delete del;
	}
	void delMiddle(int posisi) {
		if (posisi == 1) {
			this->delFirst();
		}
		else if (posisi == this->dataCount) {
			this->delLast();
		}
		else if (posisi > this->dataCount) {
			printf("(error) Position (%i) cant be above the amount of the data (%i)\n", posisi, this->dataCount);
		}
		else {
			// Decrease Data Count
			this->dataCount--;

			Hero* temp = head;
			Hero* beforeDel = nullptr;
			int i = 1;

			while (i < posisi) {
				if (i == (posisi - 1)) {
					beforeDel = temp;
				}
				temp = temp->next;
				i++;
			}
			Hero* afterDel = temp->next;
			Hero* del = temp;
			beforeDel->next = afterDel;

			delete del;
		}
	}

    // Change methods
	void changeFirst(const string &nama, const string &role, const string &damage, const int &skill, const int &tahunRilis) {
		head->nama = nama;
		head->role = role;
		head->damage = damage;
		head->skill = skill;
		head->tahunRilis = tahunRilis;
	}
	void changeLast(const string &nama, const string &role, const string &damage, const int &skill, const int &tahunRilis) {
		tail->nama = nama;
		tail->role = role;
		tail->damage = damage;
		tail->skill = skill;
		tail->tahunRilis = tahunRilis;
	}
	void changeMiddle(const string &nama, const string &role, const string &damage, const int &skill, const int &tahunRilis, int posisi) {
		if (posisi == 1) {
			this->changeFirst(nama, role, damage, skill, tahunRilis);
		}
		else if (posisi == this->dataCount) {
			this->changeLast(nama, role, damage, skill, tahunRilis);
		}
		else if (posisi > this->dataCount) {
			printf("(error) Position (%i) cant be above the amount of the data (%i)\n", posisi, this->dataCount);
		}
		else {

			Hero* temp = head;
			int i = 1;

			while (i < posisi) {
				temp = temp->next;
				i++;
			}
			temp->nama = nama;
			temp->role = role;
			temp->damage = damage;
			temp->skill = skill;
			temp->tahunRilis = tahunRilis;
		}
	}


	// Display Data method
	void displayData() const {
		cout << "Jumlah Hero : " << this->dataCount << endl;
		cout << "List Hero :" << endl << endl;
		Hero* temp = head;
		while (temp != nullptr) {
			cout << "Nama Hero           :  " << temp->nama << endl;
			cout << "Role Hero           :  " << temp->role << endl;
			cout << "Jenis Damage Hero   :  " << temp->damage << endl;
			cout << "Jumlah Skill Hero   :  " << temp->skill << endl;
			cout << "Tahun Rilis Hero    :  " << temp->tahunRilis << endl;
			cout << endl;

			temp = temp->next;
		}
	}
};

int main() {
	LinkedList* emel = new LinkedList();

	// Test addLast method
	emel->addLast("Alucard", "Fighter / Assassin", "Physical", 3, 2016);
	emel->addLast("Miya", "Marksman", "Physical", 3, 2016);
	emel->addLast("Layla", "Marksman", "Physical", 3, 2016);

	// Test addFisrt method
	emel->addFirst("Zilong", "Fighter", "Physical", 3, 2018);
	emel->addFirst("Xavier", "Mage", "Magic", 3, 2021);

	// Test addMiddle method
	emel->addMiddle("Cyclop", "Mage", "Magic", 3, 2019, 5);
	emel->addMiddle("Pharsa", "Mage", "Magic", 4, 2020, 3);

	// Tes delLast method
	emel->delLast();

	// Tes delFirst method
	emel->delFirst();

	// Tes delMiddle method
	emel->delMiddle(2);

	// Test changeLast method
	emel->changeLast("Balmond", "Fighter", "Physical", 3, 2017);

	// Test changeFisrt method
	emel->changeFirst("Yu Zhong", "Fighter", "Physical", 4, 2021);

	// Test changeMiddle method
	emel->changeMiddle("Diggie", "Support", "Magic", 4, 2020, 2);
	emel->changeMiddle("Moskov", "Marksman", "Physical", 4, 2019, 3);

	emel->addLast("Alucard", "Fighter / Assassin", "Physical", 3, 2016);
	emel->addLast("Miya", "Marksman", "Physical", 3, 2016);
	emel->addLast("Layla", "Marksman", "Physical", 3, 2016);

	// Display Data
	emel->displayData();

	return 0;
}