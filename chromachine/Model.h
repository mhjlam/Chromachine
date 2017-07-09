#pragma once

#include <memory>
#include <string>

class Mesh;
class Material;

class Model
{
private:
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Material> material;

public:
	Model(const std::string& meshfile, const std::string& matfile);
	~Model();
};

