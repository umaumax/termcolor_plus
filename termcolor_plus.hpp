#pragma once
#include <cassert>
#include <string>
#include "termcolor/include/termcolor/termcolor.hpp"

namespace tc {
namespace detail {
inline std::string GetEnvVar(std::string const& key) {
  char const* val = getenv(key.c_str());
  return val == NULL ? std::string() : std::string(val);
}

inline bool GetBoolByEnv(std::string const& key) {
  std::string ret = GetEnvVar(key);
  if (ret == "TRUE" || ret == "T" || ret == "true" || ret == "t" || ret == "1") {
    return true;
  } else if (ret == "FALSE" || ret == "F" || ret == "false" || ret == "f" || ret == "0") {
    return false;
  }
  assert((ret == "") || !(std::cerr << "wrong env : env key = " << key << ", env val = " << ret << std::endl << "select TRUE, T, true, t, 1, FALSE, F, false, f, 0" << std::endl));
  return false;
}

inline bool IsStdoutAtty() {
  static bool cout_flag = detail::GetBoolByEnv("COLOR_FORCE") || termcolor::_internal::is_atty(std::cout);
  return cout_flag;
}
inline bool IsStderrAtty() {
  static bool cerr_flag = detail::GetBoolByEnv("COLOR_FORCE") || termcolor::_internal::is_atty(std::cerr);
  return cerr_flag;
}
}  // namespace detail

#define TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(col, str)                                                              \
  inline std::string cout_##col() { return detail::IsStdoutAtty() ? str : ""; }                                   \
  inline std::string cout_##col(std::string s) { return (detail::IsStdoutAtty() ? str : "") + s + cout_reset(); } \
  inline std::string cerr_##col() { return detail::IsStderrAtty() ? str : ""; }                                   \
  inline std::string cerr_##col(std::string s) { return (detail::IsStderrAtty() ? str : "") + s + cerr_reset(); } \
  inline std::string /*  */ col() { return (str); }                                                               \
  inline std::string /*  */ col(std::string s) { return (str) + s + cerr_reset(); }

// NOTE ";" is no meaning
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(reset, /*     */ "\033[00m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(grey, /*      */ "\033[30m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(red, /*       */ "\033[31m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(green, /*     */ "\033[32m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(yellow, /*    */ "\033[33m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(blue, /*      */ "\033[34m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(magenta, /*   */ "\033[35m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(cyan, /*      */ "\033[36m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(white, /*     */ "\033[37m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(on_grey, /*   */ "\033[40m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(on_red, /*    */ "\033[41m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(on_green, /*  */ "\033[42m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(on_yellow, /* */ "\033[43m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(on_blue, /*   */ "\033[44m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(on_magenta, /**/ "\033[45m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(on_cyan, /*   */ "\033[46m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(on_white, /*  */ "\033[47m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(bold, /*      */ "\033[1m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(dark, /*      */ "\033[2m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(underline, /* */ "\033[4m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(blink, /*     */ "\033[5m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(reverse, /*   */ "\033[7m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(concealed, /* */ "\033[8m");

// expand color only for 256colors?
// FYI: [/usr/lib/X11/rgb.txt]( http://www.astrouw.edu.pl/~jskowron/colors-x11/rgb.html )
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(orange_256, /*   */ "\033[38;2;255;165;0m");
TERM_COLOR_PLUS_COLOR_DEFINE_MACRO(on_orange_256, /**/ "\033[48;2;255;165;0m");
}  // namespace tc
