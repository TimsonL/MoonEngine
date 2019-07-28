#pragma once

#include "Event.h"

namespace moon {

  class KeyEvent : public Event
  {
  public:
    KeyEvent() : Event() {}
    KeyEvent(Data&& data) : Event(std::move(data)) {}
  };

}
