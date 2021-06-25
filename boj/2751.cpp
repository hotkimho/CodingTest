#include <iostream>
#include <algorithm>
using namespace std;


//임의의 다른 저장할 배열이 필요하다.
//전역 변수로 사용해야하는것인가 아니면 일일히 동적할당 해야하는것인가?
int tmp[1000002];
void merge(int arr[], int start, int middle, int end)
{
	int i = start;
	int j = middle + 1;
	int k = start;

	while (i <= middle && j <= end)
	{
		if(arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	
	while (i <= middle)
		tmp[k++] = arr[i++];
	while (j <= end)
		tmp[k++] = arr[j++];
	for (int i=start; i<=end; i++) arr[i] = tmp[i];
}

void mergeSort(int arr[], int start, int end)
{
	int middle;

	if (start < end)
	{
		middle = (start + end) / 2;
		mergeSort(arr, start, middle);
		mergeSort(arr, middle + 1, end);
		
		merge(arr, start, middle, end);
	}

}
