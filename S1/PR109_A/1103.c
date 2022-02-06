void sort(int array[], int n)
{
	for(int i = 0; i < n - 1; i ++)
      for(int j = 0; j < n - 1; j ++)
        if (array[j] > array[j + 1]) {
        	int t = array[j];
          	array[j] = array[j + 1];
          	array[j + 1] = t;
        }
  return;
}
