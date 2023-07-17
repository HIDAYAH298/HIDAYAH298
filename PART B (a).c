#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main() {
  int server_socket, client_socket;
  struct sockaddress_in server_address, client_address;
  socklen_t address_size;
  char buffer[1024];
  int random_number;

  // Create a socket.
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port.
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8080);
  server_address.sin_address.s_address = INADDR_ANY;
  address_size = sizeof(server_addr);
  if (bind(server_socket, (struct sockaddress *) &server_address, address_size) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for connections.
  listen(server_socket, 1);

  // Accept a connection.
  client_socket = accept(server_socket, (struct sockaddress*) &client_address, &address_size);
  if (client_socket < 0) {
    perror("Error accepting connection");
    exit(1);
  }

  // Generate a random number between 50,000 and 80,000.
  random_number = rand() % (80000 - 50000 + 1) + 50000;

  // Send the random number to the client.
  sprintf(buffer, "%d", random_number);
  send(client_socket, buffer, strlen(buffer) + 1, 0);

  // Close the socket.
  close(server_socket);
  close(client_socket);

  return 0;
}
