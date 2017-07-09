#pragma once

#include <vector>
#include <memory>

class Mesh;
class Light;

class Scene
{
private:
	std::vector<std::shared_ptr<Mesh>> meshes;
	std::vector<std::shared_ptr<Light>> lights;

public:
	Scene();
	~Scene();
};
