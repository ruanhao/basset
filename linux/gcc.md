gcc
===


```
gcc --print-search-dirs  ## print lib search path

ldconfig -p | grep <libname>

pkg-config --cflags --libs <lib-name-under-/usr/lib/pkgconfig>
```
