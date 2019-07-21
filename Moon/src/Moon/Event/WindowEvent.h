#pragma once

#include "Event.h"

namespace moon {

  class WindowEvent : public Event
  {
  public:
    WindowEvent(EventType type, Data&& data) : Event(type, std::move(data)) {}
  };

}

