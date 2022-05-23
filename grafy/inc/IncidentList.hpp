#ifndef IncidentList_hpp
#define IncidentList_hpp
#include "Include.hpp"

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
        EdgeL(int W, EdgeL *ad, VertexL *w, VertexL *v){ Start = w; Koniec = v;Wartosc = W; Adres = ad; };
        VertexL* IsOpposite(VertexL *v) {
            if (Start == v)     return Koniec;
            else                return Start;
        };
        void UpdateAdjacency(AdjPoint  *L1, AdjPoint  *L2) { List1 = L1; List2 = L2; };
        void SetAdress(EdgeL *ad);
        void Show() {
            std:: cout << "Wartosc: " << this->Wartosc << std::endl
                        << "Adres: " << Adres << std::endl
                        << "Start: " << Start << std::endl
                        << "Start: " << Koniec << std::endl;
//            << "Start: " << Start << std::endl;
        };
        ~EdgeL() = default;
        
    };
    struct AdjPoint {
        
        int   IlPolaczen;
        EdgeL **Edge;
        
        AdjPoint(EdgeL *E) {
            IlPolaczen = 0;
            Edge[IlPolaczen] = E;
        };
        void AddPoint(EdgeL *E) {
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
    EdgeL    ***AdjList;

public:
    
    AdjacencyList(int W, int G) {
        
        Rozmiar     = W;
        Gestosc     = G;
        IlKrawedzi  = 0;
        int KrawTmp = 0;
        int MaxIlKrawedzi = (Gestosc * Rozmiar * (Rozmiar-1)) / 2;
        

        std:: random_device dev;
        std:: mt19937 rng(dev());
        std:: uniform_int_distribution<std::mt19937::result_type> dist6(1,99999);
        
        bool TrueFalse[MaxIlKrawedzi];
        for (int i = 0 ; i < MaxIlKrawedzi; ++i) {
            TrueFalse[i] = ( dist6(rng) % 100 ) < Gestosc;      // Na dany procent da 1
            if (TrueFalse[i] == 1) ++IlKrawedzi;
        }
        
        this -> VertArr  =  new VertexL[Rozmiar];
        this -> EdgeArr  =  new EdgeL[IlKrawedzi];
        this -> AdjList  =  new EdgeL**[Rozmiar];
        
        for (int i = 0; i < Rozmiar; ++i) {                   // Tworzę listę i wypełniam ją Nullami
            AdjList[i] = new EdgeL*[Rozmiar-1];
            for (int j = 0; j < Rozmiar-1; ++j)
                AdjList[i][j] = NULL;
        }
        
        std:: uniform_int_distribution<std::mt19937::result_type> dist7(1,Rozmiar);
        for (int i = 0; i < Rozmiar; ++i)                   // Wypełniam wierzchołki
            VertArr[i] = VertexL(dist7(rng), &VertArr[i]);
        
        std:: uniform_int_distribution<std::mt19937::result_type> dist8(1,IlKrawedzi);
        for (int i = 0; i < Rozmiar; ++i)                   // Tworzę połączenie tam gdzie powinno być
        for (int j = 0; j < Rozmiar-1; ++j) {
            if (j-i >= 1 &&  TrueFalse[KrawTmp] != 0) {     // Jest połączenie, wypełniam krawedzie i listę
                EdgeArr[KrawTmp] = EdgeL(dist8(rng), &EdgeArr[i], &VertArr[j], &VertArr[i]);
                AdjList[i][j]  = &EdgeArr[KrawTmp];
            }
            ++KrawTmp;
        }
        
    };
    bool  IsAdjacent() {
//        if (AdjList[i] != NULL)    return true;
        return false;
    };
    void  WyswietlListe(std::ostream &strm){
        strm << std:: endl;
        strm << std:: endl;
        strm << std:: endl;
    for (int i = 0; i < Rozmiar; ++i) {
        for (int j = 0; j< Rozmiar-1; ++j)
            strm << AdjList[i][j] << ", ";
        strm << std::endl;
    }
};
    void  WyswietlListeEdge(std::ostream &strm){
        strm << std:: endl;
        strm << std:: endl;
        strm << std:: endl;
        for (int i = 0; i < Rozmiar; ++i) {
            for (int j = 0; j< Rozmiar-1; ++j)
                AdjList[i][j]->Show();
            strm << std::endl;
        }
    };
    ~AdjacencyList() = default;
};


#endif
