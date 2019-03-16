#include <iostream>
#include "Matrix_impl.h"
using namespace std;

int main()
{
  const Matrix<int, 3, 2> m1; // Creates 3*2 matrix, with all the default elements set to 0;
  //Matrix<int, 3, 3> m2(4);  // Creates 3*3 matrix, with the default elements equals to 4;
  //const Matrix<int, 3, 3> m3 = m2; // C-py constructor may take O(MN) and not O(1).

    return 0;
}
