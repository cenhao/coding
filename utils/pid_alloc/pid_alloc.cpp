#include <pthread.h>
#include <string.h>

#include "pid_alloc.h"

#define MIN_PID 300
#define MAX_PID 5000

static bool pidmap[MAX_PID - MIN_PID];
static bool is_init = false;
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int allocate_map(void) {
	if (!is_init) {
		if (pthread_mutex_lock(&lock) != 0) {
			return 1;
		}

		if (!is_init) {
			memset(pidmap, false, sizeof(pidmap));
			is_init = true;
		}

		if (pthread_mutex_unlock(&lock) != 0) {
			return 1;
		}
	}

	return 0;
}

int allocate_pid(void) {
	if (!is_init) { return 0; }
	if (pthread_mutex_lock(&lock) != 0) {
		return 0;
	}

	int pid = 1;
	for (int i=0, end=MAX_PID-MIN_PID; i<end; ++i) {
		if (!pidmap[i]) {
			pidmap[i] = true;
			pid = i+MIN_PID;
			break;
		}
	}

	pthread_mutex_unlock(&lock);
	return pid;
}

void release_pid(int pid) {
	if (pthread_mutex_lock(&lock) != 0) { return ; }
	pidmap[pid-MIN_PID] = false;
	pthread_mutex_unlock(&lock);
}
