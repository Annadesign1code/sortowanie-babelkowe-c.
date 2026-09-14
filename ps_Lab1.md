# Zadanie laboratoryjne  

![VS Code](https://img.shields.io/badge/IDE-VS%20Code-007ACC?logo=visualstudiocode&logoColor=white)
![Visual Studio](https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?logo=visualstudio&logoColor=white)
![Mermaid](https://img.shields.io/badge/Diagram-Mermaid-FF3670?logo=mermaid&logoColor=white)
![GitHub Markdown](https://img.shields.io/badge/Format-GitHub%20Markdown-181717?logo=github&logoColor=white)

[![C Reference](https://img.shields.io/badge/Dokumentacja-C%20Reference-00599C?logo=c&logoColor=white)](https://en.cppreference.com/w/c)

**Przedmiot:** *Programowanie strukturalne*  







## <img src="https://img.icons8.com/color/48/info--v1.png" alt="Piktogram informacje o zadaniu" width="24" /> Informacje o zadaniu

| Pole | Wartość |
|---|---|
| Numer laboratorium | 1 |
| Temat laboratorium | Programowanie strukturalne - Złożoność obliczeniowa algorytmów sortowania. |
| Data realizacji | 17.05.2026 |
| Data oddania | 22.05.2026 |
| Język programowania | C |
| Środowisko / IDE | VSC/VS |

## <img src="https://img.icons8.com/color/48/task.png" alt="Piktogram tresc zadania" width="24" /> Treść zadania

Krótki opis zadania:

Napisz program, który umożliwa posortowanie losowych 100 liczb z zakresu od (-1000 do 1000) z zastosowanie algorytmy sortowania bąbelkowego.

## <img src="https://img.icons8.com/color/48/checklist.png" alt="Piktogram wymagania funkcjonalne" width="24" /> Wymagania funkcjonalne

| ID | Opis wymagania | Poziom |
|---|---|---|
| WF-01 | Program generuje 100 losowych liczb całkowitych z zakresu od -1000 do 1000. | Wysoki |
| WF-02 | Program wyświetla wygenerowane liczby przed sortowaniem. | Wysoki |
| WF-03 | Program sortuje liczby algorytmem sortowania bąbelkowego. | Wysoki |
| WF-04 | Program wyświetla posortowane liczby po zakończeniu sortowania. | Wysoki |

## <img src="https://img.icons8.com/color/48/inspection.png" alt="Piktogram wymagania niefunkcjonalne" width="24" /> Wymagania niefunkcjonalne

| ID | Opis wymagania | Poziom |
|---|---|---|
| WN-01 | Kod jest napisany w języku C zgodnie z zasadami programowania strukturalnego. | Wysoki |
| WN-02 | Program kompiluje się bez błędów w standardowym kompilatorze C (np. gcc). | Wysoki |
| WN-03 | Kod jest czytelny i podzielony na funkcje (generowanie, sortowanie, wyświetlanie). | Średni |
| WN-04 | Interfejs tekstowy programu zawiera jasne komunikaty dla użytkownika. | Średni |

## <img src="https://img.icons8.com/color/48/workflow.png" alt="Piktogram realizacja zadania" width="24" /> Realizacja zadania



Opis implementacji:

Program został zaimplementowany w języku C zgodnie z paradygmatem programowania strukturalnego. Logika aplikacji została podzielona na niezależne funkcje: `main` (zarządzanie przepływem i losowanie danych), `sortujBabelkowo` (odpowiedzialna za algorytm sortowania) oraz `wyswietlTablice` (odpowiedzialna za sformatowaną prezentację danych na ekranie). Do wygenerowania 100 losowych wartości z przedziału od -1000 do 1000 wykorzystano funkcję `rand()` zainicjalizowaną czasem systemowym za pomocą `srand(time(NULL))`. Zastosowane w kodzie formatowanie `%6d` gwarantuje równe wyrównanie kolumn w interfejsie tekstowym, niezależnie od długości znakowej liczb (dodatnie, ujemne, jedno- lub wielocyfrowe), co spełnia wymóg niefunkcjonalny NF-04.

## <img src="https://img.icons8.com/color/48/workflow.png" alt="Piktogram schemat algorytmu" width="24" /> Schemat algorytmu

1. Zainicjuj generator liczb losowych (`srand`), zadeklaruj tablicę `tab[100]`.
2. Wypełnij tablicę 100 losowymi liczbami całkowitymi z zakresu −1000 .. 1000.
3. Wyświetl zawartość tablicy **przed** sortowaniem.
4. Sortowanie bąbelkowe:
   - Dla `i = 0` do `n-2`:
     - Dla `j = 0` do `n-2-i`:
       - Jeśli `tab[j] > tab[j+1]` → zamień `tab[j]` z `tab[j+1]`.
5. Wyświetl zawartość tablicy **po** sortowaniu.
## <img src="https://img.icons8.com/color/48/source-code.png" alt="Piktogram kod zrodlowy" width="24" /> Kod źródłowy


### <img src="https://img.icons8.com/color/48/c-programming.png" alt="Piktogram C" width="24" /> C

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR 100
#define DOLNY_ZAKRES -1000
#define GORNY_ZAKRES 1000

// Funkcja sortująca algorytmem bąbelkowym
void sortujBabelkowo(int tablica[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tablica[j] > tablica[j + 1]) {
                // Zamiana miejscami (swap)
                temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }
}

// Funkcja pomocnicza do wyświetlania tablicy
void wyswietlTablice(const int tablica[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%6d ", tablica[i]); // Rezerwacja 6 miejsc na liczbę dla równego układu kolumn
        if ((i + 1) % 10 == 0) {
            printf("\n"); // Nowa linia co 10 elementów
        }
    }
}

int main() {
    int liczby[ROZMIAR];
    int i;

    printf("==================================================\n");
    printf(" PROGRAM SORTUJACY - SORTOWANIE BABELKOWE\n");
    printf("==================================================\n\n");

    // Inicjalizacja generatora liczb losowych
    srand((unsigned int)time(NULL));

    // Wypełnianie tablicy losowymi liczbami z zakresu [-1000, 1000]
    for (i = 0; i < ROZMIAR; i++) {
        liczby[i] = rand() % (GORNY_ZAKRES - DOLNY_ZAKRES + 1) + DOLNY_ZAKRES;
    }

    printf(" Wygenerowane liczby przed sortowaniem:\n");
    printf("--------------------------------------------------\n");
    wyswietlTablice(liczby, ROZMIAR);
    printf("--------------------------------------------------\n");

    // Uruchomienie algorytmu sortowania
    printf("\nTrwa sortowanie algorytmem babelkowym...\n");
    sortujBabelkowo(liczby, ROZMIAR);
    printf("Sortowanie zakonczone sukcesem.\n\n");

    printf(" Liczby po zakonczeniu sortowania:\n");
    printf("--------------------------------------------------\n");
    wyswietlTablice(liczby, ROZMIAR);
    printf("--------------------------------------------------\n");

    return 0;
}

```

## <img src="https://img.icons8.com/color/48/combo-chart--v1.png" alt="Piktogram wynik dzialania" width="24" /> Wynik działania programu

Opis testów i przykładowe wyniki:



```bash
PROGRAM SORTUJACY - SORTOWANIE BABELKOWE
==================================================

 Wygenerowane liczby przed sortowaniem:
--------------------------------------------------
   203    863    427    157   -328    945    254   -428    841    340 
  -107     89     47     79    511     21   -771    290   -765    357 
  -520    927    411   -467    170    205   -955    735   -222    -40 
  -338   -361    369   -924   -243   -576     40    -34   -406   -539 
  -661    946     14    -18    678   -467    762    433   -726   -969 
   247   -446   -610   -404   -499    343    884    226   -271    748 
  -887    599   -272    737   -301   -834     87    563    688    490 
  -579    158   -893   -342    795    436     -7    571    362   -518 
    88    181    876   -382     56    929   -685     96    180   -741 
  -423    654    616   -539   -307    923   -333    -90   -729   -302 
--------------------------------------------------

Trwa sortowanie algorytmem babelkowym...
Sortowanie zakonczone sukcesem.

 Liczby po zakonczeniu sortowania:
--------------------------------------------------
  -969   -955   -924   -893   -887   -834   -771   -765   -741   -729 
  -726   -685   -661   -610   -579   -576   -539   -539   -520   -518 
  -499   -467   -467   -446   -428   -423   -406   -404   -382   -361 
  -342   -338   -333   -328   -307   -302   -301   -272   -271   -243 
  -222   -107    -90    -40    -34    -18     -7     14     21     40 
    47     56     79     87     88     89     96    157    158    170 
   180    181    203    205    226    247    254    290    340    343 
   357    362    369    411    427    433    436    490    511    563 
   571    599    616    654    678    688    735    737    748    762 
   795    841    863    876    884    923    927    929    945    946 

```
## <img src="https://img.icons8.com/color/48/test-passed.png" alt="Piktogram samoocena" width="24" /> Samoocena studenta

| Kryterium | Tak / Nie | Uwagi |
|---|---|---|
| Program kompiluje się bez błędów | Tak | Brak błędów i ostrzeżeń podczas kompilacji GCC. |
| Wszystkie wymagania zostały spełnione | Tak | Program realizuje wszystkie wytyczne funkcjonalne i niefunkcjonalne. |
| Program poprawnie generuje 100 losowych liczb z zakresu -1000..1000 | Tak | Użyto poprawnego skalowania funkcji rand(). |
| Algorytm sortowania bąbelkowego działa poprawnie | Tak | Liczby układają się prawidłowo w porządku rosnącym. |
| Kod jest czytelny i podzielony na funkcje | Tak | Wydzielono funkcje do sortowania oraz wyświetlania danych. |
| Zastosowano zasady programowania strukturalnego | Tak | Kod jest w pełni proceduralny, napisany w czystym języku C. |





