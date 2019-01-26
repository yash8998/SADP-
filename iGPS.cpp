#include<iostream>
#include<time.h>
using namespace std;


class iGps
{
  public:
  virtual int getMobileNetwork()=0;
  virtual bool isGpsWeak()=0;
};
