#pragma once

#include "pch.h"
#include "Event.h"

namespace moon {

  class KeyEvent : public Event
  {
  public:
    inline int GetKeyCode() { return m_KeyCode; }
  protected:
    KeyEvent(int keycode) : m_KeyCode(keycode) {}
    
    int m_KeyCode;
  };

  class KeyPressedEvent : public KeyEvent
  {
  public:
    KeyPressedEvent(int keycode, bool repeat)
      : KeyEvent(keycode), m_IsRepeating(repeat) {}

    inline bool IsRepeating() { return m_IsRepeating; }

    std::string ToString() const override
    {
      std::stringstream ss;
      ss << "KeyPressedEvent " << m_KeyCode << (m_IsRepeating) ? " repeating" : " pressed";
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyPressed);
  private:
    bool m_IsRepeating;
  };


  class KeyReleasedEvent : public KeyEvent
  {
  public:
    KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

    EVENT_CLASS_TYPE(KeyReleased);
  };

  class KeyTypedEvent : public KeyEvent
  {
  public:
    KeyTypedEvent(int keycode) : KeyEvent(keycode) {}

    EVENT_CLASS_TYPE(KeyTyped);
  };

}