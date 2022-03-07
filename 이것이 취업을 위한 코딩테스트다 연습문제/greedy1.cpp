#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
   return a > b;
}
int main() 
{  
   int N, M, K, count = 0, sum = 0;
   int arr[1002];

   cin >> N >> M >> K;
   for (int i = 0; i < N; i++)
      cin >> arr[i];
   sort(arr, arr + N, compare);
   
   for (int i = 0; i < M; i++)
   {
      if (count == K)
      {
         sum += arr[1];
         count = 0;
      }
      else
      {
         sum += arr[0];
         count++;
      }
   }
   cout << sum <<endl;

   
}