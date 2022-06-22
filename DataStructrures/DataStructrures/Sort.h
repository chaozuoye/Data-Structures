#include<vector>
#include<iostream>
#include <unordered_map>
int Paritition1(int A[], int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot) {
            ++low;
        }
        A[high] = A[low];
    }
    A[high] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high) //¿ìÅÅÄ¸º¯Êý
{
    if (low < high) {
        int pivot = Paritition1(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}

void bubblesort(vector<int>&A) {
    bool flag = true;
    int i = 0;
    while (flag)
    {
        flag = false;
        for (int j = 1; j < A.size(); j++) {
            if (A[j - 1] > A[j]) {
                int temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                flag = true;
            }
        }
    }
}

void insertion_sort(vector<int>& A) {
    for (int i = 1; i < A.size(); i++) {
        int key = A[i ];
        int j = i - 1;
        while (j > 0&&A[j]>key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
int part(vector<int>& A, int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) {
            high--;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot) {
            low++;
        }
        A[high] = A[low];
        A[low] = pivot;

    }
    return low;
}
void quick_sort(vector<int>& A, int low, int high) {
    if (low < high) {
        int pivot = part(A, low, high);
        quick_sort(A, low, pivot-1);
        quick_sort(A, pivot+1, high);
    }
}
