#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

class node
{
public:
 int data;
 node *next;
 node(int x)
 {
  data = x;
 }
 ~node() {}
};

class linked_list
{
public:
 node *strt;
 int len = 0;
 linked_list() {}
 ~linked_list() {}
 // push
 void push(int x)
 {
  node *novo = new node(x);
  novo->next = nullptr;

  if (len == 0)
  {
   strt = novo;
   len++;
   return;
  }
  novo->next = strt;
  strt = novo;
  len++;
 }
 // pop_top
 int pop_top()
 {
  int x = strt->data;
  strt = strt->next;
  len--;
  return x;
 }
 // is_empty
 bool is_empty()
 {
  if (len == 0)
  {
   return true;
  }
  return false;
 }
 // reverse_itr
 void reverse_itr()
 {
  node *itr = strt;
  node *last = nullptr;
  while (itr != nullptr)
  {
   // a -> b -> c => a <- b -> c
   node *prox = itr->next;
   itr->next = last;
   last = itr;
   itr = prox;
  }
  strt = last;
 }
 // reverse_rec
 void reverse_rec(node *itr, node *last)
 {
  if (itr == nullptr)
  {
   strt = last;
   return;
  }
  node *prox = itr->next;
  itr->next = last;
  last = itr;
  itr = prox;
  reverse_rec(itr, last);
 }
 // iterate in list
 void itr_list()
 {
  node *itr = strt;
  while (itr != nullptr)
  {
   std::cout << itr->data << (char)32;
   itr = itr->next;
  }
  std::cout << (char)10;
 }
};

main()
{
 /* ?\n;||(or) e &&(and)*/
 linked_list *l = new linked_list();
 l->push(1);
 l->push(2);
 l->push(3);
 l->itr_list();
 l->reverse_itr();
 l->itr_list();

 return 0;
}
