#include "uart_c.hpp"

int main(int argc, char** argv) {
  int serial_descriptor = 0;
  serial_descriptor = openSerial();

  int bytesWritten = write_uart(serial_descriptor, "hello", 5);
  std::cout << bytesWritten;

  return EXIT_SUCCESS;
}
