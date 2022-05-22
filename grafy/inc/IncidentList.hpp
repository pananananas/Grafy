#ifndef IncidentList_hpp
#define IncidentList_hpp
#include "EdgeList.hpp"


class AdjacencyList {
    
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
        EdgeL **EdgeArr;
        
        AdjPoint() {
            IlPolaczen = 0;
            this -> EdgeArr = new EdgeL*[IlPolaczen];
            
        };
        void UpdateEdge(EdgeL *E) { EdgeArr[IlPolaczen] = E; IlPolaczen++; };
        ~AdjPoint() = default;
        
    };
    
    int Rozmiar;  // Czyli ilość wierzchołków
    int Gestosc;
    int IlKrawedzi;
    
    VertexL  *VertArr;
    EdgeL    *EdgeArr;
    AdjPoint **AdjList;

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
        this -> AdjList  =  new AdjPoint*[Rozmiar];
        
        for (int i = 0; i < Rozmiar; ++i)                   // Tworzę listę i wypełniam ją Nullami
            AdjList[i] = new AdjPoint[Rozmiar];
            
        
        for (int i = 0; i < MaxIlKrawedzi; ++i){
            if (TrueFalse[i] != 0) {     // Jest połączenie, wypełniam wierzchołki i macierz
                EdgeArr[i] = EdgeL(rand()%IlKrawedzi*10, &EdgeArr[i]);//, &VertArr[j], &VertArr[i]);
//                AdjList[i]->UpdateEdge(&EdgeArr[i]);
                
                
            }else   AdjList[i] = NULL;
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



#endif
