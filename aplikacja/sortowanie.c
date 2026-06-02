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