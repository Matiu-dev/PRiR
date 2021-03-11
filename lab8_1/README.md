# PRIR-lab8_1

SPRAWOZDANIE

OPIS PROBLEMU 

Gra toczy się na nieskończonej planszy (płaszczyźnie) podzielonej na kwadratowe komórki. Każda komórka ma ośmiu „sąsiadów” (tzw. sąsiedztwo Moore’a), czyli komórki przylegające do niej bokami i rogami. Każda komórka może znajdować się w jednym z dwóch stanów: może być albo „żywa” (włączona), albo „martwa” (wyłączona). Stany komórek zmieniają się w pewnych jednostkach czasu. Stan wszystkich komórek w pewnej jednostce czasu jest używany do obliczenia stanu wszystkich komórek w następnej jednostce. Po obliczeniu wszystkie komórki zmieniają swój stan dokładnie w tym samym momencie. Stan komórki zależy tylko od liczby jej żywych sąsiadów. W grze w życie nie ma graczy w dosłownym tego słowa znaczeniu. Udział człowieka sprowadza się jedynie do ustalenia stanu początkowego komórek.

Reguły gry według Conwaya
Martwa komórka, która ma dokładnie 3 żywych sąsiadów, staje się żywa w następnej jednostce czasu (rodzi się)
Żywa komórka z 2 albo 3 żywymi sąsiadami pozostaje nadal żywa; przy innej liczbie sąsiadów umiera (z „samotności” albo „zatłoczenia”)

STRUKTURA PROGRAMU

1.Mamy zadeklarowawną planszę X na X z kilkoma polami oznaczonymi jako 1(zywe) a reszta ma stan 0(martwa)
2.Sprawdza liczbe iteracji, musi być 1 lub 2
3.Sprawdza czy MPI sie zainicjalizowalo i przypisuje liczbe procesów i ich ID do zmiennych.
4.Potem jest pętla, która na podstawie warunków wykonuje kolejne modyfikacje planszy i przesyła aktualne stany do następnego wątku.
5.Następne wątki przyjmują te dane i wypisuje ponownie plansze.

KOMENDY NA URUCHOMIENIE:
sudo apt install lam4-dev
sudo apt install lam-runtime

lamboot -v

KOMPILACJA
mpicc zad1.c -o zad1.exe
mpirun -np <ilosc procesow> zad1.exe <liczba iteracji>
  
UZYSKANE WYNIKI

Wynikiem programu jest plansza x na x zdefiniowana w programiu i kolejne plansze prezentujące zmiany poszczególnych komórek. Pokazuje, która komórka jest zywa to jest mająca stan 1, kiedy ma 2 lub 3 sąsiadów lub martwa kiedy posiada stan 0, wtedy kiedy ma inna liczbę sąsiadów niż 2 lub 3.
