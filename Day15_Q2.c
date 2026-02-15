#include <stdio.h>
int main(){
    int r, c , s=0;
    printf("Enter number of rows and columns:");
    scanf("%d %d",&r,&c);
    int arr[r][c];

    printf("Enter elements of Matrix:\n");
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            scanf("%d",&arr[i][j]);
            
        }
    }

    
    int row_flag = 0, col_flag = 0;
    for (int i=1 ; i<r ; i++){
        if (arr[i][0] == 0){
            row_flag = 1;
            break;
                
        }
            
        
    }
    for (int j=0 ; j<c ; j++){
        if (arr[0][j] == 0){
            col_flag = 1;
            break;
            
        }
    }
                

    for (int i=1 ; i<r ; i++){
        for (int j=1 ; j<c ; j++){
            if (arr[i][j] == 0){
               arr[i][0] = 0;
               arr[0][j] = 0;

            }
        }
    }

    for (int i=1 ; i<r ; i++){
        for (int j=1 ; j<c ; j++){
            if (arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
            }
        }
    }

    if(row_flag){
        for (int j=0 ; j<c ; j++)
            arr[0][j] = 0;
    }

    if (col_flag){
        for (int i=0 ; i<r ; i++)
            arr[i][0] = 0;
    }
   

    for (int i=0; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
     return 0;
}