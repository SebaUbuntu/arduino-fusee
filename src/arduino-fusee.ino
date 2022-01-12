#define DEBUG

//#include "payload.h"
#include "logging.h"
#include <SD.h>

#define SD_MISO 12
#define SD_MOSI 11
#define SD_SCK 13
#define SD_CS 10

static bool ready = false;

void setup() {
	int rc = 0;

	Serial.begin(9600);

	LOGI("Setting up SD card...");
	rc = SD.begin(SD_CS);
	if (!rc) {
		LOGE("SD card failed to initialize");
		goto exit;
	}

	LOGI("SD card initialized");

	LOGI("Checking if payload.bin exists...");
	rc = SD.exists("payload.bin");
	if (!rc) {
		LOGE("payload.bin does not exist");
		goto exit;
	}

	LOGI("payload.bin found");

	ready = true;

exit:
	return;
}

void loop() {
	while (!ready) {
		delay(100);
	}

	// Here we would read the payload.bin file and send it to the
	// USB port, not today.
}
