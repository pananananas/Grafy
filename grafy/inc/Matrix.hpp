#ifndef Macierz_hpp
#define Macierz_hpp
#include "EdgeMatrix.hpp"

struct VertexM {
    
    int      Wartosc;
    VertexM  *Adres;
    int      ID;
    
    VertexM(){};
    VertexM (int id, int W, VertexM *Ad) { Wartosc = W; ID = id; Adres = Ad; };
    void SetAdress(VertexM *ad);
    void Show();
    int  ReturnID(){ return ID; };
    
    ~VertexM(){};
};


struct EdgeM {
    
    int      Wartosc;
    EdgeM    *Adres;
    VertexM  *Start;
    VertexM  *Koniec;
    
    EdgeM(){};
    EdgeM(int W, EdgeM *ad) { Wartosc = W; Adres = ad; };
    EdgeM(int W, EdgeM *ad, VertexM *w, VertexM *v){ Wartosc = W; Adres = ad; Start = w; Koniec = v; };
    void SetAdjacency(VertexM *w, VertexM *v) { Start = w; Koniec = v; };
    void SetAdress(EdgeM *ad);
    void Show();
    ~EdgeM(){}
};


class AdjacencyMatrix {
public:
    
    //    struct VertexM;
    //    struct EdgeM;
    
    int Rozmiar;  // Czyli ilość wierzchołków
    int Gestosc;
    int IlKrawedzi;
    
    VertexM  *VertArr;
    EdgeM    *EdgeArr;
    EdgeM  ***AdjMatrix;
    
    
    AdjacencyMatrix(int W, int G) {
        
        Rozmiar     = W;
        Gestosc     = G;
        IlKrawedzi  = 0;
        int KrawTmp = 0;
        int MaxIlKrawedzi = (Gestosc * Rozmiar * (Rozmiar-1)) / 2;
        
        srand( (unsigned int) time(NULL) );
        bool TrueFalse[MaxIlKrawedzi];
        for (int i = 0 ; i < MaxIlKrawedzi; ++i) {
            TrueFalse[i] = ( rand() % 100 ) < Gestosc;    // Na dany procent da 1
            if (TrueFalse[i] == 1) ++IlKrawedzi;
        }
        
        this -> VertArr   = new VertexM[Rozmiar];
        this -> EdgeArr   = new EdgeM[IlKrawedzi];
        this -> AdjMatrix = new EdgeM**[Rozmiar];
        
        for (int i = 0; i < Rozmiar; ++i)                   // Wypełniam wierzchołki
            VertArr[i] = VertexM(i, rand()%Rozmiar*10, &VertArr[i]);
        
        for (int i = 0; i < Rozmiar; ++i) {                 // Inicjuję rozmiar macierzy i wypełniam Nullami
            AdjMatrix[i] = new EdgeM*[Rozmiar];
            for (int j = 0; j< Rozmiar; ++j)
                    AdjMatrix[i][j] = NULL;
        }
        for (int i = 0; i < Rozmiar; ++i)                   // Tworzę połączenie tam gdzie powinno być
        for (int j = 0; j < Rozmiar; ++j) {
            if (j-i >= 1 &&  TrueFalse[KrawTmp] != 0) {     // Jest połączenie, wypełniam wierzchołki i macierz
                EdgeArr[KrawTmp] = EdgeM(rand()%IlKrawedzi*10, &EdgeArr[i], &VertArr[j], &VertArr[i]);
                AdjMatrix[i][j]  = &EdgeArr[KrawTmp];
                AdjMatrix[j][i]  = &EdgeArr[KrawTmp];
            }
            ++KrawTmp;
        }
        
        std:: cout << " Tmp: " << KrawTmp << std:: endl;    // Debug
        std:: cout << " Wla: " << IlKrawedzi << std:: endl;
        std:: cout << " Max: " << MaxIlKrawedzi << std:: endl;
    };
    
    bool AreAdjacent(int i, int j) {
        if (AdjMatrix[i][j] != NULL)    return true;
        else                            return false;
    };
    
    EdgeM* ReturnAdjacency(int i, int j) {
        if (AdjMatrix[i][j] != NULL)    return AdjMatrix[i][j];
        else                            return NULL;
    };
    
    void WyswietlMacierz(std::ostream &strm) {
        
        for (int i = 0; i < Rozmiar; ++i) {
            
            for (int j = 0; j< Rozmiar; ++j)
                strm << AdjMatrix[i][j] << ", ";
            strm << std::endl;
        }
    };
    
    ~AdjacencyMatrix(){};
};

//std::ostream& operator << (std::ostream &strm, AdjacencyMatrix M){
//    for (int i = 0; i < 1000; ++i){
//        for (int j = 0; j < 1000; ++j){
//            strm << M.ReturnAdjacency(i,j) << "    ";
//        }
//        strm << std:: endl;
//    }
//    return strm;
//}


#endif
