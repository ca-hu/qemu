/*
 * QEMU Guest Agent Exec Helper
 *
 * Copyright (C) 2022 Red Hat Inc.
 *
 * This work is licensed under the terms of the GNU General Public
 * License, version 2 or later.  See the COPYING file in the top-level
 * directory.
 *
 * This helper is used to transition from the confined qemu-ga context
 * into an unconfined one.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "qemu/osdep.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s <command> [args...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    execvp(argv[1], &argv[1]);

    fprintf(stderr, "failed to execute '%s': %s\n", argv[1], strerror(errno));

    return EXIT_FAILURE;
}

