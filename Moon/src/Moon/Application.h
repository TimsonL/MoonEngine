#pragma once

#include "Core.h"
#include "Moon/Event/EngineEvent.h"

namespace moon {

  class Application : public EventListener
  {
  public:
    Application();
    virtual ~Application();

    void Run();

    void OnEvent(EventType type, const Event::Data& data) const override {
      if (EventType::EngineUpdate == type) MOON_INFO("Engine Update Event Proccessed");
    }
  protected:
    EventDispatcher<EngineEvent> m_engineEventDispatcher;
  };

  Application* CreateApplication();

}
