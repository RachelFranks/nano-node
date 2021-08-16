#pragma once

#include <nano/lib/errors.hpp> // for REGISTER_ERROR_CODES

#include <boost/program_options/variables_map.hpp> // for variables_map

#include <system_error> // for error_code

namespace boost
{
namespace program_options
{
	class options_description;
}
}
namespace nano
{
class node_config;
}
namespace nano
{
class node_flags;
}

namespace nano
{
/** Command line related error codes */
enum class error_cli
{
	generic = 1,
	parse_error = 2,
	invalid_arguments = 3,
	unknown_command = 4,
	database_write_error = 5,
	reading_config = 6,
	disable_all_network = 7,
	ambiguous_udp_options = 8,
	ambiguous_pruning_voting_options = 9
};

void add_node_options (boost::program_options::options_description &);
void add_node_flag_options (boost::program_options::options_description &);
std::error_code update_flags (nano::node_flags &, boost::program_options::variables_map const &);
std::error_code flags_config_conflicts (nano::node_flags const &, nano::node_config const &);
std::error_code handle_node_options (boost::program_options::variables_map const &);
}

REGISTER_ERROR_CODES (nano, error_cli)
