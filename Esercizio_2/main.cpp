#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary; // Namespace della libreria

int main() {
    double iter = 150;  // Numero di iterazioni per ciascun test
    cout << "Inserire la grandezza del vettore : ";  //Grandezza del vettore da input dell'utente
    size_t dimV;
    cin >> dimV;
    vector<int> v(dimV);   //Creazione del vettore
    cout << endl;

    // Test su vettori ordinati
    iota(v.begin(), v.end(), dimV);  //Creazione di un vettore con valori ordinati
    cout << "Vettori ordinati: " << endl;
    double TimeBubble = 0;  //Inizializziamo il tempo totale per il Bubble Sort
    double TimeMerge = 0;   // E per il Merge Sort
    for (unsigned int i = 0; i < iter; ++i) {
        vector<int> vBubble = v;  //Copia del vettore
        auto startBubble = chrono::steady_clock::now(); //Tempo di inizio
        BubbleSort(vBubble); //esecuzione del BS
        auto endBubble = chrono::steady_clock::now(); //Tempo di fine
        TimeBubble += chrono::duration_cast<chrono::nanoseconds>(endBubble - startBubble).count(); //Tempo totale aumentato a ogni ciclo
        //Lo stesso per il Merge Sort
        vector<int> vMerge = v;
        auto startMerge = chrono::steady_clock::now();
        MergeSort(vMerge);
        auto endMerge = chrono::steady_clock::now();
        TimeMerge += chrono::duration_cast<chrono::nanoseconds>(endMerge - startMerge).count();
    }
    double mediaBubble = TimeBubble / iter;  //Calcoliamo le due medie
    double mediaMerge = TimeMerge / iter;
    cout << "Tempo medio Bubble Sort: " << mediaBubble << " ns" << endl;  // E stampiamo i risulati
    cout << "Tempo medio Merge Sort: " << mediaMerge << " ns" << endl;
    cout << endl;

    // Test su vettori ordinati casualmente
    for (unsigned int i = 0; i < dimV; ++i)   //Creazione di un vettore con valori casuali tra 0 e 999
        v[i] = rand() % 1000;
    cout << "Vettori ordinati casualmente: " << endl;
    double TimeBRand = 0;   //Procedimento analogo a quello precedente per valori ordinati
    double TimeMRand = 0;
    for (unsigned int i = 0; i < iter; ++i) {
        vector<int> vBubble = v;
        auto startBRand = chrono::steady_clock::now();
        BubbleSort(vBubble);
        auto endBRand = chrono::steady_clock::now();
        TimeBRand += chrono::duration_cast<chrono::nanoseconds>(endBRand - startBRand).count();

        vector<int> vMerge = v;
        auto startMRand = chrono::steady_clock::now();
        MergeSort(vMerge);
        auto endMRand = chrono::steady_clock::now();
        TimeMRand += chrono::duration_cast<chrono::nanoseconds>(endMRand - startMRand).count();
    }
    double mediaBRand = TimeBRand / iter;
    double mediaMRand = TimeMRand / iter;
    cout << "Tempo medio Bubble Sort: " << mediaBRand << " ns" << endl;
    cout << "Tempo medio Merge Sort: " << mediaMRand << " ns" << endl;
    cout << endl;

    return 0;
}
