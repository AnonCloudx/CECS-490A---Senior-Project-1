const int MOISTURE_PIN = 34;

const int DRY_THRESHOLD = 3250;
const int POTTY_THRESHOLD = 3000;

enum DiaperState
{
    DRY,
    POTTY_STARTED,
    POTTY_ACTIVE,
    POTTY_ENDED
};

DiaperState currentState = DRY;

int previousReading = 0;
int stableCounter = 0;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    int moisture = analogRead(MOISTURE_PIN);

    switch(currentState)
    {
        case DRY:

            if(moisture < POTTY_THRESHOLD)
            {
                currentState = POTTY_STARTED;

                Serial.println("EVENT: POTTY_STARTED");
            }

            break;

        case POTTY_STARTED:

            currentState = POTTY_ACTIVE;

            Serial.println("STATE: POTTY_ACTIVE");

            break;

        case POTTY_ACTIVE:

            if(abs(moisture - previousReading) < 20)
            {
                stableCounter++;
            }
            else
            {
                stableCounter = 0;
            }

            if(stableCounter >= 10)
            {
                currentState = POTTY_ENDED;

                Serial.println("EVENT: POTTY_ENDED");
            }

            break;

        case POTTY_ENDED:

            if(moisture > DRY_THRESHOLD)
            {
                currentState = DRY;

                Serial.println("STATE: DRY");
            }

            break;
    }

    previousReading = moisture;

    Serial.print("Moisture: ");
    Serial.println(moisture);

    delay(1000);
}