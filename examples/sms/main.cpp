#include "sms_app.h"
#include <SDL.h>

int main(int argc, char* argv[])
{
	SMSApp app(argc, argv);

	return app.run();
}
