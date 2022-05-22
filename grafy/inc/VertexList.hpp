#ifndef VertexList_hpp
#define VertexList_hpp
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <chrono>    // Do liczenia czasu
#include <ctime>
#include <cmath>
#include <cstdlib>
//#include "IncidentList.hpp"


class VertexList {              // Wierzchołek do listy sąsiedztwa

public:
    VertexList   *Adres;
    int           Wartosc;
//    IncidentList *IncListPointer;
    
    
    VertexList(){};
    VertexList(int x){ Wartosc = x; };
    void SetAdress(VertexList *ad){ Adres = ad; };
//    EdgeList IncidentEdges();  // return an edge list of the edges
    bool IsAdjancent(VertexList v); // test whether v and u are adjencent
    ~VertexList(){};
};







#endif /* VertexList_hpp */
