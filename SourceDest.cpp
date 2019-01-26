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

class SourceDest : public iSourceDest
{
  private:
    string source;
    string destination;
    int source_index;
    int dest_index;

  public:
    void getSourceDest(const iMap &imapObj);
    bool validateLocation(const iMap &imapObj, string source, string destination);
    void setSourceIndex(int s_index);
    void setDestIndex(int d_index);
    int getSourceIndex();
    int getDestIndex();
};

/*
 * Used to check the source and destination entered by the user
 * @param vector location list of valid locations
 */
void SourceDest :: getSourceDest(const iMap &imapObj)
{
    do
    {
      cout<<"----------------------"<<endl;
      cout<<"Enter Source Location : ";
      cin>>source;
      cout<<"Enter Destination Location : ";
      cin>>destination;
      cout<<endl;
      cout<<"----------------------"<<endl;
      cout<<"Validating Information"<<endl;
    }while(!validateLocation(imapObj,  source,  destination));
    cout<<"Information is valid"<<endl;
    cout<<"----------------------"<<endl;
}

/*
 * helper function used for validating the locations
 * @param vector location list of valid locations
 * @param string source source location
 * @param string destination destination location
 * @return bool true if locations are valid
 */
bool SourceDest :: validateLocation(const iMap &imapObj, string source, string destination)
{
  int source_index = -1;
  int dest_index = -1;
    /*
     * Iterating through the vector of locations
     */

     //--- size shouldnt be 0. Unable to access Map.cpp
     cout<<imapObj.location.size()<<endl;
     //----
    for (int i=0; i<imapObj.location.size(); i++)
    {
        /*
         * source location found in the vector
         * and stores the index at which the location
         * was found
         */
        if(imapObj.location[i] == source)
        {
            source_index = i;
            setSourceIndex(source_index);
        }

        /*
         * destination location found in the vector
         * and stores the index at which the location
         * was found
         */
        if(imapObj.location[i] == destination)
        {
            dest_index = i;
            setDestIndex(dest_index);
        }

    }

        /*
         * source and destination locations
         * must be different
         */
        if(source == destination)
        {
            cout<<"Source and destination cannot be the same"<<endl;
            cout<<"Invalid input"<<endl;
            return false;
        }

    /*
     * the source and destination indices were
     * modified, as the location was found
     * Hence, they are valid
     */

    if(source_index!=-1 && dest_index!=-1)
    {
        cout<<"Locations are valid"<<endl;
        return true;
    }

    /*
     * if either the source and destination indices were
     * not modified, the location was not found
     * Hence, the location/ locations are invalid
     */
    cout<<"Source OR Destination is invalid"<<endl;
    return false;
}


void SourceDest :: setSourceIndex(int s_index)
{
    source_index = s_index;
}


void SourceDest :: setDestIndex(int d_index)
{
  dest_index = d_index;
}


int SourceDest:: getSourceIndex()
{
    return source_index;
}

int SourceDest :: getDestIndex()
{
  return dest_index;
}
