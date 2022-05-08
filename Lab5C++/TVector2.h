#pragma once
#include "TVector.h"
class TVector2: public TVector
{
	float x, y;
public:
	TVector2(float, float);
	float get_coord(char) override;
	float get_length() override;
	float scalar(TVector&) override;
};

