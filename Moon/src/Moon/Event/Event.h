#pragma once

#include "Moon/Core.h"
#include <string>

namespace moon {

  enum class EventType
  {
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased, KeyTyped,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
  };

  class Event
  {
  public:
    bool Handled = false;

    virtual EventType GetEventType() const = 0;
    virtual const char* GetName() const = 0;

    virtual std::string ToString() const { return GetName(); }
  };

  class EventDispatcher
  {
    template<typename T>
    using EventFn = std::function<bool(T&)>;
  public:
    EventDispatcher(Event& event)
      : m_Event(event)
    {
    }

    template<typename T>
    bool Dispatch(EventFn<T> func)
    {
      if (m_Event.GetEventType() == T::GetStaticType())
      {
        m_Event.Handled = func(*(T*)&m_Event);
        return true;
      }
      return false;
    }
  private:
    Event& m_Event;
  };

  inline std::ostream& operator<<(std::ostream& os, const Event& e)
  {
    return os << e.ToString();
  }

}