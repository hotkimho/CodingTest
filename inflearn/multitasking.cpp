#include <iostream>
#include <vector>
using namespace std;

int main() {  
   int N, K, sum = 0;;
   int arr[2001] ={0,};

   cin >> N;
   for (int i = 1; i <= N; i++){
       cin >> arr[i];
       sum += arr[i];
   }
   cin >> K;
   if (sum <= K) {
       cout<<-1<<endl;
       return 0;
   }

   int j = 1;
   int i = 0;
   while (i < K) {
       if (arr[j++]) {
            arr[j - 1]--;
            i++;
       }
       if (j > N)
            j = 1; 
   }
   while (1) {
       if (arr[j]) break;
       if (j > N) j = 1;
       j++;
   }
   cout<<j<<endl;
}