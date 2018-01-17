#include "geocoder.h"

#include <cstdlib>
#include <string>
#include <iostream>

#include <cpr/cpr.h>

Geocoder::Geocoder() {
	if(const char* env_key = std::getenv("OPENCAGE_API_KEY")) {
		api_key = (std::string) env_key;
	} else {
		std::cerr << "Could not load API key." << std::endl;
	}
}

Geocoder::Geocoder(std::string key) {
	api_key = key;
}

std::string Geocoder::geocode(std::string query) {
	auto r = cpr::Get(cpr::Url{"https://api.opencagedata.com/geocode/v1/json"},
			  cpr::Parameters{{"q", query},
			  		  {"key", api_key},
					  {"no_annotations", std::to_string(no_annotations)}});
	return r.text;
}

