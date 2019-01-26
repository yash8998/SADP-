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

class Eta : public iEta
{
  public:
    void alarmTrigger();
    int* HoursMinute(int time);
    int calculateDistance(const iMap &imapObj, int sindex, int dindex);
    int calculateTime(const iMap &imapObj, int sindex, int dindex);
    void decrementTime(const iMap &imapObj, int source_index, int dest_index);
    void goToStart();
};

/*
 * triggers the alarm
 */
void Eta :: alarmTrigger()
{
    char stop ;
    cout<<"*ALERT*ALERT*ALERT*ALERT*"<<endl;

    cout<<"Alarm Rings"<<endl;
    cout<<"Almost there! Wake Up!"<<endl;
    cout<<"Enter X to stop alarm"<<endl;
    cin>>stop;

    /*
     * alarm is ringing
     *  Enter X/x to stop the alarm
     */
    while(stop!='X' && stop != 'x')
    {
        cout<<"Enter X to stop alarm"<<endl;
        cin>>stop;
    }
    cout<<"----------------------"<<endl;

    /*
     * go to the initial screen of the application
     */
    goToStart();

}

/*
 * converts minutes to hours and minutes
 * @return int ptr to an array
 */
int* Eta :: HoursMinute(int time)
{
    int *arr = new int[100];
    /*
     * arr[0] stores the hours
     * arr[1] stores the minutes
     */
    arr[0] = time / 60;
    arr[1] = time % 60;

    return arr;
}

/*
 * calculates the distance from the source to the destination
 * @param vector adjList[] stores the edges of the graph
 * @param int sindex source index
 * @param int dindex destination index
 * @param int distance distance to reach destination
 */
int Eta :: calculateDistance(const iMap &imapObj, int sindex, int dindex)
{
    int distance;
    /*
     * iterates through the graph
     * the endpoint and the distance are stored in a pair
     */
    vector<pair<int, int> > ::iterator itr;
    for (itr = imapObj.adjList[sindex].begin(); itr != imapObj.adjList[sindex].end(); itr++)
    {
            /*
             * if it finds the destination index in the adjacency list
             * it returns the distance/weight of that edge
             */
            if (itr->first == dindex)
            {
                distance = itr->second;
                cout << "Destination is " << distance << " km away" << endl;
                break;
            }
    }

    return distance;
}
/*
 * calculates the time from the source to the destination
 * Assumption: 1 km takes 5 minutes
 * @param vector adjList[] stores the edges of the graph
 * @param int sindex source index
 * @param int dindex destination index
 * @return int time time to reach destination
 */
int Eta :: calculateTime(const iMap &imapObj, int sindex, int dindex)
{
    /*
     * distance to minute converter
     *  1 km = 5 mins
     */
    int distToTimeConvert = 5;
    /*
     * calculates the distance
     */
    int distance = calculateDistance(imapObj, sindex, dindex);
    /*
     * converts distance to time
     */
    int time = distToTimeConvert*distance;

    /*
     * if time is greater than 60 minutes,
     * then it calls HoursMinutes converter
     */
    if (time >= 60)
    {
        int *ptr = HoursMinute(time);

        /*
         * if-else statement is for better readability
         * i.e instead of printing 1 hours it will print 1 hour
         */
        if (ptr[0] == 1 && ptr[1] == 0)
        {
            cout << "Time to destination is " << ptr[0] << " hour " << ptr[1] << " minute " << endl;
        } else if (ptr[0] == 1)
        {
            cout << "Time to destination is " << ptr[0] << " hour " << ptr[1] << " minutes " << endl;
        } else if (ptr[1] == 0)
        {
            cout << "Time to destination is " << ptr[0] << " hours " << ptr[1] << " minute " << endl;
        } else
        {
            cout << "Time to destination is " << ptr[0] << " hours " << ptr[1] << " minutes " << endl;
        }
    }
    /*
     * time is less than 60 minutes
     */
    else
    {
        cout << "Time to destination is " << time << " minutes" << endl;
    }

    return time;
}

/*
 * decrements the time while traveling
 * and triggers the alarm when the delimiter is reached
 * i.e when time remaining is 5 minutes
 * @param int sindex source index
 * @param int dindex destination index
 * @return int time remaining
 */
void Eta :: decrementTime(const iMap &imapObj, int source_index, int dest_index)
{
    int time = 0;
    time = calculateTime(imapObj, source_index, dest_index);

    /*
     * decrements of 1 minute
     */
    while(time > 5)
    {
        time -=1;
        cout<<"Time to destination is "<<time<<" minutes"<<endl;
    }
        cout<<"----------------------"<<endl;

     /*
      * time remaining is 5 minutes or less
      */
    alarmTrigger();
}


/*
 * used to exit the application
 */
void Eta:: goToStart()
{
    char q_char;
    cout<<"Enter Q to quit"<<endl;
    cin>>q_char;
    /*
     * when Q/q is entered, the application quits
     */
    while(q_char!='Q' && q_char !='q')
    {
        cout<<"Enter Q to quit"<<endl;
        cin>>q_char;
    }
    cout<<"----------------------"<<endl;
     exit(0);
}
