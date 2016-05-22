//
// Created by mmarci on 2016.05.15..
//

#ifndef PROGHF_TXTFILE_H
#define PROGHF_TXTFILE_H


#include <cstdio>
#include <cstdlib>
#include "String.hpp"
#include "Vector.hpp"
#include "Algorithms.h"



using namespace std;

class TxtFile{
    Vector<String> lines;

public:

    typedef String* Iterator;

    TxtFile(){ lines = Vector<String>();}
    TxtFile(char*);
    TxtFile(const String&);
    TxtFile(TxtFile&);
    TxtFile normalSort(); //yes
    TxtFile reverseSort(); // speaks for itself
    TxtFile notCaseSensitiveSort();	//speaks for itself
    TxtFile humanReadableSort();	//sort "K M G" values
    TxtFile numericSort();	//sort by numeric value not ascii
    int getSize(){return lines.size();} // get the number of lines
    void push(String&); // add a line to the object
    Iterator end();
    Iterator begin();
    //TxtFile operator=(TxtFile& rhs);

};

bool reverse(const String& lhs, const String& rhs ){
    return lhs < rhs;
}


bool notCaseSensitive(const String& lhs, const String& rhs){
    unsigned i = 0;
    for (;i<lhs.length() && i<rhs.length(); i++){
        if (tolower(lhs[i]) != tolower(rhs[i]))
            return tolower(lhs[i]) < tolower(rhs[i]) ;

    }
    return i == lhs.length();
};


bool numeric(const String& lhs, const String& rhs){
    int i = atoi(lhs.c_str());
    int j = atoi(rhs.c_str());

    return i<j;
}

bool hread(const String& lhs, const String& rhs){
    char lhslast = lhs[lhs.length()-1];
    char rhslast = rhs[rhs.length()-1];
    int rhstrenght;
    int lhstrenght;
    switch(lhslast){
        case 'B'  :
            lhstrenght = 0;
            break;
        case 'K'  :
            lhstrenght = 1;
            break;
        case 'M'  :
            lhstrenght = 2;
            break;
        case 'G'  :
            lhstrenght = 3;
            break;
        case 'T'  :
            lhstrenght = 4;
            break;
        default:
            lhstrenght = -1;
    }
    switch(rhslast){
        case 'B'  :
            rhstrenght = 0;
            break;

        case 'K'  :
            rhstrenght = 1;
            break;

        case 'M'  :
            rhstrenght = 2;
            break;

        case 'G'  :
            rhstrenght = 3;
            break;
        case 'T'  :
            rhstrenght = 4;
            break;
        default:
            rhstrenght = -1;
    }
    if (lhstrenght < rhstrenght){
        return true;
    }else if (lhstrenght > rhstrenght){
        return false;
    }else{
        return numeric(lhs, rhs);
    }
}

TxtFile::TxtFile(char* filename){
    if (filename == "")
        throw "Can't make object from nothing... -.-' Please specify something";

    FILE *f = fopen(filename, "r");
    if (f == NULL) perror("Error opening file");

    char *line = new char[1024];
    String sLine;

    while (fgets(line, 1024, f) != NULL ) {
        sLine = String(line);
        lines.push_back(sLine);
    }
    fclose(f);
    delete [] line;

}

TxtFile::TxtFile(const String& filename) {
    if (filename == "")
        throw "Can't make object from nothing... -.-' Please specify something";

    FILE *f = fopen(filename.c_str(), "r");
    if (f == NULL) perror("Error opening file");

    char *line = new char[1024];
    String sLine;

    while (fgets(line, 1024, f) != NULL ) {
        sLine = String(line);
        lines.push_back(sLine);
    }
    fclose(f);
    delete [] line;

}

TxtFile::TxtFile(TxtFile& other){
    for (int i = 0; i<other.getSize(); i++){
        lines.push_back(other.lines[i]);
    }
}

void TxtFile::push(String& str){
    lines.push_back(str);
}


TxtFile TxtFile::normalSort() {
    TxtFile tmp;
    for(unsigned i = 0; i < lines.size(); i++){
        tmp.push(lines[i]);
    }
    Algorithms::sort(tmp.lines.begin(), tmp.lines.end());
    return tmp;

}

TxtFile TxtFile::reverseSort(){
    TxtFile tmp;
    for (unsigned i = 0; i < lines.size(); i++)
        tmp.push(lines[i]);
    Algorithms::sort(tmp.begin(), tmp.end(), reverse);
    return tmp;
}

TxtFile TxtFile::notCaseSensitiveSort(){
    TxtFile tmp;

    for (unsigned i = 0; i < lines.size(); i++)
        tmp.push(lines[i]);

    Algorithms::sort(tmp.begin(), tmp.end(), notCaseSensitive);


    return tmp;
}

TxtFile TxtFile::numericSort(){
    TxtFile tmp;

    for (unsigned i = 0; i < lines.size(); i++)
        tmp.push(lines[i]);

    Algorithms::sort(tmp.begin(), tmp.end(), numeric);


    return tmp;
}


TxtFile TxtFile::humanReadableSort(){
    TxtFile tmp;

    for (unsigned i = 0; i < lines.size(); i++)
        tmp.push(lines[i]);

    Algorithms::sort(tmp.begin(), tmp.end(), hread);


    return tmp;
}

TxtFile::Iterator TxtFile::end(){
    return lines.end();
}

TxtFile::Iterator TxtFile::begin(){
    return lines.begin();
}

//TxtFile TxtFile::operator=( TxtFile &rhs) {
//    if (this != &rhs){
//        lines.clear();
//        lines = Vector<String>();
//        Iterator it;
//        for (it = rhs.begin() ; it != rhs.end();  it++){
//            lines.push_back(*it);
//        }
//
//    }
//}


ostream &operator<<(ostream &os , TxtFile &rhs) {
    TxtFile::Iterator it;
    for (it = rhs.begin(); it != rhs.end(); it++){
        os<<*it<<endl;
    }

    return os;
}


#endif //PROGHF_TXTFILE_H
