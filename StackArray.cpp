#include <iostream>

// Class
class stek {
private:
	int maks;
	int top;
	std::string* arrayFilm;
	int arrayLoop;
public:
	stek(const int& maksimal): maks(maksimal), top(0), arrayLoop(0){
		arrayFilm = new std::string[maks];
	}
	~stek() {
		delete[] arrayFilm;
	}
	bool isEmpty() {
		if (top == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isFull() {
		if (top == maks) {
			return true;
		}
		else {
			return false;
		}
	}
	void push(std::string film) {
		if (!this->isFull()) {
			arrayFilm[top] = film;
			top++;
		}
		else {
			std::cout << "(error) DATA PENUH" << std::endl << std::endl;
		}
	}
	void pop() {
		if (this->isEmpty()) {
			std::cout << "Data masih kosong!" << std::endl;
		}
		else {
			arrayFilm[top - 1] = "";
			top--;
		}
	}
	void peek(const int& posisi) {
		if (top == 0) {
			std::cout << "Data masih kosong!" << std::endl;
		}
		else if ((posisi > top) || (posisi < 0)) {
			std::cout << "(error) POSISI SALAH" << std::endl << std::endl;
		}
		else {
			std::cout << "Data ke-" << (posisi) << " : " << arrayFilm[top-posisi] << std::endl << std::endl;
		}
	}
	void change(const int& posisi, std::string filmBaru) {
		if (top == 0) {
			std::cout << "Data masih kosong!" << std::endl;
		}
		else if ((posisi > top) || (posisi < 0)) {
			std::cout << "(error) POSISI SALAH" << std::endl << std::endl;
		}
		else {
			arrayFilm[top - posisi] = filmBaru;
		}
	}
	void destroy() {
		for (int i = (top - 1); i >= 0; i--) {
			arrayFilm[i] = "";
		}
		top = 0;
	}
	void display() {
		if (top == 0) {
			std::cout << "Data masih kosong!" << std::endl;
		}
		else {
			for (int i = (top - 1); i >= 0; i--) {
				std::cout << arrayFilm[i] << std::endl;
			}
		}
	}
};

int main() {
	stek* film = new stek(5);

	film->push("Interstellar");
	film->push("Shawshank Redemption");
	film->push("About Time");
	film->push("Our Beloved Summer");

	film->pop();
	
	film->push("The Secret Life of Walter Mitty");
	film->push("Taxi Driver");
	film->push("Miracle in Cell No.7");

	film->peek(4);

	film->change(1, "Hacksaw Ridge");
	film->change(5, "Pee Mak");
	film->change(2, "Memories of Murder");

	film->destroy();

	film->display();

	delete film;

	return 0;
}
