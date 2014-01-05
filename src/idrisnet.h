#ifndef IDRISNET_H
#define IDRISNET_H

#include <errno.h>
#include <netdb.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef struct idrnet_recv_result {
    int result;
    void* payload;
} idrnet_recv_result;

// Memory management functions
void* idrnet_malloc(int size);
void idrnet_free(void* ptr);

// Gets value of errno
int idrnet_errno(); 

// Bind
int idrnet_bind(int sockfd, int family, int socket_type, char* host, int port);

// Connect
int idrnet_connect(int sockfd, int family, int socket_type, char* host, int port);

// Accessor functions for struct_sockaddr
int idrnet_sockaddr_family(void* sockaddr);
char* idrnet_sockaddr_ipv4(void* sockaddr);
void* idrnet_create_sockaddr();

// Accept
int idrnet_accept(int sockfd, void* sockaddr);

// Send
int idrnet_send(int sockfd, char* data);
int idrnet_send_buf(int sockfd, void* data, int len);

// Receive
// Creates a result structure containing result and payload
void* idrnet_recv(int sockfd, int len);
// Receives directly into a buffer
int idrnet_recv_buf(int sockfd, void* buf, int len);

// Receive structure accessors
int idrnet_get_recv_res(void* res_struct);
void* idrnet_get_recv_payload(void* res_struct);

#endif
