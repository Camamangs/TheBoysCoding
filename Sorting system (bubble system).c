#include <stdio.h>

//I still Do not understand this or rather I understand it but cant imagine it

int main() {
    int l = 0;

    printf("Max Count of Integers to Sort: ");
    scanf("%d", &l);
    printf("\n\n");

    int Array[l];

    for (int i = 0; i < l; i++){
        printf("Enter a Integer[%d]: ", i);
        scanf("%d", &Array[i]);
    }

    for (int i = 0; i < l; i++){
        printf("Array[%d] = %d\n", i, Array[i]);
    }

    int boolean = 1;
    while(boolean) {
        boolean = 0;
        for (int i = 0; i < l; i++) {
            printf("Compare %d and %d\n", Array[i], Array[i+1]);
            if (Array[i] > Array[i+1]) {

                printf("Swapped (");
                
                printf(" '%d' ", Array[i]);
                printf(" '%d' ", Array[i+1]);
                
                printf(") ==>");

                int temp = Array[i];
                Array[i] = Array[i+1];
                Array[i+1] = temp;  
                boolean = 1;

                printf("Swapped (");
                for (int i = 0; i < l ; i++){
                    printf(" '%d' ", Array[i]);
                }
                printf(")\n");

            }
            else {
                printf("Not Swapped\n");
            }
        }

        printf("\n\n");
        for (int i = 0; i < l; i++){
            printf("Array[%d] = %d\n", i, Array[i]);
        }
    }
        
    return 0;
}