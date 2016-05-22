#include "String.hpp"
#include "TxtFile.hpp"
#include <cstring>

using namespace std;




int main(int argc, char *argv[]) {
    if (argc < 2) {
        exit(2);
    }

    cout << argv[1] << endl;
    TxtFile txtFile = TxtFile(argv[1]);
    TxtFile::Iterator it;
    for (it = txtFile.begin(); it != txtFile.end(); it++){
        cout<< *it;
    }

    cout <<endl;
    cout <<endl;

    TxtFile normalSorted = txtFile.normalSort();
    for (it = normalSorted.begin(); it != normalSorted.end(); it++){
        cout<< *it;
    }

    cout <<endl;
    cout <<endl;


    TxtFile reverseSorted = txtFile.reverseSort();
    for (it = reverseSorted.begin(); it != reverseSorted.end(); it++){
        cout<< *it;
    }

    cout << endl;
    cout << endl;

    TxtFile notCaseSensitiveSorted = txtFile.notCaseSensitiveSort();
    for (it = notCaseSensitiveSorted.begin(); it != notCaseSensitiveSorted.end(); it++){
        cout<< *it;
    }

    cout<<endl;
    cout<<endl;

    TxtFile humanReadableSorted = txtFile.humanReadableSort();
    for (it = humanReadableSorted.begin(); it != humanReadableSorted.end(); it++){
        cout<< *it;
    }

    cout<<endl;
    cout<<endl;

    TxtFile numericSorted = txtFile.numericSort();
    for (it = numericSorted.begin(); it != numericSorted.end(); it++){
        cout<< *it;
    }






    return 0;
}
