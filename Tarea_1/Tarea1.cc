//Program that finds the perimeter, volume and area of a pool

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;



void pool()
{
  //variable declaration
  double high [8] = {25.0, 25.0, 25.0, 25.0, 30.0, 30.0, 30.0, 30.0};
  double width [8] = {10.0, 10.0, 10.0, 10.0, 12.0, 12.0, 12.0, 12.0};
  double depth [8] = {5.0, 5.5, 6.0, 6.5, 5.0, 5.5, 6.0, 6.5};
  double sum, product, perimeter, volume, area;
  int i;

  //print in screen
  cout << "high     " << "width    " << "depth    " << "perimeter " << "volume   " << "area     " << endl;
  cout << "******** " << "******** " << "******** " << "********* " << "******** " << "******** " << endl;

  for (i=0; i<8;++i)
  {
    //instruction high + width
    sum = high[i] + width[i];
    //instruction high * width
    product = high[i] * width[i];

    //define operations
    perimeter = 2*sum;
    volume = product*depth[i];
    area = perimeter*depth[i]+product;

    //output values of operations with format
    cout << setw(9) << setiosflags(ios::showpoint) << setprecision(3) << setiosflags(ios::left)
         << high[i]
         << setw(9) << setiosflags(ios::showpoint) << setprecision(3) << setiosflags(ios::left)
         << width[i]
         << setw(9) << setiosflags(ios::showpoint) << setprecision(2) << setiosflags(ios::left)
         << depth[i]
         << setw(10) << setiosflags(ios::showpoint) << setprecision(3) << setiosflags(ios::left)
         << perimeter
         << setw(9) << setiosflags(ios::showpoint) << setprecision(5) << setiosflags(ios::left)
         << volume
         << setw(9) << setiosflags(ios::showpoint) << setprecision(4) << setiosflags(ios::left)
         << area << endl;

  }

}

int main()
{
  //call the function pool()
  pool();

  return 0;
}
