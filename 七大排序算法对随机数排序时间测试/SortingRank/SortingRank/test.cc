#include<iostream>
#include<algorithm>
#include<time.h>
#include<stdlib.h>

using namespace std;

//插入排序
void InsertionSort(int *arr, int len){
	if (arr == NULL)
		return;
	if (len <= 1)
		return;

	for (int i = 0; i < len - 1; i++){
		for (int j = i; j >= 0; j--){
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
			//来到else说明到这个位置已经有序了，所以break
			else{
				break;
			}
		}
	}
}

//希尔排序
void ShellSort(int *arr, int len){
	//gap 表示间隔的大小是多少
	for (int gap = (len / 3) + 1; gap >= 1; (gap /= 3) + 1){
		//group 表示当前在排序的是第几组 比如10个数gap等于5就一共5组
		for (int group = 0; group < gap; group++){
			//下面两个循环是对当前这个小组进行直接插入排序
			for (int i = group; i + gap < len; i += gap){
				for (int t = i; t >= group; t -= gap){
					if (arr[t] > arr[t + gap])
						swap(arr[t], arr[t + gap]);
					else
						break;
				}
			}
		}
	}
	return;
}

//冒泡排序
void bubble_sort(int* arr, size_t len){
	for (size_t i = 0; i < len - 1; i++){
		for (size_t j = 0; j < len - i - 1; j++){
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	return;
}

int main(){
	srand((unsigned int)time(NULL));
	int len = 20000;
	int arr[20000] = { 0 };
	for (int i = 0; i < len; i++){
		arr[i] = rand() % len;
	}
	clock_t start, end;
	start = clock();
	ShellSort(arr, len);
	end = clock();
	////想验证排序是否正确可以打印
	//for (size_t i = 0; i < len; i++){
	//	cout << arr[i] << ' ';
	//	if (i % 10 == 0)
	//		cout << endl;
	//}
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}