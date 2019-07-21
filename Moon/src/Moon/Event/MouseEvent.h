#pragma once

#include "Event.h"

namespace moon {

  class MouseEvent : Event
  {
  public:
    MouseEvent(EventType type, Data&& data) : Event(type, data) {}
  };

}

