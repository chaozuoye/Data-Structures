#include<iostream>
#include<algorithm>
#include"Lights_out_problem.h"
#include"Sort.h"
#include<vector>
using namespace std;
class father {
private:
	int test=1;
public:
	friend class son;
};
class son :father {
public:
	void sum() {
		test += 1;
	}
};
int minTimeToType(string word) {
	int start = 0;
	int ans = 0, right = 0, left = 0;
	int length = word.length();
	for (int i = 0; i < length; i++) {
		right = abs(start - (word[i] - 'a'))%24;
		left = (start + ('z' - word[i]) + 1);
		start = word[i] - 'a';
		ans += (left < right ? left : right);
	}
	return ans + length;
}
int maxArea(vector<int>& height) {
	int begin = 0, end = height.size() - 1;
	int ans = 0;
	if (height[begin] < height[end]) {
		ans = height[begin] * end;
		begin++;
	}
	else {
		ans = height[end] * end;
		end--;
	}
	while (begin < end) {
		if (height[begin] < height[end]) {
			ans = max(height[begin] * end, ans);
			begin++;
		}
		else {
			ans = max(height[end] * end, ans);
			end--;
		}
	}
	return ans;
}
void function(int a, int b, int c) {
	char buffer1[15];
	char buffer2[10];
	int* r;
	r = (int*)(buffer1 + 12);
	(*r) += 8;
}
int main() {
	int x = 0;
	function(1, 2, 3);
	x = 1;
	cout << x;
	vector<int>height{ 1,8,6,2,5,4,8,3,7 };
	cout << maxArea(height);
	//vector<int> A{ 1,2,7,3,5,9,22,1,9,8 };
	//quick_sort(A,0,A.size()-1);
	//for (auto i = A.begin(); i < A.end(); i++) {
	//	cout << *i << " ";
	//}
//	vector<vector<int>>num{ {1,3},{2,2},{3,1} };
//	sort(num.begin(), num.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] > b[1];
//});
//	for (int i = 0; i < num.size(); i++) {
//		cout << num[i][1]<<endl;
//	}
	//int A[] = { 3,5,1,0,2,11,23,9,8,7 };
	//int low = 0;
	//int high=sizeof(A) / sizeof(A[0]);
	//QuickSort(A, low,high-1 );
	//for (int i = 0; i < high; i++) {
	//	std::cout << A[i]<<" ";
	//}
	//solve();	//2811£ºÏ¨µÆÎÊÌâ
	//int a = 1 & 1;
	//cout << a;
}
