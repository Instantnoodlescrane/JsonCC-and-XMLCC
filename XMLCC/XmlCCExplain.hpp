#ifndef XMLCCExplain_hpp
#define XMLCCExplain_hpp


#include <iostream>
#include <fstream>
#include <string>


class XmlCCExplain
{
private:
    std::ifstream fin;
    
public:
    XmlCCExplain() : fin(nullptr) {}
    XmlCCExplain( const std::string& pathName ) { fin.open( pathName, std::ios::binary ); }

    void Explain( const std::string& name );
    std::string Explain( const std::initializer_list<std::string>& li );
    
    ~XmlCCExplain() { fin.clear(); }
};


#endif /* XMLCCExplain_hpp */
