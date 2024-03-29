/*
 * File:   main.c
 * Author: papa
 *
 * Created on 1 июля 2019 г., 8:51
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int in;

  int out;

  float** matrix;

  float* hidden;

  float* errors;
} nnLay;


void
setIOWithMatrix (nnLay *curLay,float* _matrix, int rows, int elems)
{
  // создаем матрицу и считываем в нее из матрицы параметра
  float **matrix;
  matrix = (float**) malloc (rows * sizeof (float*));
  for (int row = 0; row < rows; row++)
    {

      matrix[row] = (float*) malloc (elems * sizeof (float));

    }
  for (int row = 0; row < rows; row++)
    {
      for (int elem = 0; elem < elems; elem++)
        {
          matrix[row][elem] = *(_matrix + row * elems + elem);

        }


    }

  // записываем в поле matrix
  curLay->matrix = matrix;
}

void
printMatrix (nnLay *curLay,int rows,int elems)
{
  for (int row = 0; row < rows; row++)
    {
      for (int elem = 0; elem < elems; elem++)
        {
          float elem_val = curLay->matrix[row][elem];
          printf ("%f ", elem_val);

        }
      printf ("\n");

    }

}

int
main (int argc, char** argv)
{
  float dense_1[2][2] = {
    {-0.6639823317527771, -1.148194670677185},
    {-0.959995687007904, -0.9399744272232056}
  };
  float *p=&dense_1;
  nnLay* lay = (nnLay*) malloc (sizeof (nnLay));

  setIOWithMatrix (lay,p, 2,2);
  printMatrix (lay,2,2);
/*
--->  -0.663982 -1.148195
      -0.959996 -0.939974
*/


  return (EXIT_SUCCESS);
}

