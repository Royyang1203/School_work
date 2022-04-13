
void sort_by_digit(int *A, int n, int r, int p)
{
    int base = 1;
    while (p > 0)
    {
        --p;
        base *= r;
    }
    int count[r], B[n], m = 0;
    for (int j = 0; j < r; ++j)
        count[j] = 0;
    for (int i = 0; i < n; ++i)
        count[(A[i] / base) % r]++;
    for (int j = 0, psum = 0, sum = 0; j < r; ++j)
    {
        psum = sum;
        sum += count[j];
        count[j] = psum;
    }
    for (int i = 0; i < n; ++i)
        B[count[(A[i] / base) % r]++] = A[i];
    for (int i = 0; i < n; ++i)
        A[i] = B[i];
}
void radix_sort_MSD(int *A, int n, int r, int d)
{
    msdR(int *A, int r, int d, int lo, int hi);
}

void msdR(int *A, int r, int d, int lo, int hi)
{
    int count[r + 1] = {0};
    if (hi <= lo)
        return;
    keyindex(a, lo, hi, d, count);
    sort_by_digit(A[lo], hi - lo, r, i);
    // recursively sort 255 pieces
    for (int i = 0; i < r; ++i)
        msdR(a, lo + count[i], lo + count[i + 1] - 1, d + 1);
}

void msd(char *a[], int lo, int hi)
{
    msdR(a, lo, hi, 0);
}