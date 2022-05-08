#pragma once
#include "TVector.h"
class TVector3: public TVector
{
	float x, y, z;
public:
	TVector3(float x = 0, float y = 0, float z = 0);
	float get_coord(char) override;
	float get_length() override;
	float scalar(TVector&) override;
};

