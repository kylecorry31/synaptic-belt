#include "HapticBelt.h"
#include <Arduino.h>

HapticBelt::HapticBelt(int haptics[8])
{
    memccpy(haptic_pins_, haptics, 8, sizeof(int));
    for (int i = 0; i < 8; i++)
    {
        pinMode(haptic_pins_[i], OUTPUT);
    }
}

bool HapticBelt::isDirectionValid(int direction)
{
    return direction >= 0 && direction < 360 && direction % 45 == 0;
}

void HapticBelt::on(int direction)
{
    if (!isDirectionValid(direction))
    {
        // Error condition
        return;
    }

    int position = direction / 45;

    digitalWrite(haptic_pins_[position], HIGH);
}

void HapticBelt::off(int direction)
{
    if (!isDirectionValid(direction))
    {
        // Error condition
        return;
    }

    int position = direction / 45;

    digitalWrite(haptic_pins_[position], LOW);
}
