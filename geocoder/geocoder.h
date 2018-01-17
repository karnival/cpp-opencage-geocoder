#ifndef GEOCODER_H
#define GEOCODER_H

#include <string>

class Geocoder {
	public:
		Geocoder();
		Geocoder(std::string api_key);

		std::string geocode(std::string query);
		std::string get_format_string();

		bool is_premium = false;
		bool no_annotations = true;

		enum class OutputFormat {JSON, GEOJSON, XML, MAP, GOOGLE_JSON}; 
		OutputFormat output_format = OutputFormat::JSON;

	private:
		std::string api_key;
};

#endif
