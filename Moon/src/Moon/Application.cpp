#include "pch.h"

#include "Application.h"

namespace moon {

  Application::Application()
  {
    m_engineEventDispatcher.AddListener(EventType::EngineUpdate, this);
  }


  Application::~Application()
  {
  }


  void Application::Run()
  {
    while (true)
    {
      m_engineEventDispatcher.dispatch({ EventType::EngineUpdate, Event::Data() });
    }
  }

}
