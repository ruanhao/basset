int partition(int a[], int l, int r) {
    int i = l-1, j = r, v = a[r];
    int t;
    for (;;) {
        while (a[++i] < v) ;
        while (v < a[--j]) if (j == l) break;
        if (i >= j) break;
        t = a[i], a[i] = a[j], a[j] = t;
    }
    t = a[i], a[i] = a[r], a[r] = t;
    return i;
}

void quicksort(int a[], int l, int r) {
    if (r <= l) return;
    int i = partition(a, l, r);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}
