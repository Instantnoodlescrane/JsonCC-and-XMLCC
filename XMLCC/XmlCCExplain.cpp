#include "XmlCCExplain.hpp"
 

void XmlCCExplain::Explain( const std::string& name )
{
    char zeroHsC;
    std::string zeroHsS = "";
    
    if( fin.is_open() )
    {
        while( !fin.eof() ) {
            zeroHsC = fin.get();
            if( zeroHsC == '<' )
            {
                while( !fin.eof() )
                {
                    zeroHsC = fin.get();
                    if( zeroHsC == '>' || zeroHsC == ' ' )
                    {
                        if( zeroHsS == name )
                            return;
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


std::string XmlCCExplain::Explain( const std::initializer_list<std::string>& li )
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
            if( zeroHsC == '<' )
                return zeroHsS;
            zeroHsS += zeroHsC;
        }
    }

    return "无标签";
}
