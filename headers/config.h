#ifndef HEADERS_CONFIG_H
#define HEADERS_CONFIG_H

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>

namespace stmj {

	typedef struct {
		std::string case_name;
		double x0, y0, t0, tf;
		double t_delta;
		uint32_t n_samples;
	} test_case;

	class Config {
		private:
			double x0, y0;
			double xt, yt;
			double t0, tf, dt;
			double nSample;
			test_case tsc;
			std::string linebuff;
			std::string fName;
		
		public:
		// Default constructor
		Config();

		// Constructor with config filepath
		Config(std::string aFilePath);

		// Get config file
		void getConfigFile(std::string aConfigFile);

		// Class Destructor
		~Config();

		// for all methods that should be in this class only
		protected:
		void readConfigFile(std::string fName);

	};
};


#endif // HEADERS_CONFIG_H