/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr testA;
  string a = "hello";
  string b = "my";
  string c = "name";
  string d = "is";
  string e = "erika";

  testA.push_back(a);
  testA.push_back(b);
  testA.push_back(c);
  testA.push_back(d);
  testA.push_back(e);
  
  cout << testA.get(0) << endl; //should print hello 
  cout << testA.get(1) << endl; //should print my 
  cout << testA.get(2) << endl; //should print name 
  cout << testA.get(3) << endl; //should print is  
  cout << testA.get(4) << endl; //should print erika 


  string f = "position 5";
  string g = "position 6";
  string h = "position 7";
  string i = "position 8";
  string j = "position 9";
  string k = "position 10";
  string l = "position 11";
  string m = "position 12";


  testA.push_back(f);
  testA.push_back(g);
  testA.push_back(h);
  testA.push_back(i);
  testA.push_back(j);
  testA.push_back(k);
  testA.push_back(l);
  testA.push_back(m);


  cout << testA.size() << endl; //size should be 2 
  cout << testA.get(12) << endl; // should print position 12


  //****POP BACK TEST:
 // testA.pop_back();
//cout << testA.get(12) << endl; // should create a seg fault   -- did create a seg fault, so passed the test

  string n = "should have made a new node when pushing front this string, and this is now at index 9";

  testA.push_front(n);

  cout << testA.size() << endl; //size should be 3
  cout << testA.get(9) << endl; // should print string n
  cout << testA.get(10) << endl; // should print hello


  string o = "new position 8";
  testA.push_front(o);
  cout << testA.get(8) << endl; // should print string new position 8

  string z = "new position 7";
  testA.push_front(z);
  cout << testA.get(7) << endl; // should print string new position 7



  ULListStr testB;
  string aB = "new List"; 

  testB.push_front(aB); //testing push front on an empty list

  cout << testB.get(9) << endl; // should print string aB

  



  









  return 0;
}
