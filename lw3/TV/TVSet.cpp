#include "TVSet.h"
#include "RemoteControl.h"

void CTVSet::TurnOn()
{
	m_isEnable = true;
}

void CTVSet::TurnOff()
{
	m_isEnable = false;
}

bool CTVSet::IsTurnOn() const
{
	return m_isEnable;
}

bool CTVSet::IsExist(int currentChannel)
{
	return currentChannel >= m_minChannel && currentChannel <= m_maxChannel;
}

bool CTVSet::SelectChannel(int currentChannel)
{
	if (!m_isEnable)
	{
		return false;
	}
	else if (IsExist(currentChannel))
	{
		m_previousChannel = m_channel;
		m_channel = currentChannel;
		return true;
	}
	return false;
}

int CTVSet::GetChannel() const
{
	if (m_isEnable)
		return m_channel;
	return 0;
}

void CTVSet::SelectPreviousChannel()
{
	if (!m_isEnable || m_previousChannel != 0)
		std::swap(m_channel, m_previousChannel);
}