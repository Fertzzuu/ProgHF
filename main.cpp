#include "String.hpp"
#include "TxtFile.hpp"

using namespace std;




int main() {

    String fn("/home/mmarci/ClionProjects/ProgHF/test.txt");
    TxtFile txtFile;
    txtFile = TxtFile(fn);


    return 0;
}
