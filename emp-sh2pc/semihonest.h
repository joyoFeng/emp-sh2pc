#ifndef SEMIHONEST_H__
#define SEMIHONEST_H__
#include "emp-sh2pc/semihonest_gen.h"
#include "emp-sh2pc/semihonest_eva.h"

namespace emp {
template<typename IO>
inline void setup_semi_honest(IO* io, int party) {
	if(party == ALICE) {
		HalfGateGen<IO> * t = new HalfGateGen<IO>(io);
		CircuitExecutionProxy::circ_exec.setup(t);
		ProtocolExecutionProxy::prot_exec.setup(new SemiHonestGen<IO>(io, t));
	} else {
		HalfGateEva<IO> * t = new HalfGateEva<IO>(io);
		CircuitExecutionProxy::circ_exec.setup(t);
		ProtocolExecutionProxy::prot_exec.setup(new SemiHonestEva<IO>(io, t));
	}
}

template<typename IO>
inline void finalize_semi_honest(IO* io, int party) {
	ProtocolExecutionProxy::prot_exec.finalize();
	CircuitExecutionProxy::circ_exec.finalize();
}
}
#endif
