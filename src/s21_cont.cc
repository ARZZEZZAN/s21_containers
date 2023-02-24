#include <iostream>
#include <vector>
using namespace std;

// шаблоны функции

// T условное нахвание типа
template <typename T1, typename T2>
T2 Sum(T1 a, T2 b) {
  return a + b;
}

// int main() {
//   cout << Sum(5100, 10.5) << endl;
//   vector<int> a = {1, 2, 3.4};
//   for (int i = 0; i < int(a.size()); i++) {
//     cout << a[i] << " ";
//   }
//   return 0;
// }
