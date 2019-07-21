#pragma once

#include "Event.h"

namespace moon {

  class SystemEvent : Event
  {
  public:
    SystemEvent(EventType type, Data&& data) : Event(type, data) {}
  };

}

