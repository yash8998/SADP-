/*
* This file is used by the Driver to
* change/set the bus number
*/

#include<iostream>
using namespace std;

class ChangeBus : public iChangeBus
{
  private:
  int busNumber;

  public:
    void enterBusNumber();
    bool validate(int bus_no);
};

bool ChangeBus :: validate(int bus_no)
{
    if(bus_no < 600 && bus_no > 0)
    {
      return true;
    }
    return false;
}

void ChangeBus :: enterBusNumber()
{

  cout<<"Enter the bus number"<<endl;
  cin>>busNumber;

  while(!validate(busNumber))
  {
    cout<<"Bus number is invalid"<<endl;
    cout<<"Re enter bus number"<<endl;
  }

  cout<<"Bus number is invalid"<<endl;
}
