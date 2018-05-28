#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int M = 10;//row
const int N = 10;//column
int board[M][N];
//---------------------
//    0: empty
//    1: player1
//    2: player2
//---------------------
void init()
{
	int i, j;
	for (i = 0; i < M; i++)
	for (j = 0; j < N; j++)
		board[i][j] = 0;
}
void write()
{
	ofstream file;
	file.open("board.txt");
	int i, j;
	for (i = 0; i < M; i++)
	for (j = 0; j < N; j++)
		file << board[i][j] << endl;
	file.close();
}
void read()
{
	ifstream file;
	file.open("board.txt");
	int i, j;
	for (i = 0; i < M; i++)
	for (j = 0; j < N; j++)
		file >> board[i][j];
	file.close();
}
void show(){
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			cout << board[i][j];
		cout << endl;
	}
}
bool set(int i, int j, int m)
{
	if (0 == board[i][j])
	{
		board[i][j] = m;
		return true;
	}
	else
		return false;
}
void play(int m)
{
	int x = rand() % M;
	int y = rand() % N;
	int sum[10] = { 0 };
	srand(time(0));
	bool a = false;

	if (m == 1){

		///////////////////////������ 
		//1//////11~30//37~38//41~58

		if (m = 1 && a == false){
			//2//11�����G�_�G
			if (a == false){
				for (int i = 0; i < 10; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 0 && board[i][j + 3] == 1 && board[i][j + 4] == 1){
							set(i, j + 2, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//12�����G�_�G
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j < 10; j++){
						if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 0 && board[i + 3][j] == 1 && board[i + 4][j] == 1){
							set(i + 2, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//13�k�פG�_�G
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1){
							set(i + 2, j + 2, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//14���פG�_�G
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 9; j >= 4; j -= 1){
						if (board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 1){
							set(i + 2, j - 2, m);
							//board[i + 2][j - 2] = 2;
							a = true;
							break;

						}
					}
				}
			}
			////�߱�T�_�@15~30
			//*2//27�����T�_�@
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						//�T�_�@
						if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 0 && board[i][j + 4] == 1){
							set(i, j + 3, m);
							//board[i][j + 3] = 2;
							a = true;
							break;
						}
						//�@�_�T
						if (board[i][j] == 1 && board[i][j + 1] == 0 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 1){
							set(i, j + 1, m);
							//board[i][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*2//28�����T�_�@
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						//���T�_�@
						if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 0 && board[i + 4][j] == 1){
							set(i + 3, j, m);
							//board[i + 3][j] = 2;
							a = true;
							break;
						}
						//���@�_�T
						if (board[i][j] == 1 && board[i + 1][j] == 0 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 1){
							set(i + 1, j, m);
							//board[i + 1][j] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*2//29�k�פT�_�@
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						//���T�_�@			
						if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 1){
							set(i + 3, j + 3, m);
							//board[i + 3][j + 3] = 2;
							a = true;
							break;
						}
						//���@�_�T			
						if (board[i][j] == 1 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1){
							set(i + 1, j + 1, m);
							//board[i + 1][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*2//30���צ��T�_�@
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 9; j >= 4; j -= 1){
						//���T�_�@			
						if (board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 1){
							set(i + 3, j - 3, m);
							//board[i + 3][j - 3] = 2;
							a = true;
							break;
						}
						//���@�_�T			
						if (board[i][j] == 1 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 1){
							set(i + 1, j - 1, m);
							//board[i + 1][j - 1] = 2;
							a = true;
							break;
						}
					}
				}
			}

			//////////
			//2//37�ץk���|
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						if (i <= 5 && j <= 5 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1){
							//������
							if (board[i - 1][j - 1] == 2 && board[i + 4][j + 4] == 0){
								set(i + 4, j + 4, m);
								//board[i + 4][j + 4] = 2;
								a = true;
								break;
							}
							//���k��
							if (board[i - 1][j - 1] == 0 && board[i + 4][j + 4] == 2){
								set(i - 1, j - 1, m);
								//board[i - 1][j - 1] = 2;
								a = true;
								break;
							}
						}
					}
				}
			}
			//2//38�ץ����|
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 8; j >= 4; j -= 1){
						if (i <= 5 && j >= 4 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1){
							if (board[i - 1][j + 1] == 2 && board[i + 4][j - 4] == 0){
								set(i + 4, j - 4, m);
								//board[i + 4][j - 4] = 2;
								a = true;
								break;
							}
							if (board[i - 1][j + 1] == 0 && board[i + 4][j - 4] == 2){
								set(i - 1, j + 1, m);
								//board[i - 1][j + 1] = 2;
								a = true;
								break;
							}
						}
					}
				}
			}
			//2//41�W���I0,0~0,9�����s�|
			int i0 = 0;
			if (a == false){
				for (int j = 0; j < 10; j++){
					if (a == true)
						break;
					i0 = 0;
					sum[0] = 0;
					while (i0 < 4){
						if (board[i0][j] == 1 && i0 < 3){
							i0++;
							sum[0]++;
						}
						else if (board[3][j] == 1 && board[4][j] == 0 && sum[0] == 3){
							set(4, j, m);
							//board[4][j] = 2;
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//2//42�U���I9,0~9,9�����s�|
			int i1 = 0;
			if (a == false){
				for (int j = 0; j < 10; j++){
					if (a == true)
						break;
					i1 = 9;
					sum[1] = 0;
					while (i1 > 5){
						if (board[i1][j] == 1 && i1 > 6){
							i1 -= 1;
							sum[1]++;
						}
						else if (board[6][j] == 1 && board[5][j] == 0 && sum[1] == 3){
							set(5, j, m);
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//2//43�����I0,0~9,0�����s�|
			int j0 = 0;
			if (a == false){
				for (int i = 0; i < 10; i++){
					if (a == true)
						break;
					j0 = 0;
					sum[2] = 0;
					while (j0 < 4){
						if (board[i][j0] == 1 && j0 < 3){
							j0++;
							sum[2]++;
						}
						else if (board[i][3] == 1 && board[i][4] == 0 && sum[2] == 3){
							set(i, 4, m);
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//2//44�k���I9,0~9,9�����s�|
			int j1 = 0;
			if (a == false){
				for (int i = 0; i < 10; i++){
					if (a == true)
						break;
					j1 = 9;
					sum[3] = 0;
					while (j1 > 5){
						if (board[i][j1] == 1 && j1 > 6){
							j1 -= 1;
							sum[3]++;
						}
						else if (board[i][6] == 1 && board[i][5] == 0 && sum[3] == 3){
							set(i, 5, m);
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//2//45���W���I0,0~0,5�ץk�U�s�|
			int i2 = 0, j2 = 0;
			if (a == false){
				for (int j = 0; j < 6; j++){
					if (a == true)
						break;
					i2 = 0;
					j2 = j;
					sum[4] = 0;
					while (i2 < 4 && j2 < j + 4){
						if (board[i2][j2] == 1 && i2 < 3 && j2 < j + 3){
							i2++;
							j2++;
							sum[4]++;
						}
						else if (board[3][j2] == 1 && board[4][j2 + 1] == 0 && sum[4] == 3){
							set(4, j2 + 1, m);
							a = true;
							break;
						}
						else break;
					}
				}
			}

			//2//46�k�W���I0,0~0,4�ץ��U�s�|
			int i3 = 0, j3 = 0;
			if (a == false){
				for (int j = 9; j > 4; j -= 1){
					if (a == true)
						break;
					i3 = 0;
					j3 = j;
					sum[5] = 0;
					while (i3 < 4 && j3 > j - 4){
						if (board[i3][j3] == 1 && i3<3 && j3>j - 3){
							i3++;
							j3 -= 1;
							sum[5]++;
						}
						else if (board[3][j3] == 1 && board[4][j3 - 1] == 0 && sum[5] == 3){
							set(4, j3 - 1, m);
							//board[4][j3 - 1] = 2;
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//2//47���U���I9,0~9,5�ץk�W�s�|
			int i4 = 0, j4 = 0;
			if (a == false){
				for (int j = 0; j < 6; j++){
					if (a == true)
						break;
					i4 = 9;
					j4 = j;
					sum[6] = 0;
					while (i4 > 5 && j4 < j + 4){
						if (board[i4][j4] == 1 && i4>6 && j4 < j + 3){
							i4 -= 1;
							j4++;
							sum[6]++;
						}
						else if (board[6][j4] == 1 && board[5][j4 + 1] == 0 && sum[6] == 3){
							set(5, j4 + 1, m);
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//2//48�k�U���I9,9~9,4�ץ��W�s�|
			int i5 = 0, j5 = 0;
			if (a == false){
				for (int j = 9; j > 4; j -= 1){
					if (a == true)
						break;
					i5 = 9;
					j5 = j;
					sum[7] = 0;
					while (i5 > 5 && j5 > j - 4){
						if (board[i5][j5] == 1 && i5 > 6 && j5 > j - 3){
							i5 -= 1;
							j5 -= 1;
							sum[7]++;
						}
						else if (board[6][j5] == 1 && board[5][j5 - 1] == 0 && sum[7] == 3){
							set(5, j5 - 1, m);
							//board[5][j5 - 1] = 2;
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//2//49���W��ץk�U�s�|
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 0; j++){
						if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
							set(i + 4, j + 4, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//50�k�W��ץ��U�s�|
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 9; j <= 9; j++){
						if (board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
							set(i + 4, j - 4, m);
							a = true;
							break;
						}
					}
				}
			}

			//2//51���U��ץk�W�s�|
			if (a == false){
				for (int i = 4; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 0; j++){
						if (board[i][j] == 1 && board[i - 1][j + 1] == 1 && board[i - 2][j + 2] == 1 && board[i - 3][j + 3] == 1 && board[i - 4][j + 4] == 0){
							set(i - 4, j + 4, m);
							a = true;
							break;
						}
					}
				}
			}

			//2//52�k�U��ץ��W�s�|
			if (a == false){
				for (int i = 4; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 9; j <= 9; j++){
						if (board[i][j] == 1 && board[i - 1][j - 1] == 1 && board[i - 2][j - 2] == 1 && board[i - 3][j - 3] == 1 && board[i - 4][j - 4] == 0){
							set(i - 4, j - 4, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//53�������|
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 8; j++){
						//������
						if (board[i][j - 1] == 2 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
							set(i, j + 4, m);
							a = true;
							break;
						}
						//���k��
						if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 2){
							set(i, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//54�������|
			if (a == false){
				for (int i = 1; i <= 8; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						//���W��
						if (board[i - 1][j] == 2 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
							set(i + 4, j, m);
							a = true;
							break;
						}
						//���U��
						if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 2){
							set(i - 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//////////////////////��Ĺ��
			//2//55�������|
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
							set(i, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//56�������|
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
							set(i - 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//57�k�׬��|
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						if (board[i - 1][j - 1] == 0 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
							set(i - 1, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//58���׬��|
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 8; j >= 4; j -= 1){
						if (board[i - 1][j + 1] == 0 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
							set(i - 1, j + 1, m);
							//board[i + 2][j - 2] = 2;
							a = true;
							break;
						}
					}
				}
			}

		}


		//1/////////////////////���u
		//////11~30//37~38//41~58
		//1//11�������G�_�G
		if (a == false){
			for (int i = 0; i < 10; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 5; j++){
					if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 0 && board[i][j + 3] == 2 && board[i][j + 4] == 2){
						set(i, j + 2, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//12�������G�_�G
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j < 10; j++){
					if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 0 && board[i + 3][j] == 2 && board[i + 4][j] == 2){
						set(i + 2, j, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//13�k�׬��G�_�G
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 5; j++){
					if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2){
						set(i + 2, j + 2, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//14���׬��G�_�G
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 9; j >= 4; j -= 1){
					if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2){
						set(i + 2, j - 2, m);
						//board[i + 2][j - 2] = 2;
						a = true;
						break;
					}
				}
			}
		}
		///1//////////3-1//
		////�߱�T�_�@15~30
		//*1//27�����T�_�@
		if (a == false){
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 5; j++){
					//�T�_�@
					if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0 && board[i][j + 4] == 2){
						set(i, j + 3, m);
						//board[i][j + 3] = 2;
						a = true;
						break;
					}
					//�@�_�T
					if (board[i][j] == 2 && board[i][j + 1] == 0 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2){
						set(i, j + 1, m);
						//board[i][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*1//28�����T�_�@
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					//���T�_�@
					if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 0 && board[i + 4][j] == 2){
						set(i + 3, j, m);
						//board[i + 3][j] = 2;
						a = true;
						break;
					}
					//���@�_�T
					if (board[i][j] == 2 && board[i + 1][j] == 0 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2){
						set(i + 1, j, m);
						//board[i + 1][j] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*1//29�k�פT�_�@
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 5; j++){
					//���T�_�@			
					if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 2){
						set(i + 3, j + 3, m);
						//board[i + 3][j + 3] = 2;
						a = true;
						break;
					}
					//���@�_�T			
					if (board[i][j] == 2 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2){
						set(i + 1, j + 1, m);
						//board[i + 1][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*1//30���צ��T�_�@
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 9; j >= 4; j -= 1){
					//���T�_�@			
					if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 2){
						set(i + 3, j - 3, m);
						//board[i + 3][j - 3] = 2;
						a = true;
						break;
					}
					//���@�_�T			
					if (board[i][j] == 2 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2){
						set(i + 1, j - 1, m);
						//board[i + 1][j - 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		////////
		//1//37�ץk���|
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					if (i <= 5 && j <= 5 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2){
						//���W��
						if (board[i - 1][j - 1] == 1 && board[i + 4][j + 4] == 0){
							set(i + 4, j + 4, m);
							//board[i + 4][j + 4] = 2;
							a = true;
							break;
						}
						//���U��
						if (board[i - 1][j - 1] == 0 && board[i + 4][j + 4] == 1){
							set(i - 1, j - 1, m);
							//board[i - 1][j - 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
		}
		//1//38�ץ����|
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 8; j >= 4; j -= 1){
					if (i <= 5 && j >= 4 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2){
						//���W��
						if (board[i - 1][j + 1] == 1 && board[i + 4][j - 4] == 0){
							set(i + 4, j - 4, m);
							//board[i + 4][j - 4] = 2;
							a = true;
							break;
						}
						//���U��
						if (board[i - 1][j + 1] == 0 && board[i + 4][j - 4] == 1){
							set(i - 1, j + 1, m);
							//board[i - 1][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
		}
		//1//41�W���I0,0~0,9�����s�|
		int i0 = 0;
		if (a == false){
			for (int j = 0; j < 10; j++){
				if (a == true)
					break;
				i0 = 0;
				sum[0] = 0;
				while (i0 < 4){
					if (board[i0][j] == 2 && i0 < 3){
						i0++;
						sum[0]++;
					}
					else if (board[3][j] == 2 && board[4][j] == 0 && sum[0] == 3){
						set(4, j, m);
						//board[4][j] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//1//42�U���I9,0~9,9�����s�|
		int i1 = 0;
		if (a == false){
			for (int j = 0; j < 10; j++){
				if (a == true)
					break;
				i1 = 9;
				sum[1] = 0;

				while (i1 > 5){
					if (board[i1][j] == 2 && i1 > 6){
						i1 -= 1;
						sum[1]++;
					}
					else if (board[6][j] == 2 && board[5][j] == 0 && sum[1] == 3){
						set(5, j, m);
						//board[5][j] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//1//43�����I0,0~9,0�����s�|
		int j0 = 0;
		if (a == false){
			for (int i = 0; i < 10; i++){
				if (a == true)
					break;
				j0 = 0;
				sum[2] = 0;
				while (j0 < 4){
					if (board[i][j0] == 2 && j0 < 3){
						j0++;
						sum[2]++;
					}
					else if (board[i][3] == 2 && board[i][4] == 0 && sum[2] == 3){
						set(i, 4, m);
						//board[i][4] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//1//44�k���I0,9~9,9�����s�|
		int j1 = 0;
		if (a == false){
			for (int i = 0; i < 10; i++){
				if (a == true)
					break;
				j1 = 9;
				sum[3] = 0;
				while (j1 > 5){
					if (board[i][j1] == 2 && j1 > 6){
						j1 -= 1;
						sum[3]++;
					}
					else if (board[i][6] == 2 && board[i][5] == 0 && sum[3] == 3){
						set(i, 5, m);
						//board[i][5] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//1//45���W���I0,0~0,5�ץk�U�s�|
		int i2 = 0, j2 = 0;
		if (a == false){
			for (int j = 0; j < 6; j++){
				if (a == true)
					break;
				i2 = 0;
				j2 = j;
				sum[4] = 0;
				while (i2 < 4 && j2 < j + 4){
					if (board[i2][j2] == 2 && i2 < 3 && j2 < j + 3){
						i2++;
						j2++;
						sum[4]++;
					}
					else if (board[3][j2] == 2 && board[4][j2 + 1] == 0 && sum[4] == 3){
						set(4, j2 + 1, m);
						//board[4][j2 + 1] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}

		//1//46�k�W���I0,9~0,5�ץ��U�s�|
		int i3 = 0, j3 = 0;
		if (a == false){
			for (int j = 9; j > 4; j -= 1){
				if (a == true)
					break;
				i3 = 0;
				j3 = j;
				sum[5] = 0;
				while (i3 < 4 && j3 > j - 4){
					if (board[i3][j3] == 2 && i3<3 && j3>j - 3){
						i3++;
						j3 -= 1;
						sum[5]++;
					}
					else if (board[3][j3] == 2 && board[4][j3 - 1] == 0 && sum[5] == 3){
						set(4, j3 - 1, m);
						//board[4][j3 - 1] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//1//47���U���I9,0~9,5�ץk�W�s�|
		int i4 = 0, j4 = 0;
		if (a == false){
			for (int j = 0; j < 6; j++){
				if (a == true)
					break;
				i4 = 9;
				j4 = j;
				sum[6] = 0;
				while (i4 > 5 && j4 < j + 4){
					if (board[i4][j4] == 2 && i4>6 && j4 < j + 3){
						i4 -= 1;
						j4++;
						sum[6]++;
					}
					else if (board[6][j4] == 2 && board[5][j4 + 1] == 0 && sum[6] == 3){
						set(5, j4 + 1, m);
						//board[5][j4 + 1] = 1;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//1//48�k�U���I9,9~9,4�ץ��W�s�|
		int i5 = 0, j5 = 0;
		if (a == false){
			for (int j = 9; j > 4; j -= 1){
				if (a == true)
					break;
				i5 = 9;
				j5 = j;
				sum[7] = 0;
				while (i5 > 5 && j5 > j - 4){
					if (board[i5][j5] == 2 && i5 > 6 && j5 > j - 3){
						i5 -= 1;
						j5 -= 1;
						sum[7]++;
					}
					else if (board[6][j5] == 2 && board[5][j5 - 1] == 0 && sum[7] == 3){
						set(5, j5 - 1, m);
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//1//49���W��ץk�U�s�|
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 0; j++){
					if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
						set(i + 4, j + 4, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//50�k�W��ץ��U�s�|
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 9; j <= 9; j++){
					if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
						set(i + 4, j - 4, m);
						a = true;
						break;
					}
				}
			}
		}

		//1//51���U��ץk�W�s�|
		if (a == false){
			for (int i = 4; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 0; j++){
					if (board[i][j] == 2 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 0){
						set(i - 4, j + 4, m);
						a = true;
						break;
					}
				}
			}
		}

		//1//52�k�U��ץ��W�s�|
		if (a == false){
			for (int i = 4; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 9; j <= 9; j++){
					if (board[i][j] == 2 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 0){
						set(i - 4, j - 4, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//53�������|
		if (a == false){
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 8; j++){
					//������
					if (board[i][j - 1] == 1 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
						set(i, j + 4, m);
						a = true;
						break;
					}
					//���k��
					if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 1){
						set(i, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}

		//1//54�������|
		if (a == false){
			for (int i = 1; i <= 8; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					//���W��
					if (board[i - 1][j] == 1 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
						set(i + 4, j, m);
						a = true;
						break;
					}
					//���U��
					if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 1){
						set(i - 1, j, m);
						a = true;
						break;
					}
				}
			}
		}
		////////��Ĺ��/////�̥��u���M�S�ϤF
		//1//55�������|
		if (a == false){
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
						set(i, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//56�������|
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
						set(i - 1, j, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//57�k�׬��|
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					if (board[i - 1][j - 1] == 0 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
						set(i - 1, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//58���׬��|
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 8; j >= 4; j -= 1){
					if (board[i - 1][j + 1] == 0 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
						set(i - 1, j + 1, m);
						//board[i + 2][j - 2] = 2;
						a = true;
						break;
					}
				}
			}
		}






		///////////////////////////////��u
		//////1~10////31~36//39~40//
		//1//1������
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 2; j <= 7; j++){
					if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j] == 2 && board[i + 1][j] == 0 && board[i - 1][j] == 0 && board[i + 1][j - 2] == 0 && board[i + 1][j + 2] == 0 && board[i + 3][j] == 0){
						set(i + 1, j, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//2�פ���
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (board[i][j] == 2 && board[i][j + 2] == 2 && board[i + 2][j] == 2 && board[i + 2][j + 2] == 2 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i - 1][j + 3] == 0 && board[i + 3][j - 1] == 0 && board[i + 3][j + 3] == 0){
						set(i + 1, j + 1, m);
						a = true;
						break;
					}
				}
			}
		}

		//1//3��T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (board[i][j] == 2 && board[i][j + 2] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 1] == 2 && board[i][j + 1] == 0 && board[i - 1][j + 1] == 0 && board[i][j - 1] == 0 && board[i][j + 3] == 0 && board[i + 3][j + 1] == 0){
						set(i, j + 1, m);
						a = true;
						break;
					}
				}
			}
		}

		//1//4��T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 2; j <= 7; j++){
					if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j - 1] == 2 && board[i + 2][j + 1] == 2 && board[i + 2][j] == 0 && board[i - 1][j] == 0 && board[i + 2][j - 2] == 0 && board[i + 2][j + 2] == 0 && board[i + 3][j] == 0){
						set(i + 2, j, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//5��T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 1][j + 2] == 2 && board[i + 2][j] == 2 && board[i + 1][j] == 0 && board[i - 1][j] == 0 && board[i + 1][j - 1] == 0 && board[i + 1][j + 3] == 0 && board[i + 3][j] == 0){
						set(i + 1, j, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//6�kT   -|
		if (a == false){
			for (int i = 2; i <= 7; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i - 1][j + 2] == 2 && board[i + 1][j + 2] == 2 && board[i][j + 2] == 0 && board[i - 2][j + 2] == 0 && board[i][j - 1] == 0 && board[i][j + 3] == 0 && board[i + 2][j + 2] == 0){
						set(i, j + 2, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//7���k��T
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 3; j <= 7; j++){
					if (board[i][j] == 2 && board[i + 2][j - 2] == 2 && board[i + 2][j] == 2 && board[i + 3][j + 1] == 2 && board[i + 1][j - 1] == 0 && board[i - 1][j + 1] == 0 && board[i][j - 2] == 0 && board[i + 3][j - 3] == 0 && board[i + 4][j + 2] == 0){
						set(i + 1, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//8�˥k��T
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 1][j + 3] == 2 && board[i + 3][j + 1] == 2 && board[i + 2][j + 2] == 0 && board[i - 1][j - 1] == 0 && board[i][j + 4] == 0 && board[i + 4][j] == 0 && board[i + 3][j + 3] == 0){
						set(i + 2, j + 2, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//9������T
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 2; j <= 6; j++){
					if (board[i][j] == 2 && board[i + 2][j] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j - 1] == 2 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i + 4][j - 2] == 0 && board[i + 3][j + 3] == 0 && board[i][j + 2] == 0){
						set(i + 1, j + 1, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//10�˥���T
		if (a == false){
			for (int i = 2; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					if (board[i][j] == 2 && board[i][j + 2] == 2 && board[i - 1][j + 3] == 2 && board[i + 2][j + 2] == 2 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i - 2][j + 4] == 0 && board[i + 2][j] == 0 && board[i + 3][j + 3] == 0){
						set(i + 1, j + 1, m);
						a = true;
						break;
					}
				}
			}
		}
		//1//31�������G�_�@
		if (a == false){
			for (int i = 0; i < 10; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					//�G�_�@
					if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 0 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
						set(i, j + 2, m);
						//board[i][j + 2] = 2;
						a = true;
						break;
					}
					//�@�_�G
					if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 0 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
						set(i, j + 1, m);
						//board[i][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//1//32�������G�_�@
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j < 10; j++){
					//�G�_�@
					if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 0 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
						set(i + 2, j, m);
						//board[i + 2][j] = 2;
						a = true;
						break;
					}
					//�@�_�G
					if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 0 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
						set(i + 1, j, m);
						//board[i + 1][j] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//1//33�k�׬��G�_�@
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					//�G�_�@
					if (board[i - 1][j - 1] == 0 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
						set(i + 2, j + 2, m);
						//board[i + 2][j + 2] = 2;
						a = true;
						break;
					}
					//�@�_�G
					if (board[i - 1][j - 1] == 0 && board[i][j] == 2 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
						set(i + 1, j + 1, m);
						//board[i + 1][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//1//34���׬��G�_�@
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 8; j >= 4; j -= 1){
					//�G�_�@
					if (board[i - 1][j + 1] == 0 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
						set(i + 2, j - 2, m);
						//board[i + 2][j - 2] = 2;
						a = true;
						break;
					}
					//�@�_�G
					if (board[i - 1][j + 1] == 0 && board[i][j] == 2 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
						set(i + 1, j - 1, m);
						//board[i + 1][j - 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//1//35�ץk���T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (i <= 3 && j <= 6 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
						set(i + 3, j + 3, m);
						//board[i + 3][j + 3] = 2;
						a = true;
						break;
					}
					if (i >= 4 && i <= 6 && j <= 2 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
						set(i + 3, j + 3, m);
						//board[i + 3][j + 3] = 2;
						a = true;
						break;
					}
					if (i >= 4 && i <= 6 && j >= 3 && j <= 6 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
						set(i - 1, j - 1, m);
						//board[i - 1][j - 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//1//36�ץ����T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 8; j >= 3; j -= 1){
					if (i <= 3 && j >= 3 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
						set(i + 3, j - 3, m);
						//board[i + 3][j - 3] = 2;
						a = true;
						break;
					}
					if (i >= 4 && i <= 6 && j >= 7 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
						set(i + 3, j - 3, m);
						//board[i + 3][j - 3] = 2;
						a = true;
						break;
					}
					if (i >= 4 && i <= 6 && j >= 3 && j <= 6 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
						set(i - 1, j + 1, m);
						//board[i - 1][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//1//39�������T
		if (a == false){
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (j <= 3 && board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0){
						set(i, j + 3, m);
						a = true;
						break;
					}
					if (j > 3 && board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0){
						set(i, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}

		//1//40�������T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					if (i <= 3 && board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 0){
						set(i + 3, j, m);
						a = true;
						break;
					}
					if (i > 3 && board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 0){
						set(i - 1, j, m);
						a = true;
						break;
					}
				}
			}
		}



		////////////////���//1~10//31~40

		if (m = 1 && a == false)
		{

			//2//1������
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 2; j <= 7; j++){
						if (board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j] == 1 && board[i + 1][j] == 0 && board[i - 1][j] == 0 && board[i + 1][j - 2] == 0 && board[i + 1][j + 2] == 0 && board[i + 3][j] == 0){
							set(i + 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//2�פ���
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (board[i][j] == 1 && board[i][j + 2] == 1 && board[i + 2][j] == 1 && board[i + 2][j + 2] == 1 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i - 1][j + 3] == 0 && board[i + 3][j - 1] == 0 && board[i + 3][j + 3] == 0){
							set(i + 1, j + 1, m);
							a = true;
							break;
						}
					}
				}
			}

			//2//3��T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (board[i][j] == 1 && board[i][j + 2] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 1] == 1 && board[i][j + 1] == 0 && board[i - 1][j + 1] == 0 && board[i][j - 1] == 0 && board[i][j + 3] == 0 && board[i + 3][j + 1] == 0){
							set(i, j + 1, m);
							a = true;
							break;
						}
					}
				}
			}

			//2//4��T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 2; j <= 7; j++){
						if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j - 1] == 1 && board[i + 2][j + 1] == 1 && board[i + 2][j] == 0 && board[i - 1][j] == 0 && board[i + 2][j - 2] == 0 && board[i + 2][j + 2] == 0 && board[i + 3][j] == 0){
							set(i + 2, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//5��T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 1][j + 2] == 1 && board[i + 2][j] == 1 && board[i + 1][j] == 0 && board[i - 1][j] == 0 && board[i + 1][j - 1] == 0 && board[i + 1][j + 3] == 0 && board[i + 3][j] == 0){
							set(i + 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//6�kT   -|
			if (a == false){
				for (int i = 2; i <= 7; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i - 1][j + 2] == 1 && board[i + 1][j + 2] == 1 && board[i][j + 2] == 0 && board[i - 2][j + 2] == 0 && board[i][j - 1] == 0 && board[i][j + 3] == 0 && board[i + 2][j + 2] == 0){
							set(i, j + 2, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//7���k��T
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 3; j <= 7; j++){
						if (board[i][j] == 1 && board[i + 2][j - 2] == 1 && board[i + 2][j] == 1 && board[i + 3][j + 1] == 1 && board[i + 1][j - 1] == 0 && board[i - 1][j + 1] == 0 && board[i][j - 2] == 0 && board[i + 3][j - 3] == 0 && board[i + 4][j + 2] == 0){
							set(i + 1, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}
			///2/8�˥k��T
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 1][j + 3] == 1 && board[i + 3][j + 1] == 1 && board[i + 2][j + 2] == 0 && board[i - 1][j - 1] == 0 && board[i][j + 4] == 0 && board[i + 4][j] == 0 && board[i + 3][j + 3] == 0){
							set(i + 2, j + 2, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//9������T
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 2; j <= 6; j++){
						if (board[i][j] == 1 && board[i + 2][j] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j - 1] == 1 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i + 4][j - 2] == 0 && board[i + 3][j + 3] == 0 && board[i][j + 2] == 0){
							set(i + 1, j + 1, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//10�˥���T
			if (a == false){
				for (int i = 2; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						if (board[i][j] == 1 && board[i][j + 2] == 1 && board[i - 1][j + 3] == 1 && board[i + 2][j + 2] == 1 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i - 2][j + 4] == 0 && board[i + 2][j] == 0 && board[i + 3][j + 3] == 0){
							set(i + 1, j + 1, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//31�������G�_�@
			if (a == false){
				for (int i = 0; i < 10; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						//�G�_�@
						if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 0 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
							set(i, j + 2, m);
							//board[i][j + 2] = 2;
							a = true;
							break;
						}
						//�@�_�G
						if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 0 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
							set(i, j + 1, m);
							//board[i][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}

			//2//32�������G�_�@
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j < 10; j++){
						//�G�_�@
						if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 0 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
							set(i + 2, j, m);
							//board[i + 2][j] = 2;
							a = true;
							break;
						}
						//�@�_�G
						if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 0 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
							set(i + 1, j, m);
							//board[i + 1][j] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//2//33�k�׬��G�_�@
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						//�G�_�@
						if (board[i - 1][j - 1] == 0 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
							set(i + 2, j + 2, m);
							//board[i + 2][j + 2] = 2;
							a = true;
							break;
						}
						//�@�_�G
						if (board[i - 1][j - 1] == 0 && board[i][j] == 1 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
							set(i + 1, j + 1, m);
							//board[i + 1][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//2//34���׬��G�_�@
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 8; j >= 4; j -= 1){
						//�G�_�@
						if (board[i - 1][j + 1] == 0 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
							set(i + 2, j - 2, m);
							//board[i + 2][j - 2] = 2;
							a = true;
							break;
						}
						//�@�_�G
						if (board[i - 1][j + 1] == 0 && board[i][j] == 1 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
							set(i + 1, j - 1, m);
							//board[i + 1][j - 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//2//35�ץk���T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (i <= 3 && j <= 6 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
							set(i + 3, j + 3, m);
							//board[i + 3][j + 3] = 2;
							a = true;
							break;
						}
						if (i >= 4 && i <= 6 && j <= 2 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
							set(i + 3, j + 3, m);
							//board[i + 3][j + 3] = 2;
							a = true;
							break;
						}
						if (i >= 4 && i <= 6 && j >= 3 && j <= 6 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
							set(i - 1, j - 1, m);
							//board[i - 1][j - 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//2//36�ץ����T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 8; j >= 3; j -= 1){
						if (i <= 3 && j >= 3 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
							set(i + 3, j - 3, m);
							//board[i + 3][j - 3] = 2;
							a = true;
							break;
						}
						if (i >= 4 && i <= 6 && j >= 7 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
							set(i + 3, j - 3, m);
							//board[i + 3][j - 3] = 2;
							a = true;
							break;
						}
						if (i >= 4 && i <= 6 && j >= 3 && j <= 6 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
							set(i - 1, j + 1, m);
							//board[i - 1][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//2//39�������T
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (j <= 3 && board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 0){
							set(i, j + 3, m);
							a = true;
							break;
						}
						if (j > 3 && board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 0){
							set(i, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}

			//2//40�������T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						if (i <= 3 && board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 0){
							set(i + 3, j, m);
							a = true;
							break;
						}
						if (i > 3 && board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 0){
							set(i - 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
		}



		//�üƤU
		int p = rand();
		int q = rand();
		while (a == false){
			p = rand() % 10;
			q = rand() % 10;
			if (board[p][q] == 0){
				set(p, q, m);
				a = true;
			}
		}
	}
	if (m == 2)
	{
		////////////////����Ĺ
		//1//////11~30//37~38//41~54

		if (m == 2 && a == false){


			//4//11�������G�_�G
			if (a == false){
				for (int i = 0; i < 10; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 0 && board[i][j + 3] == 2 && board[i][j + 4] == 2){
							set(i, j + 2, m);
							a = true;
							break;
						}
					}
				}
			}
			//4//12�������G�_�G
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j < 10; j++){
						if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 0 && board[i + 3][j] == 2 && board[i + 4][j] == 2){
							set(i + 2, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//4//13�k�׬��G�_�G
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2){
							set(i + 2, j + 2, m);
							a = true;
							break;
						}
					}
				}
			}
			//4//14���׬��G�_�G
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 9; j >= 4; j -= 1){
						if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2){
							set(i + 2, j - 2, m);
							//board[i + 2][j - 2] = 2;
							a = true;
							break;

						}
					}
				}
			}

			////////4//////////////3-1
			////�߱�T�_�@15~30
			//*4//27�����T�_�@
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						//�T�_�@
						if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0 && board[i][j + 4] == 2){
							set(i, j + 3, m);
							//board[i][j + 3] = 2;
							a = true;
							break;
						}
						//�@�_�T
						if (board[i][j] == 2 && board[i][j + 1] == 0 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2){
							set(i, j + 1, m);
							//board[i][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*4//28�����T�_�@
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						//���T�_�@
						if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 0 && board[i + 4][j] == 2){
							set(i + 3, j, m);
							//board[i + 3][j] = 2;
							a = true;
							break;
						}
						//���@�_�T
						if (board[i][j] == 2 && board[i + 1][j] == 0 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2){
							set(i + 1, j, m);
							//board[i + 1][j] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*4//29�k�פT�_�@
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						//���T�_�@			
						if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 2){
							set(i + 3, j + 3, m);
							//board[i + 3][j + 3] = 2;
							a = true;
							break;
						}
						//���@�_�T			
						if (board[i][j] == 2 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2){
							set(i + 1, j + 1, m);
							//board[i + 1][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*4//30���צ��T�_�@
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 9; j >= 4; j -= 1){
						//���T�_�@			
						if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 2){
							set(i + 3, j - 3, m);
							//board[i + 3][j - 3] = 2;
							a = true;
							break;
						}
						//���@�_�T			
						if (board[i][j] == 2 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 2){
							set(i + 1, j - 1, m);
							//board[i + 1][j - 1] = 2;
							a = true;
							break;
						}
					}
				}
			}









			/////////

			//37�ץk���|
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;

					for (int j = 1; j <= 5; j++){
						if (i <= 5 && j <= 5 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2){
							if (board[i - 1][j - 1] == 1 && board[i + 4][j + 4] == 0){
								set(i + 4, j + 4, m);
								//board[i + 4][j + 4] = 2;
								a = true;
								break;
							}

							if (board[i - 1][j - 1] == 0 && board[i + 4][j + 4] == 1){
								set(i - 1, j - 1, m);
								//board[i - 1][j - 1] = 2;
								a = true;
								break;
							}
						}
					}
				}
			}
			//38�ץ����|
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;

					for (int j = 8; j >= 4; j -= 1){
						if (i <= 5 && j >= 4 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2){
							if (board[i - 1][j + 1] == 1 && board[i + 4][j - 4] == 0){
								set(i + 4, j - 4, m);
								//board[i + 4][j - 4] = 2;
								a = true;
								break;
							}


							if (board[i - 1][j + 1] == 0 && board[i + 4][j - 4] == 1){
								set(i - 1, j + 1, m);
								//board[i - 1][j + 1] = 2;
								a = true;
								break;

							}
						}
					}
				}
			}

			//4//41�W���I0,0~0,9�����s�|
			int i0 = 0;

			if (a == false){
				for (int j = 0; j < 10; j++){
					if (a == true)
						break;
					i0 = 0;
					sum[0] = 0;
					while (i0 < 4){
						if (board[i0][j] == 2 && i0 < 3){
							i0++;
							sum[0]++;
						}
						else if (board[3][j] == 2 && board[4][j] == 0 && sum[0] == 3){
							set(4, j, m);
							//board[4][j] = 2;
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//4//42�U���I9,0~9,9�����s�|
			int i1 = 0;
			if (a == false){
				for (int j = 0; j < 10; j++){
					if (a == true)
						break;
					i1 = 9;
					sum[1] = 0;

					while (i1 > 5){
						if (board[i1][j] == 2 && i1 > 6){
							i1 -= 1;
							sum[1]++;
						}
						else if (board[6][j] == 2 && board[5][j] == 0 && sum[1] == 3){
							set(5, j, m);
							//board[5][j] = 2;
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//4//43�����I0,0~9,0�����s�|
			int j0 = 0;
			if (a == false){
				for (int i = 0; i < 10; i++){
					if (a == true)
						break;
					j0 = 0;
					sum[2] = 0;
					while (j0 < 4){
						if (board[i][j0] == 2 && j0 < 3){
							j0++;
							sum[2]++;
						}
						else if (board[i][3] == 2 && board[i][4] == 0 && sum[2] == 3){
							set(i, 4, m);
							//board[i][4] = 2;
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//44�k���I0,9~9,9�����s�|
			int j1 = 0;
			if (a == false){
				for (int i = 0; i < 10; i++){
					if (a == true)
						break;
					j1 = 9;
					sum[3] = 0;
					while (j1 > 5){
						if (board[i][j1] == 2 && j1 > 6){
							j1 -= 1;
							sum[3]++;
						}
						else if (board[i][6] == 2 && board[i][5] == 0 && sum[3] == 3){
							set(i, 5, m);
							//board[i][5] = 2;
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//45���W���I0,0~0,5�ץk�U�s�|
			int i2 = 0, j2 = 0;
			if (a == false){
				for (int j = 0; j < 6; j++){
					if (a == true)
						break;
					i2 = 0;
					j2 = j;
					sum[4] = 0;
					while (i2 < 4 && j2 < j + 4){
						if (board[i2][j2] == 2 && i2 < 3 && j2 < j + 3){
							i2++;
							j2++;
							sum[4]++;
						}
						else if (board[3][j2] == 2 && board[4][j2 + 1] == 0 && sum[4] == 3){
							set(4, j2 + 1, m);
							//board[4][j2 + 1] = 2;
							a = true;
							break;
						}
						else break;
					}
				}
			}

			//46�k�W���I0,9~0,5�ץ��U�s�|
			int i3 = 0, j3 = 0;
			if (a == false){
				for (int j = 9; j > 4; j -= 1){
					if (a == true)
						break;
					i3 = 0;
					j3 = j;
					sum[5] = 0;
					while (i3 < 4 && j3 > j - 4){
						if (board[i3][j3] == 2 && i3<3 && j3>j - 3){
							i3++;
							j3 -= 1;
							sum[5]++;
						}
						else if (board[3][j3] == 2 && board[4][j3 - 1] == 0 && sum[5] == 3){
							set(4, j3 - 1, m);
							//board[4][j3 - 1] = 2;
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//47���U���I9,0~9,5�ץk�W�s�|
			int i4 = 0, j4 = 0;
			if (a == false){
				for (int j = 0; j < 6; j++){
					if (a == true)
						break;
					i4 = 9;
					j4 = j;
					sum[6] = 0;
					while (i4 > 5 && j4 < j + 4){
						if (board[i4][j4] == 2 && i4>6 && j4 < j + 3){
							i4 -= 1;
							j4++;
							sum[6]++;
						}
						else if (board[6][j4] == 2 && board[5][j4 + 1] == 0 && sum[6] == 3){
							set(5, j4 + 1, m);
							//board[5][j4 + 1] = 1;
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//4//48�k�U���I9,9~9,4�ץ��W�s�|
			int i5 = 0, j5 = 0;
			if (a == false){
				for (int j = 9; j > 4; j -= 1){
					if (a == true)
						break;
					i5 = 9;
					j5 = j;
					sum[7] = 0;
					while (i5 > 5 && j5 > j - 4){
						if (board[i5][j5] == 2 && i5 > 6 && j5 > j - 3){
							i5 -= 1;
							j5 -= 1;
							sum[7]++;
						}
						else if (board[6][j5] == 2 && board[5][j5 - 1] == 0 && sum[7] == 3){
							set(5, j5 - 1, m);
							a = true;
							break;
						}
						else break;
					}
				}
			}
			//4//49���W��ץk�U�s�|
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 0; j++){
						if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
							set(i + 4, j + 4, m);
							a = true;
							break;
						}
					}
				}
			}
			//4//50�k�W��ץ��U�s�|
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 9; j <= 9; j++){
						if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
							set(i + 4, j - 4, m);
							a = true;
							break;
						}
					}
				}
			}

			//4//51���U��ץk�W�s�|
			if (a == false){
				for (int i = 4; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 0; j++){
						if (board[i][j] == 2 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 0){
							set(i - 4, j + 4, m);
							a = true;
							break;
						}
					}
				}
			}

			//4//52�k�U��ץ��W�s�|
			if (a == false){
				for (int i = 4; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 9; j <= 9; j++){
						if (board[i][j] == 2 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2 && board[i - 4][j - 4] == 0){
							set(i - 4, j - 4, m);
							a = true;
							break;
						}
					}
				}
			}
			//4//53�������|
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 8; j++){
						//������
						if (board[i][j - 1] == 1 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
							set(i, j + 4, m);
							a = true;
							break;
						}
						//���k��
						if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 1){
							set(i, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}

			//4//54�������|
			if (a == false){
				for (int i = 1; i <= 8; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						//���W��
						if (board[i - 1][j] == 1 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
							set(i + 4, j, m);
							a = true;
							break;
						}
						//���U��
						if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 1){
							set(i - 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
			/////��Ĺ��
			//4//55�������|
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
							set(i, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}
			//4//56�������|
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
							set(i - 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//4//57�k�׬��|
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						if (board[i - 1][j - 1] == 0 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
							set(i - 1, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}
			//4//58���׬��|
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 8; j >= 4; j -= 1){
						if (board[i - 1][j + 1] == 0 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
							set(i - 1, j + 1, m);
							//board[i + 2][j - 2] = 2;
							a = true;
							break;
						}
					}
				}
			}
		}

		/////////////////�����u
		//3//////11~30//37~38//41~58

		//3//11�������G�_�G
		if (a == false){
			for (int i = 0; i < 10; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 5; j++){
					if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 0 && board[i][j + 3] == 1 && board[i][j + 4] == 1){
						set(i, j + 2, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//12�������G�_�G
		if (a == false){

			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;

				for (int j = 0; j < 10; j++){
					if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 0 && board[i + 3][j] == 1 && board[i + 4][j] == 1){
						set(i + 2, j, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//13�k�׬��G�_�G
		if (a == false){

			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;

				for (int j = 0; j <= 5; j++){
					if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1){
						set(i + 2, j + 2, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//14���׬��G�_�G
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 9; j >= 4; j -= 1){
					if (board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 1){
						set(i + 2, j - 2, m);
						//board[i + 2][j - 2] = 2;
						a = true;
						break;

					}
				}
			}
		}
		////�߱�T�_�@15~30
		//*3//27�����T�_�@
		if (a == false){
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 5; j++){
					//�T�_�@
					if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 0 && board[i][j + 4] == 1){
						set(i, j + 3, m);
						//board[i][j + 3] = 2;
						a = true;
						break;
					}
					//�@�_�T
					if (board[i][j] == 1 && board[i][j + 1] == 0 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 1){
						set(i, j + 1, m);
						//board[i][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*2//28�����T�_�@
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					//���T�_�@
					if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 0 && board[i + 4][j] == 1){
						set(i + 3, j, m);
						//board[i + 3][j] = 2;
						a = true;
						break;
					}
					//���@�_�T
					if (board[i][j] == 1 && board[i + 1][j] == 0 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 1){
						set(i + 1, j, m);
						//board[i + 1][j] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*2//29�k�פT�_�@
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 5; j++){
					//���T�_�@			
					if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 1){
						set(i + 3, j + 3, m);
						//board[i + 3][j + 3] = 2;
						a = true;
						break;
					}
					//���@�_�T			
					if (board[i][j] == 1 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1){
						set(i + 1, j + 1, m);
						//board[i + 1][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*2//30���צ��T�_�@
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 9; j >= 4; j -= 1){
					//���T�_�@			
					if (board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 1){
						set(i + 3, j - 3, m);
						//board[i + 3][j - 3] = 2;
						a = true;
						break;
					}
					//���@�_�T			
					if (board[i][j] == 1 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 1){
						set(i + 1, j - 1, m);
						//board[i + 1][j - 1] = 2;
						a = true;
						break;
					}
				}
			}
		}








		//37�ץk���|
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;

				for (int j = 1; j <= 5; j++){
					if (i <= 5 && j <= 5 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1){
						if (board[i - 1][j - 1] == 2 && board[i + 4][j + 4] == 0){
							set(i + 4, j + 4, m);
							//board[i + 4][j + 4] = 2;
							a = true;
							break;
						}

						if (board[i - 1][j - 1] == 0 && board[i + 4][j + 4] == 2){
							set(i - 1, j - 1, m);
							//board[i - 1][j - 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
		}
		//38�ץ����|
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;

				for (int j = 8; j >= 4; j -= 1){
					if (i <= 5 && j >= 4 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1){
						if (board[i - 1][j + 1] == 2 && board[i + 4][j - 4] == 0){
							set(i + 4, j - 4, m);
							//board[i + 4][j - 4] = 2;
							a = true;
							break;
						}


						if (board[i - 1][j + 1] == 0 && board[i + 4][j - 4] == 2){
							set(i - 1, j + 1, m);
							//board[i - 1][j + 1] = 2;
							a = true;
							break;

						}
					}
				}
			}
		}
		//3//39�������T
		if (a == false){
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (j <= 3 && board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 0){
						set(i, j + 3, m);
						a = true;
						break;
					}
					if (j > 3 && board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 0){
						set(i, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}

		//3//40�������T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					if (i <= 3 && board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 0){
						set(i + 3, j, m);
						a = true;
						break;
					}
					if (i > 3 && board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 0){
						set(i - 1, j, m);
						a = true;
						break;
					}
				}
			}
		}




		//41�W���I0,0~0,9�����s�|
		int i[20] = { 0 };
		int i0 = 0;

		if (a == false){
			for (int j = 0; j < 10; j++){
				if (a == true)
					break;
				i0 = 0;
				sum[0] = 0;
				while (i0 < 4){
					if (board[i0][j] == 1 && i0 < 3){
						i0++;
						sum[0]++;
					}
					else if (board[3][j] == 1 && board[4][j] == 0 && sum[0] == 3){
						set(4, j, m);
						//board[4][j] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//42�U���I9,0~9,9�����s�|
		int i1 = 0;
		if (a == false){
			for (int j = 0; j < 10; j++){
				if (a == true)
					break;
				i1 = 9;
				sum[1] = 0;
				while (i1 > 5){
					if (board[i1][j] == 1 && i1 > 6){
						i1 -= 1;
						sum[1]++;
					}
					else if (board[6][j] == 1 && board[5][j] == 0 && sum[1] == 3){
						set(5, j, m);
						//board[5][j] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//43�����I0,0~9,0�����s�|
		int j[20] = { 0 };
		int j0 = 0;
		if (a == false){
			for (int i = 0; i < 10; i++){
				if (a == true)
					break;
				j0 = 0;
				sum[2] = 0;
				while (j0 < 4){
					if (board[i][j0] == 1 && j0 < 3){
						j0++;
						sum[2]++;
					}
					else if (board[i][3] == 1 && board[i][4] == 0 && sum[2] == 3){
						set(i, 4, m);
						//board[i][4] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//44�k���I9,0~9,9�����s�|
		int j1 = 0;
		if (a == false){
			for (int i = 0; i < 10; i++){
				if (a == true)
					break;
				j1 = 9;
				sum[3] = 0;
				while (j1 > 5){
					if (board[i][j1] == 1 && j1 > 6){
						j1 -= 1;
						sum[3]++;
					}
					else if (board[i][6] == 1 && board[i][5] == 0 && sum[3] == 3){
						set(i, 5, m);
						//board[i][5] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//45���W���I0,0~0,5�ץk�U�s�|
		int i2 = 0, j2 = 0;
		if (a == false){
			for (int j = 0; j < 6; j++){
				if (a == true)
					break;
				i2 = 0;
				j2 = j;
				sum[4] = 0;
				while (i2 < 4 && j2 < j + 4){
					if (board[i2][j2] == 1 && i2 < 3 && j2 < j + 3){
						i2++;
						j2++;
						sum[4]++;
					}
					else if (board[3][j2] == 1 && board[4][j2 + 1] == 0 && sum[4] == 3){
						set(4, j2 + 1, m);
						//board[4][j2 + 1] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}

		//46�k�W���I0,0~0,4�ץ��U�s�|
		int i3 = 0, j3 = 0;
		if (a == false){
			for (int j = 9; j > 4; j -= 1){
				if (a == true)
					break;
				i3 = 0;
				j3 = j;
				sum[5] = 0;
				while (i3 < 4 && j3 > j - 4){
					if (board[i3][j3] == 1 && i3<3 && j3>j - 3){
						i3++;
						j3 -= 1;
						sum[5]++;
					}
					else if (board[3][j3] == 1 && board[4][j3 - 1] == 0 && sum[5] == 3){
						set(4, j3 - 1, m);
						//board[4][j3 - 1] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//47���U���I9,0~9,5�ץk�W�s�|
		int i4 = 0, j4 = 0;
		if (a == false){
			for (int j = 0; j < 6; j++){
				if (a == true)
					break;
				i4 = 9;
				j4 = j;
				sum[6] = 0;
				while (i4 > 5 && j4 < j + 4){
					if (board[i4][j4] == 1 && i4>6 && j4 < j + 3){
						i4 -= 1;
						j4++;
						sum[6]++;
					}
					else if (board[6][j4] == 1 && board[5][j4 + 1] == 0 && sum[6] == 3){
						set(5, j4 + 1, m);
						//board[5][j4 + 1] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//48�k�U���I9,9~9,4�ץ��W�s�|
		int i5 = 0, j5 = 0;
		if (a == false){
			for (int j = 9; j > 4; j -= 1){
				if (a == true)
					break;
				i5 = 9;
				j5 = j;
				sum[7] = 0;
				while (i5 > 5 && j5 > j - 4){
					if (board[i5][j5] == 1 && i5 > 6 && j5 > j - 3){
						i5 -= 1;
						j5 -= 1;
						sum[7]++;
					}
					else if (board[6][j5] == 1 && board[5][j5 - 1] == 0 && sum[7] == 3){
						set(5, j5 - 1, m);
						//board[5][j5 - 1] = 2;
						a = true;
						break;
					}
					else break;
				}
			}
		}
		//3//49���W��ץk�U�s�|
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 0; j++){
					if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
						set(i + 4, j + 4, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//50�k�W��ץ��U�s�|
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 9; j <= 9; j++){
					if (board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
						set(i + 4, j - 4, m);
						a = true;
						break;
					}
				}
			}
		}

		//3//51���U��ץk�W�s�|
		if (a == false){
			for (int i = 4; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 0; j++){
					if (board[i][j] == 1 && board[i - 1][j + 1] == 1 && board[i - 2][j + 2] == 1 && board[i - 3][j + 3] == 1 && board[i - 4][j + 4] == 0){
						set(i - 4, j + 4, m);
						a = true;
						break;
					}
				}
			}
		}

		//3//52�k�U��ץ��W�s�|
		if (a == false){
			for (int i = 4; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 9; j <= 9; j++){
					if (board[i][j] == 1 && board[i - 1][j - 1] == 1 && board[i - 2][j - 2] == 1 && board[i - 3][j - 3] == 1 && board[i - 4][j - 4] == 0){
						set(i - 4, j - 4, m);
						a = true;
						break;
					}
				}
			}
		}

		//3//53�������|
		if (a == false)
		{
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 8; j++){
					//������
					if (board[i][j - 1] == 2 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
						set(i, j + 4, m);
						a = true;
						break;
					}
					//���k��
					if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 2){
						set(i, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}


		//3//54�������|
		if (a == false){
			for (int i = 1; i <= 8; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					//���W��
					if (board[i - 1][j] == 2 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
						set(i + 4, j, m);
						a = true;
						break;
					}
					//���U��
					if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 2){
						set(i - 1, j, m);
						a = true;
						break;
					}
				}
			}
		}
		/////�̥��u���M�S�ϤF
		//3//55�������|
		if (a == false){
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
						set(i, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//56�������|
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
						set(i - 1, j, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//57�k�׬��|
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					if (board[i - 1][j - 1] == 0 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
						set(i - 1, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//58���׬��|
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 8; j >= 4; j -= 1){
					if (board[i - 1][j + 1] == 0 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
						set(i - 1, j + 1, m);
						//board[i + 2][j - 2] = 2;
						a = true;
						break;
					}
				}
			}
		}

		////////////////��u
		//3////////1~10//31~36//39~40
		//3//1������
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 2; j <= 7; j++){
					if (board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j] == 1 && board[i + 1][j] == 0 && board[i - 1][j] == 0 && board[i + 1][j - 2] == 0 && board[i + 1][j + 2] == 0 && board[i + 3][j] == 0){
						set(i + 1, j, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//2�פ���
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (board[i][j] == 1 && board[i][j + 2] == 1 && board[i + 2][j] == 1 && board[i + 2][j + 2] == 1 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i - 1][j + 3] == 0 && board[i + 3][j - 1] == 0 && board[i + 3][j + 3] == 0){
						set(i + 1, j + 1, m);
						a = true;
						break;
					}
				}
			}
		}

		//3//3��T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (board[i][j] == 1 && board[i][j + 2] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 1] == 1 && board[i][j + 1] == 0 && board[i - 1][j + 1] == 0 && board[i][j - 1] == 0 && board[i][j + 3] == 0 && board[i + 3][j + 1] == 0){
						set(i, j + 1, m);
						a = true;
						break;
					}
				}
			}
		}

		//3//4��T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 2; j <= 7; j++){
					if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j - 1] == 1 && board[i + 2][j + 1] == 1 && board[i + 2][j] == 0 && board[i - 1][j] == 0 && board[i + 2][j - 2] == 0 && board[i + 2][j + 2] == 0 && board[i + 3][j] == 0){
						set(i + 2, j, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//5��T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 1][j + 2] == 1 && board[i + 2][j] == 1 && board[i + 1][j] == 0 && board[i - 1][j] == 0 && board[i + 1][j - 1] == 0 && board[i + 1][j + 3] == 0 && board[i + 3][j] == 0){
						set(i + 1, j, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//6�kT   -|
		if (a == false){
			for (int i = 2; i <= 7; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i - 1][j + 2] == 1 && board[i + 1][j + 2] == 1 && board[i][j + 2] == 0 && board[i - 2][j + 2] == 0 && board[i][j - 1] == 0 && board[i][j + 3] == 0 && board[i + 2][j + 2] == 0){
						set(i, j + 2, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//7���k��T
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 3; j <= 7; j++){
					if (board[i][j] == 1 && board[i + 2][j - 2] == 1 && board[i + 2][j] == 1 && board[i + 3][j + 1] == 1 && board[i + 1][j - 1] == 0 && board[i - 1][j + 1] == 0 && board[i][j - 2] == 0 && board[i + 3][j - 3] == 0 && board[i + 4][j + 2] == 0){
						set(i + 1, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//8�˥k��T
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 1][j + 3] == 1 && board[i + 3][j + 1] == 1 && board[i + 2][j + 2] == 0 && board[i - 1][j - 1] == 0 && board[i][j + 4] == 0 && board[i + 4][j] == 0 && board[i + 3][j + 3] == 0){
						set(i + 2, j + 2, m);
						a = true;
						break;
					}
				}
			}
		}
		///3//9������T
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 2; j <= 6; j++){
					if (board[i][j] == 1 && board[i + 2][j] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j - 1] == 1 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i + 4][j - 2] == 0 && board[i + 3][j + 3] == 0 && board[i][j + 2] == 0){
						set(i + 1, j + 1, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//10�˥���T
		if (a == false){
			for (int i = 2; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					if (board[i][j] == 1 && board[i][j + 2] == 1 && board[i - 1][j + 3] == 1 && board[i + 2][j + 2] == 1 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i - 2][j + 4] == 0 && board[i + 2][j] == 0 && board[i + 3][j + 3] == 0){
						set(i + 1, j + 1, m);
						a = true;
						break;
					}
				}
			}
		}
		//3//31�������G�_�@
		if (a == false){
			for (int i = 0; i < 10; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					//�G�_�@
					if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 0 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
						set(i, j + 2, m);
						//board[i][j + 2] = 2;
						a = true;
						break;
					}
					//�@�_�G
					if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 0 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
						set(i, j + 1, m);
						//board[i][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//3//32�������G�_�@
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j < 10; j++){
					//�G�_�@
					if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 0 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
						set(i + 2, j, m);
						//board[i + 2][j] = 2;
						a = true;
						break;
					}
					//�@�_�G
					if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 0 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
						set(i + 1, j, m);
						//board[i + 1][j] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//3//33�k�׬��G�_�@
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					//�G�_�@
					if (board[i - 1][j - 1] == 0 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
						set(i + 2, j + 2, m);
						//board[i + 2][j + 2] = 2;
						a = true;
						break;
					}
					//�@�_�G
					if (board[i - 1][j - 1] == 0 && board[i][j] == 1 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
						set(i + 1, j + 1, m);
						//board[i + 1][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//3//34���׬��G�_�@
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 8; j >= 4; j -= 1){
					//�G�_�@
					if (board[i - 1][j + 1] == 0 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
						set(i + 2, j - 2, m);
						//board[i + 2][j - 2] = 2;
						a = true;
						break;
					}
					//�@�_�G
					if (board[i - 1][j + 1] == 0 && board[i][j] == 1 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
						set(i + 1, j - 1, m);
						//board[i + 1][j - 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//3//35�ץk���T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 6; j++){
					if (i <= 3 && j <= 6 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
						set(i + 3, j + 3, m);
						//board[i + 3][j + 3] = 2;
						a = true;
						break;
					}
					if (i >= 4 && i <= 6 && j <= 2 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
						set(i + 3, j + 3, m);
						//board[i + 3][j + 3] = 2;
						a = true;
						break;
					}
					if (i >= 4 && i <= 6 && j >= 3 && j <= 6 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
						set(i - 1, j - 1, m);
						//board[i - 1][j - 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//3//36�ץ����T
		if (a == false){
			for (int i = 1; i <= 6; i++){
				if (a == true)
					break;
				for (int j = 8; j >= 3; j -= 1){
					if (i <= 3 && j >= 3 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
						set(i + 3, j - 3, m);
						//board[i + 3][j - 3] = 2;
						a = true;
						break;
					}
					if (i >= 4 && i <= 6 && j >= 7 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
						set(i + 3, j - 3, m);
						//board[i + 3][j - 3] = 2;
						a = true;
						break;
					}
					if (i >= 4 && i <= 6 && j >= 3 && j <= 6 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
						set(i - 1, j + 1, m);
						//board[i - 1][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}











		////////////////���
		if (m == 2 && a == false){
			//4//1������
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 2; j <= 7; j++){
						if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j] == 2 && board[i + 1][j] == 0 && board[i - 1][j] == 0 && board[i + 1][j - 2] == 0 && board[i + 1][j + 2] == 0 && board[i + 3][j] == 0){
							set(i + 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//2�פ���
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (board[i][j] == 2 && board[i][j + 2] == 2 && board[i + 2][j] == 2 && board[i + 2][j + 2] == 2 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i - 1][j + 3] == 0 && board[i + 3][j - 1] == 0 && board[i + 3][j + 3] == 0){
							set(i + 1, j + 1, m);
							a = true;
							break;
						}
					}
				}
			}

			//3��T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (board[i][j] == 2 && board[i][j + 2] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 1] == 2 && board[i][j + 1] == 0 && board[i - 1][j + 1] == 0 && board[i][j - 1] == 0 && board[i][j + 3] == 0 && board[i + 3][j + 1] == 0){
							set(i, j + 1, m);
							a = true;
							break;
						}
					}
				}
			}

			//4��T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 2; j <= 7; j++){
						if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j - 1] == 2 && board[i + 2][j + 1] == 2 && board[i + 2][j] == 0 && board[i - 1][j] == 0 && board[i + 2][j - 2] == 0 && board[i + 2][j + 2] == 0 && board[i + 3][j] == 0){
							set(i + 2, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//5��T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 1][j + 2] == 2 && board[i + 2][j] == 2 && board[i + 1][j] == 0 && board[i - 1][j] == 0 && board[i + 1][j - 1] == 0 && board[i + 1][j + 3] == 0 && board[i + 3][j] == 0){
							set(i + 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//6�kT   -|
			if (a == false){
				for (int i = 2; i <= 7; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i - 1][j + 2] == 2 && board[i + 1][j + 2] == 2 && board[i][j + 2] == 0 && board[i - 2][j + 2] == 0 && board[i][j - 1] == 0 && board[i][j + 3] == 0 && board[i + 2][j + 2] == 0){
							set(i, j + 2, m);
							a = true;
							break;
						}
					}
				}
			}
			//7���k��T
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 3; j <= 7; j++){
						if (board[i][j] == 2 && board[i + 2][j - 2] == 2 && board[i + 2][j] == 2 && board[i + 3][j + 1] == 2 && board[i + 1][j - 1] == 0 && board[i - 1][j + 1] == 0 && board[i][j - 2] == 0 && board[i + 3][j - 3] == 0 && board[i + 4][j + 2] == 0){
							set(i + 1, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}
			//8�˥k��T
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 1][j + 3] == 2 && board[i + 3][j + 1] == 2 && board[i + 2][j + 2] == 0 && board[i - 1][j - 1] == 0 && board[i][j + 4] == 0 && board[i + 4][j] == 0 && board[i + 3][j + 3] == 0){
							set(i + 2, j + 2, m);
							a = true;
							break;
						}
					}
				}
			}
			//9������T
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 2; j <= 6; j++){
						if (board[i][j] == 2 && board[i + 2][j] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j - 1] == 2 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i + 4][j - 2] == 0 && board[i + 3][j + 3] == 0 && board[i][j + 2] == 0){
							set(i + 1, j + 1, m);
							a = true;
							break;
						}
					}
				}
			}
			//10�˥���T
			if (a == false){
				for (int i = 2; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						if (board[i][j] == 2 && board[i][j + 2] == 2 && board[i - 1][j + 3] == 2 && board[i + 2][j + 2] == 2 && board[i + 1][j + 1] == 0 && board[i - 1][j - 1] == 0 && board[i - 2][j + 4] == 0 && board[i + 2][j] == 0 && board[i + 3][j + 3] == 0){
							set(i + 1, j + 1, m);
							a = true;
							break;
						}
					}
				}
			}
			//31�������G�_�@
			if (a == false){
				for (int i = 0; i < 10; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						//�G�_�@
						if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 0 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
							set(i, j + 2, m);
							//board[i][j + 2] = 2;
							a = true;
							break;
						}
						//�@�_�G
						if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 0 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
							set(i, j + 1, m);
							//board[i][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//32�������G�_�@
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j < 10; j++){
						//�G�_�@
						if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 0 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
							set(i + 2, j, m);
							//board[i + 2][j] = 2;
							a = true;
							break;
						}
						//�@�_�G
						if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 0 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
							set(i + 1, j, m);
							//board[i + 1][j] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//33�k�׬��G�_�@
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						//�G�_�@
						if (board[i - 1][j - 1] == 0 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
							set(i + 2, j + 2, m);
							//board[i + 2][j + 2] = 2;
							a = true;
							break;
						}
						//�@�_�G
						if (board[i - 1][j - 1] == 0 && board[i][j] == 2 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
							set(i + 1, j + 1, m);
							//board[i + 1][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//34���׬��G�_�@
			if (a == false){

				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;

					for (int j = 8; j >= 4; j -= 1){
						//�G�_�@
						if (board[i - 1][j + 1] == 0 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
							set(i + 2, j - 2, m);
							//board[i + 2][j - 2] = 2;
							a = true;
							break;
						}
						//�@�_�G
						if (board[i - 1][j + 1] == 0 && board[i][j] == 2 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
							set(i + 1, j - 1, m);
							//board[i + 1][j - 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//4//35�ץk���T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (i <= 3 && j <= 6 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
							set(i + 3, j + 3, m);
							//board[i + 3][j + 3] = 2;
							a = true;
							break;
						}
						if (i >= 4 && i <= 6 && j <= 2 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
							set(i + 3, j + 3, m);
							//board[i + 3][j + 3] = 2;
							a = true;
							break;
						}
						if (i >= 4 && i <= 6 && j >= 3 && j <= 6 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i - 1][j - 1] == 0 && board[i + 3][j + 3] == 0){
							set(i - 1, j - 1, m);
							//board[i - 1][j - 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//36�ץ����T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 8; j >= 3; j -= 1){
						if (i <= 3 && j >= 3 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
							set(i + 3, j - 3, m);
							//board[i + 3][j - 3] = 2;
							a = true;
							break;
						}
						if (i >= 4 && i <= 6 && j >= 7 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
							set(i + 3, j - 3, m);
							//board[i + 3][j - 3] = 2;
							a = true;
							break;
						}
						if (i >= 4 && i <= 6 && j >= 3 && j <= 6 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i - 1][j + 1] == 0 && board[i + 3][j - 3] == 0){
							set(i - 1, j + 1, m);
							//board[i - 1][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//4//39�������T
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 6; j++){
						if (j <= 3 && board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0){
							set(i, j + 3, m);
							a = true;
							break;
						}
						if (j > 3 && board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0){
							set(i, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}

			//4//40�������T
			if (a == false){
				for (int i = 1; i <= 6; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						if (i <= 3 && board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 0){
							set(i + 3, j, m);
							a = true;
							break;
						}
						if (i > 3 && board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 0){
							set(i - 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
		}

		//�üƤU
		int p = rand();
		int q = rand();
		while (a == false){
			p = rand() % 10;
			q = rand() % 10;
			if (board[p][q] == 0){
				set(p, q, m);
				//board[p][q] = 2;
				a = true;
			}
		}
	}

	//cout << "(" << x << "," << y << ")" << endl;
	//set(x, y, m);
}

int check()
{
	int winner = 0;
	return winner;
}
int main(int n, char** args)
{
	int player = args[1][0] - '0';
	srand(time(0));
	if (player == 0) {
		init(); write(); show();
	}
	else
	{
		read();
		cout << "player" << player << endl;
		play(player);
		write();
		show();
	}
	return 0;
}