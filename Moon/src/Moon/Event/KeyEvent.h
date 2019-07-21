#pragma once

#include "Event.h"

namespace moon {

  class KeyEvent : Event
  {
  public:
    KeyEvent(EventType type, Data&& data) : Event(type, data) {}
  };

}
