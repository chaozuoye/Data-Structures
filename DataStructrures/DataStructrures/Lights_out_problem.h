#pragma once
#include<iostream>
#include<string>
using namespace std;
int m[5][6], temp[5][6], answer[5][6];
int Move[][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool islegal(int x, int y) {
	return (x < 6 && x >= 0) && (y < 5 && y >= 0);
}

void init() {
	int Inits[5][6] = { 
		{0,1,1,1,0,1},
		{1,0,0,1,1,1},
		{0,0,1,0,0,1},
		{1,0,0,1,0,1},
		{0,1,1,1,0,0} };
	memcpy(m, Inits, sizeof(Inits));
}
void reverseBits(int x, int y) {
	temp[x][y] ^= 1;
	for (int i = 0; i < 4; i++) {
		int xx =x+ Move[i][0],
			yy =y+ Move[i][1];
		if (islegal(xx, yy)) temp[xx][yy] ^= 1;
	}
}
void solve() {
	init();
	for (int i = 0; i < 32; i++) {
		memcpy(temp, m, sizeof(m));
		memset(answer, 0, sizeof(answer));
		int t = i;
		for (int j = 0; t; j++) {
			if (t & 1) {
				reverseBits(j, 0);
				answer[j][0] = 1;
			}
			t >>= 1;
		}
		for (int j = 0; j < 5; j++) {
			for (int i = 0; i < 5; i++) {
				if (temp[i][j]) {
					reverseBits(i, j + 1);
					answer[i][j + 1] = 1;
				}
			}
		}
		bool flag = true;
		for (int i = 0; i < 5; i++) {
			if (temp[i][5]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 6; j++) {
					cout << temp[i][j] << " ";
				}
				cout << endl;
			}
			cout << "---------------------------µÆ------------------------------" << endl;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 6; j++) {
					cout << answer[i][j] << " ";
				}
				cout << endl;
			}
			cout << "----------------------------°´Å¥-----------------------------" << endl;
		}

	}
}