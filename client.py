import socket
#sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #tcp connect
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) #udp connect
addr = ('ubuntu', 8000) #udp connect
#sock.connect(('ubuntu', 7000)) #tcp connect
while(True):
    print("text to serv")
    data = input()
    #sock.send(data.encode())#tcp connect
    sock.sendto(data.encode(), addr) #udp connect
    print("Server:", sock.recv(1024).decode())
  
sock.close()