#include <iostream>
#include <boost/program_options.hpp>  // sudo apt install libboost-all-dev

namespace po = boost::program_options;

int main(int argc, char** argv)
{
    try {
        po::options_description desc("Allowed options");
        desc.add_options()("help", "produce help message")(
            "input,i", po::value<std::string>(), "input file")(
            "output,o", po::value<std::string>(), "output file");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << "\n";
            return 1;
        }

        if (vm.count("input")) {
            std::cout << "Input file: " << vm["input"].as<std::string>()
                      << "\n";
        } else {
            std::cout << "Input file was not set.\n";
        }

        if (vm.count("output")) {
            std::cout << "Output file: " << vm["output"].as<std::string>()
                      << "\n";
        } else {
            std::cout << "Output file was not set.\n";
        }
    } catch (std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    } catch (...) {
        std::cerr << "Exception of unknown type!\n";
    }

    return 0;
}
