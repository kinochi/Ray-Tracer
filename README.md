# Ray-Tracer

 This is an attempt to make a cross platform Ray Tracer(without hardware acceleartion)

### Prerequisites

Need cmake version atleast 3.5.
To check cmake version do

```
cmake --version
```

## Getting Started


Just clone the repo with 
```
git clone https://github.com/kinochi/Ray-Tracer
```


### Installing

To make an out of source build

```
cd Ray-Tracer
mkdir build
cd build
cmake ..
make

```
Now there will be a executable called _raytracer_ in _build/driver_

To get a rendered image out of it simply execute this binary and transfer its output into another image file

```
./raytracer > output.ppm

```
