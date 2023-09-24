#include <iostream>
#define MAX 4
#include <time.h> 

using namespace std;


int main() {
    double A[MAX][MAX]={
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11},
        {12,13,14,15}
    };

    double x[MAX]={1,2,3,4};
    double y[MAX]={0};
    int i ,j;

    //First pair of loops 

    clock_t start = clock();
    
    for (i = 0; i < MAX; i++){
        cout<<"\n";
    
        for (j = 0; j < MAX; j++){
            y[i] += A[i][j]*x[j];
            cout<<y[i]<<" ";}
    }
    clock_t stop = clock();
    
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f\n\n", elapsed);
    
    // Assign y = 0 
        
    for ( i = 0; i < MAX; i++)
    {
        y[i] = 0;
    }
    //Second pair of loops 

    clock_t start1 = clock();

    for (j = 0; j < MAX; j++){
        cout<<"\n";
        for (i = 0; i < MAX; i++){
            y[i] += A[i][j]*x[j];
            cout<<y[i]<<" ";
        }
    }      
    clock_t stop1 = clock();

    double elapsed1 = (double)(stop1 - start1) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f\n\n", elapsed);
}