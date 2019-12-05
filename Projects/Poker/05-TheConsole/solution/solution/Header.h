
#pragma once

#include <string_view>

namespace colour
{
	constexpr std::string_view BLACK = "\[\033[0;30m\]";
	constexpr std::string_view RED   = "\[\033[0;31m\]";
	constexpr std::string_view GREEN = "\[\033[0;32m\]";
	constexpr std::string_view YELLOW = "\[\033[0;33m\]";
	constexpr std::string_view BLUE = "\[\033[0;34m\]";
	constexpr std::string_view PURPLE = "\[\033[0;35m\]";
	constexpr std::string_view CYAN = "\[\033[0;36m\]";
	constexpr std::string_view WHITE = "\[\033[0;37m\]";
}