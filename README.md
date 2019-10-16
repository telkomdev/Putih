## Putih

Redis Command Line Client Writen in `C++`

### Requirements
- gcc https://gcc.gnu.org/install/binaries.html
- cmake https://cmake.org/download/

# Building

Change directory to root project
```shell
$ cd putih
```

Create `build` folder
```shell
$ mkdir build
```

Run `cmake`
```shell
$ cmake ..
```

Run `make`
```shell
$ make
```

### Usage
After building process above, we can use produced binary in `build` folder to connect with `redis server`
```shell
$ ./putih localhost 6379
```