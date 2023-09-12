#include <iostream>
using namespace std;

// int main() {
//     int n = 1000;
//     int *a = (int*)malloc(sizeof(int)*1000);
//     int *p = a;
//     while(p < a + n) {
//         cout << *p++ << endl; // 打印1000个0
//     }
//     int *q = a++;
//     cout << *q << endl;
// }

/* Reverses a series of numbers (pointer version) */
#include <stdio.h>
#define N 10
int main(void)
{
  int a[N], *p;
  printf("Enter %d numbers: ", N);
  for (p = a; p < a + N; p++)
    scanf("%d", p);
  printf("In reverse order:");
  for (p = a + N - 1; p >= a; p--)
    printf(" %d", *p);
  printf("\n");
  return 0;
}