#pragma once

#include "Event.h"

namespace moon {

  class WindowEvent : Event
  {
  public:
    WindowEvent(EventType type, Data&& data) : Event(type, data) {}
  };

}

