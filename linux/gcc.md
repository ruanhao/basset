gcc
===


```
gcc --print-search-dirs  ## print lib search path

ldconfig -p | grep <libname>

pkg-config --cflags --libs <lib-name-under-/usr/lib/pkgconfig>



## library creation example ## 
$ gcc -Wall -fPIC -c *.c
#soname: libctest.so.1
#real name: libctest.so.1.0
$ gcc -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0 *.o
$ mv libctest.so.1.0 /opt/lib
#soname is a symbolic link to the real name
$ ln -sf /opt/lib/libctest.so.1.0 /opt/lib/libctest.so.1
#linker name is a symbolic link to the soname
$ ln -sf /opt/lib/libctest.so.1 /opt/lib/libctest.so
## Programs, when they internally list the shared libraries they need,
## should only list the soname they need. Conversely, when you create a shared library,
## you only create the library with a specific filename (with more detailed version information).
## When you install a new version of a library, you install it in one of a few special directories and then run the program ldconfig(8).
## Ldconfig examines the existing files and creates the sonames as symbolic links to the real names,
## as well as setting up the cache file /etc/ld.so.cache. ldconfig doesn’t set up the linker names;
## typically this is done during library installation, and the linker name is simply created as a symbolic to the latest soname or the latest real name.

```
