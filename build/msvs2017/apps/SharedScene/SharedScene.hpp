#pragma once

#include <SLRenderer/SLRenderer.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

void CreateScene(ISLRenderer* renderer, ISLModel** ppModel, ISLCamera** ppCamera);
void DeleteRenderScene(ISLRenderer* renderer);
