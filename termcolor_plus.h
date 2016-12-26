#pragma once
#include <iostream>
#include "termcolor.hpp"

#define _set_color(col, str)                                                                                                          \
	static std::string cout_##col() { return termcolor::_internal::is_atty(std::cout) ? str : ""; }                                   \
	static std::string cout_##col(std::string s) { return (termcolor::_internal::is_atty(std::cout) ? str : "") + s + cout_reset(); } \
	static std::string cerr_##col() { return termcolor::_internal::is_atty(std::cerr) ? str : ""; }                                   \
	static std::string cerr_##col(std::string s) { return (termcolor::_internal::is_atty(std::cerr) ? str : "") + s + cerr_reset(); }
namespace tc {
//	NOTE ";" is no meaning
//	this must be top
_set_color(reset, "\033[00m");
//
_set_color(grey, "\033[30m");
_set_color(red, "\033[31m");
_set_color(green, "\033[32m");
_set_color(yellow, "\033[33m");
_set_color(blue, "\033[34m");
_set_color(magenta, "\033[35m");
_set_color(cyan, "\033[36m");
_set_color(white, "\033[37m");

_set_color(on_grey, "\033[40m");
_set_color(on_red, "\033[41m");
_set_color(on_green, "\033[42m");
_set_color(on_yellow, "\033[43m");
_set_color(on_blue, "\033[44m");
_set_color(on_magenta, "\033[45m");
_set_color(on_cyan, "\033[46m");
_set_color(on_white, "\033[47m");

_set_color(bold, "\033[1m");
_set_color(dark, "\033[2m");
_set_color(underline, "\033[4m");
_set_color(blink, "\033[5m");
_set_color(reverse, "\033[7m");
_set_color(concealed, "\033[8m");
}
