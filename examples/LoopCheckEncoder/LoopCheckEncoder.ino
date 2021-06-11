#include "ArduinoRotaryEncoder.h"

ArduinoRotaryEncoder encoder(2, 3);

void handleEncoderEvent(const RotaryEncoder* enc, ENCODER_EVENT eventType)
{
	switch (eventType)
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

void setup()
{
	Serial.begin(115200);

	encoder.initPins();

	encoder.setEventHandler(handleEncoderEvent);
}

void loop()
{
	if (encoder.catchTicks())
	{
		Serial.println(F("rotating"));
	}
}
