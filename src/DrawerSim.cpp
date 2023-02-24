#include "Drawer3D/DrawerSim.h"

DrawerSim::DrawerSim() : window(1000, 800, "DrawerSim"), modelShader("model.vs", "model.fs")
{
    Model newModel(FileSystem::getPath("resources/objects/backpack/backpack.obj"));
    axis_Model.push_back(newModel);
}

DrawerSim::~DrawerSim()
{
}
void DrawerSim::setBGColor(float r, float g, float b, float t)
{
    BGColor[0] = r;
    BGColor[1] = g;
    BGColor[2] = b;
    BGColor[3] = t;
}
void DrawerSim::run()
{
    while (!window.ShouldClose())
    {
        window.processInput();
        glClearColor(BGColor[0], BGColor[1], BGColor[2], BGColor[3]);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        modelShader.use();

        // view/projection transformations
        Camera camera = window.getCamera();
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)window.getWidth() / (float)window.getHeight(), 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        modelShader.setMat4("projection", projection);
        modelShader.setMat4("view", view);

        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));     // it's a bit too big for our scene, so scale it down
        modelShader.setMat4("model", model);
        for (Model axis : axis_Model)
        {
            axis.Draw(modelShader);
        }

        window.update();
    }
}
