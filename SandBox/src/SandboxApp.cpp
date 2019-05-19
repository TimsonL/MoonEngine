#include <Moon.h>

class SandBox : public moon::Application
{
public:
  SandBox()
  {

  }

  ~SandBox()
  {

  }

};

moon::Application* moon::CreateApplication()
{
  return new SandBox();
}
