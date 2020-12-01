#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define is2020(x) (x == 2020)
#define exceeds2020(x) (x > 2020)

int add (int x, int y, int z) {
  int sum;
  sum=x+y+z;
  return sum;
}

int multiply (int x, int y, int z){
  int product;
  product=x*y*z;
  return product;
}

int main()
{
  vector <int> report {
    1721,
    979,
    366,
    299,
    675,
    1456
  };
  std::sort(report.begin(), report.end());

  int maxSize = report.size();

  for (int x=0; x<maxSize-2; x++)
    for (int y=x+1; y<maxSize-1; y++) {
        int sum;
        sum = add(report[x], report[y], 0);

        if (exceeds2020(sum)) {
          break;
        }

        for (int z=y+1; z<maxSize; z++) {
          int sum;
          sum = add(report[x], report[y], report[z]);

          if (is2020(sum)) {
            cout << multiply(report[x], report[y], report[z]);
            }
            else if (exceeds2020(sum)) {
              break;
            }
        }
      }
}
