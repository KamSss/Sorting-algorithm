#include<iostream>
#include<algorithm>
#include<time.h>
#include<stdlib.h>

using namespace std;

//��������
void InsertionSort(int *arr, int len){
	if (arr == NULL)
		return;
	if (len <= 1)
		return;

	for (int i = 0; i < len - 1; i++){
		for (int j = i; j >= 0; j--){
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
			//����else˵�������λ���Ѿ������ˣ�����break
			else{
				break;
			}
		}
	}
}

//ϣ������
void ShellSort(int *arr, int len){
	//gap ��ʾ����Ĵ�С�Ƕ���
	for (int gap = (len / 3) + 1; gap >= 1; (gap /= 3) + 1){
		//group ��ʾ��ǰ��������ǵڼ��� ����10����gap����5��һ��5��
		for (int group = 0; group < gap; group++){
			//��������ѭ���ǶԵ�ǰ���С�����ֱ�Ӳ�������
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

//ð������
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
	////����֤�����Ƿ���ȷ���Դ�ӡ
	//for (size_t i = 0; i < len; i++){
	//	cout << arr[i] << ' ';
	//	if (i % 10 == 0)
	//		cout << endl;
	//}
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}