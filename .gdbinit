# https://youtrack.jetbrains.com/issue/CPP-7090

set confirm off
set pagination off
set height unlimited
#set verbose on
#set logging on
set trace-commands on
set print inferior-events on

show debug-file-directory
set disassembly-flavor intel
set debug-file-directory /usr/lib/debug
directory ~/git/c/42london/push_swap/src
directory ~/staging/glibc-2.31
directory ~/staging/glibc-2.31/elf
directory ~/staging/glibc-2.31/nptl
directory ~/staging/glibc-2.31/dlfcn
directory ~/staging/glibc-2.31/misc
directory ~/staging/glibc-2.31/csu
directory ~/staging/glibc-2.31/ctype
directory ~/staging/glibc-2.31/stdlib
directory ~/staging/glibc-2.31/sysdeps/x86_64/multiarch
show directories

define target remote
set remote exec-file ./bin/push_swap
show remote exec-file
set debug target 0
file ./bin/push_swap
if $argc == 1
    target extended-remote $arg0
end
if $argc == 2
    target extended-remote $arg0 $arg1
end
if $argc == 3
    target extended-remote $arg0 $arg1 $arg2
end
if $argc == 4
    target extended-remote $arg0 $arg1 $arg2 $arg3
end
if $argc == 5
    target extended-remote $arg0 $arg1 $arg2 $arg3 $arg4
end
if $argc == 6
    target extended-remote $arg0 $arg1 $arg2 $arg3 $arg4 $arg5
end
if $argc == 7
    target extended-remote $arg0 $arg1 $arg2 $arg3 $arg4 $arg5 $arg6
end
if $argc == 8
    target extended-remote $arg0 $arg1 $arg2 $arg3 $arg4 $arg5 $arg6 $arg7
end
set breakpoint pending on
br _start
br _dl_start
br _dl_start_final
br _start
br libc-start.c:308
br libc-start.c:339
br main

#monitor reset halt
info inferiors
info threads
info files
info target
maintenance info sections
end

set follow-fork-mode child
set follow-exec-mode new
set detach-on-fork off
catch fork

show user
#show auto-load
