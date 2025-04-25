#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary 
{

//Il concept Sortable richiede che il tipo T sia dotato di una relazione d'ordine totale.
template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> convertible_to<bool>;
};

/*BubbleSort prende in input un vettore v di oggetti di tipo T, dove T è Sortable, 
e lo ordina sfruttando l'arlgoritmo di sorting bubble sort.*/
template<Sortable T>
void BubbleSort(vector<T>& v)
{
    const size_t n = v.size();

    for(size_t i = 0; i <= n - 2; i++)
    {
        for(size_t j = i+1; j <= n-1; j++)
        {
            if(v[j] < v[i])
			{
				// swap(v[j], v[i]) 
				const T tmp = v[j];
				v[j] = v[i];
				v[i] = tmp;
			}
        }
    }
}

template<Sortable T>
void HeapSort(vector<T>& v)
{
	const size_t n = v.size();
	
	make_heap(v.begin(), v.end()); //Trasforma v in un heap
	
	for(size_t j = 0; j <= n-1; j++){
		/*Scambio il primo e l'ultimo elemento dell'heap, 
		poi ritrasformo in heap escludendo l'ultimo elemento.*/
		pop_heap(v.begin(), v.end()-j);
	}
}

}


