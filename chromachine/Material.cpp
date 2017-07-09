#include <boost/filesystem.hpp>
#include "Material.h"

Material::Material(const std::string& matfile)
{
	boost::filesystem::path p(matfile);

	if (!boost::filesystem::exists(p))
	{
		std::string msg = "Unable to find material file " + boost::filesystem::absolute(p).filename().string();
		throw std::exception(msg.c_str());
	}

	if (!boost::filesystem::is_regular_file(p))
	{
		std::string msg = "Provided material file " + boost::filesystem::absolute(p).filename().string() + " is not a regular file";
		throw std::exception(msg.c_str());
	}
}

Material::~Material()
{
}
