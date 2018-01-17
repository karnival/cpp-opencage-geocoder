#ifndef GEOCODER_H
#define GEOCODER_H

#include <string>

class Geocoder {
	public:
		Geocoder();
		Geocoder(std::string api_key);

		std::string geocode(std::string query);
		std::string get_format_string();
		
		enum class OutputFormat {JSON, GEOJSON, XML, MAP, GOOGLE_JSON}; 
		OutputFormat output_format = OutputFormat::JSON;

		// Boolean query parameters always used, defaults as when unspecified.
		bool no_annotations = true;
		bool abbrv = false;
		bool no_dedupe = false;
		bool no_record = false;
		bool pretty = false;

		// Setters for non-default parameters.
		void set_min_confidence(int confidence);
		void set_bounds(float bounds[4]);
		void set_countrycode(std::string code);
		void set_language(std::string langugage);

	private:
		std::string api_key;

		// Query parameters not used by default.
		bool use_min_confidence = false;
		bool use_bounds = false;
		bool use_countrycode = false;
		bool use_language = false;

		std::string language = "";
		int limit = 0;
		int min_confidence = 0;
		float bounds[4] = {0.0, 0.0, 0.0, 0.0};
		std::string countrycode = "";

};

#endif
