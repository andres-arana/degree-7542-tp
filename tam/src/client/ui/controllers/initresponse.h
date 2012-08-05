#ifndef CLIENT_UI_CONTROLLERS_INITRESPONSE_H_
#define CLIENT_UI_CONTROLLERS_INITRESPONSE_H_

namespace client {
	namespace ui {
		namespace controllers {
			class InitResponse {
				private:
					bool exited;
					bool multiplayer;
					
				public:
					InitResponse(bool exited, bool multiplayer);
					
					bool getExited() const;					
					bool getMultiplayerSession() const;
			};
		}
	}
}

#endif /*CLIENT_UI_CONTROLLERS_INITRESPONSE_H_*/
