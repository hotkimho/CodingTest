#include <iostream>
#include <vector>
using namespace std;

int main() {    
    int arr[102];
    int output[102] = {0,};
    int n;
    
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    for (int i = n; i > 0; i--)
    {
        int j = i;
        for (int k = 0; k < arr[i]; k++)
        {
            output[j] = output[j + 1];
            j++;
        }
        output[j] = i;
    }

    for (int i = 1; i <= n; i++)
        cout<<output[i]<<" ";
}