import socket
socket.setdefaulttimeout(2)
s = socket.socket() #create a socket
# connect the socket to the remote endpoint
#connect() needs an endpoint (IP,port) tuple!
s.connect(("10.2.43.30",5678))
s.send("Message from client")
ans = s.recv(1024) #read max 1024 bytes of data from socket
print ans
f = open("out.txt","w+")
f.write(ans)
f.close()