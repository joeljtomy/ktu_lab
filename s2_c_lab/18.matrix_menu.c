#include <stdio.h>
#include <stdlib.h>

void getmat(int mat[][100], int row, int col)
{
  int i, j;
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      printf("Element (%d,%d): ", i + 1, j + 1);
      scanf("%d", &mat[i][j]);
    }
  }
}

void disp_mat(int mat[][100], int row, int col)
{
  int i, j;
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
      printf("%d\t", mat[i][j]);
    printf("\n");
  }
}

void add_mat(int a[][100], int b[][100], int row, int col)
{
  int sum[100][100], i, j;
  for (i = 0; i < row; i++)
    for (j = 0; j < col; j++)
      sum[i][j] = a[i][j] + b[i][j];
  printf("The sum of two matrices is:\n");
  disp_mat(sum, row, col);
}

void mul_mat(int a[][100], int b[][100], int r1, int c1, int c2)
{
  int pro[100][100], i, j, k, sum;
  for (i = 0; i < r1; i++)
  {
    for (j = 0; j < c2; j++)
    {
      sum = 0;
      for (k = 0; k < c1; k++)
      {
        sum += a[i][k] * b[k][j];
        pro[i][j] = sum;
      }
    }
  }
  printf("The product of two matrices is:\n");
  disp_mat(pro, r1, c2);
}

void mat_trans(int a[][100], int row, int col)
{
  int trans[100][100], i, j;
  for (i = 0; i < row; i++)
    for (j = 0; j < col; j++)
      trans[j][i] = a[i][j];
  printf("The matrix is:\n");
  disp_mat(a, row, col);
  printf("The transpose matrix is\n");
  disp_mat(trans, col, row);
}

int main()
{
  int mat1[100][100], mat2[100][100], r1, c1, r2, c2, opt;

  printf("Enter first matrix:\nrows: ");
  scanf("%d", &r1);
  printf("columns: ");
  scanf("%d", &c1);
  printf("Enter the elements:\n");
  getmat(mat1, r1, c1);

  printf("Enter second matrix:\nrows: ");
  scanf("%d", &r2);
  printf("columns: ");
  scanf("%d", &c2);
  printf("Enter the elements:\n");
  getmat(mat2, r2, c2);

  while (1)
  {
    printf("\nSelect operation from menu\n");
    printf("\t\tMENU\nl.Matrix addition\n2.Matrix multiplication\n3.Transpose of matrix\n4.Exit\n");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
      if (r1 == r2 && c1 == c2)
        add_mat(mat1, mat2, r1, r1);
      else
        printf("!!incompatable...can't add!!\n");
      break;
    case 2:
      if (c1 == r2)
        mul_mat(mat1, mat2, r1, c1, c2);
      else
        printf("!!incompatable...can't multiply!!\n");
      break;
    case 3:
      mat_trans(mat1, r1, c1);
      mat_trans(mat2, r2, c2);
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice!!!\n");
    }
  }
}