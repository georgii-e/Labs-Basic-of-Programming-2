#pragma once
class TVector
{
public:
	virtual float get_length() = 0;
	virtual float get_coord(char) = 0;
	virtual float scalar(TVector&) = 0;
};

