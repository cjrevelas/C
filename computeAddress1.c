#include <stdio.h>

// address1:  100 (1,1,3,1) (base)
// address2:  106 (1,1,3,2)
// address3:  112 (1,2,3,1)
// address4:  118 (1,2,3,2)
// address5:  124 (1,3,3,1)
// address6:  130 (1,3,3,2)
// address7:  136 (2,1,3,1)
// address8:  142 (2,1,3,2)
// address9:  148 (2,2,3,1)
// address10: 154 (2,2,3,2)
// address11: 160 (2,3,3,1)
// address12: 166 (2,3,3,2)

int main() {

  int b = 100;
  int L = 6;

  int LL[4] = {1,1,3,1};
  int UU[4] = {2,3,3,2};
  int CC[5] = {0,0,0,0,L}; // c[4] = L

  for (int ii=4; ii>1; --ii) {
    CC[ii-1] = (UU[ii-1] - LL[ii-1] + 1) * CC[ii]; // CC[3] = (UU[3] - LL[3] + 1) * CC[4]
                                                   // CC[2] = (UU[2] - LL[2] + 1) * CC[3]
  }                                                // CC[1] = (UU[1] - LL[1] + 1) * CC[2]

  CC[0] = b - CC[1]*LL[0] - CC[2] * LL[1] - CC[3]*LL[2] - CC[4]*LL[3];

  // the last element: 100 + 11 * 6 = 166
  int i1 = 2;
  int i2 = 3;
  int i3 = 3;
  int i4 = 2;

  int address = CC[0] + CC[1]*i1 + CC[2]*i2 + CC[3]*i3 + CC[4]*i4;

  printf("The address of element (%d, %d, %d, %d) is: %d\n", i1, i2, i3, i4, address);

  return 0;
}
