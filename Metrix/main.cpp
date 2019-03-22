#include <iostream>
#include "include\Matrix_impl.h"

using namespace std;

int main()
{
  const Matrix<int, 3, 2> m1; // Creates 3*2 matrix, with all the default elements set to 0;
  Matrix<int, 3, 3> m2(4);  // Creates 3*3 matrix, with the default elements equals to 4;
  const Matrix<int, 3, 3> m3 = m2; // C-py constructor may take O(MN) and not O(1).

    // min() returns the minimal value in the matrix.
  /*if (min(m1) < min(m3))
    */
    cout << "Min value of m3 is bigger";

    Matrix<int, 3, 3> m4;
    m4 = m3;
      for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
          m4(i, j) = i+j;
        }
      }
  cout << "m4[1][1] = " << m4(1,1);  // m4(1,1) same result as m4[1][1]
      /*
    cout << "m3[1][1] = " << m3[1][1];
*/
    Matrix<int, 3, 3> m5(3);
    m5 = 2 * m4;


    return 0;
}
