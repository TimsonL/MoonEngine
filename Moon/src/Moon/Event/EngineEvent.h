#pragma once

#include "Event.h"

namespace moon {

  class EngineEvent : Event
  {
  public:
    EngineEvent(EventType type, Data&& data) : Event(type, data) {}
  };

}

