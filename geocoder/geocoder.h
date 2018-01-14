#ifndef GEOCODER_H
#define GEOCODER_H

#include <string>

class Geocoder {
	public:
		Geocoder();
		Geocoder(std::string api_key);
		std::string geocode(std::string query);
		bool is_premium = false;
		bool no_annotations = true;

	private:
		std::string api_key;
};

#endif
