#include <stdio.h>
#include <string.h> // strerror
#include <errno.h>  // errno
#include <fcntl.h>  // open(), O_RDONLY
#include <unistd.h> // close()
#include <curses.h> // setupterm(), tigetnum()
#include <term.h>   // ^ Same as above

int main() {
	int tty_fd = open("/dev/tty", O_RDONLY);
	if (tty_fd == -1) {
		fprintf(stderr, "Opening `/dev/tty` failed (%d): %s\n", errno, strerror(errno));
		return 1;
	}

	// Intentionally not handling errors as none of
	// the documented errors can happen on macOS
	setupterm("xterm", tty_fd, NULL);

	int cols = tigetnum("cols");
	if (cols < 0) {
		fprintf(stderr, "tigetnum(\"cols\") returned error code %d\n", cols);
		close(tty_fd);
		return 1;
	}

	int rows = tigetnum("lines");
	if (rows < 0) {
		fprintf(stderr, "tigetnum(\"lines\") returned error code %d\n", rows);
		close(tty_fd);
		return 1;
	}

	fprintf(stdout, "%d\n%d\n", cols, rows);
	return 0;
}

