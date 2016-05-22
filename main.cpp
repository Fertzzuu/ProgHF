#include "String.hpp"
#include "TxtFile.hpp"

using namespace std;




int main() {

    String fn= String("/home/mmarci/ClionProjects/ProgHF/test.txt");
    TxtFile txtFile = TxtFile(fn);
    //TxtFile normalSorted = txtFile.normalSort();



    return 0;
}
