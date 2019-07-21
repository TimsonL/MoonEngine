#pragma once

#include "Event.h"

namespace moon {

  class KeyEvent : public Event
  {
  public:
    KeyEvent(EventType type, Data&& data) : Event(type, std::move(data)) {}
  };

}
