/*******************************************************************/
/**   MAC 438  - Programação Concorrente                          **/
/**   IME-USP  - Primeiro Semestre de 2016                        **/
/**   Prof. Marcel Parolin Jackowski                              **/
/**                                                               **/
/**   Primeiro Exercício-Programa                                 **/
/**   Arquivo: heapsort.c                                         **/
/**                                                               **/
/**   Ronaldo Yang                   7576750                      **/
/**   Yoshio Mori                    6432393                      **/
/**                                                               **/
/**   04/04/2016                                                  **/
/**   Referência: http://algs4.cs.princeton.edu/24pq/             **/
/*******************************************************************/

int less(int *a, int i, int j) {
	return (a[i-1] < a[j-1]) ? 1 : 0;
}

void exch(int *a, int i, int j) {
	int c;
	c = a[i-1];
	a[i-1] = a[j-1];
	a[j-1] = c;
}

void sink(int *a, int k, int n) { 
	int j;
	while (2*k <= n) { 
		j = 2*k;
		if (j < n && less(a, j, j+1)) j++;
		if (!less(a, k, j)) break;
		exch(a, k, j); 
		k = j;
	}
}

void heapsort(int n, int *a) { 
	int k;
	for (k = n/2; k >= 1; k--) sink(a, k, n);
	while (n > 1) { 
		exch(a, 1, n--); 
		sink(a, 1, n); 
	}
}
 
