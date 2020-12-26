import base64
from socket import *

subject = "I love computer networks!"

endmsg = "\r\n.\r\n"
# Choose a mail server (e.g. Google mail server) 
# and call it mailserver 
mailserver = "smtp.163.com"  # Fill in start # Fill in end
# Sender and reciever
# Fill in start
src_address = "hucong0430@163.com"
dst_address = "hucong@outlook.com"
# Fill in end

# Auth information (Encode with base64)
# Fill in start
auth_code = "NXJUJXBEUATRNYTV"  # 网易邮箱的授权码
username = base64.b64encode(src_address.encode()).decode()
password = base64.b64encode(auth_code.encode()).decode()
# Fill in end

# Create socket called clientSocket 
# and establish a TCP connection with mailserver
# Fill in start
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailserver, 25))
# Fill in end
recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '220':
    print('220 reply not received from server.')

# Send HELO command and print server response.
heloCommand = 'HELO Alice\r\n'
clientSocket.send(heloCommand.encode())
recv1 = clientSocket.recv(1024).decode()
print(recv1)
if recv1[:3] != '250':
    print('250 reply not received from server.')

# Auth
clientSocket.sendall('AUTH LOGIN\r\n'.encode())
recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '334':
    print('334 reply not received from server')

clientSocket.sendall((username + '\r\n').encode())
recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '334':
    print('334 reply not received from server')

clientSocket.sendall((password + '\r\n').encode())
recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '235':
    print('235 reply not received from server')
# Send MAIL FROM command and print server response.
# Fill in start
clientSocket.sendall(('MAIL FROM: <' + src_address + '>\r\n').encode())
recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '250':
    print('250 reply not received from server')
# Fill in end

# Send RCPT TO command and print server response.
# Fill in start
clientSocket.sendall(('RCPT TO: <' + dst_address + '>\r\n').encode())
recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '250':
    print('250 reply not received from server')
# Fill in end

# Send DATA command and print server response.
# Fill in start
clientSocket.send('DATA\r\n'.encode())
recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '354':
    print('354 reply not received from server')
# Fill in end

# Send message data.
# Fill in start

# Send message with image
text = 'HIT 1920-2020'
img = open('img.jpg', 'rb').read()
img = base64.b64encode(img)

message = 'from:%s\nto:%s\nsubject:%s\
\nContent-Type:multipart/mixed;boundary="simple"\n\n--simple\n' % (src_address, dst_address, subject) + 'Content-Type:text/plain\n\nHIT 1920-2020\n\n'
message = message.encode() + '--simple\n'.encode()

message += 'Content-Type:image/JPEG\nContent-transfer-encoding:base64\n\n'.encode()
message += img
message += '\n--simple\r\n'.encode()

clientSocket.sendall(message)
# Fill in end

# Message ends with a single period.
# Fill in start
clientSocket.sendall(endmsg.encode())
recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '250':
    print('250 reply not received from server')
# Fill in end

# Send QUIT command and get server response.
# Fill in start
clientSocket.sendall('QUIT\r\n'.encode())
# Fill in end

# Close connection
# Fill in start
clientSocket.close()
# Fill in end
