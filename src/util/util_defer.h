#pragma once

namespace ranae {

  template <typename Func>
  class Deferrer {

  public:

    Deferrer(Func func) : m_func(func) {}
	~Deferrer() { m_func(); }

  private:

    Func m_func;

  };

  template <typename Func>
  Deferrer<Func> DeferFunction(Func f) {
	  return Deferrer<Func>(f);
  }

}

#define DEFER_1(x, y) x##y
#define DEFER_2(x, y) DEFER_1(x, y)
#define DEFER_3(x)    DEFER_2(x, __COUNTER__)
#define defer(code)   auto DEFER_3(_defer_) = ::ranae::DeferFunction([&](){code;})