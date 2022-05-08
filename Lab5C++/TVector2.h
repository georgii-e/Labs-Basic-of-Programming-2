#pragma once
#include "TVector.h"
class TVector2: public TVector
{
	float x, y;
public:
	TVector2(float x = 0, float y = 0);
	float get_coord(char) override;
	float get_length() override;
	float scalar(TVector&) override;
};

