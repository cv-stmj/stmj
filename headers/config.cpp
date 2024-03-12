/**
 * This is the declaration file to config.h
 * we will be using Mozilla CPP Coding Style which is a simplified version
 * of Google CPP Coding Guide
 * Banjarbaru, 2024-March-12
 */

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "config.h"

namespace stmj {
// Default constructor
Config::Config() {

}

// Constructor with config filepath
Config::Config(std::string aFilePath) {
	fName = aFilePath;
	std::ifstream config_file;
	config_file.open(fName);
	if (config_file.is_open())
	{
		std::cout << "File opened: " << fName << std::endl;
		std::string line_buff;
		while (std::getline(config_file, line_buff))
		{
			std::istringstream is_line(line_buff);
			std::string key;
			if (std::getline(is_line, key, '='))
			{
				std::string value;

				if (std::getline(is_line, value)) {
					// std::cout << "key -> " << key;
					// std::cout << " with value -> " << value << std::endl;
					if (key == "case_name")
						tsc.case_name = value;
					if (key == "x_origin")
						tsc.x0 = std::stod(value);
					if (key == "y_origin")
						tsc.y0 = std::stod(value);
					if (key == "t_init")
						tsc.t0 = std::stod(value);
					if (key == "t_final")
						tsc.tf = std::stod(value);

					if (key == "t_delta")
						tsc.t_delta = std::stod(value);
				} // if value
			}	  // if key
		}		  // while getline
	}			  // if config_file is_open()

	config_file.close();
	std::cout << "File closed!" << std::endl;
}

// Obvious
void Config::getConfigFile(std::string aConfigFile) {
	fName = aConfigFile;
	readConfigFile(fName);
}

// Obvious
void Config::readConfigFile(std::string fName) {
	
}


};