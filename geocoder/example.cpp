#include <iostream>
#include <memory>

#include "geocoder.h"

int main(void) {
	std::unique_ptr<Geocoder> g(new Geocoder());

	std::cout << g->geocode("52.516,13.378") << std::endl;

	g->output_format = Geocoder::OutputFormat::XML;
	std::cout << g->geocode("52.516,13.378") << std::endl;

	g->set_language("es");

	g->output_format = Geocoder::OutputFormat::JSON;
	std::cout << g->geocode("52.516,13.378") << std::endl;

	return 0;
}
