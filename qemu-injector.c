#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>

typedef int (*orig_execve_f_type)(const char *filename, char *const argv[], char *const envp[]);

int execve(const char *filename, char *const argv[], char *const envp[])
{
	int argc = 0;
	int i = 0;
	char **qemu_argv = NULL;

	while (argv[argc]) {
		argc++;
	}

	qemu_argv = malloc (sizeof (char*)*(argc+1));

	qemu_argv[0] = "/usr/bin/qemu-arm-static";

	for (i = 0; i < argc; i++)
		qemu_argv[i+1] = argv[i];

	qemu_argv[i+1] = NULL;

    orig_execve_f_type orig_execve;
    orig_execve = (orig_execve_f_type)dlsym(RTLD_NEXT,"execve");
    return orig_execve("/usr/bin/qemu-arm-static", qemu_argv, envp);
}
