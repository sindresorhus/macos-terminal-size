#include <stdio.h>
#include <string.h>    // strerror
#include <errno.h>     // errno
#include <fcntl.h>     // open(), O_EVTONLY, O_NONBLOCK
#include <unistd.h>    // close()
#include <sys/ioctl.h> // ioctl()

int main() {
	int tty_fd = open("/dev/tty", O_EVTONLY | O_NONBLOCK);
	if (tty_fd == -1) {
		fprintf(stderr, "Opening `/dev/tty` failed (%d): %s\n", errno, strerror(errno));
		return 1;
	}

	struct winsize ws;
	int result = ioctl(tty_fd, TIOCGWINSZ, &ws);
	close(tty_fd);

	if (result == -1) {
		fprintf(stderr, "Getting the size failed (%d): %s\n", errno, strerror(errno));
		return 1;
	}

	fprintf(stdout, "%d\n%d\n", ws.ws_col, ws.ws_row);
	return 0;
}
