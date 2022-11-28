//
//  main.cpp
//  JsonCC
//
//  Created by apple on 2022/11/25.
//

#include <iostream>
#include <string>
#include <fstream>

#include "JsonExplain.hpp"
#include "JsonOut.hpp"


int main( int argc, const char * argv[] ) {
    // insert code here...

    JsonOut jsonOut( "./Text.json" );
    // JsonOut jsonOut;
    
    jsonOut.SaveFJson();
    jsonOut.WriteJson( "string", "1", "as" );
    jsonOut.WriteJson( "bool", "bool", "true" );
    jsonOut.WriteJson( "numder", "ID", "1020983902183091283" );
    jsonOut.WriteJson( "numder", "numder", "123" );
    jsonOut.WriteJson( "object", "Object1", {"numder", "Day", "6", "bool", "V/M", "False", "string", "name", "AUAS"} );
    jsonOut.WriteJson( "object", "Object2", {"numder", "Day", "7", "bool", "V/M", "T", "string", "name", "AUA2S"} );
    jsonOut.WriteJson( "array", "Arr", {{ {"numder", "D2ay", "7"}, {"bool", "V/31M", "T"}, {"string", "name", "AUA2S"} },{ {"numder", "D123ay", "7"}, {"bool", "V/M", "T"}, {"string", "name", "AUA2S"} },{ {"numder", "1Day", "7"}, {"bool", "1V/M", "T"}, {"string", "1name", "AUA2S"} }} );
    jsonOut.WriteJson( "numder", "The", "3" );
    jsonOut.SaveEJson();
    
    JsonExplain jsonExplain( "./Text.json" );
    auto b = jsonExplain.Explain( {"Arr", "D2ay"} );
    std::cout << b << std::endl;
    
    return 0;
}
