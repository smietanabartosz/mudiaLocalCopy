#ifndef __RTOSTHREADS_H__
#define __RTOSTHREADS_H__

#include <mutex.hpp>

#include <functional>

namespace re2
{
    class mutex {
      private:
        cpp_freertos::MutexStandard mutex;

      public:
        void lock() { mutex.Lock(); }
        void unlock() { mutex.Unlock(); }
    };

    class once_flag
    {
        bool called;
      public:
        once_flag() noexcept : called(false) {}
        once_flag(const once_flag&) = delete;
        once_flag& operator=(const once_flag&) = delete;

        template <typename Callable, typename... Args>
        friend void call_once(once_flag &flag, Callable &&f, Args &&... args);
    };

    template <typename Callable, typename... Args> void call_once(once_flag &flag, Callable &&f, Args &&... args)
    {
        static mutex mutex;

        mutex.lock();
        if (!flag.called) {
            std::invoke(std::forward<Callable>(f), std::forward<Args>(args)...);
            flag.called = true;
        }
        mutex.unlock();
    }
}


#endif // __RTOSTHREADS_H__
