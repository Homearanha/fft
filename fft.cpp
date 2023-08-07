#include <stdio.h>
#include <complex.h>

#define LEN 100
#define PI 3.1416

/*
def dft(x):
    x = np.asarray(x, dtype=float)
    N = x.shape[0]
    n = np.arange(N)
    k = n.reshape((N, 1))
    M = np.exp(-2j * np.pi * k * n / N)
    return np.dot(M, x)
*/
__complex__ float* dft(float* x, int N)
{
    //float** M = new float*[N];
    //for(int i=0; i<N; i++) M[i] = new float[N];

    __complex__ float* ret = new __complex__ float[N];
    __complex__ float sum=0;

    for(int k=0; k<N; k++)
    {
        for(int n=0; n<N; n++)
            sum+=x[n] * cexpf(-2 * I * PI * k * n / N);
        ret[k] = sum;
        sum=0;
    }
    return ret;
}

int main()
{
    float x[LEN];
    for(int i=0; i<LEN; i++) x[i] = sin(2*PI*i/LEN);
    __complex__ float* X = dft(x, LEN);
    for(int i=0; i<LEN; i++) printf("%.2f+%.2fi\n", crealf(X[i]), cimagf(X[i]));
    return 0;
}