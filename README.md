# MPGJS [![Build Status](https://travis-ci.org/loftili/mpgjs.svg?branch=master)](https://travis-ci.org/loftili/mpgjs)

This project was designed to bring the functionality from mpg123 into node by creaing a node native extension. 

## Dependencies

Installing this packages requires you to have the [libmpg123](http://www.mpg123.de/api/) library installed on the machine. An example installation process can be found in the [travis file](https://github.com/loftili/mpgjs/blob/mpgjs-4/.travis.yml), but generally looks like this:


```
> wget $MPG123_HOME
> tar xjvf mpg123-1.20.1.tar.bz2
> cd mpg123-1.20.1
> ./configure && make && sudo make install
```

------------------------

## Functions

### isValid(string filepath)

Checks the `filepath` for a valid mp3 file base on the mpg123 library's ability to open a stream and get a format from that path.


