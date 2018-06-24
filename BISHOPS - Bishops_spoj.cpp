#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
namespace mp = boost::multiprecision;

using namespace std;

int main()
{
   mp::cpp_int n;
   
   while(cin >> n)
   {
      if(n == 1)
         cout << 1 << endl;
      else
         cout << 2*n-2 << endl;
   }
}