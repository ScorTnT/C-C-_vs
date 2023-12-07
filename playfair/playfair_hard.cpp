#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define key "speaker"
#define pair "k/a"
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
	cout << "- - - - - - - table - - - - - - -" << endl;
	for (int l = 0; l < 5; l++) {
		for (int k = 0; k < 5; k++) {
			cout << mTable[l * 5 + k];
			if (mTable[l * 5 + k] == mPair[0]) cout << mPair.substr(1, 2);
			cout << '\t';
		}
		cout << endl;
	}
	cout << "- - - - - - - - - - - - - - - - -" << endl << endl;
}

string Playfair::makeEncryption(string mEncryption) {
	int Bflag[2] = { 0 };
	// 공백 제거
	mEncryption.erase(remove(mEncryption.begin(), mEncryption.end(), ' '), mEncryption.end());
	int l = mEncryption.length();
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
	cout << "put x : " << mEncryption << endl;

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

		//case : pair -> flag 
		int pairF = 0;
		if (before[0] == mPair[2] || before[1] == mPair[2]) {
			pairF = 1;
			for (int k = 0; k < 25; k++) if (mTable[k] == mPair[0]) mTable[k] = mPair[2];
		}

		//case : same line. 
		if (y == b || x == a) {
			if (y == b) {
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
		after.append(before);
		c = 0; d = 0;
		if (pairF == 1) for (int k = 0; k < 25; k++) if (mTable[k] == mPair[2]) mTable[k] = mPair[0];
		for (int t = 0; t < 2; t++) Bflag[t] = 0;
	}
	cout << "after = " << after << endl;
	return after;
}
string gets_f() {
	ifstream fin;
	fin.open(txtfile);
	// txtfile을 연다.
	if (!fin) {
		cout << "error" << endl;
		return 0;
	}
	string result;
	fin.seekg(0, ios::end);

	int size = fin.tellg();
	result.resize(size);
	// 그 크기의 문자열을 할당한다.
	fin.seekg(0, ios::beg);
	// 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
	// 파일 전체 크기 만큼을 읽어서 문자열에 저장한다.
	fin.read(&result[0], size);	// char 주소의 값을 줘야하는 첫 인자이기에 string의 주소를 전달
	// 줄넘김 \n 제거
	result.erase(remove(result.begin(), result.end(), '\n'), result.end());
	//cout << result << endl;
	return result;
} 
int playfairF() {
	string keyin, pairin;
	cout << "key 입력(종료:0) : ";
	cin >> keyin;
	if (strcmp(&keyin[0], "0") == 0) return 0;
	cout << "pair 입력 ( ex: a/b ) : ";
	cin >> pairin;
	Playfair pfair(keyin, pairin);
	pfair.makeTable();
	pfair.showTable();
	string encrypt, buffer, endSen;
	buffer = gets_f();
	cout << "before : " << buffer << endl;
	while (encrypt != buffer) {
		encrypt = buffer.substr(0, buffer.find("."));
		if (buffer.find(".") == -1) {
			if (encrypt[0] == '\0')
				break;
		}
		else buffer = buffer.substr(buffer.find(".") + 1);
		cout << "before : " << encrypt << endl;
		//cout << "en : " << encrypt << endl << "bu : "<< buffer << endl;
		endSen += pfair.makeEncryption(encrypt);	//what if, in hard mode put string that ends <.>
		endSen += ".";
	};
	cout << "full encrytion : " << endSen << endl;
	return 1;
}
int main() {
	while (playfairF() != 0);
}