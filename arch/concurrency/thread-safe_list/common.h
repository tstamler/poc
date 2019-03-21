#ifndef COMMON_H
#define COMMON_H

#ifndef __USE_GNU
#define __USE_GNU
#endif
#define _GNU_SOURCE

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <sched.h>

#define GET_TS() ({                         \
    struct timespec ts;                     \
    double ret = 0;                         \
    clock_gettime(CLOCK_MONOTONIC, &ts);    \
    ret = ts.tv_sec + 1E-9*ts.tv_nsec;      \
    ret;                                    \
    })

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

#define DEFAULT_NTHREADS 1
extern int nthreads, nadds, nbatch, nskip, nrems;

void usage(char *cmd);
void process_args(int argc, char **argv);
void bind_to_core(int thr_idx);
uint32_t get_thread_id();

#endif // COMMON_H
