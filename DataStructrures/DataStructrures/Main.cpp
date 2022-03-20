#include<iostream>
#include"Lights_out_problem.h"
#include"QuickSort.h"
using namespace std;
int main() {
	int A[] = { 3,5,1,0,2,11,23,9,8,7 };
	int low = 0;
	int high=sizeof(A) / sizeof(A[0]);
	QuickSort(A, low,high-1 );
	for (int i = 0; i < high; i++) {
		std::cout << A[i]<<" ";
	}
	//solve();	//2811£ºÏ¨µÆÎÊÌâ
	//int a = 1 & 1;
	//cout << a;
}
