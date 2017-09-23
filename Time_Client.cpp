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
  SOCKET s;
  int n, len;
  time_t now;
  struct sockaddr_in servaddr;

  /* Must initialize the socket DLL first */
  if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
    printf("WSAStartup failed\n");

  if (argc != 2)
    printf("usage: daytimeudpcli <IPaddress>");

  /* Create a socket, and check the return value */
  if ( (s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET )
  printf("socket error: error number %d\n", WSAGetLastError());

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(S_PORT);
  if ( (servaddr.sin_addr.s_addr = inet_addr(argv[1])) == INADDR_NONE)
    printf("inet_addr error: error number %d\n", WSAGetLastError());

  sendto(s, NULL, 0, 0, (SA *)&servaddr, sizeof(servaddr));

  len = sizeof(SA);
  n = recvfrom(s, (char *)&now, sizeof(now), 0, (SA *)&servaddr, &len);
  if (n == SOCKET_ERROR)
    printf("recvfrom failed: error number %d\n", WSAGetLastError());

  now = ntohl((u_long)now);
  now -= WINEPOCH;
  printf("%s", ctime(&now));
	
  WSACleanup();

  return 0;
}
