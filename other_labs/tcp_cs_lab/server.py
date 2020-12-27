from socket import *
import sys

server_socket = socket(AF_INET, SOCK_STREAM)
address = ("", 2233)
server_socket.bind(address)
server_socket.listen(128)

while True:

    client_socket, address = server_socket.accept()

    recv_data = client_socket.recv(1000000)  # 单次文件大小
    file_name = recv_data.decode("utf-8")
    print("File Name %s" % file_name)

    with open(file_name, 'rb') as file:
        file_content = file.read()
    if file_content:
        client_socket.send(file_content)

    client_socket.close()

server_socket.close()
