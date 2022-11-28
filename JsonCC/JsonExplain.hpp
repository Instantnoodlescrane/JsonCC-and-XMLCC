/*
解释处理业务逻辑，不涉及复杂的算法逻辑
*/


#ifndef JsonExplain_hpp
#define JsonExplain_hpp


#include <iostream>
#include <string>
#include <fstream>


class JsonExplain
{
private:
    std::ifstream fin;
    
public:
    JsonExplain() : fin(nullptr) {}
    JsonExplain( const std::string& pathName ) { fin.open( pathName, std::ios::binary ); }

    void Explain( const std::string& name );
    std::string Explain( const std::initializer_list<std::string>& li );
    
    ~JsonExplain() { fin.clear(); }
};



#endif /* JsonExplain_hpp */
