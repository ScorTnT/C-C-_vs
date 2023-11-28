/*
#include <stdio.h>
#define FIN 123123
#define L 13				//from, what error
#define M 23				//to, what error
#define N 12				//form || to error

int hanoi_tower(int from, int to, int what);
int position();
int T1(int a);
int T2(int a);
int T3(int a);
int slash(int b);
static int A = 321, B = 0, C = 0, tries = 0;

int main(void) {
	position();
	int from, to, what;
	printf("(ex) FROM: 2, TO: 3, WHAT:1");
	printf("WHAT:(  /  )=1,( /// )=2,(/////)=3\n");
	printf("If you want Re press 9 on from or to or what");
	printf("\nFROM:");
	scanf("%d", &from);
	printf("TO:");
	scanf("%d", &to);
	printf("WHAT:");
	scanf("%d", &what);
	printf("\n");
	if (from == 9 || to == 9 || what == 9) {
		printf("\n\n\nrestart!\n");
		A = 321;
		B = 0;
		C = 0;
		tries = 0;
		return main();
	}
	hanoi_tower(from, to, what);

	if (hanoi_tower(from, to, what) == FIN) {
		printf("�����մϴ�.");
		return 0;
	}
	else {
		if (hanoi_tower(from, to, what) == L) {
			printf("from �Ǵ� what�� �Է¿���\n");
			return main();
		}
		else if (hanoi_tower(from, to, what) == M) {
			printf("to �Ǵ� what�� �Է¿���\n");
			return main();
		}
		else if (hanoi_tower(from, to, what) == N) {
			printf("from �Ǵ� to�� �Է¿���\n");
			return main();
		}
	}
	return 0;
}

int hanoi_tower(int from, int to, int what) {
	tries++;								//����Ҷ� 1���ڸ����� 0,1
											//10���ڸ����� 0,1,2
											//100���ڸ����� 0,1,2,3		���Ѽ� ����ڵ�.
												//if ((A % 100) % 10 != c)
	// ((A % 100) % 10) > 1���ڸ�, ((A % 100) / 10) > 10���ڸ�,  (A / 100) > 100���ڸ�
	if (C == 321) {
		printf("\n�����Ͽ����ϴ�.\n");
		printf("�õ� Ƚ�� : %d\n\n", tries);
		return FIN;
	}

	//fromŸ������ ���� ������ error�Ǵ�
	if (from == 1) {
		if ((A % 100) % 10 == 0) {
			if ((A % 100) / 10 == 0) {
				if (A / 100 == 0) {
					return L;
				}
				else if (A / 100 != what) {
					return L;
				}
			}
			else if ((A % 100) / 10 != what) {
				return L;
			}
		}
		else if ((A % 100) % 10 != what) {
			return L;
		}
	}
	else if (from == 2) {
		if ((B % 100) % 10 == 0) {
			if ((B % 100) / 10 == 0) {
				if (B / 100 == 0) {
					return L;
				}
				else if (B / 100 != what) {
					return L;
				}
			}
			else if ((B % 100) / 10 != what) {
				return L;
			}
		}
		else if ((B % 100) % 10 != what) {
			return L;
		}
	}
	else if (from == 3) {
		if ((C % 100) % 10 == 0) {
			if ((C % 100) / 10 == 0) {
				if (C / 100 == 0) {
					return L;
				}
				else if (C / 100 != what) {
					return L;
				}
			}
			else if ((C % 100) / 10 != what) {
				return L;
			}
		}
		else if ((C % 100) % 10 != what) {
			return L;
		}
	}

	//to�� ���� ������ error�Ǵ�
	if (to == 1) {
		if ((A % 100) % 10 == 0) {
			if ((A % 100) / 10 == 0) {
				if (A / 100 != 0) {
					if (A / 100 < what) {
						return M;
					}
				}
			}
			else {
				if ((A % 100) / 10 < what) {
					return M;
				}
			}
		}
		else {
			return M;
		}
	}
	else if (to == 2) {
		if ((B % 100) % 10 == 0) {
			if ((B % 100) / 10 == 0) {
				if (B / 100 != 0) {
					if (B / 100 < what) {
						return M;
					}
				}
			}
			else {
				if ((B % 100) / 10 < what) {
					return M;
				}
			}
		}
		else {
			return M;
		}
	}
	else if (to == 3) {
		if ((C % 100) % 10 == 0) {
			if ((C % 100) / 10 == 0) {
				if (C / 100 != 0) {
					if (C / 100 < what) {
						return M;
					}
				}
			}
			else {
				if ((C % 100) / 10 < what) {
					return M;
				}
			}
		}
		else {
			return M;
		}
	}

	//from���� �� �и�
	if (from == 1) {
		if ((A % 100) % 10 == 0) {				//1���ڸ� ���ڰ� 0�̸�
			if ((A % 100) / 10 == 0) {				//10���ڸ� ���ڰ� 0�̸�
				if (A / 100 == 1) {						//100���ڸ� ���ڰ� 1�̸�
					A = A - 100;
				}
				else if (A / 100 == 2) {				//100���ڸ� ���ڰ� 2�̸�
					A = A - 200;
				}
				else if (A / 100 == 3) {				//100���ڸ� ���ڰ� 3�̸�
					A = A - 300;
				}
			}
			else if ((A % 100) / 10 == 1) {		//10���ڸ� ���ڰ� 1�̸�
				A = A - 10;
			}
			else if ((A % 100) / 10 == 2) {		//10���ڸ� ���ڰ� 2�̸�
				A = A - 20;
			}
		}
		else if ((A % 100) % 10 == 1) {		//1���ڸ� ���ڰ� 1�̸�
			A = A - 1;
		}
	}
	else if (from == 2) {
		if ((B % 100) % 10 == 0) {
			if ((B % 100) / 10 == 0) {
				if (B / 100 == 1) {
					B = B - 100;
				}
				else if (B / 100 == 2) {
					B = B - 200;
				}
				else if (B / 100 == 3) {
					B = B - 300;
				}
			}
			else if ((B % 100) / 10 == 1) {
				B = B - 10;
			}
			else if ((B % 100) / 10 == 2) {
				B = B - 20;
			}
		}
		else if ((B % 100) % 10 == 1) {
			B = B - 1;
		}
	}
	else if (from == 3) {
		if ((C % 100) % 10 == 0) {
			if ((C % 100) / 10 == 0) {
				if (C / 100 == 1) {
					C = C - 100;
				}
				else if (C / 100 == 2) {
					C = C - 200;
				}
				else if (C / 100 == 3) {
					C = C - 300;
				}
			}
			else if ((C % 100) / 10 == 1) {
				C = C - 10;
			}
			else if ((C % 100) / 10 == 2) {
				C = C - 20;
			}
		}
		else if ((C % 100) % 10 == 1) {
			C = C - 1;
		}
	}
	else {
		return N;
	}

	//to�� �� �ȱ�
	if (to == 1) {
		if (A / 100 == 0) {
			A = A + (100 * what);
		}
		else {
			if (((A % 100) / 10) == 0) {
				A = A + (10 * what);
			}
			else {
				if ((A % 100) % 10 == 0) {
					A = A + what;
				}
			}
		}
	}
	else if (to == 2) {
		if (B / 100 == 0) {
			B = B + (100 * what);
		}
		else {
			if (((B % 100) / 10) == 0) {
				B = B + (10 * what);
			}
			else {
				if ((B % 100) % 10 == 0) {
					B = B + what;
				}
			}
		}
	}
	else if (to == 3) {
		if (C / 100 == 0) {
			C = C + (100 * what);
		}
		else {
			if (((C % 100) / 10) == 0) {
				C = C + (10 * what);
			}
			else {
				if ((C % 100) % 10 == 0) {
					C = C + what;
				}
			}
		}
	}
	else {
		return N;
	}

	//Ÿ�� ���� ǥ�� �Լ� ȣ��
	position();

	//TOWER 3 �� C�� �Ǻ�
	//321�� ���� �����̹Ƿ� 321�� �ƴҽ� ����Լ��� ����.
	if (C != 321) {
		int from, to, what;
		printf("(ex) FROM: 2, TO: 3, WHAT:1");
		printf("WHAT:  /  =1, ///  =2,/////=3");
		printf("\nFROM:");
		scanf("%d", &from);
		printf("TO:");
		scanf("%d", &to);
		printf("WHAT:");
		scanf("%d", &what);
		printf("\n");
		return hanoi_tower(from, to, what);					//���
	}
	return 0;
}

//Ÿ���� ���� ǥ��
int position() {
	printf("TOWER 1\n");
	for (int l = 3; l > 0; l--) {
		T1(l);
		printf("\n");
	}
	printf("\n\nTOWER 2\n");
	for (int m = 3; m > 0; m--) {
		T2(m);
		printf("\n");
	}
	printf("\n\nTOWER 3\n");
	for (int n = 3; n > 0; n--) {
		T3(n);
		printf("\n");
	}
	return 0;
}
int T1(int a) {							//TOWER 1
	if (a == 3) {
		slash((A % 100) % 10);
	}
	else if (a == 2) {
		slash((A % 100) / 10);
	}
	else if (a == 1) {
		slash(A / 100);
	}
	return 0;
}
int T2(int a) {							//TOWER 2
	if (a == 3) {
		slash((B % 100) % 10);
	}
	else if (a == 2) {
		slash((B % 100) / 10);
	}
	else if (a == 1) {
		slash(B / 100);
	}
	return 0;
}
int T3(int a) {							//TOWER 3
	if (a == 3) {
		slash((C % 100) % 10);
	}
	else if (a == 2) {
		slash((C % 100) / 10);
	}
	else if (a == 1) {
		slash(C / 100);
	}
	return 0;
}
int slash(int b) {						//�� ���� �Ǵ� �� return
	if (b == 3) {
		return printf("/////");
	}
	else if (b == 2) {
		return printf(" /// ");
	}
	else if (b == 1) {
		return printf("  /  ");
	}
	else if (b == 0) {
		return printf("  l  ");
	}
	return 0;
}
*/