#ifndef IncidentList_hpp
#define IncidentList_hpp
#include "EdgeList.hpp"
struct AdjPoint;

class AdjacencyList {
    
    struct VertexL  {
        
        int       Wartosc;
        VertexL   *Adres;
        AdjPoint  *List;
        
        VertexL() {};
        VertexL(int W, VertexL *Ad) { Wartosc = W; Adres = Ad; };
        void UpdateAdjacency(AdjPoint  *L) { List = L; };
        void SetAdress(VertexL *ad);
        void Show ();
        ~VertexL() = default;
    
    };
    struct EdgeL    {
        
        int       Wartosc;
        EdgeL     *Adres;
        VertexL   *Start;
        VertexL   *Koniec;
        AdjPoint  *List1;
        AdjPoint  *List2;
        
        EdgeL() {};
        EdgeL(int W, EdgeL *ad) { Wartosc = W; Adres = ad; };
        EdgeL(EdgeL *ad, int W, VertexL *w, VertexL *v){ Start = w; Koniec = v;Wartosc = W; Adres = ad; };
        void UpdateAdjacency(AdjPoint  *L1, AdjPoint  *L2) { List1 = L1; List2 = L2; };
        void SetAdress(EdgeL *ad);
        void Show();
        ~EdgeL() = default;
        
    };
    struct AdjPoint {
        
        int   IlPolaczen;
        EdgeL **Edge;
        
        AdjPoint(EdgeL *E)         {
            IlPolaczen = 0;
            Edge[IlPolaczen] = E;
            
//            this -> Punkty  =  new AdjPoint**[Max];
//            Punkty[0] = AdjPoint(**E);
        };
        void AddPoint(EdgeL *E)    {
            IlPolaczen++;
            Edge[IlPolaczen] = E;
        };
        void UpdateEdge(EdgeL **E) { Edge = E; };
        ~AdjPoint() = default;
        
    };
    
    int Rozmiar;
    int Gestosc;
    int IlKrawedzi;
    VertexL  *VertArr;
    EdgeL    *EdgeArr;
    AdjPoint ***AdjList;
    EdgeL    ***AdjList2;       // Dla testu

public:
    
    AdjacencyList(int W, int G) {
        
        Rozmiar     = W;
        Gestosc     = G;
        IlKrawedzi  = 0;
//        int KrawTmp = 0;
        int MaxIlKrawedzi = (Gestosc * Rozmiar * (Rozmiar-1)) / 2;
        
        srand( (unsigned int) time(NULL) );
        bool TrueFalse[MaxIlKrawedzi];
        for (int i = 0 ; i < MaxIlKrawedzi; ++i) {
            TrueFalse[i] = ( rand() % 100 ) < Gestosc;      // Na dany procent da 1
            if (TrueFalse[i] == 1) ++IlKrawedzi;
        }
        
        this -> VertArr  =  new VertexL[Rozmiar];
        this -> EdgeArr  =  new EdgeL[IlKrawedzi];
        this -> AdjList   =  new AdjPoint**[Rozmiar];
        this -> AdjList2  =  new EdgeL**[Rozmiar];
        
        for (int i = 0; i < Rozmiar; ++i)                   // Tworzę listę i wypełniam ją Nullami
            AdjList2[i] = new EdgeL*[Rozmiar];
            
        
        for (int i = 0; i < IlKrawedzi; ++i){
            if (TrueFalse[i] != 0) {     // Jest połączenie, wypełniam wierzchołki i macierz
                EdgeArr[i] = EdgeL(rand()%IlKrawedzi*10, &EdgeArr[i]);//, &VertArr[j], &VertArr[i]);
                AdjList2[i][i] = &EdgeArr[i];
                
            }else   AdjList2[i] = NULL;
        }
        
//        for (int i = 0; i < Rozmiar; ++i)                   // Wypełniam wierzchołki
//            VertArr[i] = VertexL(rand()%Rozmiar*10, &VertArr[i]);
//        EdgeArr[i] = EdgeM(rand()%IlKrawedzi*10, &EdgeArr[i], &VertArr[j], &VertArr[i]);
        
        
        
        

    };
    bool  IsAdjacent() {
//        if (AdjList[i] != NULL)    return true;
        return false;
    };
    void  WyswietlListe(std::ostream &strm) {
        for (int i = 0; i < Rozmiar; ++i)
            strm << " " << AdjList[i] << ";\n";
    };
    ~AdjacencyList() = default;
};


//    struct AdjBody  {
//
//        int   IlPolaczen;
//        AdjPoint ***Punkty;
//
//        AdjBody() = default; //{ IlPolaczen = 0; };
//        AdjBody(EdgeL *E, int Max) {
//
//            IlPolaczen = 0;
//            this -> Punkty  =  new AdjPoint**[Max];
//            Punkty[0] = AdjPoint(**E);
//        }
////        void AddPoint();
//        ~AdjBody() = default;
//    };

#endif
