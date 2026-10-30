# Ordenamiento rapido (quick sort): O(n log n) en promedio, O(n^2) en el peor caso,
# que se da con la lista ya ordenada. Ahi la recursion llega a profundidad n y puede
# superar el limite de Python.
# Convencion del curso: el pivote es el mayor entre los primeros dos elementos diferentes.


def escoger_pivote(v, izq, der):
    """Devuelve None si todos los elementos son iguales: el rango ya esta ordenado."""
    for k in range(izq + 1, der + 1):
        if v[k] != v[izq]:
            return max(v[izq], v[k])
    return None


def particion(v, izq, der, pivote):
    """Deja los menores en v[izq..l-1] y los mayores o iguales en v[l..der]. Devuelve l.

    El pivote no queda en su posicion final: queda en el grupo de la derecha.
    """
    l, r = izq, der
    while l <= r:
        v[l], v[r] = v[r], v[l]
        while v[l] < pivote:
            l += 1
        while v[r] >= pivote:
            r -= 1
    return l


def quick_sort(v, izq=0, der=None):
    if der is None:
        der = len(v) - 1
    if izq >= der:
        return
    pivote = escoger_pivote(v, izq, der)
    if pivote is None:
        return
    corte = particion(v, izq, der, pivote)
    quick_sort(v, izq, corte - 1)
    quick_sort(v, corte, der)  # incluye el corte: el pivote sigue en este grupo


if __name__ == "__main__":
    v = [7, 7, 5, 8, 1, 9, 6, 8]
    quick_sort(v)
    print(*v)
