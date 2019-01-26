#include<iostream>
using namespace std;

class iChangeBus
{
  private:
  int busNumber;

  public:
    virtual void enterBusNumber()=0;
    virtual bool validate(int bus_no)=0;
};
