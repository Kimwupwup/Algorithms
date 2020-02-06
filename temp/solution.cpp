#include <cstdio>
#include <algorithm>
using namespace std;

int L,N,K,M,X[555],F[555];

int main()
{
	int T; scanf ("%d",&T); while (T--){
		scanf ("%d %d %d",&L,&N,&K); M = 0;
		for (int i=0;i<N;i++){
			int x,o; scanf ("%d %d",&x,&o);
			X[i] = x;
			if (o == 1) F[M++] = L-x;
		}
		sort(X,X+N);
		sort(F,F+M);
		printf ("%d %d\n",F[K-1],X[N-K]);
	}

	return 0;
}
