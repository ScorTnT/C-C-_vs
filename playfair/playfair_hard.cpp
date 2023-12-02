#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define key "assasinator"
#define pair "m/a"
#define txtfile "test.txt"

class Playfair {
	char mTable[25];
	string mKey;
	string mPair;
public:
	Playfair(string mKey, string mPair);
	void makeTable();
	void showTable();
	string makeEncryption(string mEncryption);
};

Playfair::Playfair(string mKey, string mPair) {
	this->mKey = mKey;
	if (mPair[0] > mPair[2]) {	
		string temp;
		temp[0] = mPair[0];
		mPair[0] = mPair[2];
		mPair[2] = temp[0];
	}
	this->mPair = mPair;
}
bool equalCheck(int a, int b) {
	bool result = (a == b);
	return result;
}
void Playfair::makeTable() {
	// mKey와 mPair를 이용하여 mTable을 만드세요. (5 X 5 로 표현하시오)
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	string cpKey = mKey;
	cpKey.append(alpha);
	int n = cpKey.length();
	// 중복 문자 공백으로 변경
	for (int t = 0; t < n - 1; t++) for (int k = t + 1; k < n; k++) if (cpKey[k] == cpKey[t]||cpKey[k]==this->mPair[2]) cpKey[k] = ' ';
	// 공백 제거
	cpKey.erase(remove(cpKey.begin(), cpKey.end(), ' '), cpKey.end());
	for (int k = 0; k < cpKey.length(); k++) this->mTable[k] = cpKey[k];
}

void Playfair::showTable() {
	// mTable에 있는 값들을 5 X 5 로 화면에 출력하시오.
	cout << "- - table" << endl;
	for (int l = 0; l < 5; l++) {
		for (int k = 0; k < 5; k++) {
			cout << mTable[l * 5 + k];
			if (mTable[l * 5 + k] == mPair[0]) cout << mPair.substr(1, 2);
			cout << '\t';
		}
		cout << endl;
	}
	cout << "- - - - -" << endl;
}

