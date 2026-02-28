#include "BasicLayer.h"

#include "Core/Application.h"

int main()
{
    Core::ApplicationSpecification appSpec;
    appSpec.name = "Test";
    appSpec.windowSpec.width = 1920;
    appSpec.windowSpec.height = 1080;

    Core::Application application(appSpec);
    application.PushLayer<BasicLayer>();
    application.Run();

    return 0;
}
