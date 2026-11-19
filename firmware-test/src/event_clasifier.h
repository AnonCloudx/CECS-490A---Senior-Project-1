
#ifndef EVENT_CLASSIFIER_H
#define EVENT_CLASSIFIER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    EVENT_DRY = 0,
    EVENT_POTTY = 1
} PottyEvent;

PottyEvent classify_moisture(int sensor_value,
                             int threshold);

#ifdef __cplusplus
}
#endif

#endif