string Playfair::makeEncryption(string mEncryption) {
	int Bflag[2] = { 0 };
	// 공백 제거
	mEncryption.erase(remove(mEncryption.begin(), mEncryption.end(), ' '), mEncryption.end());
	//cout << mEncryption << endl; 

	//if string include <.>, remove <.>
	if (mEncryption[mEncryption.length() - 1] == '.') mEncryption = mEncryption.substr(0, mEncryption.length() - 1);
	//be careful for assasinator 같은 문장이 mEncryption 으로 들어옴
	int l = mEncryption.length();
	//replace upper-letter to lower-letter.
	//for (int k = 0; k < l; k++) if ('A' <= mEncryption[k] && mEncryption[k] <= 'Z') mEncryption[k] += 32;
	//insert x between same letter.
	for (int k = 0; k < l; k++) {
		if ((mEncryption[k] == mEncryption[k + 1])) {
			mEncryption.insert(k + 1, "x");
			l = mEncryption.length();
			k++;
		}
		if (mEncryption[k] == mPair[0] || (mEncryption[k] + 32) == mPair[0] || (mEncryption[k] - 32) == mPair[0]) {
			if (mEncryption[k+1] == mPair[2] || (mEncryption[k+1] + 32) == mPair[2] || (mEncryption[k+1] - 32) == mPair[2]) {
				mEncryption.insert(k + 1, "x");
				l = mEncryption.length();
				k++;
			}
		}
		if (mEncryption[k] == mPair[2] || (mEncryption[k] + 32) == mPair[2] || (mEncryption[k] - 32) == mPair[2]) {
			if (mEncryption[k + 1] == mPair[0] || (mEncryption[k + 1] + 32) == mPair[0] || (mEncryption[k + 1] - 32) == mPair[0]) {
				mEncryption.insert(k + 1, "x");
				l = mEncryption.length();
				k++;
			}
		}
	}

	//if .length() = odd, append x.
	if (mEncryption.length() % 2 == 1) mEncryption.append("x");

	//middle checking mEncryption string.
	//cout << mEncryption << endl;

	//start encryption
	l = mEncryption.length();
	int a = 0, b = 0, c = 0, d = 0, x = 0, y = 0;
	string before;
	string after;
	for (int k = 0; k < l / 2; k++) {
		before = mEncryption.substr(k * 2, 2);
		for (int t = 0; t < 2; t++) if ('A' <= before[t] && before[t] <= 'Z') {
			before[t] += 32;
			Bflag[t] = 1;
		}
		//cout << before << endl;
		for (int p = 0; p < 25; p++) {
			if (c != 0 && d != 0)break;
			//pair check
			if (mTable[p] == mPair[0]) {
				if (mPair[2] == before[0]) c = p;
				if (mPair[2] == before[1]) d = p;
			}
			if (mTable[p] == before[0]) c = p;
			if (mTable[p] == before[1]) d = p;

			// c,d = index.
		}
		b = c / 5; a = c % 5;
		y = d / 5; x = d % 5;
		//cout << "before[0] " << b << " " << a << endl;
		//cout << "before[1] " << y << " " << x << endl;

		//replace letter use index .
		//if (y == b && x == a); // no exist same letter, it solved by insert x routine.

		//case : pair -> flag 
		int pairF = 0;
		if (before[0] == mPair[2] || before[1] == mPair[2]) {
			pairF = 1;
			for (int k = 0; k < 25; k++) if (mTable[k] == mPair[0]) mTable[k] = mPair[2];
		}

		//case : same line. 
		if (y == b || x == a) {
			if (y == b) {
				//in mTable, two letters exist next to each other.
				if (x > a) { a++; x = (x + 1) % 5; }
				else { x++; a = (a + 1) % 5; }
			}
			else if (x == a) {
				if (y > b) { b++; y = (y + 1) % 5; }
				else { y++; b = (b + 1) % 5; }
			}
		}
		else { //case : different line.
			int temp;
			temp = a;
			a = x;
			x = temp;
		}
		before[0] = mTable[b * 5 + a];
		before[1] = mTable[y * 5 + x];
		for (int t = 0; t < 2; t++) if (Bflag[t] == 1) before[t] -= 32;

		//cout << "after: " << before << endl;
		after.append(before);
		c = 0; d = 0;
		//cout << endl;
		if (pairF == 1) for (int k = 0; k < 25; k++) if (mTable[k] == mPair[2]) mTable[k] = mPair[0];
		for (int t = 0; t < 2; t++) Bflag[t] = 0;
	}
	cout << "after = " << after << endl;
	return after;
}
string gets_f() {
	ifstream fin;
	fin.open(txtfile);
	if (!fin) {
		cout << "error" << endl;
		return 0;
	}
	string result;

	fin.seekg(0, ios::end);
	// 그리고 그 위치를 읽는다. (파일의 크기)
	int size = fin.tellg();
	// 그 크기의 문자열을 할당한다.
	result.resize(size);
	// 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
	fin.seekg(0, ios::beg);
	// 파일 전체 내용을 읽어서 문자열에 저장한다.
	fin.read(&result[0], size);	// char 주소의 값을 줘야하는 첫 인자이기에 string의 주소를 전달
	// 줄넘김 \n 제거
	result.erase(remove(result.begin(), result.end(), '\n'), result.end());
	//cout << result << endl;
	return result;
} 
int main() {
	Playfair pfair(key, pair);
	pfair.makeTable();
	pfair.showTable();
	string encrypt, buffer,endSen;
	buffer = gets_f();
	cout << "before : " << buffer << endl;
	while (encrypt!=buffer) {
		encrypt = buffer.substr(0, buffer.find("."));
		if (buffer.find(".")==-1)break;
		buffer = buffer.substr(buffer.find(".") + 1);
		//cout << "before :" << encrypt << endl;
		//cout << "en : " << encrypt << endl << "bu : "<< buffer << endl;
		endSen += pfair.makeEncryption(encrypt);	//what if, in hard mode put string that ends <.>
		endSen += ".";
	};
	cout << endSen << endl;
}