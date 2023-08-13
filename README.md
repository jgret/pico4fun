# pico4fun

This repository contains small projects all around the *raspberry pi pico* and *pico w*. The main focus is learning and using the pico c sdk to do some stuff.

## Project Structure

The projects are structured in subdirectories to keep it tidy. 

| Folder | Description                                                     |
| ------ | --------------------------------------------------------------- |
| pio    | playing around with the programmable io peripherals of the pico |
| sensor | reading all kinds of sensors                                    |

## Build

The project can be build by using cmake. Make sure the pico c sdk is installed properly.
The uf2 files needed for flashing the pico can be found in the related subdirectory.

```console
mkdir build & cd build
cmake ..
make
```

