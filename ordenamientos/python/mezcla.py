# Ordenamiento por mezcla (merge sort): O(n log n) siempre, O(n) de espacio, estable.


def mezclar(v, izq, medio, der):
    """Mezcla los rangos ordenados v[izq..medio] y v[medio+1..der]."""
    a = v[izq:medio + 1]
    b = v[medio + 1:der + 1]

    i = j = 0
    k = izq
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:  # el <= lo hace estable
            v[k] = a[i]
            i += 1
        else:
            v[k] = b[j]
            j += 1
        k += 1
    while i < len(a):
        v[k] = a[i]
        i += 1
        k += 1
    while j < len(b):
        v[k] = b[j]
        j += 1
        k += 1


def merge_sort(v, izq=0, der=None):
    if der is None:
        der = len(v) - 1
    if izq >= der:
        return
    medio = (izq + der) // 2
    merge_sort(v, izq, medio)
    merge_sort(v, medio + 1, der)
    mezclar(v, izq, medio, der)


if __name__ == "__main__":
    v = [38, 27, 43, 10]
    merge_sort(v)
    print(*v)
