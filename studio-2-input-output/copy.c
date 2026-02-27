
#include <unistd.h>
#define bufferSize 200

int main() {
	char buffer[bufferSize];
	ssize_t bytesRead;
	while (1) {
		bytesRead = read(STDIN_FILENO, buffer, bufferSize);
		if (bytesRead == 0) {
			break;
		}
		if (bytesRead < 0) {
			return 1; // error
		}
		ssize_t bytesWritten = 0;
		while (bytesWritten < bytesRead) {
			ssize_t result = write(STDOUT_FILENO, buffer + bytesWritten, bytesRead - bytesWritten);
			if (result < 0) {
				return 1; // error
			}
			bytesWritten += result;
		}
	}
	return 0;
}
