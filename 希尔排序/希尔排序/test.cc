#include<iostream>
#include<algorithm>

using namespace std;

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