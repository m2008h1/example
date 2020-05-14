#include <iostream>

const int Weight_limit = 40;
const int N = 7;
int weight[N] = {12, 1, 24, 3, 6, 7, 15};
int value[N] = {3, 4, 56, 1, 22, 3, 44};

int dp[N + 1][Weight_limit + 1] = {0};

int get_max_value(int idx, int remaining_weight)
{
  if (dp[idx][remaining_weight] != 0)
    return dp[idx][remaining_weight];

  if (idx >= N)
    return 0;

  if (weight[idx] > remaining_weight)
  {
    dp[idx][remaining_weight] = get_max_value(idx + 1, remaining_weight);
    return dp[idx][remaining_weight];
  }

  dp[idx][remaining_weight] = std::max(
    get_max_value(idx + 1, remaining_weight),
    get_max_value(idx + 1, remaining_weight - weight[idx]) + value[idx]);
  return dp[idx][remaining_weight];
}

int main()
{
  std::cout << "max value: " << get_max_value(0, Weight_limit) << std::endl;
}