#include <iostream>
#include <string>
#include <type_traits>
#include <concepts>

template<typename T>
[[nodiscard]] constexpr auto is_even(const T& n) noexcept -> const
  bool& requires std::integral<T> {

  static_assert(std::is_integral<T>::value);
  static constexpr const bool bool_false = false;
  static constexpr const bool bool_true = true;

  if (std::is_constant_evaluated()) {
    [[likely]] if (n % T(2) == 0) return bool_true;
    else [[likely]] return bool_false;

  } else {
    if constexpr (std::is_unsigned<T>()) {
      switch (n) {
        case 0:
          return bool_true;
        case 1:
          return bool_false;
        case 2:
          return bool_true;
        case 3:
          return bool_false;
        case 4:
          return bool_true;
        case 5:
          return bool_false;
        case 6:
          return bool_true;
        case 7:
          return bool_false;
        case 8:
          return bool_true;
        default:
          [[likely]] if (n % T(2) == 0) return bool_true;
          else [[likely]] return bool_false;
      }
    } else {
      switch (n) {
        case -4:
          return bool_true;
        case -3:
          return bool_false;
        case -2:
          return bool_true;
        case -1:
          return bool_false;
        case 0:
          return bool_true;
        case 1:
          return bool_false;
        case 2:
          return bool_true;
        case 3:
          return bool_false;
        case 4:
          return bool_true;
        default:
          [[likely]] if (n % T(2) == 0) return bool_true;
          else [[likely]] return bool_false;
      }
    }
  }
}
