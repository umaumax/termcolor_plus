#include <iostream>
#include "termcolor.hpp"
#include "termcolor_plus.hpp"

#include "tinyformat.h"

int main(int /*argc*/, char** /*argv*/) {
  {
    std::cout << termcolor::red << "Hello, Colorful World!" << std::endl;
    std::cout << termcolor::reset;
  }
  {
    //	is terminal?
    std::cout << termcolor::_internal::is_atty(std::cout) << std::endl;
    std::cerr << termcolor::_internal::is_atty(std::cerr) << std::endl;

    // segmentation fault
    //	std::stringstream ss;
    //	std::cout << termcolor::_internal::is_atty(ss) << std::endl;

    std::string cout_red = "\033[31m";
    std::string cout_reset = "\033[00m";
    std::string cerr_red = "\033[31m";
    std::string cerr_reset = "\033[00m";
    if (!termcolor::_internal::is_atty(std::cout)) {
      cout_red = "";
      cout_reset = "";
    }
    if (!termcolor::_internal::is_atty(std::cerr)) {
      cerr_red = "";
      cerr_red = "";
    }

    tfm::printf("%scout hello%s\n", cout_red, cout_reset);
    tfm::format(std::cerr, "%scerr hello%s\n", cerr_red, cerr_reset);
  }
  {
    std::stringstream ss;
    ss << tc::red("stringstream red");
    std::cout << ss.str() << std::endl;
    std::cerr << ss.str() << std::endl;

    std::cout << tc::dark() << tc::red("dark red") << std::endl;
    std::cout << tc::orange("orange") << std::endl;
    std::cout << tc::on_orange("orange") << std::endl;

    std::cout << tc::cout_red() << "cout hello" << std::endl;
    std::cout << tc::cout_red("cout hello") << std::endl;
    std::cout << tc::cout_blue("cout hello") << std::endl;
    std::cerr << tc::cerr_green("cerr hello") << std::endl;
    std::cerr << tc::cerr_on_green("cerr hello") << std::endl;
    std::cerr << tc::cerr_bold("cerr hello") << std::endl;

    tfm::printf("%s\n", tc::cout_red("cout hello"));
    tfm::format("%s\n", tc::cerr_red("cout hello"));
  }
  return 0;
}
