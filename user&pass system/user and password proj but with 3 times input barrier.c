//i may proceed with a hidden password and better create new account system
//this is a auto registering user and password system

#include <stdio.h>
#include <string.h>

int main() {
    // start making a system that checks for the correct username and password
    // done
    int D = 1000, DataLength = 50; // dili mo gana dapat ma initialized ang StoredUser kay ang c taas ra kung mag puno ani nga mga variable as a initializer

    char StoredUser[1000][50] = {"Admin", "test1", "test2", "test3", "test4"};
    char StoredPass[1000][50] = {"123", "testing", "testing", "testing", "testing"};
    char InputUser[DataLength];
    char InputPass[DataLength];
    int Pass = 0, Count = 0, IncorrectCounter = 0;
    
    LogIn:

    if (IncorrectCounter >= 3) { // if the user is found but the password is incorrect 3 times the system will end
        printf("You inputed 3 times with a incorrect password try again later");
        return 0;
    }

    // I sould put a barrier if input has a more than charachters than 10 cause it will break the system
    //Later nlng kapuy na
    //Karun nlng
    printf("Username: ");
    scanf("%s", &InputUser);

    printf("Paswword: ");
    scanf("%s", &InputPass);

    if (strlen(InputUser) < 3 || strlen(InputPass) < 3) { //checks the input if less than 3
        printf("Please Input More than 3 characters\n");
        goto LogIn;
    }
    else if (strlen(InputUser) > 20 || strlen(InputPass) > 20) { // checks the input if more than 20
        printf("Please Input Less than 20 characters\n");
        goto LogIn;
    }
    
    printf("\n\n");

    //checks the inputs
    for (int i = 0 ; i <= D; i++) {
        printf("Comparing with %s\n", StoredUser[i]);

        if (i > Count){
            Count = i;// count changes into the value of 'i'
        }

        // checks the username if it is present in the array
        if (strcmp(InputUser, StoredUser[i]) == 0) {
            printf("\nUser Found!!\n");

            //checks the password aligned with the StoredUser variable
            if (strcmp(InputPass, StoredPass[i]) == 0) {
                printf("Password Correct!");
                Pass = 1;
            }
            else {
                printf("Password Incorrect!!\n");
                IncorrectCounter++;
                goto LogIn;
            }
            break;
        }

        //stops the search after it encounters an empty spot in the array
        if (strcmp(StoredUser[i], "\0") == 0) {
            printf("Array spot is 'Empty'\nUser Not Found!");
            printf("\nSearch Ended\n");
            break;
        }
    }

    //checks if the variable 'Pass' changes
    if (Pass == 0) {
        int repeat = 1;
        while (repeat) {
            char YN[3];
            printf("Would you like to create an account with the Username: '%s' and with the Password: '%s' Yes-[Y/y] or No[N/n]: ", InputUser, InputPass); // asks the user if, wants to add a new account with the inputs
            scanf("%s", &YN);

            if (strcmp(YN, "Y") == 0 || strcmp(YN, "y") == 0 || strcmp(YN, "N") == 0 || strcmp(YN, "n") == 0) {
                if (!(strcmp(YN, "N") == 0 || strcmp(YN, "n") == 0)) {
                    strcpy(StoredUser[Count], InputUser); // uses count to align. so that empty slots are only changed no the already occupied spots
                    strcpy(StoredPass[Count], InputPass);
                    repeat = 0;
                    break;
                }
                else {
                    repeat = 0;
                    break;
                }
            }
            else {
                printf("Input Error. Please Input Properly");
            }
        }
        goto LogIn;
    }

    return 0; // code ends here

    /*
    done whahahaha. the stored data is declared at a high number but cant add new data within,
    the variable ony have emtpy slots available if it reaches the maximum it will no longer add new data within the variable.
    */
}