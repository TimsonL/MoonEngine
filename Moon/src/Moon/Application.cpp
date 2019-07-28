#include "pch.h"

#include "Application.h"

namespace moon {

  Application::Application()
  {
    m_dispatcher.RegisterEventCallback(this, &Application::onEngineEvent);
  }


  Application::~Application()
  {
  }


  void Application::Run()
  {
    while (true)
    {
      EngineEvent event;
      m_dispatcher.dispatch(&event);
    }
  }

}
