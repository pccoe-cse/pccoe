#include<bits/stdc++.h>

using namespace std;

int x[4][4] = {{0, 0, 0, 0},
               {0, 0, 0, 0},
               {0, 0, 0, 0},
               {0, 0, 0, 0}};

bool checker(int row, int columns)
{
  int i, j;
  for(i = 0; i < row; i++)
  {
    if(x[i][columns] == 1)
    return false;
  }

  for(i  = row, j = columns; i >= 0 && j >= 0; i--, j--)
  {
    if(x[i][j] == 1)
    return false;
  }
  for(i  = row, j = columns; i >= 0 && j < 4 ; i--, j++)
  {
    if(x[i][j] == 1)
    return false;
  }

  return true;

}

bool nqueen(int row)
{
  if(row >= 4)
  {
    return true;
  }
  for(int i = 0; i < 4; i++)
  {
    if(checker(row, i))
    {
      x[row][i] = 1;
      if(nqueen(row + 1))
      {return true;}
      x[row][i] = 0;
    }

   
  }
  return false;
}

int main()
{
  nqueen(0);
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      cout << x[i][j] << "\t";
    }
    cout << endl;
  }
}