#ifndef __NOTHR_H__
#define __NOTHR_H__

#include <functional>
#include <utility>

namespace re2
{
    class once_flag
    {
      public:
        bool called;
        once_flag() : called(false)
        {}
    };

    template <typename Callable, typename... Args> void call_once(once_flag &flag, Callable &&f, Args &&... args)
    {
        if (flag.called) {
            return;
        }

        flag.called = true;
        std::invoke(std::forward<Callable>(f), std::forward<Args>(args)...);
    }

    class dummy_mutex
    {
      public:
        dummy_mutex() = default;
        void lock(){};
        void unlock(){};
    };

} // namespace re2

#endif // __NOTHR_H__
