all:server client
server:server.c iolib.c
	gcc server.c iolib.c -o server
client:client.c iolib.c
	gcc client.c iolib.c -o client
clean:
	rm *.o server client
