//
// Created by JoachimWagner on 14.10.2022.
//

#pragma once
namespace vw::time {

    class stopwatch {

    public:
        virtual ~stopwatch() = default;

        /// Starts this stop watch.
        virtual auto start() -> void = 0;

        /// Stops this stop watch.
        virtual auto stop() -> void = 0;

        /// Returns the elapsed duration.
        ///
        /// @return the elapsed time duration between the last call to `start()` and `stop()`
        [[nodiscard]] virtual auto elapsedDuration() -> std::chrono::milliseconds = 0;
    };

}




