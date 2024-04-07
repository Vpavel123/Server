#include "MainServer.h"
#include "../Log/Log.h"

std::atomic<bool> done(false);

MainServer::MainServer()
{
}

MainServer::~MainServer()
{
}

MainServer::SocketStatus MainServer::start()
{
	// старт использования библиотеки сокетов процессом
	int result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	if (result == 0) { Log::WriteInfo("WSA Startup succes"); }

	_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	_addr.sin_port = htons(8000);
	_addr.sin_family = AF_INET;

	serv_socket = socket(_addr.sin_family, SOCK_STREAM, IPPROTO_TCP);
	// Создание сокета
	if (serv_socket == INVALID_SOCKET)
	{
		Log::WriteError("Error at socket: ", WSAGetLastError());
		WSACleanup();
		return _status = Status::err_socket_init;
	}
	int flag = true;
	setsockopt(serv_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&flag, flag);
	bindServer();
	Listen();
	_status = Status::socket_connect;

	return _status;
}

MainServer::SocketStatus MainServer::bindServer()
{
	listen_socket = bind(serv_socket, (struct sockaddr*)&_addr, sizeof(_addr));

	if (bind(serv_socket, (struct sockaddr*)&_addr, sizeof(_addr)) != SOCKET_ERROR) {
		Log::WriteError("bind failed with error: ", WSAGetLastError());
		CloseServer();
		return _status = Status::err_socket_bind;
	}

	return _status;
}

void MainServer::UnBindServer()
{
	closesocket(serv_socket);
}

MainServer::SocketStatus MainServer::Listen()
{
	// Инициализируем слушающий сокет
	listen(serv_socket, SOMAXCONN);
	if (listen(serv_socket, SOMAXCONN != SOCKET_ERROR)) {
		Log::WriteError("listen failed with error: ", WSAGetLastError());
		CloseServer();
		return _status = Status::err_socket_listen;
	}
}

void MainServer::Accept()
{
	int addrlen = sizeof(_addr);
	Log::WriteWarn("Waiting for client to connect...", addrlen);
	client_socket = accept(serv_socket, (struct sockaddr*)&_addr, &addrlen);

	if (client_socket == INVALID_SOCKET) {
		Log::WriteError("accept failed with error: ", WSAGetLastError());
		CloseServer();
	}
	else {
		Log::WriteInfo("Client connected.");
	}

}

MainServer::SocketStatus MainServer::CloseServer()
{
	closesocket(serv_socket);
	WSACleanup();
	return _status = Status::socket_close;
}

MainServer::SocketStatus MainServer::getStatus() const
{
	return _status;
}

void MainServer::SendData(std::string text)
{
	int result;

	packet responseMessage;
	strcpy((char*)responseMessage.data, text.c_str());
	// Сериализация данных из структуры packet в массив байтов
	unsigned char serializedData[DEFAULT_BUFLEN];
	// Пример сериализации id
	serializedData[0] = static_cast<unsigned char>(responseMessage.id);
	// Пример сериализации данных
	for (int i = 0; i < DEFAULT_BUFLEN; i++) {
		serializedData[i + 1] = responseMessage.data[i];
	}

	// Отправка сериализованных данных
	result = send(client_socket, reinterpret_cast<const char*>(serializedData), text.length() + 1, 0);
	Log::WriteInfo(std::format("Send: {}", (char*)&serializedData));
}

void MainServer::ReceiveData(int client_socket_)
{
	while (!done) {
		packet receivedMessage;
		receivedMessage.id = PackageType::Message;
		int bytes_received = recv(client_socket, (char*)&receivedMessage, sizeof(receivedMessage), 0);
		if (bytes_received <= 0) {
			break;
		}
		std::string data((char*)&receivedMessage, bytes_received);
		Log::WriteInfo(std::format("Received: {}", (char*)&receivedMessage));
	}
	closesocket(client_socket);
}

void MainServer::handlingAcceptLoop()
{
	while (true) {
		Accept();
		std::unique_lock<std::mutex> lock(mtx);
		threads.push_back(std::thread(&MainServer::ReceiveData, this, client_socket));
	}

	{
		std::unique_lock<std::mutex> lock(mtx);
		done = true;
	}
	cv.notify_all();

	for (auto& thread : threads) {
		thread.join();
	}

	UnBindServer();
}
