#include <stdio.h>
#include "pid_alloc.h"

int main() {
	if (allocate_map() != 0) {
		printf("map failed\n");
		return 1;
	}

	for (int i=0; i<10; ++i) {
		int pid = allocate_pid();
		printf("%d\n", pid);
		if (pid > 10) {
			release_pid(pid);
		}
	}

	return 1;
}
