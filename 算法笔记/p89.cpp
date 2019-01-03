#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int length = 0;
    char c;

    /*scanf("%d %c", &length, c);*/
    cin >> length >> c;

    for (int i = 0; i < length; i++) cout << c;
    cout << endl;
    for (int i = 0; i < length/2 - 2; i++) {
        cout << c;
        for (int j = 0; j < length - 2; j++) {
            cout << " ";
        }
        cout << c << endl;
    }
    for (int i = 0; i < length; i++) cout << c;
    return 0;
}
