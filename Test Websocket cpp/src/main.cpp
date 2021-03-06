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