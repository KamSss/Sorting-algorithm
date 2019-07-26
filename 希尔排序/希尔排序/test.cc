#include<iostream>
#include<algorithm>

using namespace std;

void ShellSort(int *arr, size_t len){
	//size_t gap = (len / 3) + 1;
	for (size_t gap = len/2; gap >= 1;gap /= 2){
		for (size_t i = 0; i < len;i += gap){
			for (size_t j = 0; j < len/gap; j++){
				if (arr[j] > arr[j + gap])
					swap(arr[j], arr[j + gap]);
			}
		}
	}
	return;
}
int main(){
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	size_t len = 10;
	ShellSort(arr, len);
	for (size_t i = 0; i < 10; i++){
		cout << arr[i];
	}
	system("pause");
	return 0;
}