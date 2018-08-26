#include "uart_c.hpp"

int main(int argc, char** argv) {
  char buffer[256];
  char buffer2[256];

  int serial_descriptor = 0;
  serial_descriptor = openSerial("/dev/ttyTHS2");

  read_uart(serial_descriptor, buffer, 6);
  read_uart(serial_descriptor, buffer2, 7);

  return EXIT_SUCCESS;
}
