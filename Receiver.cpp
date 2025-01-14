#include "Receiver.h"

Receiver::Receiver()
{
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    std::cerr << "Socket creation failed" << std::endl;
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(12345);
  if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
    std::cerr << "Invalid address/ Address not supported" << std::endl;
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
    std::cerr << "Connection Failed" << std::endl;
    exit(EXIT_FAILURE);
  }
}

Receiver::~Receiver()
{
  close(sockfd);
}

int Receiver::receive()
{
  char buffer[1024] = {0};
  int bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytesRead < 0) {
    std::cerr << "Receive failed" << std::endl;
    return 0;
  }
  buffer[bytesRead] = '\0'; // Null-terminate the received data
  int cmd = atoi(buffer);

  return cmd;
}
