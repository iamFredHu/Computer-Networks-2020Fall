from socket import *

client_socket = socket(AF_INET, SOCK_STREAM)

address = ("127.0.0.1", 2233)
client_socket.connect(address)

filename = input("Please input the filename of the file you want to download：")
client_socket.send(filename.encode("utf-8"))

data = client_socket.recv(100000000)
if data:
    with open('received_file.txt', "wb") as file:
        file.write(data)
    print("Succeed!")
else:
    print("Error!")

client_socket.close()
