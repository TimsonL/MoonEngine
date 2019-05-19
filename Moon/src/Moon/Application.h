#pragma once

#include "Core.h"

namespace moon {

  class MOON_API Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();
  };

  Application* CreateApplication();

}
