import socket
import math

def is_prime(number):
 
  if number <= 1:
    return False
  for i in range(2, int(math.sqrt(number)) + 1):
    if number % i == 0:
      return False
  return True

def main():
 
  server_socket = socket.socket(socket.AF_INET)
  server_socket.bind(("localhost", 8080))
  print("Server is listening...")
  while True:
    data, address = server_socket.receivedfrom(1024)
    number = int(data.decode())
    result = "Prime" if is_prime(number) else "Not prime"
    server_socket.sendto(result.encode(), address)

if __name__ == "__main__":
  main()

}
