#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

void print_vec(std::vector<int> &v);

void group_colors(std::vector<int> &v);

int main()
{
 /* ?\n;||(or) e &&(and)*/
 std::vector<int> v = {2, 0, 2, 1, 1, 0};
 group_colors(v);
 print_vec(v);

 return 0;
}

void print_vec(std::vector<int> &v)
{
 for (int i = 0; i < v.size(); i++)
 {
  std::cout << v[i] << ' ';
 }
 std::cout << (char)10;
}

void group_colors(std::vector<int> &v)
{
 // I just have to da a partition,where i pick the central element as pivot(must be 1)
 int n = v.size();
 if (v[n / 2] != -1)
 {
  int c = 0;
  while (v[c] != 1)
  {
   c++;
  }
  std::swap(v[c], v[n / 2]);
 }
 // partition
 int strt = 0;
 int end = n - 1;
 while (strt <= end)
 {
  while (v[strt] < 1)
  {
   strt++;
  }
  while (v[end] > 1)
  {
   end--;
  }
  if (strt <= end)
  {
   std::swap(v[strt], v[end]);
   strt++;
   end--;
  }
 }
}
