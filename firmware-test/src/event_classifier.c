
#include "event_classifier.h"

PottyEvent classify_moisture(int sensor_value,
                             int threshold)
{
    if (sensor_value < threshold) {
        return EVENT_POTTY;
    }

    return EVENT_DRY;
}
