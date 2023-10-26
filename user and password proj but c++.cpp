#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int StoredData = 1, DataLength = 10;

    char StoredUser[StoredData][DataLength] = {"Admin"};
    char StoredPass[StoredData][DataLength] = {"123"};
    char InputPass[DataLength];
    char InputUser[DataLength];

    int Passed = 0;
    int PassA = 0, PassB = 0;

    LogIn:

    cout << "Username:";
    cin >> InputUser;
    cout << "Password:";
    cin >> InputPass;

    if (strlen(InputUser) > 20 || strlen(InputPass) > 20){
        cout << "Please Input less than 20 characters" << endl;
    }
    else if (strlen(InputUser) < 3 || strlen(InputPass) < 3){
        cout << "Please Input more than 3 characters" << endl;
    }

    for (int i = 0 ; i < StoredData; i++) {
        cout << "Comparing with: " << StoredUser[i] << endl;
        
        if (strcmp(InputUser, StoredUser[i]) == 0) {
            PassA = 1;

            if (strcmp(InputPass, StoredPass[i]) == 0) {
                PassB = 1;
                break;
            }
        }
    }

    if (PassA == 1 && PassB == 1){
        Passed = 1;
    }
    else if (PassA == 0){
        cout << "Username is Incorrect or User Not found" << endl;
    }

    if (Passed == 0) {
        int reapet = 1;
        while(reapet) {
            char YN[5];
            cout << "Create new account with this Username: '" << InputUser << "' and Password: '" << InputPass << "' ?\n" << "Yes[Y/y] - No[N/n]:";
            cin >> YN;

            if (strcmp(YN, "Y") == 0 || strcmp(YN, "y") == 0 || strcmp(YN, "N") == 0 || strcmp(YN, "n") == 0) {
                if(!(strcmp(YN, "N") == 0 || strcmp(YN, "n") == 0)) {
                    StoredData++;
                    strcpy(StoredUser[StoredData-1], InputUser);
                    strcpy(StoredPass[StoredData-1], InputPass);
                    PassA, PassB = 0;
                    reapet = 0;
                    goto LogIn;
                }
                else {
                    PassA, PassB = 0;
                    reapet = 0;
                    goto LogIn;
                }
            }
        }
    }
    cout << "\nSuccesfully LogIn!!!!" << endl;
}