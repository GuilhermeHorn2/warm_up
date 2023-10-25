#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

bool interleaving_str(std::string &s1, std::string &s2, std::string &s3);

main()
{
 /* ?\n;||(or) e &&(and)*/

 std::string s1 = "aabcc";
 std::string s2 = "dbbca";
 std::string s3 = "aadbbcbcac";

 std::cout << interleaving_str(s1, s2, s3) << (char)10;
 s3 = "aadbfbcbcac";
 std::cout << interleaving_str(s1, s2, s3);

 return 0;
}

bool interleaving_str(std::string &s1, std::string &s2, std::string &s3)
{
 int curr_1 = 0;
 int curr_2 = 0;
 int k = 0;
 if (s3[0] == s1[0])
 {
  k = 0;
 }
 if (s3[0] == s2[0])
 {
  k = 1;
 }
 if (s3[0] != s1[0] && s2[0] != s3[0])
 {
  return false;
 }
 int i = 0;
 while (i < s3.size())
 {
  if (k == 0)
  {
   if (s1[curr_1] == s3[i])
   {
    curr_1++;
   }
   else
   {
    k = 1;
    if (s2[curr_2] != s3[i])
    {
     return false;
    }
    continue;
   }
  }
  if (k == 1)
  {
   if (s2[curr_2] == s3[i])
   {
    curr_2++;
   }
   else
   {
    k = 0;
    if (s1[curr_1] != s3[i])
    {
     return false;
    }
    continue;
   }
  }
  i++;
 }
 if (curr_1 + 1 >= s1.size() && curr_2 + 1 >= s2.size())
 {
  return true;
 }
 return false;
}
