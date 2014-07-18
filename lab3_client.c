#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>
#include <stdlib.h>


#define SOCK_NAME 	"mysocket"

int main(int argc, char ** argv)
{
	int sock;
	struct sockaddr_un saddr;

	if (argc < 2) {
		fprintf(stderr, "Too few arguments\n");
		return 1;
	}

//create socket
	sock = socket(PF_UNIX, SOCK_STREAM, 0);
        if (sock == -1) {
                fprintf(stderr, "soccket() error\n");
                return 1;
        }

        addr.sun_family = AF_UNIX;
        strcpy (addr.sun_path, SOCK_NAME);

//connect to local server
        if (connect (sock, (struct sockaddr *) &addr, SUN_LEN (&addr)) == -1) {
        	fprintf(stderr, "connect() error\n");
        	return 1;
        }

//sending message to the server
	if (write (sock, argv[1], strlen (argv[1])) == -1) {
		fprintf(stderr, "write error\n");
	       return 1;
	}

	close (sock);
	return 0;
}