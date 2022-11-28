//
//  JsonOut.cpp
//  JsonCC
//
//  Created by apple on 2022/11/26.
//


#include "JsonOut.hpp"


JsonOut::JsonOut()
{
    
}


JsonOut::JsonOut( const std::string jName )
{
    jsonName = jName;
    outF.open( jName, std::ios::out ); 
}


JsonOut& JsonOut::SaveFJson()
{
    outF << "{" << '\n';
    return *this;
}


JsonOut& JsonOut::SaveEJson()
{
    outF << "}" << '\n';
    outF.close();
    return *this;
}


void JsonOut::WriteJson( const std::string& mType, const std::string& name, const std::string& value )
{
    if( mType == "string" )
        WriteString( name, value );
    else if( mType == "bool" )
        WriteBool( name, value );
    else if( mType == "numder" )
        WriteNumder( name, value );
    else
        std::cout << "Error: WriteJson( const std::string& mType, const std::string& name, const std::string& value ) ^^^ const std::string& mType 无类型" << std::endl;
}


void JsonOut::WriteJson( const std::string& mType, const std::string& name, const std::initializer_list<std::string>& li )
{
    if( mType == "object" )
        WriteJson( name, li );
    else
        std::cout << "Error: WriteJson( const std::string& mType, const std::string& name, const std::string& value ) ^^^ const std::string& mType 无类型" << std::endl;
}


void JsonOut::WriteJson( const std::string& mType, const std::string& name, const std::initializer_list< std::initializer_list<std::initializer_list<std::string>>> li )
{
    if( mType == "array" )
    {
        outF << '"' << name << '"' << " : " << "[" << '\n';
        for( auto& c : li )
            WriteJson( mType, name, c );
        outF << "]" << "," << '\n';
    }
    else
        std::cout << "Error: 无类型" << std::endl;
}


void JsonOut::WriteJson( const std::string& mType, const std::string& name, const std::initializer_list<std::initializer_list<std::string>> li )
{
    if( mType == "array" )
    {
        outF << "{" << '\n';
        for( auto& w : li )
        {
            std::list<std::string> vec;
            for( auto& c : w )
            {
                vec.push_back( c );
            }
            std::string v1 = vec.front();
            vec.pop_front();
            std::string v2 = vec.front();
            vec.pop_front();
            std::string v3 = vec.front();
            vec.pop_front();
            
            WriteJson( v1, v2, v3 );
        }
        outF << "}" << "," << '\n';
    }
    else
        std::cout << "Error: WriteJson( const std::string& mType, const std::string& name, const std::string& value ) ^^^ const std::string& mType 无类型" << std::endl;
}


void JsonOut::WriteJson( const std::string& name, const std::initializer_list<std::string>& li )
{
    outF << '"' << name << '"' << " : " << "{" << '\n';
    
    std::list<std::string> vec;
    
    for( auto& o : li )
        vec.push_back( o );
    
    for( int i = 0; i < li.size()/3.0; i ++ )
    {
        std::string v1 = vec.front();
        vec.pop_front();
        std::string v2 = vec.front();
        vec.pop_front();
        std::string v3 = vec.front();
        vec.pop_front();
        WriteJson( v1, v2, v3 );
    }
    
    outF << "}" << "," << '\n';
}


void JsonOut::WriteString( const std::string& name, const std::string& value )
{
    outF << '"' << name << '"' << " : " << '"' << value << '"' << "," << '\n';
}


void JsonOut::WriteBool( const std::string& name, const std::string& value )
{
    std::string vB = "false";
    
    if( !value.empty() )
        vB = "true";
    if( value == "true" || value =="True" || value =="TRUE" || value =="T" || value =="t" )
        vB = "true";
    else if( value == "false" || value =="False" || value =="FALSE" || value =="F" || value =="f" )
        vB = "false";
    else
        std::cout << "Error: WriteBool( const std::string& name, const std::string& value ) ^^^ const std::string& value 布尔类型错误" << std::endl;

    outF << '"' << name << '"' << " : " << vB << "," << '\n';
}


void JsonOut::WriteNumder( const std::string& name, const std::string& value )
{
    outF << '"' << name << '"' << " : " << value << "," << '\n';
}

