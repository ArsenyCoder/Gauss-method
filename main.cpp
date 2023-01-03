#include <iostream>

using namespace std;

int greatest_common_divisor(int a, int b) {
  if (a % b == 0)
    return b;
  if (b % a == 0)
    return a;
  if (a > b)
    return greatest_common_divisor(a%b, b);
  return greatest_common_divisor(a, b%a);
}

int **set_array(int width,int height) {
    
}

int main()
{
    int **array;
    int a,b;
    cout<<"Введите длину, высоту системы:\n";
    cin >> a >> b;
    
    //cout << greatest_common_divisor(a,b);
    
    
    

    return 0;
}
