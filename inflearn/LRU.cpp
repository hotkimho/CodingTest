#include <iostream>
using namespace std;

void cacheMiss(int *arr, int num, int size)
{
    for(int i = size - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = num;
}

void cacheHit(int *arr, int keyIdx, int size)
{
    int key = arr[keyIdx];
    
    for (int i = keyIdx - 1; i >= 0; i--)
        arr[i + 1] = arr[i];
    arr[0] = key;
    
}

int findCache(int *arr, int n, int size)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == n)
            return i;
    return -1;
}

int main() {    
    int n,s;
    int arr[1000]={0,};
    cin>>n >> s;
    for (int i = 0; i < s; i++)
    {
        cin>>arr[i];
        int findIdx = findCache(arr, arr[i], n);
        if (findIdx >= 0)
            cacheHit(arr, findIdx, n);
        else
            cacheMiss(arr, arr[i], n);
    }
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}