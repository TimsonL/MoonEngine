#pragma once

#include "pch.h"

namespace moon {

  class Event {
  public:
    using Data = std::unordered_map<std::string, boost::any>;

    Event() {}
    Event(Data&& data) : m_data(data) {}

    const boost::any& operator[](const std::string& key) const {
      auto it = m_data.find(key);
      if (it != m_data.end()) return it->second;
      MOON_CORE_ERROR("Event does not have the requested attribute");
      assert(0);
    }
  protected:
    Data m_data;
  };

  class EventCallback;

  class EventDispatcher {
  public:
    template<class EventT>
    void dispatch(const EventT* event)
    {
      auto it = m_callbacks.find(typeid(*event));
      if (it != m_callbacks.end())
      {
        for (auto& callback : it->second) callback->exec(event);
      }
    }

    template<class T, class EventT>
    void RegisterEventCallback(T* object, void(T::*memberFn)(const EventT*))
    {
      std::type_index id = typeid(EventT);
      m_callbacks[id].push_back(std::make_unique<MemberCallback<T, EventT>>(object, memberFn));
    }
  private:
    using Callbacks = std::map< std::type_index, std::vector<std::unique_ptr<EventCallback>>>;
    Callbacks m_callbacks;
  };

  class EventCallback {
  public:
    void exec(const Event* event) { call(event); }
  private:
    virtual void call(const Event* event) = 0;
  };

  template <class T, class EventT >
  class MemberCallback : public EventCallback
  {
  public:
    using MemberFunc = void(T::*)(const EventT*);
    MemberCallback(T* object, MemberFunc memFn) : m_object(object), m_callback(memFn) {};

    void call(const Event* event)
    {
      (m_object->*m_callback)(static_cast<const EventT*>(event));
    }

  private:
    T* m_object;
    MemberFunc m_callback;
  };
}
                        