#include <iostream>
#include <vector>
using namespace std;

//9 3
//1 2 3 4 5 6 7 8 9
//결정 알고리듬
int musicVideo(int *arr, int N, int M) {
    int start = 1, end = 0;
    int min = 9999999, count;

    for (int i = 0; i < N; i++)
        end += arr[i];
    
    while (start <= end) {
        int sumOfStartAndEnd = (start + end) / 2;
        int i, count = 0, sum = 0;
        
        for (i = 0; i< N; i++) {
            if (sum + arr[i] > sumOfStartAndEnd) {
                count++;
                sum = arr[i];
            }
            else 
                sum += arr[i];
        }
        
        if (count == M - 1 && i == N) {
            if (min > sumOfStartAndEnd)
                min = sumOfStartAndEnd;
            end = sumOfStartAndEnd - 1;
        }
        else if (count < M) 
            end = sumOfStartAndEnd - 1;
        else 
            start = sumOfStartAndEnd + 1;
        
    }
    return min;
}
int main() {    
    int arr[1002];
    int N, M, sum = 0;
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout<<musicVideo(arr, N, M);
}