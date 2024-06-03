#pragma once
#include "Participant.h"

class FDealer : public FParticipant
{
public:
	FDealer();
	virtual ~FDealer();
protected:
	void Check();
};

