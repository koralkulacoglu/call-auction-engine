#pragma once

#include <algorithm>

namespace cae {

using Price = int;
using Quantity = int;

enum class Side { BUY, SELL };

struct Order {
  int id;
  Side side;
  Price limit;
  Quantity quantity;
  Quantity remaining;
};

struct Fill {
  int order_id;
  Side side;
  Price limit;
  Quantity quantity;
  Price price;
};

struct LadderRow {
  Price price;

  // total supply/demand on opposite sides of the price level
  Quantity demand;
  Quantity supply;

  constexpr Quantity exec() const noexcept { return std::min(supply, demand); }
  constexpr Quantity surplus() const noexcept { return demand - supply; }
};

} // namespace cae
