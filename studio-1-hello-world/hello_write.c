#include <unistd.h>
#include <string.h>

int main( int argc, char* argv[] ){
  const char message[] = "Hello, world!\n";
  write(STDOUT_FILENO, message, strlen(message));
  return 0;
}
