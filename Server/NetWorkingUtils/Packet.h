#pragma once
#define DEFAULT_BUFLEN 1024

enum class PackageType {
    Unknown = -1,
    File = 1,
    Message = 2,
};

struct packet
{
    PackageType id;
    unsigned char data[DEFAULT_BUFLEN];

    packet() {};
    packet(PackageType id, unsigned char datsa[DEFAULT_BUFLEN]) {
        this->id = id;
        std::copy(datsa, datsa + DEFAULT_BUFLEN, this->data);
    }
};