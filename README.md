# cpp-opencage-geocoder
A modern C++ library to access the [OpenCage geocoder](https://opencagedata.com/).

Geocoding and reverse geocoding all over the world, with options for bounding boxes, language, etc. Uses the [OpenCage geocoding API](https://geocoder.opencagedata.com/api). 

Example usage shown in `geocoder/example.cpp`.

## Installation
Build is via CMake, and requires a C++11-compatible compiler. The main dependency is the [C++ Requests](https://github.com/whoshuu/cpr) library, which is currently added via a git submodule. C++ Requests depends upon libcurl – by default our build requires you to have libcurl present on your own system.

Default build process (libcurl already installed on your system, build without C++ Requests tests):
```
git clone https://github.com/karnival/cpp-opencage-geocoder.git &&
cd cpp-opencage-geocoder &&
git submodule add https://github.com/whoshuu/cpr.git

cd /path/to/build/
cmake /path/to/cpp-opencage-geocoder/
make
```

## Usage
`example.cpp` shows a basic usage example. One important note: your API key can be set explicitly when you create a `Geocoder()` object, or can be read from the environment variable `$OPENCAGE_API_KEY`. If you want to use the environment variable approach, make sure to use `export OPENCAGE_API_KEY='your-key-here'` before execution.

## TODO
### Functionality
* ~~Implement geocoding.~~
* ~~Implement reverse geocoding.~~
* ~~Implement alternative output formats (XML).~~
* ~~Add more geocoding options.~~
* ~~Check and handle return code and headers.~~

### Build
* Make build backwards-compatible with older CMake versions.
* Integrate C++ Requests submodule into project as a subtree.
* Document building with libcurl, tests, etc.

## License
cpp-opencage-geocoder is open-source software distributed under the MIT license – see LICENSE.txt for details.
