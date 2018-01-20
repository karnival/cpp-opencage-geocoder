#ifndef GEOCODER_H
#define GEOCODER_H

#include <string>

class Geocoder {
	public:
		Geocoder();
		Geocoder(std::string api_key);

		std::string geocode(std::string query);
		std::string geocode_bounds(std::string query, std::string bounds);
		
		enum class OutputFormat {JSON, GEOJSON, XML, MAP, GOOGLE_JSON}; 
		OutputFormat output_format = OutputFormat::JSON;
		std::string get_format_string();

		// Boolean query parameters always used, defaults as when unspecified.
		bool no_annotations = true;
		bool abbrv = false;
		bool no_dedupe = false;
		bool no_record = false;
		bool pretty = false;

		// Query parameters not used by default.
		unsigned int limit = 0;
		unsigned int min_confidence = 0;
		std::string language = "";
		std::string bounds = "";
		std::string countrycode = "";

	private:
		std::string api_key;


};

#endif
