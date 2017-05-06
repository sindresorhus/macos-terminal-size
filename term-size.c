#include <stdio.h>
#include <string.h>    // strerror
#include <errno.h>     // errno
#include <fcntl.h>     // open(), O_RDONLY
#include <unistd.h>    // close()
#include <sys/ioctl.h> // ioctl()

int main() {
	int tty_fd = open("/dev/tty", O_RDONLY);
	if (tty_fd == -1) {
		fprintf(stderr, "Opening `/dev/tty` failed (%d): %s\n", errno, strerror(errno));
		return 1;
	}

	struct winsize ws;
	int result = ioctl(tty_fd, TIOCGWINSZ, &ws);
	close(tty_fd);

	if (result == -1) {
		fprintf(stderr, "Getting size failed (%d): %s\n", errno, strerror(errno));
		return 1;
	}

	fprintf(stdout, "%d\n%d\n", ws.ws_col, ws.ws_row);
	return 0;
}

