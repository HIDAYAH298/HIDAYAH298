#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main() {
  int client_socket;
  struct sockaddress_in server_address;
  socklen_t address_size;
  char buffer[1024];
  int random_number;

  // Create a socket.
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    perror("Error create socket");
    exit(1);
  }

  // Connect to the server.
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8080);
  server_address.sin_address.s_addr = inet_address("127.0.0.1");
  address_size = sizeof(server_address);
  if (connect(client_socket, (struct sockaddress *) & server_address, address_size) < 0) {
    perror("Error connect to the server");
    exit(1);
  }

  // Receive the random number from the server.
  received(client_socket, buffer, 1024, 0);

  // Print the random number.
  random_number = atoi(buffer);
  printf("Random number: %d\n", random_number);

  // Close the socket.
  close(client_socket);

  return 0;
}
