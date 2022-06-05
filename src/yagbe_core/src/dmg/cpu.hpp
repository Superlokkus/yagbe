//
// Created by Markus Klemm on 06.06.22.
//

#ifndef YAGBE_CPU_HPP
#define YAGBE_CPU_HPP

#include <array>
#include <cstdint>

class cpu {
private:
    using register_t = std::uint8_t;
    register_t acc{}; //!< Accumulator
    register_t pc{}; //!< Program Counter
    register_t f{}; //!< Flag register
    register_t sp{}; //!< Stack Pointer

    std::array<register_t, 7> cpu_registers{};


    std::array<std::uint8_t, 8 * 1024> work_ram{};
    std::array<std::uint8_t, 8 * 1024> display_ram{};
};


#endif //YAGBE_CPU_HPP
