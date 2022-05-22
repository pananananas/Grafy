#ifndef IncidentList_hpp
#define IncidentList_hpp
#include "EdgeList.hpp"


class AdjacencyList {
public:
 
    struct VertexL  {
        
        int           Wartosc;
        VertexL       *Adres;
        AdjacencyList *List;
        
        VertexL() {};
        VertexL(int W, VertexL *Ad) { Wartosc = W; Adres = Ad; };
        void UpdateAdjacency(AdjacencyList  *L) { List = L; };
        void SetAdress(VertexL *ad);
        void Show ();
        ~VertexL() = default;
    };
    struct EdgeL    {
        
        int            Wartosc;
        EdgeL          *Adres;
        VertexL        *Start;
        VertexL        *Koniec;
        AdjacencyList  *List1;
        AdjacencyList  *List2;
        
        EdgeL() {};
        EdgeL(int W, EdgeL *ad) { Wartosc = W; Adres = ad; };
        EdgeL(EdgeL *ad, int W, VertexL *w, VertexL *v){ Start = w; Koniec = v;Wartosc = W; Adres = ad; };
        void UpdateAdjacency(AdjacencyList  *L1, AdjacencyList  *L2) { List1 = L1; List2 = L2; };
        void SetAdress(EdgeL *ad);
        void Show();
        ~EdgeL() = default;
    };
    struct AdjPoint {
        
        int   IlPolaczen;
        EdgeL *EdgeArr[];
        
        AdjPoint() { IlPolaczen = 0; };
        void UpdateEdge(EdgeL *E) { EdgeArr[IlPolaczen] = E; };
        ~AdjPoint() = default;
    };
    
    
    int Rozmiar;  // Czyli ilość wierzchołków
    int Gestosc;
    int IlKrawedzi;
    
    VertexL  *VertArr;
    EdgeL    *EdgeArr;
    EdgeL  ***AdjList;
    

    
    AdjacencyList(int W, int G) {
        
        Rozmiar     = W;
        Gestosc     = G;
        IlKrawedzi  = 0;
//        int KrawTmp = 0;
        int MaxIlKrawedzi = (Gestosc * Rozmiar * (Rozmiar-1)) / 2;
        
        srand( (unsigned int) time(NULL) );
        bool TrueFalse[MaxIlKrawedzi];
        for (int i = 0 ; i < MaxIlKrawedzi; ++i) {
            TrueFalse[i] = ( rand() % 100 ) < Gestosc;    // Na dany procent da 1
            if (TrueFalse[i] == 1) ++IlKrawedzi;
        }
        
        this -> VertArr  =  new VertexL[Rozmiar];
        this -> EdgeArr  =  new EdgeL[IlKrawedzi];
        this -> AdjList  =  new EdgeL**[Rozmiar];
        
        for (int i = 0; i < Rozmiar; ++i)                   // Wypełniam wierzchołki
            VertArr[i] = VertexL(rand()%Rozmiar*10, &VertArr[i]);
    
        
        for (int i = 0; i < Rozmiar; ++i)                   // Tworzę listę i wypełniam ją Nullami
            AdjList[i] = new EdgeL*[Rozmiar];
//        AdjList[i] = NULL;
        
        for (int i = 0; i < IlKrawedzi; ++i)
            i++;
            
        
//        EdgeArr[i] = EdgeM(rand()%IlKrawedzi*10, &EdgeArr[i], &VertArr[j], &VertArr[i]);
        
        
        
        

    };
    
    
    bool IsAdjacent(int i) {
//        if (AdjList[i] != NULL)    return true;
                                   return false;
    };
    
    void WyswietlListe() {
        
        for (int i = 0; i < Rozmiar; ++i) {
            
            for (int j = 0; j< Rozmiar; ++j)
//                std::cout << AdjMatrix[i][j] << ", ";
            std::cout << std::endl;
        }
    };
    
    ~AdjacencyList() = default;
};



#endif
