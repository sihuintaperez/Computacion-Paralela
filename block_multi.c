#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500      
#define BLOCK_SIZE 25


void Multi_blocks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i += BLOCK_SIZE) {
        for (int j = 0; j < N; j += BLOCK_SIZE) {
            for (int k = 0; k < N; k += BLOCK_SIZE) {
                for (int i1 = i; i1 < i + BLOCK_SIZE; i1++) {
                    for (int j1 = j; j1 < j + BLOCK_SIZE; j1++) {
                        for (int k1 = k; k1 < k + BLOCK_SIZE; k1++) {
                            C[i1][j1] += A[i1][k1] * B[k1][j1];
                        }
                    }
                }
            }
        }
    }
}

void Multiply(int A[N][N], int B[N][N], int C[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


int main() {
    static int A[N][N];
    static int B[N][N];
    static int C[N][N];

    
    
    for (int i = 0; i < N; i++) {   
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 20; 
            B[i][j] = rand() % 20; 
        }
    }

/// BLOQUES
    struct timespec start, end;
    double time_spent;
    clock_gettime(CLOCK_REALTIME, &start);
    
    Multiply(A, B, C);
    
    clock_gettime(CLOCK_REALTIME, &end);
    time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("MULTI : Elapsed time in seconds : %f \n", time_spent);


 ///// MULTI

    struct timespec start1, end1;
    double time_spent1;
    clock_gettime(CLOCK_REALTIME, &start1);
    
    Multi_blocks(A, B, C);
    
    clock_gettime(CLOCK_REALTIME, &end1);
    time_spent1 = (end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1000000000.0;
    printf("BLOCK: Elapsed time in seconds : %f \n", time_spent1);   


    return 0;
}







