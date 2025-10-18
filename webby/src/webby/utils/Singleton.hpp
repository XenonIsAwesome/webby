#pragma once

namespace webby::utils {
    /**
     * Inheriting from this class makes the derived a singleton.
     * @tparam Derived CRTP template of the derived class
     */
    template<typename Derived>
    class Singleton {
    public:
        /**
         * Creates a static instance of the derived class and returns it.
         * @return The static instance of the derived class.
         */
        static Derived* getInstance() {
            static Derived* instance = new Derived();
            return instance;
        }
    };
}