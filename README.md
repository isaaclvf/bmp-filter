# BMP Image Filter

An image editing program for bitmap files.

## Installation
0. Install requirements: `git`, `clang`, `make`

1. Clone this repo:
```
git clone https://github.com/isaaclvf/bmp-filter
```
2. Compile:
```
make filter
```

## Usage
```
./filter [flag] infile.bmp outfile.bmp
    
Available options: 
    -b Blur
    -g Grayscale
    -r Reflection
    -s Sepia
```
