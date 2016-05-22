#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String {
    char *pData;         /// pointer az adatra
    unsigned int len;    /// hossz lezĂĄrĂł nulla nĂŠlkĂźl
public:
    String() :pData(0), len(0) {}
    const char* c_str() const { if (pData) return pData; else return "";}
    String(char ch);
    String(const char *p);
    String(const String& s1);
    ~String() { delete[] pData; }
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
        << (pData ? pData : "(NULL)") << std::endl;
    }
    String& operator=(const String& rhs_s);
    String& operator+=(const String& rhs_s) {
    *this = *this + rhs_s;
    return *this;
    }

    bool operator>(const String& rhs){
        return strcmp(this->pData, rhs.pData) < 0;
    }
    bool operator>(const String& rhs) const{
        return strcmp(this->pData, rhs.pData) < 0;
    }
    bool operator<(const String& rhs) {
        return strcmp(this->pData, rhs.pData) > 0;
    }
    bool operator<(const String& rhs) const {
        return strcmp(this->pData, rhs.pData) > 0;
    }

    bool operator==(const String& rhs){
        return strcmp(rhs.pData, this->pData) == 0;
    }

    bool operator==(const String& rhs) const{
        return strcmp(rhs.pData, this->pData) == 0;
    }


    int length(){return len;}

    const int length() const{return len;}

    String operator+(const String& rhs_s) const ;

    String operator+(char rhs_c) const { return *this + String(rhs_c);}

    char& operator[](unsigned int idx);

    const char& operator[](unsigned int idx) const;

    void erase() { *this = ""; }

//    String operator+=(char c);
//
//    String operator+(char rhs);
};

std::ostream& operator<<(std::ostream& os, const String& s0);


std::istream& operator>>(std::istream& is, String& s0);

inline String operator+(char ch, const String& str) { return String(ch) + str; }



using std::cin;
using std::ios_base;

String::String(char ch) {
    len = 1;
    pData = new char[len+1];
    pData[0] = ch;
    pData[1] = '\0';
}


String::String(const char *p) {
    len = strlen(p);
    pData = new char[len+1];
    strcpy(pData, p);
}

// MĂĄsolĂł konstruktor
String::String(const String& s1) {
    // MeghatĂĄrozzuk a hosszĂĄt
    len = s1.len;
    // Helyet foglalunk
    pData = new char[len+1];
    // BemĂĄsoljuk a stringet, ami le van zĂĄrva 0-val Ă­gy hasznĂĄlhatĂł az strcpy is
    strcpy(pData, s1.pData);
}

// operator=
String& String::operator=(const String& rhs_s) {
    if (this != &rhs_s ) {
        delete[] pData;
        len = rhs_s.len;
        // Helyet foglalunk
        pData = new char[len+1];
        // BemĂĄsoljuk a stringet, ami le van zĂĄrva 0-val Ă­gy hasznĂĄlhatĂł az strcpy is
        strcpy(pData, rhs_s.pData);
    }
    return *this;
}

// [] operĂĄtorok: egy megadott indexĹą elem REFERENCIĂJĂVAL tĂŠrnek vissza.
// indexhiba esetĂŠn dobjon egy const char * tĂ­pusĂş hibĂĄt!
char& String::operator[](unsigned int idx) {
    if (idx >= len) throw "String: indexelesi hiba";
    return pData[idx];
}

const char& String::operator[](unsigned int idx) const {
    if (idx >= len) throw "String: indexelesi hiba";
    return pData[idx];
}

// + operĂĄtor, ami kĂŠt stringet ad Ăśssze (concatString)
String String::operator+(const String& rhs_s) const {
    String temp;		// ide kerĂźl az eredmĂŠny
    // MeghatĂĄrozza az Ăşj string hosszĂĄt
    temp.len = len + rhs_s.len;
    // FelszabadĂ­tja a temp adattaerĂźletĂŠt
    delete []temp.pData;
    // lefoglalja a memĂłriĂĄt az Ăşj stringnek.
    temp.pData = new char[temp.len+1];
    // Az elejĂŠre bemĂĄsolja az elsĹ stringet
    strcpy(temp.pData, pData);
    // BemĂĄsolja a mĂĄsodik stringet.
    strcat(temp.pData, rhs_s.pData);

    return temp;		// visszatĂŠr az eredmĂŠnnyel

}

//String String::operator+(char rhs){
//    String temp;
//    temp.len = len + 1;
//    delete [] temp.pData;
//    strcpy(temp.pData, pData);
//    temp.pData[len] = rhs;
//    temp.pData[temp.len] = '\0';
//    return temp;
//}



// << operator, ami kiĂ­r az ostream-re
std::ostream& operator<<(std::ostream& os, const String& s0) {
    os << s0.c_str();
    return os;
}

// << operĂĄtor, ami beolvas az istreamrĹl egy szĂłt
std::istream& operator>>(std::istream& is, String& s0) {
    unsigned char ch;
    s0 = String("");            // Ăźres string, ehhez fĹązĂźnk hozzĂĄ
    std::ios_base::fmtflags fl = is.flags(); // eltesszĂźk a rĂŠgi flag-eket
    is.setf(ios_base::skipws);			// az elejĂŠn eldobjuk a ws-t
    while (is >> ch) {
        is.unsetf(ios_base::skipws);	// utĂĄna pedig mĂĄr nem
        if (isspace(ch)) {
            is.putback(ch);             // na ezt nem kĂŠrjĂźk
            break;
        } else {
            s0 = s0 + ch;               // vĂŠgĂŠre fĹązzĂźk a karaktert
        }
    }
    is.setf(fl);						// visszaĂĄllĂ­tjuk a flag-eket
    return is;
}



#endif
