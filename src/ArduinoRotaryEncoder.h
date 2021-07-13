#ifndef _ARDUINO_ROTARYENCODER_H_
#define _ARDUINO_ROTARYENCODER_H_

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "RotaryEncoder.h"

class ArduinoRotaryEncoder : public RotaryEncoder
{
public:
	ArduinoRotaryEncoder(uint8_t S2, uint8_t S1, EncoderEventHandler eventHandler = nullptr) : RotaryEncoder(S2, S1, eventHandler)
	{
	};

	~ArduinoRotaryEncoder()
	{
	};

	void initPins()
	{
		pinMode(pinLeft, INPUT_PULLUP);
		pinMode(pinRight, INPUT_PULLUP);
	};

protected:

	virtual uint8_t getState()
	{
		return digitalRead(pinRight) | digitalRead(pinLeft) << 1;
	};

};


#endif
