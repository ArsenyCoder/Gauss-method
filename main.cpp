#include<iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
 
int main()
{
   int i, j, n, m;
   cout << "введи число уравнений: ";
         cin >> n;
         cout << "введи число неизвестных: ";
         cin >> m;
         m+=1;
    float **matrix = new float *[n];
         for (i=0; i<n; i++)
             matrix[i] = new float [m];
 
//инициализируем
 
    for (i = 0; i<n; i++)
 
        for (j = 0; j<m; j++)
        {
            cout << "Элемент " << "[" << i+1 << " , " << j+1 << "]: "  ;
 
            cin >> matrix[i][j];
}
 
 //выводим массив
    cout << "matrix: " << endl;
      for (i=0; i<n; i++)
       {
          for (j=0; j<m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
       }
    cout << endl;
 
//Метод Гаусса
//Прямой ход, приведение к верхнетреугольному виду
    float  tmp, xx[m];
    int k;
 
    for (i=0; i<n; i++)
     {
       tmp=matrix[i][i];
         for (j=n;j>=i;j--)
             matrix[i][j]/=tmp;
           for (j=i+1;j<n;j++)
          {
             tmp=matrix[j][i];
               for (k=n;k>=i;k--)
             matrix[j][k]-=tmp*matrix[i][k];
          }
      }

    xx[n-1] = matrix[n-1][n];
     for (i=n-2; i>=0; i--)
       {
           xx[i] = matrix[i][n];
           for (j=i+1;j<n;j++) xx[i]-=matrix[i][j]*xx[j];
       }

        bool correct = true;
        for (i=0; i<n; i++) {
            if (to_string(xx[i]) == "-nan") {
                correct = false;
            }
        }

        if (correct) {
            for (i=0; i<n; i++) {
                cout << "X" << i + 1  << " = " << xx[i] << endl;
            }
            cout << endl;
        } else {
            cout << endl << "Нет решений!";
        }
 
    delete[] matrix;
 
   return 0;
}
