#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../TV/TVSet.h"

TEST_CASE("When TV turned on in the first should be 1 channel")
{
	CTVSet NewTV;
	NewTV.TurnOn();

	REQUIRE(NewTV.GetChannel() == 1);
}

TEST_CASE("When the TV is turned off, it must have channel = 0.")
{
	CTVSet NewTV;
	NewTV.TurnOff();

	REQUIRE(NewTV.GetChannel() == 0);
}

TEST_CASE("Check SelectChannel")
{
	CTVSet NewTV;
	NewTV.TurnOn();
	NewTV.SelectChannel(99);

	REQUIRE(NewTV.GetChannel() == 99);
}

TEST_CASE("When selecting a channel and restarting TV, it must be the same channel.")
{
	CTVSet NewTV;
	NewTV.TurnOn();
	NewTV.SelectChannel(10);
	NewTV.TurnOff();
	NewTV.TurnOn();

	REQUIRE(NewTV.GetChannel() == 10);
}

TEST_CASE("Select a non-existent channel.")
{
	CTVSet NewTV;
	NewTV.TurnOn();
	NewTV.SelectChannel(10);
	NewTV.SelectChannel(100);

	REQUIRE(NewTV.GetChannel() == 10);
	NewTV.SelectChannel(0);

	REQUIRE(NewTV.GetChannel() == 10);
}

TEST_CASE("Select channel at borders")
{
	CTVSet NewTV;
	NewTV.TurnOn();
	NewTV.SelectChannel(10);
	NewTV.SelectChannel(99);

	REQUIRE(NewTV.GetChannel() == 99);
	NewTV.SelectChannel(10);
	NewTV.SelectChannel(1);

	REQUIRE(NewTV.GetChannel() == 1);
}

TEST_CASE("Select a channel on the off TV.")
{
	CTVSet NewTV;
	NewTV.TurnOff();
	NewTV.SelectChannel(2);

	REQUIRE(NewTV.GetChannel() == 0);
}

TEST_CASE("When selecting the previous channel, it should form a loop between the two channels.")
{
	CTVSet NewTV;
	NewTV.TurnOn();
	NewTV.SelectChannel(10);
	NewTV.SelectChannel(99);
	NewTV.SelectChannel(1);
	NewTV.SelectPreviousChannel();
	int channel1 = NewTV.GetChannel();
	NewTV.SelectPreviousChannel();
	int channel2 = NewTV.GetChannel();
	NewTV.SelectPreviousChannel();
	int channel3 = NewTV.GetChannel();

	REQUIRE(channel1 == 99);
	REQUIRE(channel2 == 1);
	REQUIRE(channel3 == channel1);
}