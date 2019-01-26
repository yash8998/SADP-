/*
 * This file is used to load the map
 * using a graph
 * distance is stored in kilometres
 */

#include<iostream>
#include<vector>
#include<iterator>
#include<list>
#include<utility>
using namespace std;

class Map : public iMap
{
  private:
    vector<string> location;
    vector<pair<int,int> > *adjList;

  public:
    void addEdge(int u, int v, int w);
    void populateGraph();
    void locationList();
    friend class SourceDest;
    friend class iSourceDest;
};

/*
 * building the graph by connecting the edges
 * @param int u is the starting vertex
 * @param int v is the ending vertex
 * @param int w is the distance/ weight
 */
void Map :: addEdge(int u,int v, int w)
{
    /*
     * the graph is implemented using a undirected graph
     * using STL and adjacency list representation
     */
    adjList[u].push_back(make_pair(v, w));
    adjList[v].push_back(make_pair(u, w));
}

/*
 * used to load the graph with appropriate edges
 */
void Map :: populateGraph()
{
    adjList = new vector<pair<int,int> >[10];
    /*
     * calls addEdge() function and stores the edge
     */
    addEdge(0, 1, 10);
    addEdge( 0, 2, 20);
    addEdge( 0, 3, 30);
    addEdge( 0, 4, 40);
    addEdge( 0, 5, 50);
    addEdge( 0, 6, 60);
    addEdge( 0, 7, 70);
    addEdge( 0, 8, 80);
    addEdge( 0, 9, 90);

    addEdge( 1, 2, 30);
    addEdge( 1, 3, 40);
    addEdge( 1, 4, 50);
    addEdge( 1, 5, 30);
    addEdge( 1, 6, 40);
    addEdge( 1, 7, 50);
    addEdge( 1, 8, 30);
    addEdge( 1, 9, 40);

    addEdge( 2, 3, 60);
    addEdge( 2, 4, 70);
    addEdge( 2, 5, 50);
    addEdge( 2, 6, 40);
    addEdge( 2, 7, 60);
    addEdge( 2, 8, 70);
    addEdge( 2, 9, 90);


    addEdge( 3, 4, 100);
    addEdge( 3, 5, 45);
    addEdge( 3, 6, 35);
    addEdge( 3, 7, 65);
    addEdge( 3, 8, 50);
    addEdge( 3, 9, 70);

    addEdge( 4, 5, 55);
    addEdge( 4, 6, 70);
    addEdge( 4, 7, 80);
    addEdge( 4, 8, 100);
    addEdge( 4, 9, 70);

    addEdge( 5, 6, 70);
    addEdge( 5, 7, 45);
    addEdge( 5, 8, 60);
    addEdge( 5, 9, 30);

    addEdge( 6, 7, 20);
    addEdge( 6, 8, 50);
    addEdge( 6, 9, 70);

    addEdge( 7, 8, 60);
    addEdge( 7, 9, 40);

    addEdge( 8, 9, 30);

}

/*
* loads server information
* of the list of locations
*/
void Map :: locationList()
{
    location.push_back("A");
    location.push_back("B");
    location.push_back("C");
    location.push_back("D");
    location.push_back("E");
    location.push_back("F");
    location.push_back("G");
    location.push_back("H");
    location.push_back("I");
    location.push_back("J");
}
