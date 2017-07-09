#include "Model.h"
#include "Mesh.h"
#include "Material.h"

Model::Model(const std::string& meshfile, const std::string& matfile)
{
	mesh = std::shared_ptr<Mesh>(new Mesh(meshfile));
}

Model::~Model()
{

}
