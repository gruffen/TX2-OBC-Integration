#ifndef __UARTC_H
#define __UARTC_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/signal.h>
#include <cstdlib>

int openSerial();
int read_uart(int fd, char *buf, size_t nbBytes);
int write_uart(int fd, char *buf, size_t nbytes);
void clean_exit(int code);

#endif
