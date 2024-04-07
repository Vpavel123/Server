#pragma once
#include <string>
#include <winsock2.h>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <format>
#include "Packet.h"
#pragma comment(lib, "ws2_32.lib") 

class MainServer
{
public:
	MainServer();
	~MainServer();

private:
	enum class SocketStatus {
		socket_connect = 0,
		err_socket_init = 1,
		err_socket_listen = 2,
		err_socket_bind = 3,
		socket_close = 4
	};

public:
	std::mutex mtx;
	std::condition_variable cv;
	std::vector<std::thread> threads;

	// Getter кода статуса сервера
	SocketStatus start();
	// Метод для входа присоединения циклических потоков сервера
	void joinLoop();
	// привязываем сокет с адресом и номером порта
	SocketStatus bindServer();
	// отвязываем сокет с адресом и номером порта
	void UnBindServer();
	// переводит сокет сервера в пассивный режим
	SocketStatus Listen();
	void Accept();
	SocketStatus CloseServer();
	SocketStatus getStatus() const;

	void SendData(std::string text);
	void ReceiveData(int client_socket_);

	void handlingAcceptLoop();

	void setprop(u_short port) {
		this->port = port;
	}
	u_short getprop() {
		return port;
	}
	__declspec(property(get = getprop, put = setprop)) u_short _port;
	typedef SocketStatus Status;
private:
	typedef int SockLen_t;

	int listen_socket;
	// Порт сервера
	u_short port;
	SOCKADDR_IN _addr;
	// Сокет сервера
	SOCKET serv_socket;
	SOCKET client_socket;
	// Код статуса
	WSAData wsa_data;
	// Проверка статуса
	Status _status = Status::socket_close;
	// IP 127.0.0.1
	unsigned long LOCALHOST_IP = 0x0100007f;
};
