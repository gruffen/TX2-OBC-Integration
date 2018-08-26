#include "uart_c.hpp"

static struct termios uartdev;
int uart0_filestream = -1;

int openSerial() {
  int err;
  uart0_filestream = open("/dev/ttyAMA0", O_RDWR | O_NDELAY | O_NONBLOCK); // /dev/ttyAMA0 on rpi, ttyTHS1 on jetson
  if (uart0_filestream == -1) {
    std::cout << "Error: unable to open UART.\n";
    clean_exit(-1);
  } else {
    fcntl(uart0_filestream, F_SETFL, 0);
  }

  err = tcgetattr(uart0_filestream, &uartdev);
  if (err != 0) {
    std::cout << "tcgetattr failed\n";
    return 0;
  }

	uartdev.c_cflag = B9600 | CS8 | CLOCAL | CREAD;		//<Set baud rate
	uartdev.c_iflag = IGNPAR;
	uartdev.c_oflag = 0;
	uartdev.c_lflag = 0;
  cfmakeraw(&uartdev);

	tcflush(uart0_filestream, TCIFLUSH);
	tcsetattr(uart0_filestream, TCSANOW, &uartdev);

  std::cout << uart0_filestream << std::endl;

  return uart0_filestream;
}

int read_uart(int fd, char *buf, size_t nbBytes) {
  int count = 0;
  if (fd != -1) {
    count = read(fd, &buf[0], nbBytes);
    if (count < 0) {
      std::cout << "Error: RX over UART\n";
      return -1;
    } else if (count == 0) {
      // No data to be read
    } else {
      // print bytes read
    }
  }
  return count;
}

int write_uart(int fd, char *buf, size_t nbytes) {
  //unsigned char *p_tx_buffer;
  // Flush serial buffer before writing anything
  tcflush(uart0_filestream, TCIFLUSH);
  tcflush(STDIN_FILENO, TCIFLUSH);

  int count = 0;
  std::cout << "Sending to device..";
  if (fd != -1) {
    count = write(fd, &buf[0], nbytes);
    if (count < 0 ) {
      std::cout << "Error: TX over UART\n";
      return -1;
    }
  }
  std::cout << "Successfully written\n";
  return count;
}

void clean_exit(int code) {
  close(uart0_filestream);
  // tty reset settings
  //tcsetattr(STDIN_FILENO, TCSANOW, &uartdev);
  // exit
  std::exit(code);
}
