// Ordenamiento por mezcla (merge sort): O(n log n) siempre, O(n) de espacio, estable.
#include <iostream>
#include <vector>
using namespace std;

// Mezcla los rangos ordenados v[izq..medio] y v[medio+1..der].
void mezclar(vector<int>& v, int izq, int medio, int der) {
    vector<int> a(v.begin() + izq, v.begin() + medio + 1);
    vector<int> b(v.begin() + medio + 1, v.begin() + der + 1);

    size_t i = 0, j = 0;
    int k = izq;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) v[k++] = a[i++];  // el <= lo hace estable
        else              v[k++] = b[j++];
    }
    while (i < a.size()) v[k++] = a[i++];
    while (j < b.size()) v[k++] = b[j++];
}

void mergeSort(vector<int>& v, int izq, int der) {
    if (izq >= der) return;
    int medio = izq + (der - izq) / 2;
    mergeSort(v, izq, medio);
    mergeSort(v, medio + 1, der);
    mezclar(v, izq, medio, der);
}

void mergeSort(vector<int>& v) {
    mergeSort(v, 0, static_cast<int>(v.size()) - 1);
}

int main() {
    vector<int> v = {38, 27, 43, 10};
    mergeSort(v);
    for (int x : v) cout << x << ' ';
    cout << '\n';
}
