#ifndef COMMA2O2NDATACONVERTER_H
#define COMMA2O2NDATACONVERTER_H

#include <cstring>
#include "common.h"

#include "tno/dynamics/Response.h"
#include "tno/dynamics/inTRp1_1_11.h"
#include "tno/dynamics/inTRp1_3_13.h"
#include "tno/dynamics/inTRp1_4_14.h"
#include "tno/dynamics/inTRp2_1_17.h"
#include "tno/dynamics/inTRp3_1_18.h"

class ComMA2O2NDataConverter {
public:
	static float convert( real argument ) {
		return static_cast<float>( argument );
	}
	
	static int convert( int argument ) {
		return argument;
	}
	
	static bool convert( bool argument ) {
		return argument;
	}
	
	static char* convert( std::string argument ) {
		char* s = new char[ argument.length() + 1 ];
		std::strcpy( s, argument.c_str() );
		return s;
	}
	
	static tno_dynamics_Response_t convert( StateMachineController::V2::Response::Response response ) {
	    tno_dynamics_Response_t o2nResponse{};
	
	    switch ( response ) {
	    	case StateMachineController::V2::Response::ACK: {
	    	    o2nResponse = tno_dynamics_Response_t::tno_dynamics_ACK;
	    	    break;
	    	}
	    	case StateMachineController::V2::Response::UPDATE: {
	    	    o2nResponse = tno_dynamics_Response_t::tno_dynamics_UPDATE;
	    	    break;
	    	}
	    }
	
	    return o2nResponse;
	}
	
	
};

#endif //COMMA2O2NDATACONVERTER_H
