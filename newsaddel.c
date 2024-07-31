#include<stdio.h>

int main ()
{ 
  int min, max, row, col, c, i, j;
  scanf ("%d %d", &row, &col);
  int M[row][col];
  if(row == 0){
      printf ("-2");
  }
  for ( i = 0; i < row; i++) {
	  for ( j = 0; j < col; j++){
	      scanf ("%d", &M[i][j]);
	    }
	}
	
    for ( i = 0; i < row; i++){
	  min = M[i][0];
	  c = 0;
	  for (j = 0; j < col; j++)
	    {
	      if (M[i][j]<min)
		{
		  min = M[i][j];
		  c = j;
		}
	    }
	}
    max = M[0][c];
    for ( i = 0; i < row; i++){
      if ( M[i][c] > max){
          max = M[i][c];
        }
	  if (min == max){
	      printf ("  %d %d", i, c);
	    }
	}
    if (min != max){
	  printf ("-1");
	}
}
