# cpp-opencage-geocoder
A modern C++ library to access the [OpenCage geocoder](https://opencagedata.com/).

## Features
Coming soon. In a nutshell, geocoding and reverse geocoding.

## Installation
Build is via CMake, and requires a C++11-compatible compiler. The main dependency is the [C++ Requests](https://github.com/whoshuu/cpr) library, which is currently added via a git submodule. C++ Requests has a few of its own dependencies, including libcurl.

Current build process (to be improved soon): 
```
cd /path/to/src/
git submodule add git@github.com:whoshuu/cpr.git
git submodule update --init --recursive
cd /path/to/build/
cmake /path/to/src/
make
```

## Usage
`example.cpp` shows a basic usage example. One important note: your API key can be set explicitly when you create a `Geocoder()` object, or can be read from the environment variable `$OPENCAGE_API_KEY`. If you want to use the environment variable approach, make sure to use `export OPENCAGE_API_KEY='your-key-here'` before execution.

## TODO
### Functionality
* ~~Implement geocoding.~~
* ~~Implement reverse geocoding.~~
* Implement alternative output formats (XML).
* Add more geocoding options.

### Build
* Make build backwards-compatible with older CMake versions.
* Integrate C++ Requests submodule into CMake build.
* Tidy build outputs.

## License
cpp-opencage-geocoder is open-source software distributed under the MIT license -- see LICENSE.txt for details.
