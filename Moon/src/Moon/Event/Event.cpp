#include "pch.h"

#include "Event.h"
#include "EngineEvent.h"
#include "SystemEvent.h"
#include "WindowEvent.h"
#include "KeyEvent.h"
#include "MouseEvent.h"
#include "AppEvent.h"

namespace moon {

  template<typename EventCategory>
  void EventDispatcher<EventCategory>::AddListener(EventType type, EventListener* listener)
  {
    auto it = m_listeners.find(type);
    if (it != m_listeners.end()) {
      auto& listeners = it->second;
      for (auto l : listeners) {
        if (listener == l) {
          MOON_CORE_WARN("EventListener already registered");
          return;
        }
      }
      listeners.push_back(listener);
      listener->subscribe(type);
    }
    else {
      std::vector<EventListener*> newChannel;
      newChannel.push_back(listener);
      m_listeners[type] = std::move(newChannel);
    }
  }

  template<typename EventCategory>
  void EventDispatcher<EventCategory>::RemoveListener(EventType type, EventListener* listener)
  {
    auto it = m_listeners.find(type);
    if (it != m_listeners.end()) {
      auto& listeners = it->second;
      for (auto it = listeners.begin(); it != listeners.end(); ++it) {
        if (listener == *it) {
          listener->unsubscribe(type);
          listeners.erase(it);
          return;
        }
      }
      MOON_CORE_WARN("EventListener already removed");
    }
  }

  template<typename EventCategory>
  void EventDispatcher<EventCategory>::dispatch(const EventCategory& e)
  {
    auto type = e.GetType();
    auto& listeners = m_listeners[type];
    for (auto l : listeners) {
      l->OnEvent(type, e.GetData());
    }
  }

  // explicit instantiations
  template class EventDispatcher<SystemEvent>;
  template class EventDispatcher<EngineEvent>;
  template class EventDispatcher<WindowEvent>;
  template class EventDispatcher<KeyEvent>;
  template class EventDispatcher<MouseEvent>;
  template class EventDispatcher<AppEvent>;

  void EventListener::subscribe(EventType type)
  {
    m_subscriptions.emplace(type);
  }

  void EventListener::unsubscribe(EventType type)
  {
    m_subscriptions.erase(type);
  }
}
