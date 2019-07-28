#include<iostream>
#include<algorithm>

using namespace std;

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

int main(){
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int len = 10;
	InsertionSort(arr, len);
	for (size_t i = 0; i < 10; i++){
		cout << arr[i];
	}
	system("pause");
	return 0;
}