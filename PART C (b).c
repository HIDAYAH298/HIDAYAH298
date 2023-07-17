
import socket

def main():
 
  client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  host = "localhost"
  port = 8080
  print("Enter a number: ")
  number = input()
  client_socket.sendto(number.encode(), (host, port))
  data, address = client_socket.recvfrom(1024)
  result = data.decode()
  print("The result is: " + result)

if __name__ == "__main__":
  main()

}
