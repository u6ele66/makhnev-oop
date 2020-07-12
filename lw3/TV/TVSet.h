#pragma once
#include "TVAll.h"

class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	bool IsExist(int currentChannel);
	bool SelectChannel(int currentChannel);
	int GetChannel() const;
	bool IsTurnOn() const;
	void SelectPreviousChannel();
private:
	bool m_isEnable = false;
	int m_channel = 1;
	int m_previousChannel = 0;
	static const int m_minChannel = 1;
	static const int m_maxChannel = 99;
};