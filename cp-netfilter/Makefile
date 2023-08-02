# This line adds the object file 'hello_module.o' to the list of kernel modules to be built.
# The 'obj-m' variable is used to specify which files should be built as loadable kernel modules.
obj-m += hello_module.o


# The 'all' target is the default target, which will be built when 'make' is executed without arguments.
# It calls 'make' with specific arguments to build the kernel modules specified in 'obj-m'.
# The '-C' option specifies the kernel source directory, and 'M=$(PWD)' sets the output directory for the built modules.
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# The 'clean' target is used to remove generated files when 'make clean' is executed.
# It calls 'make' with the 'clean' target in the kernel source directory to clean up built files.
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
