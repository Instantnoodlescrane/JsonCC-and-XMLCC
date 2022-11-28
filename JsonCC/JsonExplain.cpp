/*
解释处理业务逻辑，不涉及复杂的算法逻辑
*/ 


#include "JsonExplain.hpp"


void JsonExplain::Explain( const std::string& name )
{
    char zeroHsC;
    std::string zeroHsS = "";
    
    if( fin.is_open() )
    {
        while( !fin.eof() ) {
            zeroHsC = fin.get();
            if( zeroHsC == '"' )
            {
                while( !fin.eof() )
                {
                    zeroHsC = fin.get();
                    if( zeroHsC == '"' )
                    {
                        if( zeroHsS == name )
                        {
                            //std::cout << zeroHsS << std::endl;
                            return;
                        }
                        //std::cout << zeroHsS << std::endl;
                        zeroHsC = fin.get();
                        zeroHsS = "";

                        break;
                    }
                    zeroHsS += zeroHsC;
                }
            }
        }
    }
}


std::string strSub( std::string s )
{
    std::string zeroHsS = "";
    
    for( auto& c : s )
        if( c != ':' && c != ',' && c != '"' && c != ' ' )
            zeroHsS += c;
    
    return zeroHsS;
}


std::string JsonExplain::Explain( const std::initializer_list<std::string>& li )
{
    char zeroHsC;
    std::string zeroHsS = "";
    
    if( fin.is_open() )
    {
        for( auto& x : li )
            Explain( static_cast<std::string>(x) );
        
        while( !fin.eof() )
        {
            zeroHsC = fin.get();
            if( zeroHsC == ',')
                return strSub( zeroHsS );
            zeroHsS += zeroHsC;
        }
    }

    return "无标签";
}



