#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r){
        int i=0, p = m, q = l;
        int *b;
        b = (int*)malloc(sizeof(int)*(r-l+1));
        while(l < p+1 && m+1 < r+1){
                if(arr[l] >= arr[m+1]){
                        b[i] = arr[m+1];
                        m++;
                }
                else if(arr[l] < arr[m+1]){
                        b[i] = arr[l];
                        l++;
                }
                i++;
        }
        if(l == p+1){
                for(int j=m+1; j<r+1; i++, j++){
                        b[i] = arr[j];
                }
        }
        else if(m+1 == r+1){
                for(int j=l; j<p+1; i++, j++){
                        b[i] = arr[j];
                }
        }
        for(int j=q, i=0; j<r+1; i++, j++){
                arr[j] = b[i];
        }
        free(b);
}

void mergeSort(int arr[], int l, int r){
        int n = r-l+1;
        int m = n/2;
        if( m != 0){
                mergeSort(arr, l, l+m-1);
                mergeSort(arr, l+m, r);
                merge(arr, l , l+m-1, r);
        }
}

int main (){
        int i, n;
        scanf("%d", &n);
        int *arr = (int*)malloc(sizeof(int)*n);
        for(i = 0; i < n; i++){
                scanf("%d", &arr[i]);
        }
        mergeSort(arr, 0, n-1);
        for(i=0; i<n; i++){
                printf("%d", arr[i]);
        }
        printf("\n");
        free(arr);
        return 0;
}