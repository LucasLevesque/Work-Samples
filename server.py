#!/usr/bin/env python
import socket

TCP_IP="10.2.43.30"
TCP_PORT=5678
BUFFER_SIZE=1024
f = open("test.txt",'r')
test = f.read()
f.close()


s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

while 1:				#Server infinite loop
	(conn, addr)=s.accept()		#Accept a client connection
	print "Connection Address: "+ str(addr)
	data=conn.recv(BUFFER_SIZE)	#Receive client message
	while data:			#Is there any more data from client?
		print "Received data: " + data
		conn.send(test)		#Echo message back to client
		data=conn.recv(BUFFER_SIZE) #Check if client sent any more data
	conn.close 			#If not, close client connection
