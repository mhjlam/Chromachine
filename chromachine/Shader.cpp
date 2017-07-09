#include <boost/filesystem.hpp>
#include "Shader.h"


Shader::Shader(const std::string& shaderfile)
{
	boost::filesystem::path p(shaderfile);

	// Check if file exists
	if (!boost::filesystem::exists(p))
	{
		std::string msg = "Unable to find shader file " + boost::filesystem::absolute(p).filename().string();
		throw std::exception(msg.c_str());
	}

	// Check that file is a regular file (no system file or directory)
	if (!boost::filesystem::is_regular_file(p))
	{
		std::string msg = "Provided shader file " + boost::filesystem::absolute(p).filename().string() + " is not a regular file";
		throw std::exception(msg.c_str());
	}

	// Attempt to compile/load shader file

}


Shader::~Shader()
{
}
