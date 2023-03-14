# Implementacja i szukanie najkrótszej drogi w grafie

Implementacja grafów zdefiniowanych przez macierz oraz listę sąsiedztwa, bez użycia biblioteki standardowej ;-; oraz implementacja algorytmu Dijkstry szukającej najkrótszej drogi w grafie.

## Wnioski z wykonanych testów wydajnościowych algorytmu

• Algorytm Dijkstry jest prosty i intuicyjny, co pociąga za sobą konsekwencje, mianowicie jest on złożony obliczeniowo dla grafu zdefiniowanego przez macierz sąsiedztwa.
• Z testów wynika, że bardzo duże znaczenie dla czasu wykonania zadania ma wielkość grafu. Dla grafów do 100 wierzchołków algorytm Dijkstry bardzo szybko znajdował ścieżki, lecz gdy tych wierzchołków było 500 lub więcej czas kalkulacji zaczynał się znacznie wydłużać.
