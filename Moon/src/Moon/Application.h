#pragma once

#include "Core.h"
#include "Moon/Event/EngineEvent.h"

namespace moon {

  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();

    void onEngineEvent(const EngineEvent* event) {
      MOON_INFO("Engine Update Event Proccessed");
    }
  protected:
    EventDispatcher m_dispatcher;
  };

  Application* CreateApplication();

}
