#include <iostream>
#include <vector>

using namespace std;

class Matriks {
public:
	vector<vector<float>> matriks;

	Matriks(vector<vector<float>> value): matriks(value){}
	Matriks(): Matriks({{0}}){}

	Matriks operator+(Matriks rval) {
		Matriks res;
		vector<vector<float>> addRes;

		for (int i = 0; i < rval.matriks.size(); i++) {
			vector<float> temp;
			for (int j = 0; j < rval.matriks[i].size(); j++) {
				float addVal = this->matriks[i][j] + rval.matriks[i][j];
				temp.push_back(addVal);
			}
			addRes.push_back(temp);
		}

		res.matriks = addRes;
		return res;
	}

	bool operator==(Matriks rval) {
		for (int i = 0; i < rval.matriks.size(); i++) {
			for (int j = 0; j < rval.matriks[i].size(); j++) {
				if(this->matriks[i][j] != rval.matriks[i][j]) return false;
			}
		}
		return true;
	}

	void printMatriks() {
		for (int i = 0; i < this->matriks.size(); i++) {
			for (int j = 0; j < this->matriks[i].size(); j++) {
				cout << this->matriks[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	vector<vector<float>> satuValues = { {1, 2, 3}, {4, 5, 6} };
	Matriks satu(satuValues);

	vector<vector<float>> duaValues = { {7, 8, 9}, {10, 11, 12} };
	Matriks dua(duaValues);


	Matriks mirip({ { 8,10,12 }, { 14,16, 18 } });

	Matriks hasil = satu + dua;

	if (hasil == mirip) {
		cout << "sama" << endl;
	}
	else {
		cout << "beda" << endl;
	}

	hasil.printMatriks();

	return 0;
}
