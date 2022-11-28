#include <iostream>

#include "XmlCCExplain.hpp"


int main(int argc, const char * argv[]) {
    XmlCCExplain xmlE( "./XML.xml" );
    std::string s = xmlE.Explain( {"prn1", "prn", "id"} );
    std::cout << s << std::endl;
    
    return 0;
}
