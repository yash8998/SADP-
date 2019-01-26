/*
 * This file is used to run the application
 */
#include<iostream>
#include<vector>
#include<iterator>
#include<utility>
//#include<iMap>

#include "iSourceDest.cpp"
#include "SourceDest.cpp"
#include "iMap.h"

//#include "iMap.cpp"
#include "Map.cpp"
#include "iEta.cpp"
#include "Eta.cpp"
#include "iChangeBus.cpp"
#include "ChangeBus.cpp"
#include "iGPS.cpp"
#include "GPS.cpp"

using namespace std;

int main()
{
  //write login/signup routine/function here

  /*
  * Run the map class
  */
  iMap *imap_obj = new Map();
  imap_obj->locationList();
  imap_obj->populateGraph();

  /*
  * Source/Dest
  */
  iSourceDest *isd_obj = new SourceDest();
  isd_obj->getSourceDest(*imap_obj);

  int s_index = isd_obj->getSourceIndex();
  //cout<<"Source index = "<<s_index<<endl;
  int d_index = isd_obj->getDestIndex();
  //cout<<"Dest index = "<<d_index<<endl;

  /*
  * ETA
  */
  iEta *ieta_obj = new Eta();
  ieta_obj->decrementTime(*imap_obj, s_index,d_index);


  return 0;
}
