# Ordenamiento rapido (quick sort): O(n log n) en promedio, O(n^2) en el peor caso.
# Particion de Lomuto con el ultimo elemento como pivote.


def particion(v, izq, der):
    """Deja el pivote en su posicion final y devuelve ese indice."""
    pivote = v[der]
    i = izq - 1  # ultimo elemento de la zona de menores
    for j in range(izq, der):
        if v[j] < pivote:
            i += 1
            v[i], v[j] = v[j], v[i]
    v[i + 1], v[der] = v[der], v[i + 1]
    return i + 1


def quick_sort(v, izq=0, der=None):
    if der is None:
        der = len(v) - 1
    if izq >= der:
        return
    corte = particion(v, izq, der)
    quick_sort(v, izq, corte - 1)
    quick_sort(v, corte + 1, der)


if __name__ == "__main__":
    v = [10, 7, 8, 9, 1, 5]
    quick_sort(v)
    print(*v)
