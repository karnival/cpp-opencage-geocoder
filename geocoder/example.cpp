#include <iostream>
#include <memory>

#include "geocoder.h"

int main(void) {
	std::unique_ptr<Geocoder> g(new Geocoder());

	std::cout << g->geocode("52.516,13.378") << std::endl;

	g->output_format = Geocoder::OutputFormat::XML;
	std::cout << g->geocode("52.516,13.378") << std::endl;

	g->language = "es";

	g->output_format = Geocoder::OutputFormat::JSON;
	std::cout << g->geocode("52.516,13.378") << std::endl;

	g->language = "en";
	g->countrycode = "uk";
	g->bounds = "-1.0,51.0,1.0,52.0";
	std::cout << g->geocode("Buckingham Palace") << std::endl;

	return 0;
}
