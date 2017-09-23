#include <stdio.h>   
#include <stdlib.h>
#include <time.h>    
#include <string.h>
#include <stdarg.h> 
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib")

#define SA struct sockaddr
#define MAXLINE 4096
#define S_PORT 37
#define WINEPOCH 2208988800 

int main(int argc, char **argv)
{
  WSADATA wsadata;
  struct sockaddr_in servaddr, cliaddr;
  char buff[MAXLINE];
  time_t ticks;	/* current time */
  int n, len;
  SOCKET s;

  if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
	printf("WSAStartup failed\n");

  /* Fill up the servaddr */
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family      = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port        = htons(S_PORT);
  s = socket(AF_INET, SOCK_DGRAM, 0);

  if (s == INVALID_SOCKET)
      printf("cannot create socket: error number %d\n", WSAGetLastError());

  /* Bind the servaddr to socket s */
  if (bind(s, (SA *) &servaddr, sizeof(servaddr)) == SOCKET_ERROR)
     printf("can't bind to port %d: error number %d\n", S_PORT, WSAGetLastError());

  for ( ; ; )  {
     len = sizeof(SA);
     if (n = recvfrom(s, buff, sizeof(buff), 0, (SA *)&cliaddr, &len) == SOCKET_ERROR)
       printf("recvfrom error: error number %d\n", WSAGetLastError());

    time(&ticks);   /* returns the number of seconds elapsed since midnight of January 1, 1970 */
    ticks = htonl((u_long)(ticks + WINEPOCH));
    sendto(s, (char *)&ticks, sizeof(ticks), 0, (SA *)&cliaddr, sizeof(cliaddr));
  } /* end of for loop */
}
