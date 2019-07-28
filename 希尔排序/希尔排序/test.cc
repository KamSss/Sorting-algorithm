#include<iostream>
#include<algorithm>

using namespace std;

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

int main(){
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int len = 10;
	ShellSort(arr, len);
	for (int i = 0; i < 10; i++){
		cout << arr[i];
	}
	system("pause");
	return 0;
}