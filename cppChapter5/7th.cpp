//#include <iostream>
//
//using namespace std;
//
//class MyIntStack {
//	int p[10] = { 0 };
//	int tos=0;
//public:
//	MyIntStack() {};
//	bool push(int n) {
//		if (tos == 10) return false;
//		else p[tos++] = n; return true;
//	};
//	bool pop(int& n) {
//		if (tos == 0) return false;
//		else n = p[--tos]; return true;
//	};
//};
//int main(void) {
//	MyIntStack a;
//	for (int i = 0; i < 11; i++) {
//		if (a.push(i)) cout << i << ' ';
//		else cout << endl << i + 1 << " ��° stack full" << endl;
//	}
//	int n;
//	for (int i = 0; i < 11; i++) {
//		if (a.pop(n)) cout << n << ' ';
//		else cout << endl << i + 1 << " ��° stack empty";
//	}
//	cout << endl;
//	return 0;
//}