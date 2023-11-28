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
		printf("종료합니다.");
		return 0;
	}
	else {
		if (hanoi_tower(from, to, what) == L) {
			printf("from 또는 what의 입력오류\n");
			return main();
		}
		else if (hanoi_tower(from, to, what) == M) {
			printf("to 또는 what의 입력오류\n");
			return main();
		}
		else if (hanoi_tower(from, to, what) == N) {
			printf("from 또는 to의 입력오류\n");
			return main();
		}
	}
	return 0;
}

int hanoi_tower(int from, int to, int what) {
	tries++;								//계산할때 1의자리에는 0,1
											//10의자리에는 0,1,2
											//100의자리에는 0,1,2,3		지켜서 계산코딩.
												//if ((A % 100) % 10 != c)
	// ((A % 100) % 10) > 1의자리, ((A % 100) / 10) > 10의자리,  (A / 100) > 100의자리
	if (C == 321) {
		printf("\n성공하였습니다.\n");
		printf("시도 횟수 : %d\n\n", tries);
		return FIN;
	}

	//from타워에서 링을 뽑을때 error판단
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

	//to에 링을 꽂을때 error판단
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

	//from에서 링 분리
	if (from == 1) {
		if ((A % 100) % 10 == 0) {				//1의자리 숫자가 0이면
			if ((A % 100) / 10 == 0) {				//10의자리 숫자가 0이면
				if (A / 100 == 1) {						//100의자리 숫자가 1이면
					A = A - 100;
				}
				else if (A / 100 == 2) {				//100의자리 숫자가 2이면
					A = A - 200;
				}
				else if (A / 100 == 3) {				//100의자리 숫자가 3이면
					A = A - 300;
				}
			}
			else if ((A % 100) / 10 == 1) {		//10의자리 숫자가 1이면
				A = A - 10;
			}
			else if ((A % 100) / 10 == 2) {		//10의자리 숫자가 2이면
				A = A - 20;
			}
		}
		else if ((A % 100) % 10 == 1) {		//1의자리 숫자가 1이면
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

	//to에 링 꽂기
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

	//타워 상태 표시 함수 호출
	position();

	//TOWER 3 는 C로 판별
	//321이 최종 목적이므로 321이 아닐시 재귀함수로 실행.
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
		return hanoi_tower(from, to, what);					//재귀
	}
	return 0;
}

//타워의 상태 표시
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
int slash(int b) {						//링 종류 판단 후 return
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