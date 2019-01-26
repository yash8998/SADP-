
/*
Interface for MAP
*/
#pragma once

/*#include<iostream>
#include<vector>
#include<iterator>
#include<list>
#include<utility>
using namespace std;*/

#ifndef IMAP_H
#define IMAP_H
class iMap
{
  private:
    std::vector<std::string> location;
    std::vector<std::pair<int,int> > *adjList;

  public:
    virtual void addEdge(int u, int v, int w)=0;
    virtual void populateGraph()=0;
    virtual void locationList()=0;
    friend class iSourceDest;
    friend class iEta;
    friend class SourceDest;
    friend class Eta;
};
#endif
