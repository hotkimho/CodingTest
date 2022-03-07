#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{  
   int N, K;
   int count = 0;

   cin >> N >> K;
   while (N != 1)
   {
      if (N % K == 0)
         N = N / K;
      else
         N -= 1;
      count++;
   }
   cout << count;
}