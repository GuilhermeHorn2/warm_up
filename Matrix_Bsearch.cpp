#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

int search_row(std::vector<std::vector<int>> &v, int x, int y, int val);
int search_column(std::vector<std::vector<int>> &v, int x, int y, int val);
int matrix_search(std::vector<std::vector<int>> &v, int val);

int main()
{
 /* ?\n;||(or) e &&(and)*/

 std::vector<int> v0 = {1, 3, 5, 7};
 std::vector<int> v1 = {10, 11, 16, 20};
 std::vector<int> v2 = {23, 30, 34, 60};
 std::vector<std::vector<int>> v = {v0, v1, v2};

 int res = matrix_search(v, 61);

 std::cout << res;

 return 0;
}

int search_column(std::vector<std::vector<int>> &v, int x, int y, int val)
{
 // y is fixed
 int strt = 0;
 int end = v.size();
 int mid;

 while (strt < end)
 {
  int mid_idx = (strt + end) / 2;
  mid = v[mid_idx][y];
  if (mid == val)
  {
   return mid_idx;
  }
  if (mid > val)
  {
   end = mid_idx - 1;
  }
  if (mid < val)
  {
   strt = mid_idx + 1;
  }
 }
 return -1;
}

int search_row(std::vector<std::vector<int>> &v, int x, int y, int val)
{
 // x is fixed
 int strt = 0;
 int end = v.size();
 int mid;

 while (strt < end)
 {
  int mid_idx = (strt + end) / 2;
  mid = v[x][mid_idx];
  if (mid == val)
  {
   return mid_idx;
  }
  if (mid > val)
  {
   end = mid_idx - 1;
  }
  if (mid < val)
  {
   strt = mid_idx + 1;
  }
 }
 return -1;
}

int matrix_search(std::vector<std::vector<int>> &v, int val)
{
 // O(lg(n)+lg(m)=lg(n+m))
 int strt = 0;
 int end = v.size();

 while (strt < end)
 {
  int mid = (strt + end) / 2;
  if (v[mid][mid] == val)
  {
   return 1;
  }
  if (search_row(v, mid, mid, val) != -1)
  {
   return 1;
  }
  if (search_column(v, mid, mid, val) != -1)
  {
   return 1;
  }
  if (v[mid][mid] > val)
  {
   end = mid - 1;
  }
  if (v[mid][mid] < val)
  {
   strt = mid + 1;
  }
 }
 return 0;
}
