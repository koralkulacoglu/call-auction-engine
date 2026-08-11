#pragma once

#include "Types.h"

#include <functional>
#include <map>
#include <optional>
#include <vector>

namespace cae {

class Book {
public:
  void insert(const Order &order);

  std::vector<LadderRow> ladder() const;

  std::optional<Price> bestBid() const;
  std::optional<Price> bestAsk() const;

private:
  std::map<Price, std::vector<Order>, std::greater<Price>> bids;
  std::map<Price, std::vector<Order>, std::less<Price>> asks;
};

} // namespace cae
