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

std::string Geocoder::get_format_string() {
	switch(output_format) {
		case OutputFormat::JSON:
			return "json";
			break;
		case OutputFormat::GEOJSON:
			return "geojson";
			break;
		case OutputFormat::XML:
			return "xml";
			break;
		case OutputFormat::MAP:
			return "map";
			break;
		case OutputFormat::GOOGLE_JSON:
			return "google-v3-json";
			break;
	}
}

std::string Geocoder::geocode(std::string query) {
	std::string base_url = "https://api.opencagedata.com/geocode/v1/";
	base_url += get_format_string(); // append data format, e.g. json

	auto r = cpr::Get(cpr::Url{base_url},
			  cpr::Parameters{{"q", query},
			  		  {"key", api_key},
					  {"no_annotations", std::to_string(no_annotations)}});
	return r.text;
}

