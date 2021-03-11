# PRiR-lab2
Tworzę obiekty wątków przydzielajać im agrumenty (ai,bi) i także ni, który w każdej metodzie używane jest inaczej ale jest potrzebne to działania funkcji.
Rozpoczynam działanie wątku metodą start().
W pętli sprawdzam czy wszystkie wątki się skończyły, a następnie wypisuje wyniki.

W metodzie wątków na przykład w klasie M_Trapezów jest metoda run która aktywuje się po uruchomieniu wątku i zapisuje rozwiązanie wątku do zmiennej wynik.
Obliczanie wyniku odbywa się w klasie MTrapezow poprzez metodę oblicz();
