#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc----
    
    // implement here
    int *R = malloc(sizeof(int) * (NA-NF+1));

    #pragma omp parallel for num_threads(8)
    for(int i = 0; i < NA-NF+1; i++){
        int conv_sum = 0;
        for(int j = NF-1; j >= 0; j--){
            conv_sum += A[i+(NF-1)-j] * F[j];
        }
        R[i] = conv_sum;
    }

    for(int i = 0; i < NA-NF+1; i++){
        printf("%d\n", R[i]);
    }
    // ---- free memory ----
    free(F);
    free(A);
    free(R);
    // ---- end free ----
    return 0;
}