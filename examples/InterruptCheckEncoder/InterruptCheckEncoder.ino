#include "ArduinoRotaryEncoder.h"
#include "EventsQueue.hpp"


ArduinoRotaryEncoder encoder(2, 3);

EventsQueue<ENCODER_EVENT, 32> queue;

void catchEncoderTicks()
{
	encoder.catchTicks();
}

void handleEncoderEvent(const RotaryEncoder* enc, ENCODER_EVENT eventType)
{
	queue.push(eventType);
}

void setup()
{
	Serial.begin(115200);

	encoder.initPins();

	encoder.setEventHandler(handleEncoderEvent);

	attachInterrupt(digitalPinToInterrupt(2), catchEncoderTicks, CHANGE);
	attachInterrupt(digitalPinToInterrupt(3), catchEncoderTicks, CHANGE);
}

void loop()
{
	bool processEncEvent;
	ENCODER_EVENT encEvent;

	do
	{
		noInterrupts();

		processEncEvent = queue.length();

		if (processEncEvent)
		{
			encEvent = queue.pop();
		}

		interrupts();

		if (processEncEvent)
		{
			switch (encEvent)
			{
			case ENCODER_EVENT::LEFT:
				Serial.println(F("LEFT"));
				break;
			case ENCODER_EVENT::RIGHT:
				Serial.println(F("RIGHT"));
				break;
			default:
				break;
			}
		}

	} while (processEncEvent);

	delay(2000);
}
