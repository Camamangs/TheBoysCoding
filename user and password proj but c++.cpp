#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int StoredData = 1, DataLength = 10;

    char StoredUser[StoredData][DataLength] = {"Admin"};
    char InputUser[DataLength];

    int Pass = 0;

    LogIn:

    cout << "Username:";
    cin >> InputUser;

    for (int i = 0 ; i <= StoredData; i++) {
        
        if (strcmp(InputUser, StoredUser[i]) == 0) {
            printf("\nUser Found!!\n");
            Pass = 1;
            break;
        }
    }

    if (Pass == 0) {
        cout << "User Not Found Try Again!\n";
        goto LogIn;
    }
}