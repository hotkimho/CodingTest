#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{  
   int N, M;
   int arr[102][102];
   
   cin >> N >> M;
   int j, min, max = -1;
   for (int i = 0; i < N; i++) 
   {
	   min = 10000;
      for (j = 0; j < M; j++)
         cin >> arr[i][j];
	   for (j = 0; j < M; j++)
		   if (arr[i][j] < min)
		      min = arr[i][j];
      arr[i][j] = min;
   }
   for (int i = 0; i< N; i++)
      if (max < arr[i][M])
         max = arr[i][M];
   cout << max;
}