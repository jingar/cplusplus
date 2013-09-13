#include <iostream>

int main()
{
  int increase_skill_by = 0;
  int skill_level_type = 0;
  int next_unlock = 0;
  int current_level = 0;
  int target_level = 0;
  std::cin >> current_level  >> target_level >> skill_level_type >> next_unlock;
  
  increase_skill_by = target_level - current_level - 1;
  int total_required_points = next_unlock;
  
  while(increase_skill_by != 0) 
    {
      std::cout << total_required_points << '\n';
      next_unlock+=skill_level_type;
      total_required_points+= next_unlock;
      --increase_skill_by;
    }
  std::cout << total_required_points << '\n';
}
