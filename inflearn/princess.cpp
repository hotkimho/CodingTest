#include <iostream>
#include <vector>
using namespace std;

int main() {  
    int N, K;
    int arr[10001];

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        arr[i] = 0;
    
    int idx = 1, count = 0;
    for (int i = 1; i < N; i++) {
        count = 0;
        while (1) {
            if (arr[idx] == 0)
                count++; 
            if (count == K)
                break;
            idx++;
            if (idx > N)
                idx = 1;
        }
        arr[idx] = 1;
    }
    for (int i = 1; i <= N; i++)
        if (arr[i] == 0)   
            cout<<i<<endl;
}