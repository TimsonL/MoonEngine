#pragma once

#include "Core.h"

namespace moon {

  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();
  };

  Application* CreateApplication();

}
