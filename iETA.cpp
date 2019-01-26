/*
 * This file is used to trigger the alarm
 * when the delimiter value has been reached
 * i.e if time remaining is 5 minutes
 * or distance remaining is 500 m
* This file is used to calculate
* the time and distance to reach the destination
*code from {calculation, Alarm}
*/


#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<iterator>
using namespace std;

class iEta
{
  public:
    virtual void alarmTrigger()=0;
    virtual int* HoursMinute(int time)=0;
    virtual int calculateDistance(const iMap &imapObj, int sindex, int dindex)=0;
    virtual int calculateTime(const iMap &imapObj, int sindex, int dindex)=0;
    virtual void decrementTime(const iMap &imapObj, int source_index, int dest_index)=0;
    virtual void goToStart()=0;
};
