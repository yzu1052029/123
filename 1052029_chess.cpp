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

		///////////////////////必先攻 
		//1//////11~30//37~38//41~58

		if (m = 1 && a == false){
			//2//11水平二斷二
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
			//2//12垂直二斷二
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
			//2//13右斜二斷二
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
			//2//14左斜二斷二
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
			////拋棄三斷一15~30
			//*2//27水平三斷一
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						//三斷一
						if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 0 && board[i][j + 4] == 1){
							set(i, j + 3, m);
							//board[i][j + 3] = 2;
							a = true;
							break;
						}
						//一斷三
						if (board[i][j] == 1 && board[i][j + 1] == 0 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 1){
							set(i, j + 1, m);
							//board[i][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*2//28垂直三斷一
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						//死三斷一
						if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 0 && board[i + 4][j] == 1){
							set(i + 3, j, m);
							//board[i + 3][j] = 2;
							a = true;
							break;
						}
						//死一斷三
						if (board[i][j] == 1 && board[i + 1][j] == 0 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 1){
							set(i + 1, j, m);
							//board[i + 1][j] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*2//29右斜三斷一
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						//死三斷一			
						if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 1){
							set(i + 3, j + 3, m);
							//board[i + 3][j + 3] = 2;
							a = true;
							break;
						}
						//死一斷三			
						if (board[i][j] == 1 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1){
							set(i + 1, j + 1, m);
							//board[i + 1][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*2//30左斜死三斷一
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 9; j >= 4; j -= 1){
						//死三斷一			
						if (board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 1){
							set(i + 3, j - 3, m);
							//board[i + 3][j - 3] = 2;
							a = true;
							break;
						}
						//死一斷三			
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
			//2//37斜右死四
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						if (i <= 5 && j <= 5 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1){
							//死左邊
							if (board[i - 1][j - 1] == 2 && board[i + 4][j + 4] == 0){
								set(i + 4, j + 4, m);
								//board[i + 4][j + 4] = 2;
								a = true;
								break;
							}
							//死右邊
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
			//2//38斜左死四
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
			//2//41上邊點0,0~0,9垂直連四
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
			//2//42下邊點9,0~9,9垂直連四
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
			//2//43左邊點0,0~9,0水平連四
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
			//2//44右邊點9,0~9,9水平連四
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
			//2//45左上邊點0,0~0,5斜右下連四
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

			//2//46右上邊點0,0~0,4斜左下連四
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
			//2//47左下邊點9,0~9,5斜右上連四
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
			//2//48右下邊點9,9~9,4斜左上連四
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
			//2//49左上邊斜右下連四
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
			//2//50右上邊斜左下連四
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

			//2//51左下邊斜右上連四
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

			//2//52右下邊斜左上連四
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
			//2//53水平死四
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 8; j++){
						//死左邊
						if (board[i][j - 1] == 2 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
							set(i, j + 4, m);
							a = true;
							break;
						}
						//死右邊
						if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 2){
							set(i, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}
			//2//54垂直死四
			if (a == false){
				for (int i = 1; i <= 8; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						//死上面
						if (board[i - 1][j] == 2 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
							set(i + 4, j, m);
							a = true;
							break;
						}
						//死下面
						if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 2){
							set(i - 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
			//////////////////////必贏攻
			//2//55水平活四
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
			//2//56垂直活四
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
			//2//57右斜活四
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
			//2//58左斜活四
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


		//1/////////////////////必守
		//////11~30//37~38//41~58
		//1//11水平活二斷二
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
		//1//12垂直活二斷二
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
		//1//13右斜活二斷二
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
		//1//14左斜活二斷二
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
		////拋棄三斷一15~30
		//*1//27水平三斷一
		if (a == false){
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 5; j++){
					//三斷一
					if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0 && board[i][j + 4] == 2){
						set(i, j + 3, m);
						//board[i][j + 3] = 2;
						a = true;
						break;
					}
					//一斷三
					if (board[i][j] == 2 && board[i][j + 1] == 0 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2){
						set(i, j + 1, m);
						//board[i][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*1//28垂直三斷一
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					//死三斷一
					if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 0 && board[i + 4][j] == 2){
						set(i + 3, j, m);
						//board[i + 3][j] = 2;
						a = true;
						break;
					}
					//死一斷三
					if (board[i][j] == 2 && board[i + 1][j] == 0 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2){
						set(i + 1, j, m);
						//board[i + 1][j] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*1//29右斜三斷一
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 5; j++){
					//死三斷一			
					if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 2){
						set(i + 3, j + 3, m);
						//board[i + 3][j + 3] = 2;
						a = true;
						break;
					}
					//死一斷三			
					if (board[i][j] == 2 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2){
						set(i + 1, j + 1, m);
						//board[i + 1][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*1//30左斜死三斷一
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 9; j >= 4; j -= 1){
					//死三斷一			
					if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 2){
						set(i + 3, j - 3, m);
						//board[i + 3][j - 3] = 2;
						a = true;
						break;
					}
					//死一斷三			
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
		//1//37斜右死四
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					if (i <= 5 && j <= 5 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2){
						//死上面
						if (board[i - 1][j - 1] == 1 && board[i + 4][j + 4] == 0){
							set(i + 4, j + 4, m);
							//board[i + 4][j + 4] = 2;
							a = true;
							break;
						}
						//死下面
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
		//1//38斜左死四
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 8; j >= 4; j -= 1){
					if (i <= 5 && j >= 4 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2){
						//死上面
						if (board[i - 1][j + 1] == 1 && board[i + 4][j - 4] == 0){
							set(i + 4, j - 4, m);
							//board[i + 4][j - 4] = 2;
							a = true;
							break;
						}
						//死下面
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
		//1//41上邊點0,0~0,9垂直連四
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
		//1//42下邊點9,0~9,9垂直連四
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
		//1//43左邊點0,0~9,0水平連四
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
		//1//44右邊點0,9~9,9水平連四
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
		//1//45左上邊點0,0~0,5斜右下連四
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

		//1//46右上邊點0,9~0,5斜左下連四
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
		//1//47左下邊點9,0~9,5斜右上連四
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
		//1//48右下邊點9,9~9,4斜左上連四
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
		//1//49左上邊斜右下連四
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
		//1//50右上邊斜左下連四
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

		//1//51左下邊斜右上連四
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

		//1//52右下邊斜左上連四
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
		//1//53水平死四
		if (a == false){
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 8; j++){
					//死左邊
					if (board[i][j - 1] == 1 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
						set(i, j + 4, m);
						a = true;
						break;
					}
					//死右邊
					if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 1){
						set(i, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}

		//1//54垂直死四
		if (a == false){
			for (int i = 1; i <= 8; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					//死上面
					if (board[i - 1][j] == 1 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
						set(i + 4, j, m);
						a = true;
						break;
					}
					//死下面
					if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 1){
						set(i - 1, j, m);
						a = true;
						break;
					}
				}
			}
		}
		////////必贏攻/////最先守雖然沒救了
		//1//55水平活四
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
		//1//56垂直活四
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
		//1//57右斜活四
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
		//1//58左斜活四
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






		///////////////////////////////後守
		//////1~10////31~36//39~40//
		//1//1正中空
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
		//1//2斜中空
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

		//1//3正T
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

		//1//4倒T
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
		//1//5左T
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
		//1//6右T   -|
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
		//1//7正右斜T
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
		//1//8倒右斜T
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
		//1//9正左斜T
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
		//1//10倒左斜T
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
		//1//31水平活二斷一
		if (a == false){
			for (int i = 0; i < 10; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					//二斷一
					if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 0 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
						set(i, j + 2, m);
						//board[i][j + 2] = 2;
						a = true;
						break;
					}
					//一斷二
					if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 0 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
						set(i, j + 1, m);
						//board[i][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//1//32垂直活二斷一
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j < 10; j++){
					//二斷一
					if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 0 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
						set(i + 2, j, m);
						//board[i + 2][j] = 2;
						a = true;
						break;
					}
					//一斷二
					if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 0 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
						set(i + 1, j, m);
						//board[i + 1][j] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//1//33右斜活二斷一
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					//二斷一
					if (board[i - 1][j - 1] == 0 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
						set(i + 2, j + 2, m);
						//board[i + 2][j + 2] = 2;
						a = true;
						break;
					}
					//一斷二
					if (board[i - 1][j - 1] == 0 && board[i][j] == 2 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
						set(i + 1, j + 1, m);
						//board[i + 1][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//1//34左斜活二斷一
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 8; j >= 4; j -= 1){
					//二斷一
					if (board[i - 1][j + 1] == 0 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
						set(i + 2, j - 2, m);
						//board[i + 2][j - 2] = 2;
						a = true;
						break;
					}
					//一斷二
					if (board[i - 1][j + 1] == 0 && board[i][j] == 2 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
						set(i + 1, j - 1, m);
						//board[i + 1][j - 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//1//35斜右活三
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
		//1//36斜左活三
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
		//1//39水平活三
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

		//1//40垂直活三
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



		////////////////後攻//1~10//31~40

		if (m = 1 && a == false)
		{

			//2//1正中空
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
			//2//2斜中空
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

			//2//3正T
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

			//2//4倒T
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
			//2//5左T
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
			//2//6右T   -|
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
			//2//7正右斜T
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
			///2/8倒右斜T
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
			//2//9正左斜T
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
			//2//10倒左斜T
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
			//2//31水平活二斷一
			if (a == false){
				for (int i = 0; i < 10; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						//二斷一
						if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 0 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
							set(i, j + 2, m);
							//board[i][j + 2] = 2;
							a = true;
							break;
						}
						//一斷二
						if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 0 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
							set(i, j + 1, m);
							//board[i][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}

			//2//32垂直活二斷一
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j < 10; j++){
						//二斷一
						if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 0 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
							set(i + 2, j, m);
							//board[i + 2][j] = 2;
							a = true;
							break;
						}
						//一斷二
						if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 0 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
							set(i + 1, j, m);
							//board[i + 1][j] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//2//33右斜活二斷一
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						//二斷一
						if (board[i - 1][j - 1] == 0 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
							set(i + 2, j + 2, m);
							//board[i + 2][j + 2] = 2;
							a = true;
							break;
						}
						//一斷二
						if (board[i - 1][j - 1] == 0 && board[i][j] == 1 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
							set(i + 1, j + 1, m);
							//board[i + 1][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//2//34左斜活二斷一
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 8; j >= 4; j -= 1){
						//二斷一
						if (board[i - 1][j + 1] == 0 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
							set(i + 2, j - 2, m);
							//board[i + 2][j - 2] = 2;
							a = true;
							break;
						}
						//一斷二
						if (board[i - 1][j + 1] == 0 && board[i][j] == 1 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
							set(i + 1, j - 1, m);
							//board[i + 1][j - 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//2//35斜右活三
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
			//2//36斜左活三
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
			//2//39水平活三
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

			//2//40垂直活三
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



		//亂數下
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
		////////////////先攻必贏
		//1//////11~30//37~38//41~54

		if (m == 2 && a == false){


			//4//11水平活二斷二
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
			//4//12垂直活二斷二
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
			//4//13右斜活二斷二
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
			//4//14左斜活二斷二
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
			////拋棄三斷一15~30
			//*4//27水平三斷一
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						//三斷一
						if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 0 && board[i][j + 4] == 2){
							set(i, j + 3, m);
							//board[i][j + 3] = 2;
							a = true;
							break;
						}
						//一斷三
						if (board[i][j] == 2 && board[i][j + 1] == 0 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2){
							set(i, j + 1, m);
							//board[i][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*4//28垂直三斷一
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						//死三斷一
						if (board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 0 && board[i + 4][j] == 2){
							set(i + 3, j, m);
							//board[i + 3][j] = 2;
							a = true;
							break;
						}
						//死一斷三
						if (board[i][j] == 2 && board[i + 1][j] == 0 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2){
							set(i + 1, j, m);
							//board[i + 1][j] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*4//29右斜三斷一
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 5; j++){
						//死三斷一			
						if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 2){
							set(i + 3, j + 3, m);
							//board[i + 3][j + 3] = 2;
							a = true;
							break;
						}
						//死一斷三			
						if (board[i][j] == 2 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2){
							set(i + 1, j + 1, m);
							//board[i + 1][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//*4//30左斜死三斷一
			if (a == false){
				for (int i = 0; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 9; j >= 4; j -= 1){
						//死三斷一			
						if (board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 2){
							set(i + 3, j - 3, m);
							//board[i + 3][j - 3] = 2;
							a = true;
							break;
						}
						//死一斷三			
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

			//37斜右死四
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
			//38斜左死四
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

			//4//41上邊點0,0~0,9垂直連四
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
			//4//42下邊點9,0~9,9垂直連四
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
			//4//43左邊點0,0~9,0水平連四
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
			//44右邊點0,9~9,9水平連四
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
			//45左上邊點0,0~0,5斜右下連四
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

			//46右上邊點0,9~0,5斜左下連四
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
			//47左下邊點9,0~9,5斜右上連四
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
			//4//48右下邊點9,9~9,4斜左上連四
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
			//4//49左上邊斜右下連四
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
			//4//50右上邊斜左下連四
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

			//4//51左下邊斜右上連四
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

			//4//52右下邊斜左上連四
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
			//4//53水平死四
			if (a == false){
				for (int i = 0; i <= 9; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 8; j++){
						//死左邊
						if (board[i][j - 1] == 1 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
							set(i, j + 4, m);
							a = true;
							break;
						}
						//死右邊
						if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 1){
							set(i, j - 1, m);
							a = true;
							break;
						}
					}
				}
			}

			//4//54垂直死四
			if (a == false){
				for (int i = 1; i <= 8; i++){
					if (a == true)
						break;
					for (int j = 0; j <= 9; j++){
						//死上面
						if (board[i - 1][j] == 1 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
							set(i + 4, j, m);
							a = true;
							break;
						}
						//死下面
						if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 1){
							set(i - 1, j, m);
							a = true;
							break;
						}
					}
				}
			}
			/////必贏攻
			//4//55水平活四
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
			//4//56垂直活四
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
			//4//57右斜活四
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
			//4//58左斜活四
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

		/////////////////必先守
		//3//////11~30//37~38//41~58

		//3//11水平活二斷二
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
		//3//12垂直活二斷二
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
		//3//13右斜活二斷二
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
		//3//14左斜活二斷二
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
		////拋棄三斷一15~30
		//*3//27水平三斷一
		if (a == false){
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 5; j++){
					//三斷一
					if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 0 && board[i][j + 4] == 1){
						set(i, j + 3, m);
						//board[i][j + 3] = 2;
						a = true;
						break;
					}
					//一斷三
					if (board[i][j] == 1 && board[i][j + 1] == 0 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 1){
						set(i, j + 1, m);
						//board[i][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*2//28垂直三斷一
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					//死三斷一
					if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 0 && board[i + 4][j] == 1){
						set(i + 3, j, m);
						//board[i + 3][j] = 2;
						a = true;
						break;
					}
					//死一斷三
					if (board[i][j] == 1 && board[i + 1][j] == 0 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 1){
						set(i + 1, j, m);
						//board[i + 1][j] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*2//29右斜三斷一
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 5; j++){
					//死三斷一			
					if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 1){
						set(i + 3, j + 3, m);
						//board[i + 3][j + 3] = 2;
						a = true;
						break;
					}
					//死一斷三			
					if (board[i][j] == 1 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1){
						set(i + 1, j + 1, m);
						//board[i + 1][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//*2//30左斜死三斷一
		if (a == false){
			for (int i = 0; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 9; j >= 4; j -= 1){
					//死三斷一			
					if (board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 1){
						set(i + 3, j - 3, m);
						//board[i + 3][j - 3] = 2;
						a = true;
						break;
					}
					//死一斷三			
					if (board[i][j] == 1 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 1){
						set(i + 1, j - 1, m);
						//board[i + 1][j - 1] = 2;
						a = true;
						break;
					}
				}
			}
		}








		//37斜右死四
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
		//38斜左死四
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
		//3//39水平活三
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

		//3//40垂直活三
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




		//41上邊點0,0~0,9垂直連四
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
		//42下邊點9,0~9,9垂直連四
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
		//43左邊點0,0~9,0水平連四
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
		//44右邊點9,0~9,9水平連四
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
		//45左上邊點0,0~0,5斜右下連四
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

		//46右上邊點0,0~0,4斜左下連四
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
		//47左下邊點9,0~9,5斜右上連四
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
		//48右下邊點9,9~9,4斜左上連四
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
		//3//49左上邊斜右下連四
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
		//3//50右上邊斜左下連四
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

		//3//51左下邊斜右上連四
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

		//3//52右下邊斜左上連四
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

		//3//53水平死四
		if (a == false)
		{
			for (int i = 0; i <= 9; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 8; j++){
					//死左邊
					if (board[i][j - 1] == 2 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
						set(i, j + 4, m);
						a = true;
						break;
					}
					//死右邊
					if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 2){
						set(i, j - 1, m);
						a = true;
						break;
					}
				}
			}
		}


		//3//54垂直死四
		if (a == false){
			for (int i = 1; i <= 8; i++){
				if (a == true)
					break;
				for (int j = 0; j <= 9; j++){
					//死上面
					if (board[i - 1][j] == 2 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
						set(i + 4, j, m);
						a = true;
						break;
					}
					//死下面
					if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 2){
						set(i - 1, j, m);
						a = true;
						break;
					}
				}
			}
		}
		/////最先守雖然沒救了
		//3//55水平活四
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
		//3//56垂直活四
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
		//3//57右斜活四
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
		//3//58左斜活四
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

		////////////////後守
		//3////////1~10//31~36//39~40
		//3//1正中空
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
		//3//2斜中空
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

		//3//3正T
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

		//3//4倒T
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
		//3//5左T
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
		//3//6右T   -|
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
		//3//7正右斜T
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
		//3//8倒右斜T
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
		///3//9正左斜T
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
		//3//10倒左斜T
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
		//3//31水平活二斷一
		if (a == false){
			for (int i = 0; i < 10; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					//二斷一
					if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 0 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
						set(i, j + 2, m);
						//board[i][j + 2] = 2;
						a = true;
						break;
					}
					//一斷二
					if (board[i][j - 1] == 0 && board[i][j] == 1 && board[i][j + 1] == 0 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 0){
						set(i, j + 1, m);
						//board[i][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//3//32垂直活二斷一
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 0; j < 10; j++){
					//二斷一
					if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 0 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
						set(i + 2, j, m);
						//board[i + 2][j] = 2;
						a = true;
						break;
					}
					//一斷二
					if (board[i - 1][j] == 0 && board[i][j] == 1 && board[i + 1][j] == 0 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 0){
						set(i + 1, j, m);
						//board[i + 1][j] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//3//33右斜活二斷一
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 1; j <= 5; j++){
					//二斷一
					if (board[i - 1][j - 1] == 0 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
						set(i + 2, j + 2, m);
						//board[i + 2][j + 2] = 2;
						a = true;
						break;
					}
					//一斷二
					if (board[i - 1][j - 1] == 0 && board[i][j] == 1 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 0){
						set(i + 1, j + 1, m);
						//board[i + 1][j + 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//3//34左斜活二斷一
		if (a == false){
			for (int i = 1; i <= 5; i++){
				if (a == true)
					break;
				for (int j = 8; j >= 4; j -= 1){
					//二斷一
					if (board[i - 1][j + 1] == 0 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
						set(i + 2, j - 2, m);
						//board[i + 2][j - 2] = 2;
						a = true;
						break;
					}
					//一斷二
					if (board[i - 1][j + 1] == 0 && board[i][j] == 1 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 0){
						set(i + 1, j - 1, m);
						//board[i + 1][j - 1] = 2;
						a = true;
						break;
					}
				}
			}
		}
		//3//35斜右活三
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
		//3//36斜左活三
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











		////////////////後攻
		if (m == 2 && a == false){
			//4//1正中空
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
			//2斜中空
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

			//3正T
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

			//4倒T
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
			//5左T
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
			//6右T   -|
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
			//7正右斜T
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
			//8倒右斜T
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
			//9正左斜T
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
			//10倒左斜T
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
			//31水平活二斷一
			if (a == false){
				for (int i = 0; i < 10; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						//二斷一
						if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 0 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
							set(i, j + 2, m);
							//board[i][j + 2] = 2;
							a = true;
							break;
						}
						//一斷二
						if (board[i][j - 1] == 0 && board[i][j] == 2 && board[i][j + 1] == 0 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 0){
							set(i, j + 1, m);
							//board[i][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//32垂直活二斷一
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 0; j < 10; j++){
						//二斷一
						if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 0 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
							set(i + 2, j, m);
							//board[i + 2][j] = 2;
							a = true;
							break;
						}
						//一斷二
						if (board[i - 1][j] == 0 && board[i][j] == 2 && board[i + 1][j] == 0 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 0){
							set(i + 1, j, m);
							//board[i + 1][j] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//33右斜活二斷一
			if (a == false){
				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;
					for (int j = 1; j <= 5; j++){
						//二斷一
						if (board[i - 1][j - 1] == 0 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 0 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
							set(i + 2, j + 2, m);
							//board[i + 2][j + 2] = 2;
							a = true;
							break;
						}
						//一斷二
						if (board[i - 1][j - 1] == 0 && board[i][j] == 2 && board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 0){
							set(i + 1, j + 1, m);
							//board[i + 1][j + 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//34左斜活二斷一
			if (a == false){

				for (int i = 1; i <= 5; i++){
					if (a == true)
						break;

					for (int j = 8; j >= 4; j -= 1){
						//二斷一
						if (board[i - 1][j + 1] == 0 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 0 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
							set(i + 2, j - 2, m);
							//board[i + 2][j - 2] = 2;
							a = true;
							break;
						}
						//一斷二
						if (board[i - 1][j + 1] == 0 && board[i][j] == 2 && board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2 && board[i + 4][j - 4] == 0){
							set(i + 1, j - 1, m);
							//board[i + 1][j - 1] = 2;
							a = true;
							break;
						}
					}
				}
			}
			//4//35斜右活三
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
			//36斜左活三
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
			//4//39水平活三
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

			//4//40垂直活三
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

		//亂數下
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