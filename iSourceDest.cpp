/*
* This file is used to get the source and destination location
* from the user and validate the location
*
* This file is used to decrement the time/ distance
* remaining as the user is traveling
*{ code from Screen1, Screen5}
*/

#include<iostream>
#include<vector>
#include<iterator>
#include "iMap.h"
//#include "iMap.cpp"
using namespace std;

class iSourceDest
{
  private:
    /*
     * global variables
     */
    string source;
    string destination;

  public:

    /*
     * function declaration
     */
    virtual void  getSourceDest(const iMap &imapObj)=0;
    virtual bool validateLocation(const iMap &imapObj, string source, string destination)=0;
    virtual void setSourceIndex(int s_index)=0;
    virtual void setDestIndex(int d_index)=0;
    virtual int getSourceIndex()=0;
    virtual int getDestIndex()=0;

};
