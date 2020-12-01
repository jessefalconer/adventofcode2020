#include <iostream>
#include <vector>
using namespace std;

#define is2020(x) (x == 2020)

int add (int x, int y) {
  int sum;
  sum=x+y;
  return sum;
}

int multiply (int x, int y){
  int product;
  product=x*y;
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
  int maxSize = report.size();

  for (int x=0; x<maxSize-1; x++)
    for (int y=x+1; y<maxSize; y++)
    {
      int sum;
      sum=add(report[x], report[y]);
      if (is2020(sum)) {
        cout << multiply(report[x], report[y]);
      }
    }
}
