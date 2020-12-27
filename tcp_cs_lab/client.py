from socket import *

client_socket = socket(AF_INET, SOCK_STREAM)

address = ("127.0.0.1", 7788)
client_socket.connect(address)

filename = input("请输入需要下载的文件名称：")
client_socket.send(filename.encode("utf-8"))

data = client_socket.recv(10000000000)
if data:
    with open('received_file.txt', "wb") as file:
        file.write(data)
    print("Succeed!")
else:
    print("Error!")

client_socket.close()
