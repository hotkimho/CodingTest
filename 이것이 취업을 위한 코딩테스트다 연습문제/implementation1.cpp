#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdio.h>
using namespace std;

int movedPos[8][8] = {
   {-1, -2},
   {+1, -2},
   {-1, +2},
   {+1, +2},
   {-2, +1},
   {-2, -1},
   {+2, +1},
   {+2, -1}
};

int getNumOfMoving(int (*map)[9], int x, int y)
{
   int count = 0;

   for (int i = 0; i < 8; i++)
   {
      int _y = y + movedPos[i][0];
      int _x = x + movedPos[i][1];
      if (_y >= 1 && _y <= 8 && _x >= 1 && _y <= 8)
         count++;
   }
   return count;
}

int main() 
{  
   int map[9][9];
   int x, y;
   string str;

   cin >> str;
   x = 98 - str[0];
   y = atoi(&str[1]);
   cout << getNumOfMoving(map, x, y);
}