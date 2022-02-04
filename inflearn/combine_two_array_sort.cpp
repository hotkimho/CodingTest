#include <iostream>
#include <vector>
using namespace std;

int main() {    
    int arr[101];
    int arr2[101];
    int result[101];
    int n, n2;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> n2;
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    int fptr = 0, sptr = 0;
    for (int i = 0; i < n + n2; i++)
    {
        if (arr[fptr] < arr2[sptr])
        {
            result[i] = arr[fptr];
            fptr++;
        }
        else
        {
            result[i] = arr2[sptr];
            sptr++;
        }
        if (fptr == n || sptr == n2)
            break; 
    }
    
    if (fptr == n)
        for (int i = fptr + sptr; i < n + n2; i++)
            result[i] = arr2[sptr++];
    else
        for (int i = fptr + sptr; i < n + n2; i++)
            result[i] = arr[fptr++];
    for (int i = 0; i < n + n2; i++)
        cout<<result[i]<<" ";
}