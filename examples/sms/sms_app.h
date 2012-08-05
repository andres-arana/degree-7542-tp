#ifndef SMS_APP_H
#define SMS_APP_H

#include "angelcodefont.h"
#include "config_file.h"
#include "spring_mass_system.h"
#include "video.h"

#include <SDL.h>

class SMSApp
{
	ACFont acf_;
	ConfigFile config_;
	SpringMassSystem sms_;
	Video video_;
	uint32_t ticks_;
	void drawFrame();
public:
	SMSApp(int argc, char* argv[]);
	virtual ~SMSApp();
	int run();
};

#endif
