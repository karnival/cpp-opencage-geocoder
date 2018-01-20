#include <iostream>
#include <memory>

#include "geocoder.h"

int main(void) {
	// Create a Geocoder() object on the heap.
	std::unique_ptr<Geocoder> g(new Geocoder());

	// If you'd prefer to create a Geocoder() on the stack.
	auto g_stack = Geocoder();

	// Creating a Geocoder() with no arguments gets your API key from 
	// the environment variable, $OPENCAGE_API_KEY. You can also set 
	// the API key explicitly when initialising the Geocoder().
	std::unique_ptr<Geocoder> g_key(new Geocoder("your-key-here"));

	// Geocoding. Results default to JSON returned as an std::string.
	std::cout << g->geocode("Buckingham Palace, London") << std::endl;

	// Change the output format for future queries from this Geocoder().
	// Possible formats are JSON, GEOJSON, XML, MAP, GOOGLE_JSON.
	g->output_format = Geocoder::OutputFormat::XML;
	std::cout << g->geocode("Buckingham Palace, London") << std::endl;

	// Change the output format back to JSON.
	g->output_format = Geocoder::OutputFormat::JSON;

	// Change the language for future queries from this Geocoder().
	g->language = "es";
	std::cout << g->geocode("Buckingham Palace, London") << std::endl;

	// Change the countrycode for future queries from this Geocoder().
	g->countrycode = "uk";
	std::cout << g->geocode("Buckingham Palace") << std::endl;

	// Create a bounding box for future queries from this Geocoder().
	g->bounds = "-1.0,51.0,1.0,52.0";
	std::cout << g->geocode("Buckingham Palace") << std::endl;

	// Reset to have no bounding box, no countrycode, default language (English).
	g->bounds = "";
	g->countrycode = "";
	g->language = "";

	// Geocode with a bounding box for *just this query* using geocode_bounds().
	std::cout << g->geocode_bounds("Buckingham Palace", "-1.0,51.0,1.0,52.0") << std::endl;

	// Reverse geocoding is just the same as geocoding.
	std::cout << g->geocode("41.40139+2.12870") << std::endl;

	// Exceptions thrown for e.g. using a bad API key, exceeding usage quota.
	try {
		auto bad_key_geocoder = Geocoder("THIS IS A BAD KEY");
		bad_key_geocoder.geocode("Buckingham Palace, London");
	} catch(std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
