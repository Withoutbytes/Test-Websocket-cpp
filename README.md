# Test-Websocket-cpp

This is a Simple Websocket example for cpp this project don't need any dlls only need you copy the ixwebsocket folder to your project folder and fallow the example:

Client and Server suport libraly

this library was not madded by me credits:
https://github.com/machinezone/IXWebSocket

```CPP
#include "../ixwebsocket/IXNetSystem.h"
#include "../ixwebsocket/IXWebSocketServer.h"
#include <Windows.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Crypt32.lib")
#pragma comment(lib, "shlwapi.lib")

int main() {
	ix::initNetSystem();

	ix::WebSocketServer webSocketsv(8080);
	webSocketsv.setOnConnectionCallback([](std::shared_ptr<ix::WebSocket> webSocket, std::shared_ptr<ix::ConnectionState> connectionState) -> void {
		webSocket->setOnMessageCallback([](const ix::WebSocketMessagePtr& msg) -> void {
			if (msg->type == ix::WebSocketMessageType::Message)
				MessageBoxA(NULL, msg->str.c_str(), "Message", MB_OK);
		});
	});

	auto res = webSocketsv.listen();
	if (!res.first)
	{
		return false;
	}

	webSocketsv.start();

	std::cout << "Server on" << std::endl;
	Sleep(INFINITE);
} 
```

# How to use
1 - You just download this project.
`git clone https://github.com/Withoutbytes/Test-Websocket-cpp.git`
2 - Open this is visual studio.

3 - Compile and run the project.

4 - Open .html file in root folder with any browser.

