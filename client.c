#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#define MAX_LINE 100

int main(int argc, char *argv[])
{

	struct sockaddr_in sin;
	char buf[MAX_LINE];
	int s_fd;
	int port=8000;
	char *str = "test string";
	
	if (argc > 1) {
		str = argv[1];	
	}
	
	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &sin.sin_addr);
	sin.sin_port = htons(port);
	s_fd = socket(AF_INET, SOCK_STREAM, 0);
	connect(s_fd, (struct sockaddr_in *)&sin, sizeof(sin));
	write(s_fd, str, strlen(str)+1);
	read(s_fd, buf, MAX_LINE);
	printf("recive from server:%s\n", buf);	
	close(s_fd);
	return 0;
}
