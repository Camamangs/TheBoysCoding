#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int StoredData = 1, DataLength = 10;

    char StoredUser[StoredData][DataLength] = {"Admin"};
    char StoredPass[StoredData][DataLength] = {"123"};
    char InputPass[DataLength];
    char InputUser[DataLength];

    int Passed = 0, PassA = 0, PassB = 0;

    LogIn:

    cout << "Username:";
    cin >> InputUser;
    cout << "Password:";
    cin >> InputPass;

    for (int i = 0 ; i < StoredData; i++) {
        cout << "Comparing with: " << StoredUser[i] << endl;
        
        if (strcmp(InputUser, StoredUser[i]) == 0) {
            cout << "User Found!!\n";
            PassA = 1;

            if (strcmp(InputPass, StoredPass[i]) == 0) {
                cout << "Pass Correct!!\n";
                PassB = 1;
                break;
            }
            else {
                cout << "Pass Incorrect.\n";
            }
        }
        else {
            cout << "User not Found.\n";

            if (PassB == 0){
                cout << "Pass Incorrect.\n";
            }
        }
    }

    if (PassA == 1 && PassB == 1){
        Passed = 1;
    }

    if (Passed == 0) {
        int reapet = 1;
        while(reapet) {
            char YN[5];
            cout << "Create new account with this Username: " << InputUser << " and Password: " << InputPass << " ?\n" << "Yes[Y/y] - No[N/n]:";
            cin >> YN;

            if (strcmp(YN, "Y") == 0 || strcmp(YN, "y") == 0 || strcmp(YN, "N") == 0 || strcmp(YN, "n") == 0) {
                if(!(strcmp(YN, "N") == 0 || strcmp(YN, "n") == 0)) {
                    StoredData++;
                    strcpy(StoredUser[StoredData-1], InputUser);
                    strcpy(StoredPass[StoredData-1], InputPass);
                    reapet = 0;
                    goto LogIn;
                }
                else {
                    reapet = 0;
                    goto LogIn;
                }
            }
        }
    }
    cout << "\nSuccesfully LogIn!!!!" << endl;
}