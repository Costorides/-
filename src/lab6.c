#include <stdio.h>
#define K 3
#define N 4
int main()
{
int x[K][N];
int i, j;
int flag;
flag = 0;
// ввод массива
// массив из K на N элементов
// среднее арифметическое
for( i = 0; i < K; i++ ) {
    for( j = 0; j < N; j++ ) {
        scanf("%d", &x[i][j]);
    }
}

for( i = 0; i < K; i++ ){
    for( j = 0; j < N; j++ )
    {
        if(x[i][j] != x[i][N-j-1])
            flag = 1;
    }
    if (flag == 0){
        for( j = 0; j < N; j++ )
        {
        x[i][j] = 0;
        }
    }
    else {
    flag = 0;
    }
 }

 // вывод массива
 for( i = 0; i < K; i++ )
 {
  for( j = 0; j < N; j++ ) {
   printf("%d ", x[i][j]);
  }
  printf("\n");
 }
 return 0;
}
