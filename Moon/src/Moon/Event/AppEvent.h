#pragma once

#include "Event.h"

namespace moon {

  class AppEvent : Event
  {
  public:
    AppEvent(EventType type, Data&& data) : Event(type, data) {}
  };

}

