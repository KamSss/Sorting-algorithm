#include<iostream>
#include<algorithm>

using namespace std;

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
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	size_t len = 10;
	bubble_sort(arr, len);
	for (size_t i = 0; i < 10; i++){
		cout << arr[i];
	}
	system("pause");
	return 0;
}