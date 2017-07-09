#include <boost/filesystem.hpp>
#include <exception>
#include "Mesh.h"


Mesh::Mesh(const std::string& meshfile)
{
	// determine file type
	// supported formats: fbx (ascii), obj (ascii), ply (ascii), stl (ascii)

	boost::filesystem::path p(meshfile);

	if (!boost::filesystem::exists(p))
	{
		std::string msg = "Unable to find mesh file " + boost::filesystem::absolute(p).filename().string();
		throw std::exception(msg.c_str());
	}

	if (!boost::filesystem::is_regular_file(p))
	{
		std::string msg = "Provided mesh file " + boost::filesystem::absolute(p).filename().string() + " is not a regular file";
		throw std::exception(msg.c_str());
	}
}

Mesh::~Mesh()
{

}
