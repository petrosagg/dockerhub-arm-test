#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
	int i = 0;
	char **qemu_argv = NULL;

	printf("Allocating %d arguments\n", argc + 2);
	qemu_argv = malloc (sizeof (char*)*(argc+2));

	qemu_argv[0] = "/usr/bin/qemu-arm-static";
	qemu_argv[1] = "/bin/bash";

	for (i = 1; i < argc; i++)
		qemu_argv[i+1] = argv[i];

	qemu_argv[i+1] = NULL;

    return execve("/usr/bin/qemu-arm-static", qemu_argv, envp);
}
