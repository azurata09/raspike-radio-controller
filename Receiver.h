#ifndef RECEIVER_H
#define RECEIVER_H

#define FORWARD_ACTION 1
#define BACKWARD_ACTION 2
#define SPIN_LEFT_ACTION 3
#define SPIN_RIGHT_ACTION 4

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

class Receiver
{
private:
  int sockfd;
  struct sockaddr_in servaddr;
public:
  Receiver();
  ~Receiver();
  int receive();
};

#endif