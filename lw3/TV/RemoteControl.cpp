#include "TVSet.h"
#include "RemoteControl.h"


void Control::TurnOn(CTVSet& TV, std::ostream& output)
{
	if (!TV.IsTurnOn())
	{
		TV.TurnOn();
		output << TV_IS_ON;
	}
	else
	{
		output << ALREADY_ON;
	}
}

void Control::TurnOff(CTVSet& TV, std::ostream& output)
{
	if (TV.IsTurnOn())
	{
		TV.TurnOff();
		output << TV_IS_OFF;
	}
	else
	{
		output << ALREADY_OFF;
	}
}

void Control::SelectChannel(CTVSet& TV, std::istream& input, std::ostream& output)
{
	int channel;
	if (input >> channel)
	{
		if (!TV.IsTurnOn())
		{
			output << TV_IS_OFF;
			return;
		}
		else if (!TV.IsExist(channel))
		{
			output << CHANNEL_NOT_EXIST;
			return;
		}
		TV.SelectChannel(channel);
		output << SELECTED_CHANNEL << channel << std::endl;
	}
	else
	{
		output << INPUT_ERROR;
		input.clear();
	}
}

void Control::Info(CTVSet& TV, std::ostream& output)
{
	if (TV.IsTurnOn())
	{
		output << TV_IS_ON;
	}
	else
	{
		output << TV_IS_OFF;
	}
	output << CURRENT_CHANNEL << TV.GetChannel() << std::endl;
}

void Control::SelectPreviousChannel(CTVSet& TV, std::ostream& output)
{
	TV.SelectPreviousChannel();
	output << PREVIOUS_CHANNEL_SELECTED;
}

void Control::Controller(CTVSet& TV, std::istream& input, std::ostream& output)
{
	std::string command;
	while (std::cin >> command)
	{

		if (command == TURN_ON)
		{
			TurnOn(TV, output);
		}
		else if (command == TURN_OFF)
		{
			TurnOff(TV, output);
		}
		else if (command == SELECT_CHANNEL)
		{
			SelectChannel(TV, input, output);
		}
		else if (command == INFO)
		{
			Info(TV, output);
		}
		else if (command == SELECT_PREVIOUS_CHANNEL)
		{
			SelectPreviousChannel(TV, output);
		}
		else
		{
			output << UNKNOWN_COMMAND;
		}
	}
}

