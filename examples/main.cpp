#include <iostream>
#include <sstream>
#include "termcolor_plus.hpp"

int main(int /*argc*/, char** /*argv*/) {
  std::stringstream ss;
  ss << tc::red("stringstream red");
  std::cout << "cout:" << ss.str() << std::endl;
  std::cerr << "cerr:" << ss.str() << std::endl;

  std::cout << tc::dark() << tc::red("dark red") << std::endl;
  std::cout << tc::orange_256("orange") << std::endl;
  std::cout << tc::on_orange_256("on_orange") << std::endl;

  std::cout << tc::cout_red() << "cout hello" << std::endl;
  std::cout << tc::cout_red("cout hello") << std::endl;
  std::cout << tc::cout_blue("cout hello") << std::endl;
  std::cerr << tc::cerr_green("cerr hello") << std::endl;
  std::cerr << tc::cerr_on_green("cerr hello") << std::endl;
  std::cerr << tc::cerr_bold("cerr hello") << std::endl;
  return 0;
}
