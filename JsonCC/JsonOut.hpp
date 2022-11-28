//
//  JsonOut.hpp
//  JsonCC
//
//  Created by apple on 2022/11/26.
//

#ifndef JsonOut_hpp
#define JsonOut_hpp


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>


class JsonOut
{
private:
    std::string jsonName;
    std::ofstream outF;
public:
    JsonOut();
    JsonOut( const std::string jName );
    
    
    JsonOut& SaveFJson();
    JsonOut& SaveEJson();
    
    void WriteJson( const std::string& mType, const std::string& name, const std::string& value );
    void WriteJson( const std::string& name, const std::initializer_list<std::string>& li );
    void WriteJson( const std::string& mType, const std::string& name, const std::initializer_list<std::string>& li );
    void WriteJson( const std::string& mType, const std::string& name, const std::initializer_list< std::initializer_list<std::string> > li );
    void WriteJson( const std::string& mType, const std::string& name, const std::initializer_list< std::initializer_list<std::initializer_list<std::string>>> li );
    void WriteString( const std::string& name, const std::string& value );
    void WriteBool( const std::string& name, const std::string& value );
    void WriteNumder( const std::string& name, const std::string& value );
};


#endif /* JsonOut_hpp */
